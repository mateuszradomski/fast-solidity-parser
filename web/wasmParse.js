const fs = require('fs');
const path = require('path');

class WasmParser {
    constructor() { }

    async parse(input) {
        const wasmPath = path.join(__dirname, "./parser.wasm");
        const wasmBuffer = fs.readFileSync(wasmPath);
        const { instance } = await WebAssembly.instantiate(wasmBuffer, {
            env: makeEnv(this)
        });
        this.instance = instance;

        const jsArray = new TextEncoder().encode(input);

        const cArrayPointer = instance.exports.malloc(jsArray.length);
        let memory_buffer = instance.exports.memory.buffer;
        this.cArray = new Uint8Array(memory_buffer, cArrayPointer, jsArray.length);
        this.cArray.set(jsArray);

        const string_struct_pointer = instance.exports.entry_point(cArrayPointer, jsArray.length);

        memory_buffer = instance.exports.memory.buffer;
        return JSON.parse(struct_string_by_pointer(memory_buffer, string_struct_pointer));
    }

    javascriptPrintStringPtr(pointer) {
        const memory_buffer = this.instance.exports.memory.buffer;
        const json_string = struct_string_by_pointer(memory_buffer, pointer);
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
