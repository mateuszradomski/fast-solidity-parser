const Deserializer = require('./Deserializer');

class WasmParser {
    constructor() {}

    async loadParser() {
        const response = await fetch('./parser.wasm');
        const wasmArrayBuffer = await response.arrayBuffer();
        const { instance } = await WebAssembly.instantiate(wasmArrayBuffer, {
            env: makeEnv(this)
        });
        this.instance = instance;
    }

    parseBinaryInterface(input) {
        const jsArray = new TextEncoder().encode(input);

        const cArrayPointer = this.instance.exports.malloc(jsArray.length);
        let memoryBuffer = this.instance.exports.memory.buffer;
        this.cArray = new Uint8Array(memoryBuffer, cArrayPointer, jsArray.length);
        this.cArray.set(jsArray);

        const resultPointer = this.instance.exports.entryPointBinaryInterface(cArrayPointer, jsArray.length);

        memoryBuffer = this.instance.exports.memory.buffer;

        const object = this.parseBinary(input, memoryBuffer, resultPointer);

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

    traceBegin(number) { }

    traceEnd() { }
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

async function loadWasmModule(url) {
    try {
        // Use the Fetch API to load the Wasm file

        // Compile and instantiate the Wasm module
        // Note: Adjust the import object based on your Wasm module's requirements
        const importObject = {
            env: {
                // Define any imports your module requires here
                // For example, memory: new WebAssembly.Memory({initial: 256, maximum: 512}),
            },
        };

        // The Wasm module is now instantiated, and you can start using it
        // For example, if your module exports a function named 'parse', you can call it as follows:
        // instance.exports.parse();
    } catch (error) {
        console.error('Error loading Wasm module:', error);
    }
}

module.exports = WasmParser;
