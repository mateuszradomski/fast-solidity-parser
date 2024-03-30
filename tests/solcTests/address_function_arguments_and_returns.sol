contract C {
    function f(address) public pure returns (address) {}
    function g(address payable hackBecauseImRight) public pure returns (address payable hackBecauseImRight) {}
}
// ----
