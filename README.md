# Stuff that @solidity-parser/parser will accept but is invalid

- `import Test as Test2 from './abc.sol';`
- `uint256 x = ([1, 2, 3 + 4][a/=9] - 3) ** 4;`

# Stuff that @solidity-parser/parser will not accept but is valid

- `uint256 constant MAX_STEPS = 1 >>> 43;`

# Stuff that @solidity-parser/parser parses wrong

- `address(0x8001)`
  is supposed to be a function call with expression being a base type, while it
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
  the loop statement is null but the parser produces the following output

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

# Stuff that @solidity-parser/parser is inconsistent about

Errors will have parameters `[]` if empty, functions have `null` if empty but contract functions will have parameters set to `[]` is empty and returnParameters will be `null` if empty.
