typedef enum TokenType {
    TokenType_None,
    TokenType_Library,
    TokenType_Contract,
    TokenType_Abstract,
    TokenType_Interface,
    TokenType_Struct,
    TokenType_Private,
    TokenType_Immutable,
    TokenType_Constant,
    TokenType_Function,
    TokenType_Internal,
    TokenType_Pure,
    TokenType_Payable,
    TokenType_New,
    TokenType_Return,
    TokenType_Returns,
    TokenType_Memory,
    TokenType_While,
    TokenType_For,
    TokenType_Import,
    TokenType_As,
    TokenType_Is,
    TokenType_From,
    TokenType_External,
    TokenType_View,
    TokenType_Public,
    TokenType_Override,
    TokenType_Virtual,
    TokenType_Modifier,
    TokenType_Fallback,
    TokenType_Receive,
    TokenType_Enum,
    TokenType_Type,
    TokenType_Indexed,
    TokenType_Event,
    TokenType_Anonymous,
    TokenType_Error,
    TokenType_Using,
    TokenType_Global,
    TokenType_Delete,
    TokenType_True,
    TokenType_False,
    TokenType_Unchecked,
    TokenType_If,
    TokenType_Else,
    TokenType_Do,
    TokenType_Continue,
    TokenType_Break,
    TokenType_Try,
    TokenType_Catch,
    TokenType_Emit,
    TokenType_Revert,
    TokenType_Assembly,
    TokenType_Pragma,
    TokenType_Mapping,
    TokenType_Storage,
    TokenType_Calldata,
    TokenType_Wei,
    TokenType_Gwei,
    TokenType_Ether,
    TokenType_Seconds,
    TokenType_Minutes,
    TokenType_Hours,
    TokenType_Days,
    TokenType_Weeks,
    TokenType_Years,
    TokenType_Exclamation,
    TokenType_Plus,
    TokenType_Minus,
    TokenType_Percent,
    TokenType_Divide,
    TokenType_Star,
    TokenType_StarStar,
    TokenType_Ampersand,
    TokenType_Pipe,
    TokenType_Carrot,
    TokenType_LeftShift,
    TokenType_RightShift,
    TokenType_RightShiftZero,
    TokenType_Tylde,
    TokenType_PlusPlus,
    TokenType_MinusMinus,
    TokenType_LTick,
    TokenType_RTick,
    TokenType_LeftEqual,
    TokenType_RightEqual,
    TokenType_EqualEqual,
    TokenType_NotEqual,
    TokenType_LogicalAnd,
    TokenType_LogicalOr,
    TokenType_QuestionMark,
    TokenType_Equal,
    TokenType_OrEqual,
    TokenType_XorEqual,
    TokenType_AndEqual,
    TokenType_LeftShiftEqual,
    TokenType_RightShiftEqual,
    TokenType_PlusEqual,
    TokenType_MinusEqual,
    TokenType_StarEqual,
    TokenType_DivideEqual,
    TokenType_PercentEqual,
    TokenType_LBracket,
    TokenType_RBracket,
    TokenType_LBrace,
    TokenType_RBrace,
    TokenType_LParen,
    TokenType_RParen,
    TokenType_Colon,
    TokenType_Semicolon,
    TokenType_Comma,
    TokenType_Dot,
    TokenType_Symbol,
    TokenType_StringLit,
    TokenType_HexStringLit,
    TokenType_UnicodeStringLit,
    TokenType_NumberLit,
    TokenType_HexNumberLit,
    TokenType_Comment,
    TokenType_Constructor,
    TokenType_EOF,
    TokenType_Count,
} TokenType;

#define INVALID_TOKEN_ID ((u32)(-1))
typedef u32 TokenId;

typedef struct TokenIdBucket {
    TokenId tokens[16];
    u32 count;
    struct TokenIdBucket *next;
} TokenIdBucket;

typedef struct TokenIdList {
    TokenIdBucket *first;
    TokenIdBucket *last;
    u32 count;
} TokenIdList;

typedef struct Token {
    TokenType type;
    String string;
} Token;

