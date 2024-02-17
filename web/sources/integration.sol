/*
 * Pragmas
 */

pragma solidity 0.4.4;
pragma solidity ^0.4.4;
pragma solidity ~0.4.4;
pragma solidity >0.4.4;
pragma solidity >=0.4.4;
pragma solidity <0.4.4;
pragma solidity <=0.4.4;
pragma solidity =0.4.4;
pragma solidity 0.4;
pragma solidity >=0.5.0 <0.7.0;
pragma solidity ^0.6;
pragma solidity ^0.5.0 || ^0.6.0;
pragma solidity ^0.5.0 || ^0.6.0 || ^0.7.0;
pragma experimental ABIEncoderV2;

/*
 * Imports
 */

import "./abc.sol";
import "./def.sol";
import "./abc.sol" as x;
import * as y from "./abc.sol";
import {a as b, c as d, f} from "./abc.sol";
import './abc.sol' as my_abc;
import { a as my_a, b as my_b } from './abc.sol';
import * as abc from './abc.sol';

/*
 * Enums
 */

enum Locations {
    Continent,
    Empire,
    Union,
    Country,
    State,
    City,
    Council,
    Village
}

event E();

contract c {
    enum foo { }
    enum validEnum { Value1, Value2, Value3, Value4 }
}

/*
 * Top-level functions
 */

function helper(uint x) pure returns (uint) {
    return x * 2;
}

/*
 * Top-level structs
 */

struct KeyValuePair {
    string name;
    int256 value;
}

struct GlobalBaseStruct {
    KeyValuePair[] pairs;
    Locations location;
}

/*
 * Constants
 */

uint constant topLevelConstantVariable = 3;

/*
 * Custom errors
 */

error TopLevelCustomError();
error TopLevelCustomErrorWithArg(uint x);
error TopLevelCustomErrorArgWithoutName(string);

contract CustomErrors {
  error ContractCustomError();
  error ContractCustomErrorWithArg(uint x);
  error ContractCustomErrorArgWithoutName(string);

  function throwCustomError() {
    revert ContractCustomError();
  }
}

/*
 * User-defined value types
 */

type Price is uint128;
type Quantity is uint128;
type UFixed is uint256;

contract Foo {
  type Id is uint8;

  Id public id;
}

/*
 * Strings
 */

contract test {
    string a = hex"00FF0000";
    string b = hex'00AA0000';
    string b = hex'00AA_0000';
    string b = hex"";
    string a = "aaa"
    "bbb";
    string b = "aaa""bbb";
    string c = "aaa"  "bbb";

    // unicode strings
    string a = unicode"Hello 😃";
    string b = unicode'Hello 😃';

    // hex literal parts
    function foo() public {
      bytes memory c = hex'dead' hex'beef'
        hex'deadbe' hex'ef';
    }
}

/*
 * Libraries
 */

library a {}
library b {}
library c {}
library f {}

library Lib {
}

library Lib {
    function f() { }
}

library FixedMath {
    uint constant multiplier = 10**18;

    function add(UFixed a, UFixed b) internal pure returns (UFixed) {
        return UFixed.wrap(UFixed.unwrap(a) + UFixed.unwrap(b));
    }

    function mul(UFixed a, uint256 b) internal pure returns (UFixed) {
        return UFixed.wrap(UFixed.unwrap(a) * b);
    }

    function floor(UFixed a) internal pure returns (uint256) {
        return UFixed.unwrap(a) / multiplier;
    }

    function toUFixed(uint256 a) internal pure returns (UFixed) {
        return UFixed.wrap(a * multiplier);
    }
}

/*
 * Assembly
 */

contract BooleanLiteralsInAssembly {
  function f() {
    uint a;
    assembly {
      a := true
      a := false
    }
  }
}

/*
 * Etc
 */

contract test {
    function f(uint a, uint b);
    function g(uint c);
}
contract c {
    event e(uint[10] a, bytes7[8] indexed b, c[3] x);
}
contract c {
    function f() {
        uint8[10 * 2] x;
    }
}
contract c {
    uint[10] a;
    uint[] a2;
    struct x { uint[2**20] b; y[0] c; }
    struct y { uint d; mapping(uint=>x)[] e; }
}
contract test {
    function fun(uint256 a) {
        uint256 x = ([1, 2, 3 + 4][a/=9] - 3) ** 4;
    }
}

