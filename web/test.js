const WasmParser = require("./wasmParse");
const parser = require("@solidity-parser/parser");
const fs = require("fs/promises");
const posix = require("path");

async function main() {
	const args = process.argv.slice(2);
    const kind = args.shift();

    if(kind === "all") {
        runAllTests(args);
    } else if(kind === "single") {
        runSingleTest(args);
    }
}

async function runSingleTest(args) {
    const input = await fs.readFile(args[0], "utf-8")
    const antlrASTObj = parser.parse(input);
    const antlrAST = JSON.stringify(antlrASTObj, null, 2);

    const wasmParser = new WasmParser();
    wasmParser.loadParserNode();
    const myASTObj = wasmParser.parseBinaryInterface(input);
    const myAST = JSON.stringify(myASTObj, null, 2);

    if (antlrAST === myAST) {
        console.log(`[ OK ]:`);
    } else {
        console.log(`[FAIL]:`);
    }

    await fs.writeFile('antlrAST.json', antlrAST);
    await fs.writeFile('myAST.json', myAST);
}

async function runAllTests(args) {
	const filesToFilterOut = [
		"free_constructor.sol",
		"free_fallback.sol",
		"free_receive.sol",
        "max_depth_reached_4.sol", // LOL
	];
	const allTestFiles = await readAllTestFilesAtPath(args[0]);
	const testFiles = allTestFiles.filter((file) => {
		return !filesToFilterOut.includes(posix.basename(file.path));
	});

	let passed = 0;
    let failed = 0;
    let crash = 0;
	for (const test of testFiles) {
		try {
            let antlrAST = "";
            if(true) {
                const antlrASTObj = parser.parse(test.content);
                antlrAST = JSON.stringify(antlrASTObj, null, 2);
            } 

			const wasmParser = new WasmParser();
			wasmParser.loadParserNode();
			const myASTObj = wasmParser.parseBinaryInterface(test.content);
			const myAST = JSON.stringify(myASTObj, null, 2);

			if (antlrAST === myAST) {
				// console.log(`[STAT]: ${passed}/${testFiles.length} tests passed`);
				passed += 1;
			} else {
                failed += 1;
				console.log(`[FAIL]: ${test.path}`);
			}
		} catch (_) {
            crash += 1;
        }
	}

	console.log(`[STAT]: ${passed}/${testFiles.length} tests passed`);
	console.log(`[STAT]: ${failed}/${testFiles.length} tests failed`);
	console.log(`[STAT]: ${crash}/${testFiles.length} tests crashed`);
}

async function readAllTestFilesAtPath(path) {
	const filePaths = await listFilesRecursively(path);
	const files = await Promise.all(
		filePaths.map(async (filePath) => {
			const file = await fs.readFile(filePath, "utf-8");
			return {
				path: filePath,
				content: file,
			};
		}),
	);
	return files;
}

async function listFilesRecursively(path) {
	const entries = await fs.readdir(path, { withFileTypes: true });
	const files = await Promise.all(
		entries.map((entry) => {
			const resolved = posix.resolve(path, entry.name);
			return entry.isDirectory() ? listFilesRecursively(resolved) : resolved;
		}),
	);

	return files.flat();
}

main();