typedef struct TokenizeResult {
    Token *tokens;
    u32 count;
    u32 capacity;
} TokenizeResult;

static String
tokenTypeToString(TokenType tokenType) {
    switch(tokenType) {
        case TokenType_None: return LIT_TO_STR("None");
        case TokenType_Library: return LIT_TO_STR("Library");
        case TokenType_Contract: return LIT_TO_STR("Contract");
        case TokenType_Abstract: return LIT_TO_STR("Abstract");
        case TokenType_Interface: return LIT_TO_STR("Interface");
        case TokenType_Struct: return LIT_TO_STR("Struct");
        case TokenType_Private: return LIT_TO_STR("Private");
        case TokenType_Immutable: return LIT_TO_STR("Immutable");
        case TokenType_Constant: return LIT_TO_STR("Constant");
        case TokenType_Function: return LIT_TO_STR("Function");
        case TokenType_Internal: return LIT_TO_STR("Internal");
        case TokenType_Pure: return LIT_TO_STR("Pure");
        case TokenType_Payable: return LIT_TO_STR("Payable");
        case TokenType_New: return LIT_TO_STR("New");
        case TokenType_Return: return LIT_TO_STR("Return");
        case TokenType_Returns: return LIT_TO_STR("Returns");
        case TokenType_Memory: return LIT_TO_STR("Memory");
        case TokenType_While: return LIT_TO_STR("While");
        case TokenType_For: return LIT_TO_STR("For");
        case TokenType_Import: return LIT_TO_STR("Import");
        case TokenType_As: return LIT_TO_STR("As");
        case TokenType_Is: return LIT_TO_STR("Is");
        case TokenType_From: return LIT_TO_STR("From");
        case TokenType_External: return LIT_TO_STR("External");
        case TokenType_View: return LIT_TO_STR("View");
        case TokenType_Public: return LIT_TO_STR("Public");
        case TokenType_Override: return LIT_TO_STR("Override");
        case TokenType_Virtual: return LIT_TO_STR("Virtual");
        case TokenType_Modifier: return LIT_TO_STR("Modifier");
        case TokenType_Fallback: return LIT_TO_STR("Fallback");
        case TokenType_Receive: return LIT_TO_STR("Receive");
        case TokenType_Enum: return LIT_TO_STR("Enum");
        case TokenType_Type: return LIT_TO_STR("Type");
        case TokenType_Indexed: return LIT_TO_STR("Indexed");
        case TokenType_Event: return LIT_TO_STR("Event");
        case TokenType_Anonymous: return LIT_TO_STR("Anonymous");
        case TokenType_Error: return LIT_TO_STR("Error");
        case TokenType_Using: return LIT_TO_STR("Using");
        case TokenType_Global: return LIT_TO_STR("Global");
        case TokenType_Delete: return LIT_TO_STR("Delete");
        case TokenType_True: return LIT_TO_STR("True");
        case TokenType_False: return LIT_TO_STR("False");
        case TokenType_Unchecked: return LIT_TO_STR("Unchecked");
        case TokenType_If: return LIT_TO_STR("If");
        case TokenType_Else: return LIT_TO_STR("Else");
        case TokenType_Do: return LIT_TO_STR("Do");
        case TokenType_Continue: return LIT_TO_STR("Continue");
        case TokenType_Break: return LIT_TO_STR("Break");
        case TokenType_Try: return LIT_TO_STR("Try");
        case TokenType_Catch: return LIT_TO_STR("Catch");
        case TokenType_Emit: return LIT_TO_STR("Emit");
        case TokenType_Revert: return LIT_TO_STR("Revert");
        case TokenType_Assembly: return LIT_TO_STR("Assembly");
        case TokenType_Pragma: return LIT_TO_STR("Pragma");
        case TokenType_Mapping: return LIT_TO_STR("Mapping");
        case TokenType_Storage: return LIT_TO_STR("Storage");
        case TokenType_Calldata: return LIT_TO_STR("Calldata");
        case TokenType_Wei: return LIT_TO_STR("Wei");
        case TokenType_Gwei: return LIT_TO_STR("Gwei");
        case TokenType_Ether: return LIT_TO_STR("Ether");
        case TokenType_Seconds: return LIT_TO_STR("Seconds");
        case TokenType_Minutes: return LIT_TO_STR("Minutes");
        case TokenType_Hours: return LIT_TO_STR("Hours");
        case TokenType_Days: return LIT_TO_STR("Days");
        case TokenType_Weeks: return LIT_TO_STR("Weeks");
        case TokenType_Years: return LIT_TO_STR("Years");
        case TokenType_Exclamation: return LIT_TO_STR("Exclamation");
        case TokenType_Plus: return LIT_TO_STR("Plus");
        case TokenType_Minus: return LIT_TO_STR("Minus");
        case TokenType_Percent: return LIT_TO_STR("Percent");
        case TokenType_Divide: return LIT_TO_STR("Divide");
        case TokenType_Star: return LIT_TO_STR("Star");
        case TokenType_StarStar: return LIT_TO_STR("StarStar");
        case TokenType_Ampersand: return LIT_TO_STR("Ampersand");
        case TokenType_Pipe: return LIT_TO_STR("Pipe");
        case TokenType_Carrot: return LIT_TO_STR("Carrot");
        case TokenType_LeftShift: return LIT_TO_STR("LeftShift");
        case TokenType_RightShift: return LIT_TO_STR("RightShift");
        case TokenType_RightShiftZero: return LIT_TO_STR("RightShiftZero");
        case TokenType_Tylde: return LIT_TO_STR("Tylde");
        case TokenType_PlusPlus: return LIT_TO_STR("PlusPlus");
        case TokenType_MinusMinus: return LIT_TO_STR("MinusMinus");
        case TokenType_QuestionMark: return LIT_TO_STR("QuestionMark");
        case TokenType_LeftEqual: return LIT_TO_STR("LeftEqual");
        case TokenType_RightEqual: return LIT_TO_STR("RightEqual");
        case TokenType_Equal: return LIT_TO_STR("Equal");
        case TokenType_OrEqual: return LIT_TO_STR("OrEqual");
        case TokenType_XorEqual: return LIT_TO_STR("XorEqual");
        case TokenType_AndEqual: return LIT_TO_STR("AndEqual");
        case TokenType_LeftShiftEqual: return LIT_TO_STR("LeftShiftEqual");
        case TokenType_RightShiftEqual: return LIT_TO_STR("RightShiftEqual");
        case TokenType_PlusEqual: return LIT_TO_STR("PlusEqual");
        case TokenType_MinusEqual: return LIT_TO_STR("MinusEqual");
        case TokenType_StarEqual: return LIT_TO_STR("StarEqual");
        case TokenType_DivideEqual: return LIT_TO_STR("DivideEqual");
        case TokenType_PercentEqual: return LIT_TO_STR("PercentEqual");
        case TokenType_EqualEqual: return LIT_TO_STR("EqualEqual");
        case TokenType_NotEqual: return LIT_TO_STR("NotEqual");
        case TokenType_LogicalAnd: return LIT_TO_STR("LogicalAnd");
        case TokenType_LogicalOr: return LIT_TO_STR("LogicalOr");
        case TokenType_LBracket: return LIT_TO_STR("LBracket");
        case TokenType_RBracket: return LIT_TO_STR("RBracket");
        case TokenType_LBrace: return LIT_TO_STR("LBrace");
        case TokenType_RBrace: return LIT_TO_STR("RBrace");
        case TokenType_LParen: return LIT_TO_STR("LParen");
        case TokenType_RParen: return LIT_TO_STR("RParen");
        case TokenType_LTick: return LIT_TO_STR("LTick");
        case TokenType_RTick: return LIT_TO_STR("RTick");
        case TokenType_Colon: return LIT_TO_STR("Colon");
        case TokenType_Semicolon: return LIT_TO_STR("Semicolon");
        case TokenType_Comma: return LIT_TO_STR("Comma");
        case TokenType_Dot: return LIT_TO_STR("Dot");
        case TokenType_Symbol: return LIT_TO_STR("Symbol");
        case TokenType_StringLit: return LIT_TO_STR("StringLit");
        case TokenType_HexStringLit: return LIT_TO_STR("HexStringLit");
        case TokenType_NumberLit: return LIT_TO_STR("NumberLit");
        case TokenType_HexNumberLit: return LIT_TO_STR("HexNumberLit");
        case TokenType_UnicodeStringLit: return LIT_TO_STR("UnicodeStringLit");
        case TokenType_Comment: return LIT_TO_STR("Comment");
        case TokenType_Constructor: return LIT_TO_STR("Constructor");
        case TokenType_Count: return LIT_TO_STR("Count");
        case TokenType_EOF: return LIT_TO_STR("EOF");
    }
}

