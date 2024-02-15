const fs = require('fs');
const path = require('path');

async function run() {
    const wasmPath = path.join(__dirname, "./parser.wasm");
    const wasmBuffer = fs.readFileSync(wasmPath);
    const { instance } = await WebAssembly.instantiate(wasmBuffer);

    const memory_buffer = instance.exports.memory.buffer;

    const inputString = "Hello, World!";
    const jsArray = new TextEncoder().encode(inputString); // Convert string to Uint8Array

    const cArrayPointer = instance.exports.malloc(jsArray.length);
    const cArray = new Uint8Array(
      memory_buffer,
      cArrayPointer,
      jsArray.length
    );
    cArray.set(jsArray);

    const string_struct_pointer = instance.exports.entry_point(cArrayPointer, jsArray.length);
    const json_string = struct_string_by_pointer(memory_buffer, string_struct_pointer);
    console.log("JSON string:", json_string);
}

run().catch(console.error);

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

function struct_string_by_pointer(mem_buffer, ptr) {
    const mem = new Uint32Array(mem_buffer);
    const string_pointer = mem[ptr / 4];
    const string_length = mem[(ptr / 4) + 1];
    const bytes = new Uint8Array(mem_buffer, string_pointer, string_length);
    return new TextDecoder().decode(bytes);
}
