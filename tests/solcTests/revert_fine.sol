contract C {
    struct S { bool f; }
    S s;
    function f() internal pure returns (S storage) {
        revert Error();
    }
    function g(bool flag) internal view returns (S storage c) {
        if (flag) c = s;
        else revert Error();
    }
}
// ----
