const fs = require("fs");
const { parse } = require("../wasmParse");
const parser = require("@solidity-parser/parser");

function runBinaryInterface(input) {
	let elapsed = -performance.now();
	parse(input);
	elapsed += performance.now();
	return elapsed;
}

function runAntlrParser(input) {
	let elapsed = -performance.now();
	parser.parse(input);
	elapsed += performance.now();
	return elapsed;
}

const tests = [
	["8.4KB", "bench/8kb.sol"],
	["20KB", "bench/20kb.sol"],
	["103KB", "bench/103kb.sol"],
	["1249KB", "bench/1249kb.sol"],
];

function benchmark(name, input) {
	console.log(`--- ${name.padStart(8)} ---`);

	const wasmTimes = [];
	for (let i = 0; i < 15; i++) {
		wasmTimes.push(runBinaryInterface(input));
	}

	const antlrTimes = [];
	for (let i = 0; i < 15; i++) {
		antlrTimes.push(runAntlrParser(input));
	}

	const averageWasmTime = wasmTimes.reduce((a, b) => a + b, 0) / wasmTimes.length;
	const averageAntlrTime = antlrTimes.reduce((a, b) => a + b, 0) / antlrTimes.length;
	const speedup = averageAntlrTime / averageWasmTime;
	console.error("WASM:    ", formatSI(input.length / (averageWasmTime / 1000), "B/s"));
	console.error("ANTLR:   ", formatSI(input.length / (averageAntlrTime / 1000), "B/s"));
	console.error("Speedup  ", `${speedup.toFixed(2)}x`);
}

function main() {
	for (const [name, path] of tests) {
		const input = fs.readFileSync(path, "utf-8");
		benchmark(name, input);
	}
}

main();

function formatSI(value, unit) {
	if (value === 0) {
		return `0 ${unit}`;
	}

	const orderPrefix = [" ", " K", " M", " G", " T", " P"];
	const order = Math.floor(Math.log2(value) / Math.log2(1000));
	const newValue = value / Math.pow(1000, order);

	const prefix = orderPrefix[order];
	return `${newValue.toFixed(2)}${prefix}${unit}`;
}
