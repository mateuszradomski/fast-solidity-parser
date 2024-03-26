const {parse} = require("./wasmParse");
const parser = require("@solidity-parser/parser");
const { readFileSync } = require("fs");
const fs = require("fs/promises");
const posix = require("path");

async function main() {
	const args = process.argv.slice(2);
    const kind = args.shift();

    if(kind === "all") {
        runAllTests(args);
    } else if(kind === "list") {
        const listPath = args[0];
        const list = readFileSync(listPath, "utf-8").split("\n");

        let passed = 0;
        let failed = 0;
        let crash = 0;
        let input = "";
        for(const filePath of list) {
            try {
                input = await fs.readFile(filePath, "utf-8")

                if(!input.includes("assembly")) {
                    input = input.replace(/revert\(/g, 'revert MyTestingError(');
                } else {
                    input = modifyReverts(input);
                }
                input = input.replace(/address payable\)/g, 'address payable asdf)');

                const antlrASTObj = parser.parse(input, { range: true });
                const antlrAST = JSON.stringify(antlrASTObj, null, 2);

                const myASTObj = parse(input, {range: true});
                const myAST = JSON.stringify(myASTObj, null, 2);

                if (antlrAST === myAST) {
                    passed += 1;
                    // console.log(`[ OK ][${passed}/${failed}/${crash}]`);
                } else {
                    failed += 1;
                    console.log(`[FAIL][${passed}/${failed}/${crash}]: ${filePath}`);
                }
            } catch (_) {
                crash += 1;
                console.log(`[FAUL][${passed}/${failed}/${crash}]: ${filePath}`);
            }
        }
    } else if(kind === "single") {
        runSingleTest(args);
    }
}

function modifyReverts(code) {
    let modifiedCode = '';
    let index = 0;
    let inAssembly = false;

    while (index < code.length) {
        // Check for the start of an assembly block
        if (code.substring(index).startsWith('assembly {')) {
            const assemblyBlockEnd = findMatchingBracketEnd(code, index + 'assembly {'.length - 1);
            // Append the whole assembly block without modification
            modifiedCode += code.substring(index, assemblyBlockEnd + 1);
            index = assemblyBlockEnd + 1;
            continue;
        }

        // Check for revert( outside of assembly
        if (code.substring(index).startsWith(' revert(')) {
            const revertArgsStart = index + ' revert('.length;
            const revertArgsEnd = findMatchingBracketEnd(code, revertArgsStart - 1);
            const revertArgs = code.substring(revertArgsStart, revertArgsEnd);

            modifiedCode += `revert MyError(${revertArgs})`;
            index = revertArgsEnd + 1;
            continue;
        }

        // Append current character and move on
        modifiedCode += code[index];
        index++;
    }

    return modifiedCode;
}

// Helper function to find the index of the matching closing bracket for any block or parenthesis
function findMatchingBracketEnd(code, startIndex) {
    let stack = [code[startIndex]];
    let index = startIndex + 1;

    while (stack.length > 0 && index < code.length) {
        if (code[index] === '{' || code[index] === '(') {
            stack.push(code[index]);
        } else if ((code[index] === '}' && stack[stack.length - 1] === '{') || 
                   (code[index] === ')' && stack[stack.length - 1] === '(')) {
            stack.pop();
        }
        index++;
    }

    // Return the index of the matching closing bracket/parenthesis, or the end of the string if not found
    return index - 1;
}

async function runSingleTest(args) {
    const enableRange = true
    let input = await fs.readFile(args[0], "utf-8")

    input = modifyReverts(input);

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

    await fs.writeFile('antlrAST.json', antlrAST);
    await fs.writeFile('myAST.json', myAST);
    } catch (e) {
    console.log(`[FAUL]:`);
    }
}

async function runAllTests(args) {
	const filesToFilterOut = [
        "max_depth_reached_4.sol", // LOL
	];

	const allTestFiles = await readAllTestFilesAtPath(args[0]);
	const testFiles = allTestFiles.filter((file) => {
		return !filesToFilterOut.includes(posix.basename(file.path));
	});
    // const overrideFilePaths = [
    //     "/Users/m/dev/parser/web/sources/tests/invalid_expressions_with_calloptions2.sol",
    //     "/Users/m/dev/parser/web/sources/tests/invalid_expressions_with_calloptions3.sol",
    // ]
    // const testFiles = await Promise.all(overrideFilePaths.map(async (filePath) => {
    //     const file = await fs.readFile(filePath, "utf-8");
    //     return {
    //         path: filePath,
    //         content: file,
    //     };
    // }));

	let passed = 0;
    let failed = 0;
    let crash = 0;
    let goPath = ""
	for (const test of testFiles) {
		try {
            let antlrAST = "";
            if(false) {
                const antlrASTObj = parser.parse(test.content);
                antlrAST = JSON.stringify(antlrASTObj, null, 2);
            } 

            let myAST = "";
            if(true) {
                goPath = test.path;
                // console.log(`[ GO ][${passed}/${failed}/${crash}]: ${test.path}`);
                const myASTObj = parse(test.content);
                myAST = JSON.stringify(myASTObj, null, 2);
            }

			if (antlrAST === myAST) {
				// console.log(`[STAT]: ${passed}/${testFiles.length} tests passed`);
				passed += 1;
			} else {
                failed += 1;
                // console.log(`[FAIL][${passed}/${failed}/${crash}]: ${test.path}`);
			}
		} catch (_) {
            if(goPath === test.path) {
                console.log(`[FAUL][${passed}/${failed}/${crash}]: ${test.path}`);
            }
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
