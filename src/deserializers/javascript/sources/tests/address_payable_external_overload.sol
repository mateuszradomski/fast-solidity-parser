contract C {
    function f(address) external pure {}
    function f(address payable hackBecauseImRight) external pure {}

}
// ----
// TypeError 9914: (58-102): Function overload clash during conversion to external types for arguments.