static TokenIdBucket *
listPushTokenId(TokenIdList *list, TokenId token, Arena *arena) {
    TokenIdBucket *bucket = 0x0;
    if(list->count == 0) {
        assert(list->first == 0x0 && list->last == 0x0);
        bucket = structPush(arena, TokenIdBucket);
        SLL_QUEUE_PUSH(list->first, list->last, bucket);
    } else {
        bucket = list->last;
    }

    if(bucket->count >= ARRAY_LENGTH(bucket->tokens)) {
        bucket = structPush(arena, TokenIdBucket);
        SLL_QUEUE_PUSH(list->first, list->last, bucket);
    }

    bucket->tokens[bucket->count++] = token;
    list->count += 1;

    return bucket;
}

static TokenId
listGetTokenId(TokenIdList *list, u32 index) {
    assert(index < list->count);
    TokenIdBucket *bucket = list->first;
    for(u32 i = 0; i < index / ARRAY_LENGTH(bucket->tokens); i++) {
        bucket = bucket->next;
    }

    return bucket->tokens[index % ARRAY_LENGTH(bucket->tokens)];
}

static TokenizeResult
allocateTokenSpace(Arena *arena, u32 capacity) {
    TokenizeResult result = {0};
    result.tokens = arrayPush(arena, Token, capacity);
    result.capacity = capacity;
    return result;
}

