const Deserializer = require('./Deserializer');
const SpallProfiler = require('./spall');
const profiler = new SpallProfiler();
const { myArray } = require('./inlineBinary');

let loaded = false;
let instance = null;

function loadParserInline() {
    profiler.trace_begin("Loading the parser inline");

    profiler.trace_begin("Creating the buffer");
    const buffer = Buffer.from(myArray)
    profiler.trace_end()

    loadWasmModule(buffer)
    profiler.trace_end()
}

function loadParserNode() {
    const fs = require('fs');
    const path = require('path');
    profiler.trace_begin("Loading the module");

    profiler.trace_begin("Read from disk");
    const wasmPath = path.join(__dirname, "./parser.wasm");
    const wasmBuffer = fs.readFileSync(wasmPath);
    profiler.trace_end();

    loadWasmModule(wasmBuffer)

    profiler.trace_end();
}

async function loadParserWeb() {
    const response = await fetch('./parser.wasm');
    const wasmBuffer = await response.arrayBuffer();
    loadWasmModule(wasmBuffer);
}

function loadWasmModule(wasmBuffer) {
    profiler.trace_begin("Make module");
    const mod = new WebAssembly.Module(wasmBuffer);
    profiler.trace_end();
    profiler.trace_begin("Make instance");
    instance = new WebAssembly.Instance(mod, {
        env: makeEnv({})
    });
    profiler.trace_end();

    loaded = true
}

function saveProfileToDisk() {
    const fs = require('fs');
    const spallBytes = profiler.serialize();
    fs.writeFileSync("data.spall", spallBytes);
}

function parse(input, options) {
    if(loaded === false) {
        loadParserInline()
    }

    instance.exports.resetBumpPointer();

    profiler.trace_begin("Encoding")
    const jsArray = new TextEncoder().encode(input);
    profiler.trace_end();

    profiler.trace_begin("Copying");
    const cArrayPointer = instance.exports.malloc(jsArray.length);
    let memoryBuffer = instance.exports.memory.buffer;
    cArray = new Uint8Array(memoryBuffer, cArrayPointer, jsArray.length);
    cArray.set(jsArray);
    profiler.trace_end();

    profiler.trace_begin("WASM Binary Interface");
    const resultPointer = instance.exports.entryPointBinaryInterface(cArrayPointer, jsArray.length);
    profiler.trace_end();

    memoryBuffer = instance.exports.memory.buffer;

    profiler.trace_begin("parseBinary");
    const object = parseBinary(input, memoryBuffer, resultPointer, options);
    profiler.trace_end();

    return object;
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
    const json_string = struct_string_by_pointer(memoryBuffer, pointer);
    console.log(json_string);
}

function javascriptPrintNumber(number) {
    console.log(number);
}

function traceBegin(number) {
    profiler.trace_begin(`${number}`);
}

function traceEnd() {
    profiler.trace_end();
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
            if(prop === "traceBegin") {
                return traceBegin;
            } else if(prop === "traceEnd") {
                return traceEnd;
            } else if(prop === "javascriptPrintStringPtr") {
                return javascriptPrintStringPtr;
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
    saveProfileToDisk
}
