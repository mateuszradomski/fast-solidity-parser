error revert Error();
contract C {
    function f() public pure {
        revert revert Error();
    }
}
// ----
// Warning 2319: (0-15): This declaration shadows a builtin symbol.
