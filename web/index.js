const fs = require('fs');
const WasmParser = require('./wasmParse');

async function runJSONInterface(input) {
    const parser = new WasmParser(input);

    let elapsed = -performance.now()
    await parser.parseJSONInterface(input)
    elapsed += performance.now();
    const lines = input.split('\n').length;
    const linesPerSeconds = lines / (elapsed / 1000);
    console.error("Lines per second:", formatSI(linesPerSeconds, "LPS"));
}

async function runBinaryInterface(input) {
    const parser = new WasmParser(input);

    let elapsed = -performance.now()
    await parser.parseBinaryInterface(input)
    elapsed += performance.now();
    const lines = input.split('\n').length;
    const linesPerSeconds = lines / (elapsed / 1000);
    console.error("Lines per second:", formatSI(linesPerSeconds, "LPS"));
}

async function main() {
    const input = fs.readFileSync("web/sources/parserbuilding.sol", 'utf-8')

    await runJSONInterface(input)
    await runBinaryInterface(input)
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