static Token
getToken(TokenizeResult tokens, TokenId tokenId) {
    assert(tokenId >= 0 && tokenId < tokens.count);
    return tokens.tokens[tokenId];
}

static void
formatToken(String *output, TokenType tokenType, String string) {
    u8 *head = output->data;

    String token = tokenTypeToString(tokenType);
    memcpy(head, token.data, token.size);
    output->size += token.size;
    head += token.size;

    memcpy(head, " -> [ ", 6);
    output->size += 6;
    head += 6;

    memcpy(head, string.data, string.size);
    output->size += string.size;
    head += string.size;

    memcpy(head, " ]", 3);
    output->size += 3;
    head += 3;
}

static void
printToken(Token token) {
    u8 buffer[2048];
    String message = {
        .data = buffer,
        .size = 0,
    };
    formatToken(&message, token.type, token.string);
    javascriptPrintStringPtr(&message);
}

static void
pushToken(TokenizeResult *result, TokenType tokenType, String string) {
    assert(result->count < result->capacity);

    result->tokens[result->count++] = (Token){
        .type = tokenType,
        .string = string
    };
}

static Token
tokenizeNumberLiteral(ByteConsumer *c, u8 byte) {
    u8 nextByte = peekByte(c);

    if(byte == '0' && (nextByte == 'x' || nextByte == 'X')) {
        String symbol = { .data = c->head - 1, .size = 2 };
        consumeByte(c);

        while(consumerGood(c)) {
            u8 nextByte = peekByte(c);
            if(!(isHexDigit(nextByte) || nextByte == '_')) {
                break;
            }

            symbol.size += 1;
            consumeByte(c);
        }

        return (Token) {
            .type = TokenType_HexNumberLit,
            .string = symbol,
        };
    } else {
        String symbol = { .data = c->head - 1, .size = 1 };

        while(consumerGood(c)) {
            u8 nextByte = peekByte(c);
            if(!(isDigit(nextByte) || nextByte == '_')) {
                break;
            }

            symbol.size += 1;
            consumeByte(c);
        }

        if(peekByte(c) == '.' && isDigit(peekString(c, 2).data[1])) {
            symbol.size += 1;
            consumeByte(c);
        }

        while(consumerGood(c)) {
            u8 nextByte = peekByte(c);
            if(!(isDigit(nextByte) || nextByte == '_')) {
                break;
            }

            symbol.size += 1;
            consumeByte(c);
        }

        if(peekByte(c) == 'e' || peekByte(c) == 'E') {
            symbol.size += 1;
            consumeByte(c);

            if(peekByte(c) == '-') {
                symbol.size += 1;
                consumeByte(c);
            }

            while(consumerGood(c)) {
                u8 nextByte = peekByte(c);
                if(isDigit(nextByte) || nextByte == '_') {
                    symbol.size += 1;
                    consumeByte(c);
                } else {
                    break;
                }
            }
        }

        return (Token) {
            .type = TokenType_NumberLit,
            .string = symbol,
        };
    }
}

