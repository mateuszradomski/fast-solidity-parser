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
    Token *tokens;
    u32 tokenCount;
    u32 currentPosition;
    u32 lastPosition;
} YulLexer;

static YulLexer
createYulLexer(Token *tokens, u32 tokenCount, u32 currentPosition) {
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
    Token token = lexer->tokens[lexer->currentPosition++];
    switch(token.type) {
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
            if(stringMatch(token.string, LIT_TO_STR("let"))) {
                result.type = YulTokenType_Let;
            } else if(stringMatch(token.string, LIT_TO_STR("leave"))) {
                result.type = YulTokenType_Leave;
            } else if(stringMatch(token.string, LIT_TO_STR("switch"))) {
                result.type = YulTokenType_Switch;
            } else if(stringMatch(token.string, LIT_TO_STR("case"))) {
                result.type = YulTokenType_Case;
            } else if(stringMatch(token.string, LIT_TO_STR("default"))) {
                result.type = YulTokenType_Default;
            } else {
                result.type = YulTokenType_Identifier;
            }

            result.string = token.string;
        } break;
        case TokenType_If: {
            result.type = YulTokenType_If;
            result.string = token.string;
        } break;
        case TokenType_For: {
            result.type = YulTokenType_For;
            result.string = token.string;
        } break;
        case TokenType_Function: {
            result.type = YulTokenType_Function;
            result.string = token.string;
        } break;
        case TokenType_Break: {
            result.type = YulTokenType_Break;
            result.string = token.string;
        } break;
        case TokenType_Continue: {
            result.type = YulTokenType_Continue;
            result.string = token.string;
        } break;
        case TokenType_Colon: {
            assert(lexer->tokens[lexer->currentPosition++].type == TokenType_Equal);
            result.string = token.string;
            result.type = YulTokenType_ColonEqual;
        } break;
        case TokenType_Minus: {
            assert(lexer->tokens[lexer->currentPosition++].type == TokenType_RTick);
            result.string = token.string;
            result.type = YulTokenType_RightArrow;
        } break;
        case TokenType_LBrace: {
            result.type = YulTokenType_LBrace;
            result.string = token.string;
        } break;
        case TokenType_RBrace: {
            result.type = YulTokenType_RBrace;
            result.string = token.string;
        } break;
        case TokenType_LParen: {
            result.type = YulTokenType_LParen;
            result.string = token.string;
        } break;
        case TokenType_RParen: {
            result.type = YulTokenType_RParen;
            result.string = token.string;
        } break;
        case TokenType_Comment: {
            result.type = YulTokenType_Comment;
            result.string = token.string;
        } break;
        case TokenType_NumberLit: {
            result.type = YulTokenType_NumberLit;
            result.string = token.string;
        } break;
        case TokenType_StringLit: {
            result.type = YulTokenType_StringLit;
            result.string = token.string;
        } break;
        case TokenType_HexNumberLit: {
            result.type = YulTokenType_HexNumberLit;
            result.string = token.string;
        } break;
        case TokenType_False:
        case TokenType_True: {
            result.type = YulTokenType_BoolLit;
            result.string = token.string;
        } break;
        case TokenType_HexStringLit: {
            result.type = YulTokenType_HexStringLit;
            result.string = token.string;
        } break;
        case TokenType_Dot: {
            result.type = YulTokenType_Dot;
            result.string = token.string;
        } break;
        case TokenType_Comma: {
            result.type = YulTokenType_Comma;
            result.string = token.string;
        } break;
        default: {
            javascriptPrintString("Unknown token type in Yul lexer\n");
            javascriptPrintNumber(token.type);
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
    Token token = lexer->tokens[lexer->currentPosition];

    u32 isIdent =
        token.type == TokenType_As |
        token.type == TokenType_Do |
        token.type == TokenType_Is |
        token.type == TokenType_New |
        token.type == TokenType_Try |
        token.type == TokenType_Wei |
        token.type == TokenType_Days |
        token.type == TokenType_Else |
        token.type == TokenType_From |
        token.type == TokenType_Emit |
        token.type == TokenType_Enum |
        token.type == TokenType_Gwei |
        token.type == TokenType_Pure |
        token.type == TokenType_Type |
        token.type == TokenType_View |
        token.type == TokenType_Error |
        token.type == TokenType_Catch |
        token.type == TokenType_Ether |
        token.type == TokenType_Event |
        token.type == TokenType_Hours |
        token.type == TokenType_Using |
        token.type == TokenType_Weeks |
        token.type == TokenType_While |
        token.type == TokenType_Years |
        token.type == TokenType_Delete |
        token.type == TokenType_Import |
        token.type == TokenType_Memory |
        token.type == TokenType_Symbol |
        token.type == TokenType_Revert |
        token.type == TokenType_Global |
        token.type == TokenType_Pragma |
        token.type == TokenType_Public |
        token.type == TokenType_Return |
        token.type == TokenType_Struct |
        token.type == TokenType_Indexed |
        token.type == TokenType_Library |
        token.type == TokenType_Mapping |
        token.type == TokenType_Minutes |
        token.type == TokenType_Private |
        token.type == TokenType_Returns |
        token.type == TokenType_Seconds |
        token.type == TokenType_Receive |
        token.type == TokenType_Storage |
        token.type == TokenType_Virtual |
        token.type == TokenType_Abstract |
        token.type == TokenType_Assembly |
        token.type == TokenType_Calldata |
        token.type == TokenType_Constant |
        token.type == TokenType_Contract |
        token.type == TokenType_External |
        token.type == TokenType_Fallback |
        token.type == TokenType_Internal |
        token.type == TokenType_Modifier |
        token.type == TokenType_Override |
        token.type == TokenType_Anonymous |
        token.type == TokenType_Immutable |
        token.type == TokenType_Interface |
        token.type == TokenType_Unchecked |
        token.type == TokenType_Constructor |
        token.type == TokenType_Payable;

    if(isIdent) {
        lexer->currentPosition++;
        return lexer->currentPosition - 1;
    } else {
        return INVALID_TOKEN_ID;
    }
}
