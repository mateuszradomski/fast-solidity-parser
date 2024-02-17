const fs = require('fs');
const WasmParser = require('./wasmParse');

async function main() {
    const input = fs.readFileSync("web/sources/integrationBig2.sol", 'utf-8')
    const parser = new WasmParser(input);

    let elapsed = -performance.now()
    await parser.parse(input)
    elapsed += performance.now();
    const lines = input.split('\n').length;
    const linesPerSeconds = lines / (elapsed / 1000);
    console.error("Lines per second:", formatSI(linesPerSeconds, "LPS"));
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
