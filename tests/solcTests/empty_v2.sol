pragma abicoder               v2;
contract C {
	function f() public {
		revert Error("");
	}
	function g(string calldata msg) public {
		revert Error(msg);
	}
}
// ====
// EVMVersion: >=byzantium
// revertStrings: debug
// ----
// f() -> FAILURE, hex"08c379a0", 0x20, 0
// g(string): "" -> FAILURE, hex"08c379a0", 0x20, 0
// g(string): 0x20, 0, "" -> FAILURE, hex"08c379a0", 0x20, 0
// g(string): 0x20, 0 -> FAILURE, hex"08c379a0", 0x20, 0
