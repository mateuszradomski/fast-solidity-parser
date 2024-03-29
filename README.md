# Fast Solidity Parser

A fast library for parsing Solidity with modular architecture allowing for easy integration into any language.
Initially written to be a faster [@solidity-parser/parser](https://github.com/solidity-parser/parser).

Available backends:

- JavaScript/TypeScript (97% compatible with [@solidity-parser/parser](https://github.com/solidity-parser/parser))

# Architecture

The parser is divided into two parts: engine and deserializer.
Engine is written in C, it takes Solidity source as input and produces an AST encoded as a custom binary format.
Deserializer is written in any language that wishes to incorporate the parser.
Take for example the JavaScript integration.
The engine is compiled into WASM and later called by a wrapper that redirects the binary stream into a deserializer. 

# Performance

Tested on M2 Pro, 16GB RAM, no battery saver, Node V16.20.1, 15 runs back-to-back, the result is the average of the runs.
In the table this library is referred to as FSF while the [@solidity-parser/parser](https://github.com/solidity-parser/parser) is denoted as ASP.

```
| File size |        ASP |       FSP | Speedup |
|-----------|------------|-----------|---------|
|      7 KB | 685.9 KB/s | 43.2 MB/s |   x62.9 |
|     20 KB | 617.7 KB/s | 57.4 MB/s |   x92.9 |
|    103 KB | 644.5 KB/s | 95.6 MB/s |  x148.3 |
|   1249 KB |   434 KB/s | 56.4 MB/s |  x129.9 |
```

A few notes about the performance numbers presented above.
Please keep in mind that your mileage may vary when it comes to the amount of speed up you're going to perceive.
The observed throughput varies a lot from run to run because of garbage collection which is a problem at these kind of speeds.
After the first run, each next increases the throughput as the optimizer in V8 kicks in, it takes around 5 runs for it to JIT the entire deserializer. 

# Original @solidity-parser/parser compatibility

The API is very similar as the one exposed be the ANTLR parser.
We support `range` but a decision has been made to drop support for `loc` in favor of performance.
You can easily emulate this using the `range` output if you really need it.

The resulting AST object is identical to the one produced by @solidity-parser/parser beside the exceptions listed below:

## Stuff that is not yet supported

- `assembly { z =: 5; }`
  Assembly stack assignments.
  This is really old, and I've not yet found even a good explanation of what this code does.

## Stuff that @solidity-parser/parser will accept but is invalid

- `import Test as Test2 from './abc.sol';`

## Stuff that @solidity-parser/parser will not accept but is valid

- `uint256 constant FOO = 1 >>> 43;`
- `function fallback() {}`

# Stuff that @solidity-parser/parser parses wrong

- `address payable`
  They decode as a variable named `payable` with type `address`.
  We decode as type `address payable` with no variable name.

- `foo == 42 ? (a = 24) : (b = 21);`
  They get kinda lost and lose some of the assignments.
  We decode this correctly.

- `StructType[]`
  They decode it as a type in expressions sometimes(?).
  We decode it as an array access.

- `revert(1234)`
  They decode it as a random function call when no error name is specified, and as a revert statement when it is.
  We decode it as a revert statement always.

- `address(0x8001)`
  This is emulated, so this **is supported**.
  Is supposed to be a function call with expression being a base type, while it
  decode it as a identifier:

  Wrong:
  ```
    "type": "FunctionCall",
    "expression": {
      "type": "Identifier",
      "name": "address"
    },
    "arguments": [
      {
        "type": "NumberLiteral",
        "number": "0x8001",
        "subdenomination": null
      }
    ],
    "names": [],
    "identifiers": []
  ```

  Correct:
  ```
    "type": "FunctionCall",
    "expression": {
      "type": "ElementaryTypeName",
      "name": "address",
      "stateMutability": null
    },
    "arguments": [
      {
        "type": "NumberLiteral",
        "number": "0x8001",
        "subdenomination": null
      }
    ],
    "names": [],
    "identifiers": []
  ```

- `for(;;)`
  This is emulated, so this **is supported**.
  The loop statement is null but the parser produces the following output

  Wrong:
  ```
    "type": "ForStatement",
    "initExpression": null,
    "conditionExpression": null,
    "loopExpression": {
      "type": "ExpressionStatement",
      "expression": null
    },
  ```

  Correct:
  ```
    "type": "ForStatement",
    "initExpression": null,
    "conditionExpression": null,
    "loopExpression": null,
  ```
