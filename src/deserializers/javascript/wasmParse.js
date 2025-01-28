const Deserializer = require('./Deserializer');
const { wasmBase64 } = require('./inlineBinary');

let loaded = false;
let instance = null;

function decodeBase64(base64) {
  if (typeof Buffer !== 'undefined') {
    return Buffer.from(base64, 'base64');
  } else {
    const binStr = atob(base64);
    const bytes = new Uint8Array(binStr.length);
    for (let i = 0; i < binStr.length; i++) {
      bytes[i] = binStr.charCodeAt(i);
    }
    return bytes;
  }
}

function loadParser() {
    const buffer = decodeBase64(wasmBase64)
    const mod = new WebAssembly.Module(buffer);
    instance = new WebAssembly.Instance(mod, {
        env: makeEnv({})
    });

    loaded = true
}

function parse(input, options) {
    if(loaded === false) {
        loadParser()
    }

    instance.exports.resetBumpPointer();

    const jsArray = new TextEncoder().encode(input);

    const cArrayPointer = instance.exports.malloc(jsArray.length);
    let memoryBuffer = instance.exports.memory.buffer;
    const cArray = new Uint8Array(memoryBuffer, cArrayPointer, jsArray.length);
    cArray.set(jsArray);

    const resultPointer = instance.exports.entryPointBinaryInterface(cArrayPointer, jsArray.length);
    memoryBuffer = instance.exports.memory.buffer;
    return parseBinary(input, memoryBuffer, resultPointer, options);
}

function parseBinary(inputString, memoryBuffer, pointer, options) {
    const memory = new Uint32Array(memoryBuffer);
    const dataPointer = memory[pointer / 4];
    const dataLength = memory[(pointer / 4) + 1];
    const data = new Uint8Array(memoryBuffer, dataPointer, dataLength);
    const dataView = new DataView(data.buffer, data.byteOffset, data.byteLength);
    const deserializer = new Deserializer(inputString, dataView, options);

    return deserializer.popSourceUnit();
}

function javascriptPrintStringPtr(pointer) {
    const memoryBuffer = instance.exports.memory.buffer;
    const string = structStringByPointer(memoryBuffer, pointer);
    console.log(string);
}

function javascriptThrowErrorStringPtr(pointer) {
    const memoryBuffer = instance.exports.memory.buffer;
    const string = structStringByPointer(memoryBuffer, pointer);
    throw new Error(string);
}

function javascriptPrintNumber(number) {
    console.log(number);
}

function structStringByPointer(mem_buffer, ptr) {
    const mem = new Uint32Array(mem_buffer);
    const string_pointer = mem[ptr / 4];
    const string_length = mem[(ptr / 4) + 1];
    const bytes = new Uint8Array(mem_buffer, string_pointer, string_length);
    return new TextDecoder().decode(bytes);
}

function makeEnv(env) {
    return new Proxy(env, {
        get(target, prop, receiver) {
            if(prop === "javascriptPrintStringPtr") {
                return javascriptPrintStringPtr;
            } else if(prop === "javascriptThrowErrorStringPtr") {
                return javascriptThrowErrorStringPtr;
            } else if(prop === "javascriptPrintNumber") {
                return javascriptPrintNumber;
            }
            return (...args) => {
                throw new Error(`NOT IMPLEMENTED: ${prop} ${args}`);
            }
        }
    });
}

module.exports = { 
    parse,
}
