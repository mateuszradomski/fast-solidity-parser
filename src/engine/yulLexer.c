typedef enum YulTokenType {
    YulTokenType_None,
    YulTokenType_Let,
    YulTokenType_If,
    YulTokenType_For,
    YulTokenType_Leave,
    YulTokenType_Break,
    YulTokenType_Continue,
    YulTokenType_Function,
    YulTokenType_Switch,
    YulTokenType_Case,
    YulTokenType_Default,
    YulTokenType_LBrace,
    YulTokenType_RBrace,
    YulTokenType_LParen,
    YulTokenType_RParen,
    YulTokenType_Identifier,
    YulTokenType_Comment,
    YulTokenType_NumberLit,
    YulTokenType_StringLit,
    YulTokenType_HexNumberLit,
    YulTokenType_BoolLit,
    YulTokenType_HexStringLit,
    YulTokenType_Dot,
    YulTokenType_Comma,
    YulTokenType_ColonEqual,
    YulTokenType_RightArrow,
    YulTokenType_EOF,
    YulTokenType_Count,
} YulTokenType;

typedef struct YulToken {
    YulTokenType type;
    String string;
} YulToken;

typedef struct YulLexer {
    TokenizeResult tokens;
    u32 tokenCount;
    u32 currentPosition;
    u32 lastPosition;
} YulLexer;

static YulLexer
createYulLexer(TokenizeResult tokens, u32 tokenCount, u32 currentPosition) {
    YulLexer result = {
        .tokens = tokens,
        .tokenCount = tokenCount,
        .currentPosition = currentPosition,
        .lastPosition = currentPosition,
    };

    return result;
}

static YulToken
advanceYulToken(YulLexer *lexer) {
    if (lexer->currentPosition >= lexer->tokenCount) {
        YulToken result = {
            .type = YulTokenType_EOF,
        };
        return result;
    }

    YulToken result = { 0 };
    lexer->lastPosition = lexer->currentPosition;
    TokenType tokenType = getTokenType(lexer->tokens, lexer->currentPosition);
    String tokenString = getTokenString(lexer->tokens, lexer->currentPosition);
    lexer->currentPosition += 1;
    switch(tokenType) {
        case TokenType_As:
        case TokenType_Do:
        case TokenType_Is:
        case TokenType_New:
        case TokenType_Try:
        case TokenType_Wei:
        case TokenType_Days:
        case TokenType_Else:
        case TokenType_Emit:
        case TokenType_Enum:
        case TokenType_Gwei:
        case TokenType_Pure:
        case TokenType_Type:
        case TokenType_View:
        case TokenType_Catch:
        case TokenType_Ether:
        case TokenType_Event:
        case TokenType_Hours:
        case TokenType_Using:
        case TokenType_Weeks:
        case TokenType_While:
        case TokenType_Years:
        case TokenType_Delete:
        case TokenType_Import:
        case TokenType_Memory:
        case TokenType_Pragma:
        case TokenType_Public:
        case TokenType_Return:
        case TokenType_Struct:
        case TokenType_Indexed:
        case TokenType_Library:
        case TokenType_Mapping:
        case TokenType_Minutes:
        case TokenType_Private:
        case TokenType_Returns:
        case TokenType_Seconds:
        case TokenType_Storage:
        case TokenType_Virtual:
        case TokenType_Abstract:
        case TokenType_Assembly:
        case TokenType_Calldata:
        case TokenType_Constant:
        case TokenType_Contract:
        case TokenType_External:
        case TokenType_Fallback:
        case TokenType_Internal:
        case TokenType_Modifier:
        case TokenType_Override:
        case TokenType_Anonymous:
        case TokenType_Immutable:
        case TokenType_Interface:
        case TokenType_Unchecked:
        case TokenType_Constructor:
        case TokenType_From:
        case TokenType_Receive:
        case TokenType_Revert:
        case TokenType_Error:
        case TokenType_Global:
        case TokenType_Payable:
        case TokenType_Symbol: {
            if(stringMatch(tokenString, LIT_TO_STR("let"))) {
                result.type = YulTokenType_Let;
            } else if(stringMatch(tokenString, LIT_TO_STR("leave"))) {
                result.type = YulTokenType_Leave;
            } else if(stringMatch(tokenString, LIT_TO_STR("switch"))) {
                result.type = YulTokenType_Switch;
            } else if(stringMatch(tokenString, LIT_TO_STR("case"))) {
                result.type = YulTokenType_Case;
            } else if(stringMatch(tokenString, LIT_TO_STR("default"))) {
                result.type = YulTokenType_Default;
            } else {
                result.type = YulTokenType_Identifier;
            }

            result.string = tokenString;
        } break;
        case TokenType_If: {
            result.type = YulTokenType_If;
            result.string = tokenString;
        } break;
        case TokenType_For: {
            result.type = YulTokenType_For;
            result.string = tokenString;
        } break;
        case TokenType_Function: {
            result.type = YulTokenType_Function;
            result.string = tokenString;
        } break;
        case TokenType_Break: {
            result.type = YulTokenType_Break;
            result.string = tokenString;
        } break;
        case TokenType_Continue: {
            result.type = YulTokenType_Continue;
            result.string = tokenString;
        } break;
        case TokenType_Colon: {
            assert(getTokenType(lexer->tokens, lexer->currentPosition++) == TokenType_Equal);
            result.string = tokenString;
            result.type = YulTokenType_ColonEqual;
        } break;
        case TokenType_Minus: {
            assert(getTokenType(lexer->tokens, lexer->currentPosition++) == TokenType_RTick);
            result.string = tokenString;
            result.type = YulTokenType_RightArrow;
        } break;
        case TokenType_LBrace: {
            result.type = YulTokenType_LBrace;
            result.string = tokenString;
        } break;
        case TokenType_RBrace: {
            result.type = YulTokenType_RBrace;
            result.string = tokenString;
        } break;
        case TokenType_LParen: {
            result.type = YulTokenType_LParen;
            result.string = tokenString;
        } break;
        case TokenType_RParen: {
            result.type = YulTokenType_RParen;
            result.string = tokenString;
        } break;
        case TokenType_Comment: {
            result.type = YulTokenType_Comment;
            result.string = tokenString;
        } break;
        case TokenType_NumberLit: {
            result.type = YulTokenType_NumberLit;
            result.string = tokenString;
        } break;
        case TokenType_StringLit: {
            result.type = YulTokenType_StringLit;
            result.string = tokenString;
        } break;
        case TokenType_HexNumberLit: {
            result.type = YulTokenType_HexNumberLit;
            result.string = tokenString;
        } break;
        case TokenType_False:
        case TokenType_True: {
            result.type = YulTokenType_BoolLit;
            result.string = tokenString;
        } break;
        case TokenType_HexStringLit: {
            result.type = YulTokenType_HexStringLit;
            result.string = tokenString;
        } break;
        case TokenType_Dot: {
            result.type = YulTokenType_Dot;
            result.string = tokenString;
        } break;
        case TokenType_Comma: {
            result.type = YulTokenType_Comma;
            result.string = tokenString;
        } break;
        default: {
            javascriptPrintString("Unknown token type in Yul lexer\n");
            javascriptPrintNumber(tokenType);
            assert(0);
        }
    }

    return result;
}

