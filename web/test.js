const WasmParser = require('./wasmParse')
const parser = require('@solidity-parser/parser')
const fs = require('fs')
const Diff = require('diff')

async function main() {
    const args = process.argv.slice(2)
    const input = fs.readFileSync(args[0], 'utf-8')

    const antlrASTObj = parser.parse(input)
    const antlrAST = JSON.stringify(antlrASTObj, null, 2)

    const wasmParser = new WasmParser();
    // const myASTObj = await wasmParser.parseJSONInterface(input)
    const myASTObj = await wasmParser.parseBinaryInterface(input)
    const myAST = JSON.stringify(myASTObj, null, 2)

    if(antlrAST !== myAST) {
        console.log("ASTs are different")
    } else {
        console.log("ASTs are the same")
    }

    fs.writeFileSync('antlrAST.json', antlrAST)
    fs.writeFileSync('myAST.json', myAST)
}

main()
