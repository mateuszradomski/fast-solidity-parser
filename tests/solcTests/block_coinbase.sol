contract C {
    function f() public returns (address payable hackBecauseImRight) {
        return block.coinbase;
    }
}
// ----
// f() -> 0x7878787878787878787878787878787878787878
// f() -> 0x7878787878787878787878787878787878787878
// f() -> 0x7878787878787878787878787878787878787878
