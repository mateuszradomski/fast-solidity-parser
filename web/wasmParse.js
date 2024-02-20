const fs = require('fs');
const path = require('path');

const SpallProfiler = require('./spall');
const profiler = new SpallProfiler();

const ASTNodeType_SourceUnit = 1
const ASTNodeType_Import = 2

function stringToStringLiteral(str) {
    if(str === null) {
        return null
    }

    return {
        type: "StringLiteral",
        value: str,
        parts: [str],
        isUnicode: [false]
    }
}

function stringToIdentifier(str) {
    if(str === null) {
        return null
    }

    return {
        type: "Identifier",
        name: str,
    }
}

class Deserializer {
    constructor(inputString, dataView) {
        this.inputString = inputString;
        this.dataView = dataView;
        this.offset = 0;
    }

    popU32() {
        const value = this.dataView.getUint32(this.offset, true);
        this.offset += 4;
        return value;
    }

    popString() {
        const offset = this.popU32();
        const length = this.popU32();

        if(offset === 0xffffffff) {
            return null;
        } else {
            return this.inputString.substring(offset, offset + length);
        }
    }

    popImport() {
        const path = this.popString();
        const unitAlias = this.popString();
        const symbolsCount = this.popU32();

        let aliases = [];
        let aliasesIdentifiers = [];

        if(symbolsCount === 0) {
            aliases = null;
            aliasesIdentifiers = null;
        }

        for (let i = 0; i < symbolsCount; i++) {
            const symbol = this.popString();
            const alias = this.popString();
            aliases.push([symbol, alias]);
            aliasesIdentifiers.push([ stringToIdentifier(symbol), stringToIdentifier(alias) ]);
        }

        return {
            type: "ImportDirective",
            path,
            pathLiteral: stringToStringLiteral(path),
            unitAlias,
            unitAliasIdentifier: stringToIdentifier(unitAlias),
            symbolAliases: aliases,
            symbolAliasesIdentifiers: aliasesIdentifiers
        }
    }

    popASTNode() {
        const type = this.popU32();

        if(type === ASTNodeType_SourceUnit) {
            return this.popSourceUnit();
        } else if(type === ASTNodeType_Import) {
            return this.popImport();
        }
    }

    popSourceUnit() {
        const type = this.popU32();
        if(type !== ASTNodeType_SourceUnit) {
            throw new Error("Invalid SourceUnit type");
        }

        const childrenCount = this.popU32();
        const children = new Array(childrenCount);

        for(let i = 0; i < childrenCount; i++) {
            children[i] = this.popASTNode();
        }

        return {
            type: "SourceUnit",
            children
        }
    }
}

class WasmParser {
    constructor() { }

    async parseJSONInterface(input) {
        const wasmPath = path.join(__dirname, "./parser.wasm");
        const wasmBuffer = fs.readFileSync(wasmPath);
        const { instance } = await WebAssembly.instantiate(wasmBuffer, {
            env: makeEnv(this)
        });
        this.instance = instance;

        const jsArray = new TextEncoder().encode(input);

        profiler.trace_begin("Copying");
        const cArrayPointer = instance.exports.malloc(jsArray.length);
        let memoryBuffer = instance.exports.memory.buffer;
        this.cArray = new Uint8Array(memoryBuffer, cArrayPointer, jsArray.length);
        this.cArray.set(jsArray);
        profiler.trace_end();

        profiler.trace_begin("WASM JSON Interface");
        const string_struct_pointer = instance.exports.entryPointJSONInterface(cArrayPointer, jsArray.length);
        profiler.trace_end();

        memoryBuffer = instance.exports.memory.buffer;

        profiler.trace_begin("StringDecode");
        const string = struct_string_by_pointer(memoryBuffer, string_struct_pointer)
        profiler.trace_end();
        profiler.trace_begin("JSONParse");
        const parsed = JSON.parse(string);
        profiler.trace_end();

        const spallBytes = profiler.serialize();
        fs.writeFileSync("data.spall", spallBytes);

        return parsed;
    }

    async parseBinaryInterface(input) {
        const wasmPath = path.join(__dirname, "./parser.wasm");
        const wasmBuffer = fs.readFileSync(wasmPath);
        const { instance } = await WebAssembly.instantiate(wasmBuffer, {
            env: makeEnv(this)
        });
        this.instance = instance;

        const jsArray = new TextEncoder().encode(input);

        profiler.trace_begin("Copying");
        const cArrayPointer = instance.exports.malloc(jsArray.length);
        let memoryBuffer = instance.exports.memory.buffer;
        this.cArray = new Uint8Array(memoryBuffer, cArrayPointer, jsArray.length);
        this.cArray.set(jsArray);
        profiler.trace_end();

        profiler.trace_begin("WASM Binary Interface");
        const resultPointer = instance.exports.entryPointBinaryInterface(cArrayPointer, jsArray.length);
        profiler.trace_end();

        memoryBuffer = instance.exports.memory.buffer;

        profiler.trace_begin("parseBinary");
        const object = this.parseBinary(input, memoryBuffer, resultPointer);
        profiler.trace_end();

        const spallBytes = profiler.serialize();
        fs.writeFileSync("data.spall", spallBytes);

        return object;
    }

    parseBinary(inputString, memoryBuffer, pointer) {
        const memory = new Uint32Array(memoryBuffer);
        const dataPointer = memory[pointer / 4];
        const dataLength = memory[(pointer / 4) + 1];
        const data = new Uint8Array(memoryBuffer, dataPointer, dataLength);
        const dataView = new DataView(data.buffer, data.byteOffset, data.byteLength);
        const deserializer = new Deserializer(inputString, dataView);

        return deserializer.popSourceUnit();
    }

    javascriptPrintStringPtr(pointer) {
        const memoryBuffer = this.instance.exports.memory.buffer;
        const json_string = struct_string_by_pointer(memoryBuffer, pointer);
        console.log(json_string);
    }

    javascriptPrintNumber(number) {
        console.log(number);
    }
}

function struct_string_by_pointer(mem_buffer, ptr) {
    const mem = new Uint32Array(mem_buffer);
    const string_pointer = mem[ptr / 4];
    const string_length = mem[(ptr / 4) + 1];
    const bytes = new Uint8Array(mem_buffer, string_pointer, string_length);
    return new TextDecoder().decode(bytes);
}

function makeEnv(env) {
    return new Proxy(env, {
        get(target, prop, receiver) {
            if (env[prop] !== undefined) {
                return env[prop].bind(env);
            }
            return (...args) => {
                throw new Error(`NOT IMPLEMENTED: ${prop} ${args}`);
            }
        }
    });
}
function hexdump(mem_buffer, index, size) {
    const mem = new Uint8Array(mem_buffer);
    const numbers = [];
    for(let i = 0; i < size; i++) {
        numbers.push(mem[index + i]);
    }

    for(let row = 0; row < size; row += 16) {
        let line = '';
        for(let col = 0; col < 16; col++) {
            if (row + col < size) {
                line += numbers[row + col].toString(16).padStart(2, '0') + ' ';
            } else {
                line += '   ';
            }
        }
        console.log(line);
    }
}

module.exports = WasmParser;
