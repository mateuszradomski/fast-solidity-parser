const fs = require('fs');
const { parse, saveProfileToDisk } = require('./wasmParse');
const parser = require('@solidity-parser/parser')

async function runBinaryInterface(input) {
    let elapsed = -performance.now()
    parse(input)
    elapsed += performance.now();

    saveProfileToDisk();
    return elapsed;
}

async function runAntlrParser(input) {
    let elapsed = -performance.now()
    parser.parse(input)
    elapsed += performance.now();
    return elapsed;
}

async function main() {
    const input = fs.readFileSync("tests/parserbuilding.sol", 'utf-8')

    const wasmTimes = []
    for(let i = 0; i < 15; i++) {
        wasmTimes.push(await runBinaryInterface(input))
    }

    const averageWasmTime = wasmTimes.reduce((a, b) => a + b, 0) / wasmTimes.length;
    console.error("WASM: Bytes per second:", formatSI(input.length / (averageWasmTime / 1000), "BPS"))

    const antlrTimes = []
    for(let i = 0; i < 15; i++) {
        antlrTimes.push(await runAntlrParser(input))
    }

    const averageAntlrTime = antlrTimes.reduce((a, b) => a + b, 0) / antlrTimes.length;
    console.error("ANTLR: Bytes per second:", formatSI(input.length / (averageAntlrTime / 1000), "BPS"))

    const speedup = averageAntlrTime / averageWasmTime
    console.error("Speedup:", speedup.toFixed(2))
}

main()

function formatSI(value, unit) {
  if (value === 0) {
    return `0 ${unit}`
  }

  const orderPrefix = [' ', ' K', ' M', ' G', ' T', ' P']
  const order = Math.floor(Math.log2(value) / Math.log2(1000))
  const newValue = value / Math.pow(1000, order)

  const prefix = orderPrefix[order]
  return `${newValue.toFixed(2)}${prefix}${unit}`
}