static YulToken
peekYulToken(YulLexer *lexer) {
    u32 position = lexer->currentPosition;
    u32 lastPosition = lexer->lastPosition;
    YulToken result = advanceYulToken(lexer);
    lexer->currentPosition = position;
    lexer->lastPosition = lastPosition;
    return result;
}

static TokenId
peekYulLastToken(YulLexer *lexer) {
    return lexer->lastPosition;
}

static TokenId
parseYulIdentifier(YulLexer *lexer) {
    TokenType tokenType = getTokenType(lexer->tokens, lexer->currentPosition);

    u32 isIdent =
        tokenType == TokenType_As |
        tokenType == TokenType_Do |
        tokenType == TokenType_Is |
        tokenType == TokenType_New |
        tokenType == TokenType_Try |
        tokenType == TokenType_Wei |
        tokenType == TokenType_Days |
        tokenType == TokenType_Else |
        tokenType == TokenType_From |
        tokenType == TokenType_Emit |
        tokenType == TokenType_Enum |
        tokenType == TokenType_Gwei |
        tokenType == TokenType_Pure |
        tokenType == TokenType_Type |
        tokenType == TokenType_View |
        tokenType == TokenType_Error |
        tokenType == TokenType_Catch |
        tokenType == TokenType_Ether |
        tokenType == TokenType_Event |
        tokenType == TokenType_Hours |
        tokenType == TokenType_Using |
        tokenType == TokenType_Weeks |
        tokenType == TokenType_While |
        tokenType == TokenType_Years |
        tokenType == TokenType_Delete |
        tokenType == TokenType_Import |
        tokenType == TokenType_Memory |
        tokenType == TokenType_Symbol |
        tokenType == TokenType_Revert |
        tokenType == TokenType_Global |
        tokenType == TokenType_Pragma |
        tokenType == TokenType_Public |
        tokenType == TokenType_Return |
        tokenType == TokenType_Struct |
        tokenType == TokenType_Indexed |
        tokenType == TokenType_Library |
        tokenType == TokenType_Mapping |
        tokenType == TokenType_Minutes |
        tokenType == TokenType_Private |
        tokenType == TokenType_Returns |
        tokenType == TokenType_Seconds |
        tokenType == TokenType_Receive |
        tokenType == TokenType_Storage |
        tokenType == TokenType_Virtual |
        tokenType == TokenType_Abstract |
        tokenType == TokenType_Assembly |
        tokenType == TokenType_Calldata |
        tokenType == TokenType_Constant |
        tokenType == TokenType_Contract |
        tokenType == TokenType_External |
        tokenType == TokenType_Fallback |
        tokenType == TokenType_Internal |
        tokenType == TokenType_Modifier |
        tokenType == TokenType_Override |
        tokenType == TokenType_Anonymous |
        tokenType == TokenType_Immutable |
        tokenType == TokenType_Interface |
        tokenType == TokenType_Unchecked |
        tokenType == TokenType_Constructor |
        tokenType == TokenType_Payable;

    if(isIdent) {
        lexer->currentPosition++;
        return lexer->currentPosition - 1;
    } else {
        return INVALID_TOKEN_ID;
    }
}
