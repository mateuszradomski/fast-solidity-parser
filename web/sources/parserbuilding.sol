import "./abc.sol";
import "./def.sol";
import './abc.sol';
import './def.sol';
import "./abc.sol" as x;
import './abc.sol' as my_abc;
import * as y from "./abc.sol";
import * as abc from './abc.sol';
import {a as b, c as d, f} from "./abc.sol";
import { a as my_a, b as my_b } from './abc.sol';

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

struct KeyValuePair {
    address a0;
    bool a1;
    string a2;
    bytes a3;
    int a4;
    int8 a5;
    int16 a6;
    int24 a7;
    int32 a8;
    int40 a9;
    int48 a10;
    int56 a11;
    int64 a12;
    int72 a13;
    int80 a14;
    int88 a15;
    int96 a16;
    int104 a17;
    int112 a18;
    int120 a19;
    int128 a20;
    int136 a21;
    int144 a22;
    int152 a23;
    int160 a24;
    int168 a25;
    int176 a26;
    int184 a27;
    int192 a28;
    int200 a29;
    int208 a30;
    int216 a31;
    int224 a32;
    int232 a33;
    int240 a34;
    int248 a35;
    int256 a36;
    uint a37;
    uint8 a38;
    uint16 a39;
    uint24 a40;
    uint32 a41;
    uint40 a42;
    uint48 a43;
    uint56 a44;
    uint64 a45;
    uint72 a46;
    uint80 a47;
    uint88 a48;
    uint96 a49;
    uint104 a50;
    uint112 a51;
    uint120 a52;
    uint128 a53;
    uint136 a54;
    uint144 a55;
    uint152 a56;
    uint160 a57;
    uint168 a58;
    uint176 a59;
    uint184 a60;
    uint192 a61;
    uint200 a62;
    uint208 a63;
    uint216 a64;
    uint224 a65;
    uint232 a66;
    uint240 a67;
    uint248 a68;
    uint256 a69;
    bytes1 a70;
    bytes2 a71;
    bytes3 a72;
    bytes4 a73;
    bytes5 a74;
    bytes6 a75;
    bytes7 a76;
    bytes8 a77;
    bytes9 a78;
    bytes10 a79;
    bytes11 a80;
    bytes12 a81;
    bytes13 a82;
    bytes14 a83;
    bytes15 a84;
    bytes16 a85;
    bytes17 a86;
    bytes18 a87;
    bytes19 a88;
    bytes20 a89;
    bytes21 a90;
    bytes22 a91;
    bytes23 a92;
    bytes24 a93;
    bytes25 a94;
    bytes26 a95;
    bytes27 a96;
    bytes28 a97;
    bytes29 a98;
    bytes30 a99;
    bytes31 a100;
    bytes32 a101;
    fixed a102;
    ufixed a103;

    abc.a a102;
    abc.b a103;
    MyContract.MyStruct a104;
    MyContract.MyStruct1.MyStruct2 a105;
    mapping(address => uint) a106;
    mapping(address => mapping(address => uint)) a107;
}