static TokenType
categorizeSymbol(String symbol) {
    switch(symbol.size) {
        case 2: {
            if(stringMatch(symbol, LIT_TO_STR("as"))) return TokenType_As;
            if(stringMatch(symbol, LIT_TO_STR("do"))) return TokenType_Do;
            if(stringMatch(symbol, LIT_TO_STR("if"))) return TokenType_If;
            if(stringMatch(symbol, LIT_TO_STR("is"))) return TokenType_Is;
            return TokenType_Symbol;
        }break;
        case 3: {
            if(stringMatch(symbol, LIT_TO_STR("for"))) return TokenType_For;
            if(stringMatch(symbol, LIT_TO_STR("new"))) return TokenType_New;
            if(stringMatch(symbol, LIT_TO_STR("try"))) return TokenType_Try;
            if(stringMatch(symbol, LIT_TO_STR("wei"))) return TokenType_Wei;
            return TokenType_Symbol;
        } break;
        case 4: {
            if(stringMatch(symbol, LIT_TO_STR("days"))) return TokenType_Days;
            if(stringMatch(symbol, LIT_TO_STR("else"))) return TokenType_Else;
            if(stringMatch(symbol, LIT_TO_STR("emit"))) return TokenType_Emit;
            if(stringMatch(symbol, LIT_TO_STR("enum"))) return TokenType_Enum;
            if(stringMatch(symbol, LIT_TO_STR("from"))) return TokenType_From;
            if(stringMatch(symbol, LIT_TO_STR("gwei"))) return TokenType_Gwei;
            if(stringMatch(symbol, LIT_TO_STR("pure"))) return TokenType_Pure;
            if(stringMatch(symbol, LIT_TO_STR("true"))) return TokenType_True;
            if(stringMatch(symbol, LIT_TO_STR("type"))) return TokenType_Type;
            if(stringMatch(symbol, LIT_TO_STR("view"))) return TokenType_View;
            return TokenType_Symbol;
        } break;
        case 5: {
            if(stringMatch(symbol, LIT_TO_STR("break"))) return TokenType_Break;
            if(stringMatch(symbol, LIT_TO_STR("catch"))) return TokenType_Catch;
            if(stringMatch(symbol, LIT_TO_STR("error"))) return TokenType_Error;
            if(stringMatch(symbol, LIT_TO_STR("ether"))) return TokenType_Ether;
            if(stringMatch(symbol, LIT_TO_STR("event"))) return TokenType_Event;
            if(stringMatch(symbol, LIT_TO_STR("false"))) return TokenType_False;
            if(stringMatch(symbol, LIT_TO_STR("hours"))) return TokenType_Hours;
            if(stringMatch(symbol, LIT_TO_STR("using"))) return TokenType_Using;
            if(stringMatch(symbol, LIT_TO_STR("weeks"))) return TokenType_Weeks;
            if(stringMatch(symbol, LIT_TO_STR("while"))) return TokenType_While;
            if(stringMatch(symbol, LIT_TO_STR("years"))) return TokenType_Years;
            return TokenType_Symbol;
        } break;
        case 6: {
            if(stringMatch(symbol, LIT_TO_STR("delete"))) return TokenType_Delete;
            if(stringMatch(symbol, LIT_TO_STR("global"))) return TokenType_Global;
            if(stringMatch(symbol, LIT_TO_STR("import"))) return TokenType_Import;
            if(stringMatch(symbol, LIT_TO_STR("memory"))) return TokenType_Memory;
            if(stringMatch(symbol, LIT_TO_STR("pragma"))) return TokenType_Pragma;
            if(stringMatch(symbol, LIT_TO_STR("public"))) return TokenType_Public;
            if(stringMatch(symbol, LIT_TO_STR("return"))) return TokenType_Return;
            if(stringMatch(symbol, LIT_TO_STR("revert"))) return TokenType_Revert;
            if(stringMatch(symbol, LIT_TO_STR("struct"))) return TokenType_Struct;
            return TokenType_Symbol;
        } break;
        case 7: {
            if(stringMatch(symbol, LIT_TO_STR("indexed"))) return TokenType_Indexed;
            if(stringMatch(symbol, LIT_TO_STR("library"))) return TokenType_Library;
            if(stringMatch(symbol, LIT_TO_STR("mapping"))) return TokenType_Mapping;
            if(stringMatch(symbol, LIT_TO_STR("minutes"))) return TokenType_Minutes;
            if(stringMatch(symbol, LIT_TO_STR("payable"))) return TokenType_Payable;
            if(stringMatch(symbol, LIT_TO_STR("private"))) return TokenType_Private;
            if(stringMatch(symbol, LIT_TO_STR("receive"))) return TokenType_Receive;
            if(stringMatch(symbol, LIT_TO_STR("returns"))) return TokenType_Returns;
            if(stringMatch(symbol, LIT_TO_STR("seconds"))) return TokenType_Seconds;
            if(stringMatch(symbol, LIT_TO_STR("storage"))) return TokenType_Storage;
            if(stringMatch(symbol, LIT_TO_STR("virtual"))) return TokenType_Virtual;
            return TokenType_Symbol;
        } break;
        case 8: {
            if(stringMatch(symbol, LIT_TO_STR("abstract"))) return TokenType_Abstract;
            if(stringMatch(symbol, LIT_TO_STR("assembly"))) return TokenType_Assembly;
            if(stringMatch(symbol, LIT_TO_STR("calldata"))) return TokenType_Calldata;
            if(stringMatch(symbol, LIT_TO_STR("constant"))) return TokenType_Constant;
            if(stringMatch(symbol, LIT_TO_STR("continue"))) return TokenType_Continue;
            if(stringMatch(symbol, LIT_TO_STR("contract"))) return TokenType_Contract;
            if(stringMatch(symbol, LIT_TO_STR("external"))) return TokenType_External;
            if(stringMatch(symbol, LIT_TO_STR("fallback"))) return TokenType_Fallback;
            if(stringMatch(symbol, LIT_TO_STR("function"))) return TokenType_Function;
            if(stringMatch(symbol, LIT_TO_STR("internal"))) return TokenType_Internal;
            if(stringMatch(symbol, LIT_TO_STR("modifier"))) return TokenType_Modifier;
            if(stringMatch(symbol, LIT_TO_STR("override"))) return TokenType_Override;
            return TokenType_Symbol;
        } break;
        case 9:  {
            if(stringMatch(symbol, LIT_TO_STR("anonymous"))) return TokenType_Anonymous;
            if(stringMatch(symbol, LIT_TO_STR("immutable"))) return TokenType_Immutable;
            if(stringMatch(symbol, LIT_TO_STR("interface"))) return TokenType_Interface;
            if(stringMatch(symbol, LIT_TO_STR("unchecked"))) return TokenType_Unchecked;
            return TokenType_Symbol;
        }break;
        case 11: {
            if(stringMatch(symbol, LIT_TO_STR("constructor"))) return TokenType_Constructor;
            return TokenType_Symbol;
        } break;
        default: {
            return TokenType_Symbol;
        }
    }
}

