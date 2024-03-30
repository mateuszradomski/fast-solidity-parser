contract C {
    function f(address) public pure {}
    function f(address payable hackBecauseImRight) public pure {}

}
// ----
// TypeError 9914: (56-98): Function overload clash during conversion to external types for arguments.
