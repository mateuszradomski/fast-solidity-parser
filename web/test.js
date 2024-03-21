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
        for(const filePath of list) {
            try {
                let input = await fs.readFile(filePath, "utf-8")

                if(!input.includes("assembly")) {
                    input = input.replace(/revert\(/g, 'revert MyTestingError(');
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
                    if(!(input.includes("assembly") && input.includes("revert"))) {
                        console.log(`[FAIL][${passed}/${failed}/${crash}]: ${filePath}`);
                    }
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

async function runSingleTest(args) {
    const enableRange = true
    let input = await fs.readFile(args[0], "utf-8")

    if(!input.includes("assembly")) {
    input = input.replace(/revert\(/g, 'revert MyTestingError(');
    }

    const antlrASTObj = parser.parse(input, { range: enableRange });
    const antlrAST = JSON.stringify(antlrASTObj, null, 2);

    const myASTObj = parse(input, { range: enableRange });
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
    let goPath = ""
	for (const test of testFiles) {
		try {
            let antlrAST = "";
            if(true) {
                const antlrASTObj = parser.parse(test.content);
                antlrAST = JSON.stringify(antlrASTObj, null, 2);
            } 

            let myAST = "";
            if(true) {
                goPath = test.path;
                const myASTObj = parse(test.content);
                myAST = JSON.stringify(myASTObj, null, 2);
            }

			if (antlrAST === myAST) {
				// console.log(`[STAT]: ${passed}/${testFiles.length} tests passed`);
				passed += 1;
			} else {
                failed += 1;
                console.log(`[FAIL][${passed}/${failed}/${crash}]: ${test.path}`);
			}
		} catch (_) {
            if(goPath === test.path) {
                // console.log(`[FAUL][${passed}/${failed}/${crash}]: ${test.path}`);
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