contract z {}
contract A {
    function f() {
        uint x = 3 < 0 ? 2 > 1 ? 2 : 1 : 7 > 2 ? 7 : 6;
    }
}
contract A {
    function f() {
        uint x = true ? 1 : 0;
        uint y = false ? 0 : 1;
    }
}
contract A {
    function f() {
        uint y = 1;
        uint x = 3 < 0 ? x = 3 : 6;
        true ? x = 3 : 4;
    }
}
contract A {
    function f() {
        uint x = 3 > 0 ? 3 : 0;
        uint y = (3 > 0) ? 3 : 0;
    }
}
contract A {
    function f() {
        uint x = 3;
        uint y = 1;
        uint z = (x > y) ? x : y;
        uint w = x > y ? x : y;
    }
}
contract base {
  function fun() {
    uint64(2);
  }
}

contract derived is base() {
  function fun() {
    uint64(2);
  }
}

contract foo {
  function fun() {
  }
}

contract bar {
  function fun() {
  }
}

contract derived is foo, bar {
  function fun() {
  }
}
contract A {
    fixed40x40 storeMe;
    function f(ufixed x, fixed32x32 y) {
        ufixed8x8 a;
        fixed b;
    }
}
contract test {
  function fun(uint256 a) returns (address b) {
    if (a < 0) b = 0x67; else if (a == 0) b = 0x12; else b = 0x78;
  }
}
contract test
{}

contract test {
  uint256 stateVar;
  function functionName(bytes20 arg1, address addr) constant
    returns (int id)
  { }
}
contract c {
    enum validEnum { Value1, Value2, Value3, Value4 }

    function c () {
        a = validEnum.Value3;
    }

    validEnum a;
}
contract c {
    event e();
}
contract c {
    event e() anonymous;
}
contract c {
    event e(uint a, bytes32 s);
}
contract c {
    event e(uint a, bytes32 indexed s, bool indexed b);
}
contract test {
    function fun(uint256 a) {
        uint256 x = 3 ** a;
    }
}
contract c {
    function x() external {}
}
contract c {
    function() { }
}
contract test {
    function fun(uint256 a) {
        uint256 i = 0;
        for (i = 0; i < 10; i++) {
            uint256 x = i;
            break;
            continue;
        }
    }
}
contract test {
    function fun(uint256 a) {
        uint256 i = 0;
        for (;;) {
            uint256 x = i;
            break;
            continue;
        }
    }
}
contract test {
  function fun(uint256 a) {
    uint256 i =0;
    for (i = 0; i < 10; i++)
        continue;
  }
}
contract test {
    function fun(uint256 a) {
        for (uint256 i = 0; i < 10; i++) {
            uint256 x = i;
            break;
            continue;
        }
    }
}
contract test {
  function functionName(bytes32 input) returns (bytes32 out);
}
contract test {
    function fun(uint256 a) {
        if (a >= 8) {
            return;
        } else {
            var b = 7;
        }
    }
}

contract test {}

contract test {}

contract test {
  function fun() {
    uint64(2);
  }
}

contract test {}

contract c {
    uint[] a;
    function f() returns (uint, uint) {
        a = [1,2,3];
        return (a[3], [2,3,4][0]);
    }
}
contract test {
    function test() {
        a = 1 wei;
        a = 2 szabo;
        a = 3 finney;
        a = 4 ether;
        a = 5 gwei;

        a = 1 seconds;
        a = 2 minutes;
        a = 3 hours;
        a = 4 days;
        a = 5 weeks;
        a = 6 years;
    }

    uint256 a;
}

contract c {
    function c ()
    {
        a = 1 wei * 100 wei + 7 szabo - 3;
    }
    uint256 a;
}
contract Foo {
    function f() {
        uint[] storage x;
        uint[] memory y;
    }
}
contract test {
    mapping(address => bytes32) names;
}
contract test {
    struct test_struct {
        address addr;
        uint256 count;
        mapping(bytes32 => test_struct) self_reference;
    }
}
contract test {
    struct test_struct {
        address addr;
        mapping (uint64 => mapping (bytes32 => uint)) complex_mapping;
    }
}
contract c {
    modifier mod { if (msg.sender == 0) _; }
}

