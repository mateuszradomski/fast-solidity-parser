const Deserializer = require('./Deserializer');
const SpallProfiler = require('./spall');
const profiler = new SpallProfiler();

class WasmParser {
    constructor() {}

    loadParserNode() {
        const fs = require('fs');
        const path = require('path');
        profiler.trace_begin("Loading the module");

        profiler.trace_begin("Read from disk");
        const wasmPath = path.join(__dirname, "./parser.wasm");
        const wasmBuffer = fs.readFileSync(wasmPath);
        profiler.trace_end();

        this.loadWasmModule(wasmBuffer)

        profiler.trace_end();
    }

    async loadParserWeb() {
        const response = await fetch('./parser.wasm');
        const wasmBuffer = await response.arrayBuffer();
        this.loadWasmModule(wasmBuffer);
    }

    loadWasmModule(wasmBuffer) {
        profiler.trace_begin("Make module");
        const mod = new WebAssembly.Module(wasmBuffer);
        profiler.trace_end();
        profiler.trace_begin("Make instance");
        const instance = new WebAssembly.Instance(mod, {
            env: makeEnv(this)
        });
        profiler.trace_end();

        this.instance = instance;
    }
    
    saveProfileToDisk() {
        const fs = require('fs');
        const spallBytes = profiler.serialize();
        fs.writeFileSync("data.spall", spallBytes);
    }

    parseBinaryInterface(input) {
        const jsArray = new TextEncoder().encode(input);

        profiler.trace_begin("Copying");
        const cArrayPointer = this.instance.exports.malloc(jsArray.length);
        let memoryBuffer = this.instance.exports.memory.buffer;
        this.cArray = new Uint8Array(memoryBuffer, cArrayPointer, jsArray.length);
        this.cArray.set(jsArray);
        profiler.trace_end();

        profiler.trace_begin("WASM Binary Interface");
        const resultPointer = this.instance.exports.entryPointBinaryInterface(cArrayPointer, jsArray.length);
        profiler.trace_end();

        memoryBuffer = this.instance.exports.memory.buffer;

        profiler.trace_begin("parseBinary");
        const object = this.parseBinary(input, memoryBuffer, resultPointer);
        profiler.trace_end();

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

    traceBegin(number) {
        profiler.trace_begin(`${number}`);
    }

    traceEnd() {
        profiler.trace_end();
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
