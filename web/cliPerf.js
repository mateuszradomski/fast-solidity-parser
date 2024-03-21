const fs = require('fs');
const { parse, saveProfileToDisk } = require('./wasmParse');
const parser = require('@solidity-parser/parser')

async function runBinaryInterface(input) {
    let elapsed = -performance.now()
    parse(input)
    elapsed += performance.now();
    const lines = input.split('\n').length;
    const linesPerSeconds = lines / (elapsed / 1000);
    console.error("WASM: Lines per second:", formatSI(linesPerSeconds, "LPS"));

    saveProfileToDisk();
}

async function runAntlrParser(input) {
    let elapsed = -performance.now()
    parser.parse(input)
    elapsed += performance.now();
    const lines = input.split('\n').length;
    const linesPerSeconds = lines / (elapsed / 1000);
    console.error("ANTLR: Lines per second:", formatSI(linesPerSeconds, "LPS"));
}

async function main() {
    const input = fs.readFileSync("web/sources/parserbuilding.sol", 'utf-8')

    for(let i = 0; i < 100; i++) {
        await runBinaryInterface(input)
    }
    await runAntlrParser(input)
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