contract c {
    modifier mod(address a) { if (msg.sender == a) _; }
}
contract c {
    modifier mod1(address a) { if (msg.sender == a) _; }
    modifier mod2 { if (msg.sender == 2) _; }
    function f() mod1(7) mod2 { }
}
contract c {
    mapping(uint => mapping(uint => int8)[8][][9])[] x;
}
contract C {
    function f() {
        var (a,b,c) = g();
        var (d) = 2;
        var (,e) = 3;
        var (f,) = 4;
        var (x,,) = g();
        var (,y,) = g();
        var (,,) = g();
    }
    function g() returns (uint, uint, uint) {}
}
contract test {
  function fun() {
    uint64(2);
  }
}

contract test2 {
  function fun() {
    uint64(2);
  }
}

contract test {
  function fun() {
  }
}

contract test2 {
  function fun() {
  }
}

contract foo {
  function foo(uint a) {
  }
}

contract bar {
    function bar(string a, string b) {
    }
}

contract derived is foo(2), bar("abc", "def") {
  function fun() {
  }
}
contract test {
    function f() returns(bool succeeded) {
        return false;
    }
}
contract test {
  uint256 stateVar;
  function functionName() {}
}

contract test {
    function fun(int256 a) {
        int256 x = (1 + 4) * (a - 12) + -9;
        bool y = true && (a < 6) || false;
    }
}
contract test {
    function fun(uint a) returns(uint r) { return a; }
    function fun(uint a, uint b) returns(uint r) { return a + b; }
}
contract c {
    function fun() returns (uint r) {
        var _ = 8;
        return _ + 1;
    }
}

contract test {}
contract test {
  uint256 stateVar;
  function functionName(bytes32 input) returns (bytes32 out) {}
}
contract test {
  uint256 stateVariable1;
}
contract test {
    function fun() {
        uint64(2);
    }
}
contract test {
    uint256 stateVar;
    struct MyStructName {
        address addr;
        uint256 count;
    }
}
contract C {
    function f() {
        uint a = (1);
        var (b,) = 1;
        var (c,d) = (1, 2 + a);
        var (e,) = (1, 2, b);
        (a) = 3;
    }
}
contract test {
  function fun() {
    var x = new uint64[](3);
  }
}
contract test {
    function f() {
        uint a = +10;
        a--;

        a = ~a;
        delete a;

        bool b = !true;
    }
}

contract C {
    struct s { uint a; }
    using Lib for uint;
    using Lib for *;
    using Lib for s;

    function f() {
    }
}
contract test {
    function fun(uint256 a) {
        var b = 5;
        uint256 c;
        mapping(address=>bytes32) d;
    }
}
contract test {
    function fun(uint256 a) {
        var b = 2;
        uint256 c = 0x87;
        uint256 d = 0X78;
        mapping(address=>bytes32) d;
        bytes32 name = "Solidity";
    }
}
contract c {
    uint private a;
    uint internal b;
    uint public c;
    uint d;
    function f() {}
    function f_priv() private {}
    function f_public() public {}
    function f_internal() internal {}
}
contract test {
    function fun(uint256 a) {
        while (true) { uint256 x = 1; break; continue; } x = 9;
    }
}

contract test {
  function() {
		assembly {
			mstore(0x40, 0x60) // store the "free memory pointer"
			// function dispatcher
			switch div(calldataload(0), exp(2, 226))
			case 0xb3de648b {
				let (r) := f(calldataload(4))
				let r := f(calldataload(4))
				let ret := $allocate(0x20)
				mstore(ret, r)
				return(ret, 0x20)
			}
			default { revert(0, 0) }
			// memory allocator
			function $allocate(size) -> pos {
				pos := mload(0x40)
				mstore(0x40, add(pos, size))
			}
			// the contract function
			function f(x) -> y {
				y := 1
				for { let i := 0 } lt(i, x) { i := add(i, 1) } {
					y := mul(2, y)
				}
				if gt(y, 2) { revert(0, 0) }
			}
		}
  }
}

contract test {
  function f() view {
    return 2;
  }
  function g() pure {
    return 2;
  }
}

contract test {
  function f() {
    uint256 a = 2.3e5;
    uint256 a = 230e-1;
  }
}

