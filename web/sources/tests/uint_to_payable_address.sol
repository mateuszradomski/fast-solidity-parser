contract C {
    function f(uint x) public pure returns (address payable hackBecauseImRight) {
        return payable(address(uint160(x)));
    }
}
// ----
