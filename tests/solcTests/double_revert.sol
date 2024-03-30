contract C {
    function f() public pure {
        revert Error();
        revert Error();
    }
}
// ----
// Warning 5740: (70-78): Unreachable code.