static TokenizeResult
tokenize(String source, Arena *arena) {
    TokenizeResult result = allocateTokenSpace(arena, source.size);

    ByteConsumer c = {
        .data = source.data,
        .head = source.data,
        .length = source.size,
    };

    while(consumerGood(&c)) {
        u8 byte = consumeByte(&c);
        if(isWhitespace(byte)) {
            continue;
        } else if(isAlphabet(byte) || byte == '_' || byte == '$') {
            String symbol = { .data = c.head - 1, .size = 1 };

            while(consumerGood(&c)) {
                u8 nextByte = peekByte(&c);
                if(nextByte == '_' || nextByte == '$' || isAlphabet(nextByte) || isDigit(nextByte)) {
                    symbol.size += 1;
                    consumeByte(&c);
                } else {
                    break;
                }
            }

            u8 nextByte = peekByte(&c);
            if(stringMatch(symbol, LIT_TO_STR("hex")) && (nextByte == '"' || nextByte == '\'')) {
                u8 delimiter = nextByte;
                consumeByte(&c);
                String symbol = { .data = c.head, .size = 0 };

                while(consumerGood(&c)) {
                    u8 nextByte = consumeByte(&c);
                    if(nextByte == delimiter) {
                        break;
                    }
                    if(nextByte == '_') {
                        symbol.size += 1;
                        continue;
                    }

                    u8 leftNibble = nextByte;
                    u8 rightNibble = consumeByte(&c);

                    assert(isHexDigit(leftNibble) && isHexDigit(rightNibble));

                    symbol.size += 2;
                }

                pushToken(&result, TokenType_HexStringLit, symbol);
            } else if(stringMatch(symbol, LIT_TO_STR("unicode")) && (nextByte == '"' || nextByte == '\'')) {
                u8 delimiter = nextByte;
                consumeByte(&c);
                String symbol = { .data = c.head, .size = 0 };

                while(consumerGood(&c)) {
                    u8 nextByte = consumeByte(&c);
                    if(nextByte == delimiter) {
                        break;
                    }
                    symbol.size += 1;
                }

                pushToken(&result, TokenType_UnicodeStringLit, symbol);
            } else {
                TokenType tokenType = categorizeSymbol(symbol);
                pushToken(&result, tokenType, symbol);
            }
        } else if(byte == '/') {
            u8 nextByte = peekByte(&c);

            if(nextByte == '*') {
                String symbol = { .data = c.head - 1, .size = 2 };
                consumeByte(&c);
                while(consumerGood(&c)) {
                    String next2Bytes = peekString(&c, 2);

                    if(stringMatch(next2Bytes, LIT_TO_STR("*/"))) { 
                        symbol.size += 2;
                        consumeByte(&c);
                        consumeByte(&c);
                        break;
                    } else {
                        symbol.size += 1;
                        consumeByte(&c);
                    }
                }

                // pushToken(&result, TokenType_Comment, symbol);
            } else if(nextByte == '/') {
                String symbol = { .data = c.head - 1, .size = 2 };
                consumeByte(&c);
                while(consumerGood(&c)) {
                    u8 nextByte = peekByte(&c);
                    if(nextByte != '\n') {
                        symbol.size += 1;
                        consumeByte(&c);
                    } else {
                        break;
                    }
                }

                // pushToken(&result, TokenType_Comment, symbol);
            } else if(nextByte == '=') {
                consumeByte(&c);
                String symbol = { .data = c.head - 2, .size = 2 };
                pushToken(&result, TokenType_DivideEqual, symbol);
            } else {
                String symbol = { .data = c.head - 1, .size = 1 };
                pushToken(&result, TokenType_Divide, symbol);
            }
        } else if(byte == '"') {
            String symbol = { .data = c.head, .size = 0 };
            u32 escapeCount = 0;
            while(consumerGood(&c)) {
                u8 nextByte = consumeByte(&c);
                if(nextByte == '"' && (escapeCount & 1) == 0) {
                    break;
                }

                escapeCount = nextByte == '\\' ? escapeCount + 1 : 0; 
                symbol.size += 1;
            }

            pushToken(&result, TokenType_StringLit, symbol);
        } else if(byte == '\'') {
            String symbol = { .data = c.head, .size = 0 };
            u32 escapeCount = 0;
            while(consumerGood(&c)) {
                u8 nextByte = consumeByte(&c);
                if(nextByte == '\'' && (escapeCount & 1) == 0) {
                    break;
                }

                escapeCount = nextByte == '\\' ? escapeCount + 1 : 0;
                symbol.size += 1;
            }

            pushToken(&result, TokenType_StringLit, symbol);
        } else if(isDigit(byte)) {
            Token token = tokenizeNumberLiteral(&c, byte);
            pushToken(&result, token.type, token.string);
        } else if(byte == '[') {
            pushToken(&result, TokenType_LBracket, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ']') {
            pushToken(&result, TokenType_RBracket, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '{') {
            pushToken(&result, TokenType_LBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '}') {
            pushToken(&result, TokenType_RBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '(') {
            pushToken(&result, TokenType_LParen, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ')') {
            pushToken(&result, TokenType_RParen, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '<') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '<') {
                consumeByte(&c);
                u8 nextByte = peekByte(&c);
                if(nextByte == '=') {
                    consumeByte(&c);
                    pushToken(&result, TokenType_LeftShiftEqual, (String){ .data = c.head - 3, .size = 3 });
                } else {
                    pushToken(&result, TokenType_LeftShift, (String){ .data = c.head - 2, .size = 2 });
                }
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_LeftEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_LTick, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '>') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '>') {
                consumeByte(&c);
                nextByte = peekByte(&c);
                if(nextByte == '>') {
                    consumeByte(&c);
                    pushToken(&result, TokenType_RightShiftZero, (String){ .data = c.head - 3, .size = 3 });
                } else if(nextByte == '=') {
                    consumeByte(&c);
                    pushToken(&result, TokenType_RightShiftEqual, (String){ .data = c.head - 3, .size = 3 });
                } else {
                    pushToken(&result, TokenType_RightShift, (String){ .data = c.head - 2, .size = 2 });
                }
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_RightEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_RTick, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == ':') {
            pushToken(&result, TokenType_Colon, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ';') {
            pushToken(&result, TokenType_Semicolon, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ',') {
            pushToken(&result, TokenType_Comma, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '.') {
            u8 nextByte = peekByte(&c);
            if(isDigit(nextByte)) {
                Token token = tokenizeNumberLiteral(&c, byte);
                pushToken(&result, token.type, token.string);
            } else {
                pushToken(&result, TokenType_Dot, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '!') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_NotEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Exclamation, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '+') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '+') {
                consumeByte(&c);
                pushToken(&result, TokenType_PlusPlus, (String){ .data = c.head - 2, .size = 2 });
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_PlusEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Plus, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '-') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '-') {
                consumeByte(&c);
                pushToken(&result, TokenType_MinusMinus, (String){ .data = c.head - 2, .size = 2 });
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_MinusEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Minus, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '%') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_PercentEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Percent, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '*') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '*') {
                consumeByte(&c);
                pushToken(&result, TokenType_StarStar, (String){ .data = c.head - 2, .size = 2 });
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_StarEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Star, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '&') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '&') {
                consumeByte(&c);
                pushToken(&result, TokenType_LogicalAnd, (String){ .data = c.head - 2, .size = 2 });
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_AndEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Ampersand, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '|') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '|') {
                consumeByte(&c);
                pushToken(&result, TokenType_LogicalOr, (String){ .data = c.head - 2, .size = 2 });
            } else if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_OrEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Pipe, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '^') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_XorEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Carrot, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '~') {
            pushToken(&result, TokenType_Tylde, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '=') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '=') {
                consumeByte(&c);
                pushToken(&result, TokenType_EqualEqual, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Equal, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '?') {
            pushToken(&result, TokenType_QuestionMark, (String){ .data = c.head - 1, .size = 1 });
        } else {
            javascriptPrintString("Ouch! Unhandled character: ");
            javascriptPrintNumber(byte);
            assert(false);
        }
    }

    pushToken(&result, TokenType_EOF, (String){0});

    arenaPop(arena, (result.capacity - result.count) * sizeof(Token));

    return result;
}
