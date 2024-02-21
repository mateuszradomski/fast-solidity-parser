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
