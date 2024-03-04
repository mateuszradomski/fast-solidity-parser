const WasmParser = require('./wasmParseWeb');
const parser = require('@solidity-parser/parser')
;
const { stringify } = require('querystring');
const button = document.getElementById('runDemoButton');

async function onButtonClick() {
    button.disabled = true;

    const response = await fetch('./sources/parserbuilding.sol')
    const input = await response.text() 
    const byteCount = input.length;
    const lineCount = input.split('\n').length;

    document.getElementById('inputByteCount').textContent = byteCount.toString();
    document.getElementById('inputLineCount').textContent = lineCount.toString();

    const antlrResultSpan = document.getElementById('antlrResult');
    const wasmResultSpan = document.getElementById('wasmResult');

    let antlrElapsed = -performance.now()
    const antlrAST = await runAntlrParser(input);
    antlrElapsed += performance.now();
    let linesPerSecond = lineCount / (antlrElapsed / 1000);
    let bytesPerSecond = byteCount / (antlrElapsed / 1000);
    antlrResultSpan.textContent = `${formatSI(linesPerSecond, "L/s")}, ${formatSI(bytesPerSecond, "B/s")}`

    const parser = new WasmParser();
    await parser.loadParser();

    let wasmElapsed = -performance.now()
    const wasmAST = await runWasmParser(parser, input);
    wasmElapsed += performance.now();
    linesPerSecond = lineCount / (wasmElapsed / 1000);
    bytesPerSecond = byteCount / (wasmElapsed / 1000);
    wasmResultSpan.textContent = `${formatSI(linesPerSecond, "L/s")}, ${formatSI(bytesPerSecond, "B/s")}`

    const astMatch = JSON.stringify(wasmAST) === JSON.stringify(antlrAST)
    const matchText = astMatch ? "is the same" : "ERROR IS NOT THE SAME"
    document.getElementById('summaryResult').textContent = `wasm was ${(antlrElapsed / wasmElapsed).toFixed(2)} times faster, output ${matchText}`

    button.disabled = false;
}

button.addEventListener('click', onButtonClick);

async function runAntlrParser(input) {
    return parser.parse(input)
}

async function runWasmParser(parser, input) {
    return parser.parseBinaryInterface(input)
}

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
