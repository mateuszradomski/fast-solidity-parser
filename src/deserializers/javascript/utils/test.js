const { parse } = require("../wasmParse");
const parser = require("@solidity-parser/parser");
const { readFileSync } = require("fs");
const fs = require("fs/promises");
const posix = require("path");

async function main() {
	const args = process.argv.slice(2);
	const kind = args.shift();

	if (kind === "all") {
		runAllTests(args);
	} else if (kind === "list") {
		runTestsFromList(args);
	} else if (kind === "single") {
		runSingleTest(args);
	}
}

// NOTE(radomski): The ANTLR generated parser has a problem with raw reverts
// without any errors. It parsers them as raw functions for some reason and not
// as a revert statement. This parser processes it corretly so we need to have
// a function that will find all the revert calls and replace them with an
// imagininary error. Because a revert can also happen in an assembly block we
// need to skip that. This is why we have an additional layer of complexity
// here.
function modifyReverts(code) {
	let modifiedCode = "";
	let index = 0;

	while (index < code.length) {
		if (code.substring(index).startsWith("assembly {")) {
			const assemblyBlockEnd = findMatchingBracketEnd(
				code,
				index + "assembly {".length - 1,
			);
			// Append the whole assembly block without modification
			modifiedCode += code.substring(index, assemblyBlockEnd + 1);
			index = assemblyBlockEnd + 1;
			continue;
		}

		if (code.substring(index).startsWith(" revert(")) {
			const revertArgsStart = index + " revert(".length;
			const revertArgsEnd = findMatchingBracketEnd(code, revertArgsStart - 1);
			const revertArgs = code.substring(revertArgsStart, revertArgsEnd);

			modifiedCode += `revert MyError(${revertArgs})`;
			index = revertArgsEnd + 1;
			continue;
		}

		modifiedCode += code[index];
		index++;
	}

	return modifiedCode;
}

function findMatchingBracketEnd(code, startIndex) {
	let stack = [code[startIndex]];
	let index = startIndex + 1;

	while (stack.length > 0 && index < code.length) {
		if (code[index] === "{" || code[index] === "(") {
			stack.push(code[index]);
		} else if (
			(code[index] === "}" && stack[stack.length - 1] === "{") ||
			(code[index] === ")" && stack[stack.length - 1] === "(")
		) {
			stack.pop();
		}
		index++;
	}

	return index - 1;
}

async function runSingleTest(args) {
	const enableRange = true;
	const input = modifyReverts(await fs.readFile(args[0], "utf-8"));

	try {
		const myASTObj = parse(input, { range: enableRange });
		const myAST = JSON.stringify(myASTObj, null, 2);

		const antlrASTObj = parser.parse(input, { range: enableRange });
		const antlrAST = JSON.stringify(antlrASTObj, null, 2);

		if (antlrAST === myAST) {
			console.log(`[ OK ]:`);
		} else {
			console.log(`[FAIL]:`);
		}

		await fs.writeFile("antlrAST.json", antlrAST);
		await fs.writeFile("myAST.json", myAST);
	} catch (e) {
		console.log(`[FAUL]:`);
	}
}

async function runTestsFromList(args) {
	const listPath = args[0];
	const list = readFileSync(listPath, "utf-8").split("\n");

	let passed = 0;
	let failed = 0;
	let crash = 0;
	let input = "";
	for (const filePath of list) {
		try {
			input = modifyReverts(await fs.readFile(filePath, "utf-8"));
			// NOTE(radomski): The reason for this is the same as the reason
			// given in the note attached to the modifyReverts function. The
			// ANTLR parser does not recognize the "address payable" type in
			// certain places. It thinks it's a variable of name "payable" with
			// the type of "address".
			input = input.replace(/address payable\)/g, "address payable asdf)");

			const antlrASTObj = parser.parse(input, { range: true });
			const antlrAST = JSON.stringify(antlrASTObj, null, 2);

			const myASTObj = parse(input, { range: true });
			const myAST = JSON.stringify(myASTObj, null, 2);

			if (antlrAST === myAST) {
				passed += 1;
				console.log(`[ OK ][${passed}/${failed}/${crash}]`);
			} else {
				failed += 1;
				console.log(`[FAIL][${passed}/${failed}/${crash}]: ${filePath}`);
			}
		} catch (_) {
			crash += 1;
			console.log(`[FAUL][${passed}/${failed}/${crash}]: ${filePath}`);
		}
	}
}

async function runAllTests(args) {
	const filesToFilterOut = [
		// NOTE(radomski): This test takes so long on the ANTLR generated
		// parser that it's really slowing down the test runs
		"max_depth_reached_4.sol",
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
			const antlrASTObj = parser.parse(test.content);
			const antlrAST = JSON.stringify(antlrASTObj, null, 2);
			const myASTObj = parse(test.content);
			const myAST = JSON.stringify(myASTObj, null, 2);

			if (antlrAST === myAST) {
				passed += 1;
			} else {
				failed += 1;
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
