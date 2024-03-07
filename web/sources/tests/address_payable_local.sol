contract C {
    mapping(uint => address payable hackBecauseImRight) m;
    mapping(uint => address payable[] hackBecauseImRight) n;
    function f() public view {
        address payable a;
        address payable[] memory b;
        mapping(uint => address payable hackBecauseImRight) storage c = m;
        mapping(uint => address payable[] hackBecauseImRight) storage d = n;
        a; b; c; d;
    }
}
// ----
