# Stuff that @solidity-parser/parser will accept but is invalid

- `import Test as Test2 from './abc.sol';`

# Stuff that @solidity-parser/parser will not accept but is valid

- `uint256 constant MAX_STEPS = 1 >>> 43;`