contract test {
  function f() {
    uint256 a;
    (a,) = g();
    (,) = g();
    () = ();
  }
}

contract test {
  function foo() public returns (byte b) {
    assembly {
      n := byte(0x0)
    }
  }
}

contract test {
    function() {
        emit EventCalled(1, 2, 3);
    }
}

contract test {
    constructor(uint a, uint b) withModifier {}
}

contract test {
    constructor(uint a, uint b) withModifier public {}
}

contract test {
  function () payable {
    (bytes32 a, uint b) = foo();
  }
}

contract test {
  uint x = .1 ether;
}

contract test {
  function () {
    type(Proxy).creationCode;
  }
}

contract test {
  uint x = 1000000;
  int x2 = -1000000;
  int x3 = -1000000 * 200;
  uint y = .25;
  uint y2 = 0.25;
  uint y3 = 10.25;
  uint y4 = 100.25;
  uint y5 = 0.0025 * 1e18;
  uint y6 = 1000000e-2;
  uint z = 0x11_22;
  uint z2 = 0x1122;
}

contract test {
  function _finalization() internal {
    if (goalReached()) {
      _escrow.close();
      _escrow.beneficiaryWithdraw();
    } else {
      _escrow.enableRefunds();
    }

    super._finalization();
  }
}

contract test {
  function testFunction() {
		assembly {
			function power(base, exponent) -> result {
        switch exponent
        case 0 { result := 1 }
        case 1 { result := base }
        default {
            result := power(mul(base, base), div(exponent, 2))
            switch mod(exponent, 2)
            case 1 {
              result := mul(base, result)
              leave
            }
        }
    }
		}
  }
}

contract Sharer {
    function sendHalf(address payable addr) public payable returns (uint balance) {
        require(msg.value % 2 == 0, "Even value required.");
        uint balanceBeforeTransfer = address(this).balance;
        addr.transfer(msg.value / 2);
        // Since transfer throws an exception on failure and
        // cannot call back here, there should be no way for us to
        // still have half of the money.
        assert(address(this).balance == balanceBeforeTransfer - msg.value / 2);
        return address(this).balance;
    }
}

contract FeedConsumer {
    DataFeed feed;
    uint errorCount;
    function rate(address token) public returns (uint value, bool success) {
        // Permanently disable the mechanism if there are
        // more than 10 errors.
        require(errorCount < 10);
        try feed.getData(token) returns (uint v) {
            return (v, true);
        } catch Error(string memory /*reason*/) {
            // This is executed in case
            // revert was called inside getData
            // and a reason string was provided.
            errorCount++;
            return (0, false);
        } catch (bytes memory /*lowLevelData*/) {
            // This is executed in case revert() was used
            // or there was a failing assertion, division
            // by zero, etc. inside getData.
            errorCount++;
            return (0, false);
        } catch {
            // This is also executed in case revert() was used
            // or there was a failing assertion, division
            // by zero, etc. inside getData.
            errorCount++;
            return (0, false);
        }
    }
}

contract test {
  receive () external payable {}
  fallback () external payable {}
}

contract D {
    uint public x;
    constructor(uint a) public payable {
        x = a;
    }
}

contract C {
    D d = new D(4); // will be executed as part of C's constructor

    function createD(uint arg) public {
        D newD = new D(arg);
        newD.x();
    }

    function createAndEndowD(uint arg, uint amount) public payable {
        // Send ether along with the creation
        D newD = new D{value: amount}(arg);
        newD.x();
    }
}

contract D {
    uint public x;
    constructor(uint a) public {
        x = a;
    }
}

contract C {
    function createDSalted(bytes32 salt, uint arg) public {
        /// This complicated expression just tells you how the address
        /// can be pre-computed. It is just there for illustration.
        /// You actually only need ``new D{salt: salt}(arg)``.
        address predictedAddress = address(bytes20(keccak256(abi.encodePacked(
            byte(0xff),
            address(this),
            salt,
            keccak256(abi.encodePacked(
                type(D).creationCode,
                arg
            ))
        ))));

        D d = new D{salt: salt}(arg);
        require(address(d) == predictedAddress);
    }
}

contract owned {
    constructor() public { owner = msg.sender; }
    address payable owner;
}

contract Destructible is owned {
    function destroy() virtual public {
        if (msg.sender == owner) selfdestruct(owner);
    }
}

