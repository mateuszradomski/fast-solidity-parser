const fs = require('fs');
const path = require('path');

const SpallProfiler = require('./spall');
const profiler = new SpallProfiler();

class WasmParser {
    constructor() { }

    async parseJSONBackend(input) {
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

        profiler.trace_begin("WASM");
        const string_struct_pointer = instance.exports.entry_point(cArrayPointer, jsArray.length);
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

    async parseBinaryBackend(input) {
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

        profiler.trace_begin("WASM");
        const resultPointer = instance.exports.entry_point(cArrayPointer, jsArray.length);
        profiler.trace_end();

        memoryBuffer = instance.exports.memory.buffer;

        profiler.trace_begin("parseBinary");
        const object = parseBinary(memoryBuffer, resultPointer);
        profiler.trace_end();

        const spallBytes = profiler.serialize();
        fs.writeFileSync("data.spall", spallBytes);

        return object;
    }

    parseBinary(memoryBuffer, resultPointer) {
        return {}
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

module.exports = WasmParser;
