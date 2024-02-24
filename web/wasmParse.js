const fs = require('fs');
const path = require('path');
const { PerformanceObserver } = require('perf_hooks');

const SpallProfiler = require('./spall');
const profiler = new SpallProfiler();

const ASTNodeType_SourceUnit = 1
const ASTNodeType_Import = 2
const ASTNodeType_EnumDefinition = 3
const ASTNodeType_StructDefinition = 4
const ASTNodeType_BaseType = 5
const ASTNodeType_FunctionType = 6
const ASTNodeType_MappingType = 7
const ASTNodeType_IdentifierPath = 8
const ASTNodeType_ArrayType = 9
const ASTNodeType_Error = 10
const ASTNodeType_Event = 11
const ASTNodeType_Typedef = 12
const ASTNodeType_ConstVariable = 13
const ASTNodeType_NumberLitExpression = 14
const ASTNodeType_StringLitExpression = 15
const ASTNodeType_BoolLitExpression = 16
const ASTNodeType_LiteralExpression = 17
const ASTNodeType_BinaryExpression = 18

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

function stringToEnumValue(str) {
    if(str === null) {
        return null
    }

    return {
        type: "EnumValue",
        name: str,
    }
}

class Deserializer {
    constructor(inputString, dataView) {
        this.inputString = inputString;
        this.dataView = dataView;
        this.offset = 0;

        this.operatorStrings = {
            67: "+",
            68: "-",
            69: "%",
            70: "/",
            71: "*",
            72: "&",
            73: "|",
            74: "^",
        }
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

    popType() {
        const kind = this.popU32();

        if(kind === ASTNodeType_BaseType) {
            const name = this.popString();
            const payable = this.popU32();
            return {
                type: "ElementaryTypeName",
                name,
                stateMutability: payable === 0 ? null : "payable"
            }
        } else if(kind === ASTNodeType_IdentifierPath) {
            const identifiersCount = this.popU32();
            let path = ""
            for(let i = 0; i < identifiersCount; i++) {
                path += this.popString();
                if(i < identifiersCount - 1) {
                    path += ".";
                }
            }
            return {
                type: "UserDefinedTypeName",
                namePath: path,
            }
        } else if(kind === ASTNodeType_MappingType) {
            const keyType = this.popType();
            const keyIdentifier = this.popString();
            const valueType = this.popType();
            const valueIdentifier = this.popString();
            return {
                type: "Mapping",
                keyType,
                keyName: stringToIdentifier(keyIdentifier),
                valueType,
                valueName: stringToIdentifier(valueIdentifier),
            }
        } else if(kind === ASTNodeType_ArrayType) {
            const baseType = this.popType();
            return {
                type: "ArrayTypeName",
                baseTypeName: baseType,
                length: null,
            }
        } else {
            throw new Error(`Unknown/Unsupported type kind: ${kind}`);
        }
    }

    popExpression() {
        const type = this.popU32();

        if(type === ASTNodeType_NumberLitExpression) {
            const value = this.popString();
            const subdenomination = this.popString();

            return {
                type: "NumberLiteral",
                number: value,
                subdenomination
            }
        } else if(type === ASTNodeType_StringLitExpression) {
            const value = this.popString();

            return {
                type: "StringLiteral",
                value,
                parts: [value],
                isUnicode: [false]
            }
        } else if(type === ASTNodeType_BoolLitExpression) {
            const value = this.popString();

            return {
                type: "BooleanLiteral",
                value: value === "true"
            }
        } else if(type === ASTNodeType_LiteralExpression) {
            const name = this.popString();

            return {
                type: "Identifier",
                name
            }
        } else if(type === ASTNodeType_BinaryExpression) {
            const operatorId = this.popU32();
            const lhs = this.popExpression();
            const rhs = this.popExpression();

            const operator = this.operatorStrings[operatorId];

            return {
                type: "BinaryOperation",
                operator,
                left: lhs,
                right: rhs
            }
        } else {
            throw new Error(`Unknown/Unsupported expression type: ${type}`);
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

    popEnumDefinition() {
        const name = this.popString();

        const membersCount = this.popU32();
        const members = []
        for(let i = 0; i < membersCount; i++) {
            members.push(stringToEnumValue(this.popString()));
        }

        return {
            type: "EnumDefinition",
            name,
            members,
        }
    }

    popStructDefinition() {
        const name = this.popString();
        const membersCount = this.popU32();
        const members = []
        for(let i = 0; i < membersCount; i++) {
            const typeName = this.popType();
            const memberName = this.popString();
            members.push({
                type: "VariableDeclaration",
                typeName,
                name: memberName,
                identifier: stringToIdentifier(memberName),
                storageLocation: null,
                isStateVar: false,
                isIndexed: false,
                expression: null,
            });
        }

        return {
            type: "StructDefinition",
            name,
            members,
        }
    }

    popError() {
        const name = this.popString();
        const paramCount = this.popU32();
        const params = []
        for(let i = 0; i < paramCount; i++) {
            const typeName = this.popType();
            const paramName = this.popString();
            params.push({
                        type: "VariableDeclaration",
                        typeName,
                        name: paramName,
                        identifier: stringToIdentifier(paramName),
                        storageLocation: null,
                        isStateVar: false,
                        isIndexed: false,
                        expression: null
            });
        }

        return {
            type: "CustomErrorDefinition",
            name,
            parameters: params
        }
    }

    popEvent() {
        const name = this.popString();
        const isAnonymous = this.popU32() === 1;
        const paramCount = this.popU32();
        const params = []
        for(let i = 0; i < paramCount; i++) {
            const typeName = this.popType();
            const paramName = this.popString();
            const indexed = this.popU32();
            params.push({
                        type: "VariableDeclaration",
                        typeName,
                        name: paramName,
                        identifier: stringToIdentifier(paramName),
                        isStateVar: false,
                        isIndexed: indexed === 1,
                        storageLocation: null,
                        expression: null
            });
        }


        return {
            type: "EventDefinition",
            name,
            parameters: params,
            isAnonymous
        }

    }

    popTypedef() {
        const name = this.popString();
        const type = this.popType();

        return {
            type: "TypeDefinition",
            name,
            definition: type
        }
    }

    popConstVariable() {
        const name = this.popString();
        const typeName = this.popType();
        const initialValue = this.popExpression();

        return {
            type: "FileLevelConstant",
            typeName,
            name,
            initialValue,
            isDeclaredConst: true,
            isImmutable: false,
        }
    }

    popASTNode() {
        const type = this.popU32();

        if(type === ASTNodeType_SourceUnit) {
            return this.popSourceUnit();
        } else if(type === ASTNodeType_Import) {
            return this.popImport();
        } else if(type === ASTNodeType_EnumDefinition) {
            return this.popEnumDefinition();
        } else if(type === ASTNodeType_StructDefinition) {
            return this.popStructDefinition();
        } else if(type === ASTNodeType_Error) {
            return this.popError();
        } else if(type === ASTNodeType_Event) {
            return this.popEvent();
        } else if(type === ASTNodeType_Typedef) {
            return this.popTypedef();
        } else if(type === ASTNodeType_ConstVariable) {
            return this.popConstVariable();
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
    constructor() { 
        this.obs = new PerformanceObserver(list => {
            const entry = list.getEntries()[0];
            console.log(entry);
        });

        /// this.obs.observe({ entryTypes: ['function'], buffered: true });
        this.obs.observe({ entryTypes: ['gc'], buffered: true });
    }

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

        this.obs.disconnect();

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