contract Base1 is Destructible {
    function destroy() public virtual override { /* do cleanup 1 */ super.destroy(); }
}


contract Base2 is Destructible {
    function destroy() public virtual override { /* do cleanup 2 */ super.destroy(); }
}

contract Final is Base1, Base2 {
    function destroy() public override(Base1, Base2) { super.destroy(); }
}

contract PayableAddress {
    function payableFn() public pure {
        address x;
        address y = payable(x);
    }
}

contract VirtualA {
    GlobalBaseStruct base;
    event MyEvent(string _myString);
    function funA() public virtual {
        emit MyEvent("from A");
    }
}

contract VirtualB {
    function funA() public virtual {
        //does nothing
    }
}

contract VirtualOverdide is VirtualA, VirtualB {
    function funA() public override(VirtualB,VirtualA) {
        emit MyEvent("from B");
        super.funA();
    }
}

contract AssemblySlotNotation {
  function foo() {
    assembly {
      ds.slot := position
      offset := x.offset
    }
  }
}

contract ArraySlices {
    function f(bytes calldata x) public {
        bytes memory a1 = abi.decode(x[:], (bytes));
        bytes4 a2 = abi.decode(x[:4], (bytes4));
        address a3 = abi.decode(x[4:], (address));
    }
}

contract WithUncheckedBlock {
  function f() public pure returns (uint) {
    uint x = 0;
    unchecked { x--; }
    return x;
  }
}

contract stateVariables {
    bytes32 constant adminRole = keccak256("ADMIN_ROLE");
    uint immutable totalSupply;
    constructor(uint _totalSupply) public {
        totalSupply = _totalSupply;
    }
}

contract userDefinedTypesAsMappingKeys {
  mapping (Foo => uint) map;
}

contract modifierWithVirtualOrOverride {
  modifier foo() virtual {_;}
  modifier bar() override {_;}
}

contract Base1
{
    function foo() virtual public {}
}

contract Base2
{
    function foo() virtual public {}
}

contract Inherited is Base1, Base2
{
    // Derives from multiple bases defining foo(), so we must explicitly
    // override it
    function foo() public override(Base1, Base2) {}
}

contract CallWithNameValue {
  function foo() {
    recipient.call("");
    recipient.call{value: 1}("");
    recipient.call{value: 1, gas: 1000}("");
  }
}

contract FunctionsNamedAsKeywords {
  function receive() {}
  function leave() {}
}

contract ImmutableKeyword {
  uint immutable foo;
}

contract FallbackWithArgs {
  fallback (bytes calldata input) external payable returns (bytes memory output) {}
}

/*
 * Issues
 */

// issue #12
contract C {
  function f() public {
    assembly {
      x := 3
      4 =: y
    }
  }
}

// issue #54
contract Foo {
  function f() public {
    (uint[][] memory x, uint y) = abi.decode(data, (uint[][], uint));
    (uint[3][] memory x, uint y) = abi.decode(data, (uint[3][], uint));
    (uint[][3] memory x, uint y) = abi.decode(data, (uint[][3], uint));
    (uint[][][] memory x, uint y) = abi.decode(data, (uint[][][], uint));
  }
}

// issue #55
pragma solidity *;

// issue #59
contract C {
  using L.Lib for uint;
}

// issue #60
contract AssemblyAssingment {
    function foo() public pure {
        assembly {
            function bar() -> a, b {
                a := 1
                b := 2
            }

            let i, j
            let k, l := bar()
            i, j := bar()
        }
    }
}

// issue #61
type Fixed18 is int256;
using Fixed18Lib for Fixed18 global;
using {plusOne, minusOne} for RestrictedNumber global;

contract Foo {
  function f() public {
    assembly ("memory-safe") {
    }
    assembly "evmasm" ("memory-safe") {
    }
  }
}


contract GlobalVarName {
    function test() pure {
        uint256 global = 1;
    }
}

// solc 0.8.18, named parameters in mapping types
contract NamedMappingParams {
  mapping (address => bool) m1;
  mapping (address a => bool) m2;
  mapping (address => bool b) m3;
  mapping (address a => bool b) m4;
}

// solc 0.8.19, user defined operators
using { add as + } for Fixed18 global;
using { add as +, sub as - } for Fixed18 global;
