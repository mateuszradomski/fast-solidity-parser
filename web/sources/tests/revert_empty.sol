contract C {
    function f() public pure {
        revert Error();
        for(int i = 0; i < 3; i++) { f(); }
    }
}
// ----
// Warning 5740: (70-105): Unreachable code.
