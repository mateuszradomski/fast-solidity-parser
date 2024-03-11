contract C {
    struct S {
        address payable a;
        address payable[] b;
        mapping(uint => address payable hackBecauseImRight) c;
        mapping(uint => address payable[] hackBecauseImRight) d;
    }
}
// ----
