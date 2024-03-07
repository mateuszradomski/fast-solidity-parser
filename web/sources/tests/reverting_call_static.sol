abstract contract B
{
        function iWillRevert() pure public virtual { revert Error(); }
}

abstract contract X
{
        function iWillRevert() pure public virtual { revert Error(); }
}

contract C is B, X
{
        function iWillRevert() pure public override(B, X) {  }

        function test(bool _param) pure external returns(uint256)
        {
                if (_param) return 1;

                B.iWillRevert();
        }
}

// ----
