static const String LIBRARY_TOKEN = LIT_TO_STR("library");
static const String CONTRACT_TOKEN = LIT_TO_STR("contract");
static const String ABSTRACT_TOKEN = LIT_TO_STR("abstract");
static const String INTERFACE_TOKEN = LIT_TO_STR("interface");
static const String STRUCT_TOKEN = LIT_TO_STR("struct");
static const String PRIVATE_TOKEN = LIT_TO_STR("private");
static const String IMMUTABLE_TOKEN = LIT_TO_STR("immutable");
static const String CONSTANT_TOKEN = LIT_TO_STR("constant");
static const String FUNCTION_TOKEN = LIT_TO_STR("function");
static const String INTERNAL_TOKEN = LIT_TO_STR("internal");
static const String PURE_TOKEN = LIT_TO_STR("pure");
static const String PAYABLE_TOKEN = LIT_TO_STR("payable");
static const String RETURN_TOKEN = LIT_TO_STR("return");
static const String RETURNS_TOKEN = LIT_TO_STR("returns");
static const String MEMORY_TOKEN = LIT_TO_STR("memory");
static const String WHILE_TOKEN = LIT_TO_STR("while");
static const String FOR_TOKEN = LIT_TO_STR("for");
static const String NEW_TOKEN = LIT_TO_STR("new");

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
    TokenType_Exclamation,
    TokenType_Plus,
    TokenType_Minus,
    TokenType_Percent,
    TokenType_Divide,
    TokenType_Star,
    TokenType_Ampersand,
    TokenType_Pipe,
    TokenType_Carrot,
    TokenType_QuestionMark,
    TokenType_Equal,
    TokenType_LBracket,
    TokenType_RBracket,
    TokenType_LBrace,
    TokenType_RBrace,
    TokenType_LParen,
    TokenType_RParen,
    TokenType_LTick,
    TokenType_RTick,
    TokenType_Colon,
    TokenType_Semicolon,
    TokenType_Comma,
    TokenType_Dot,
    TokenType_Symbol,
    TokenType_StringLit,
    TokenType_NumberLit,
    TokenType_HexNumberLit,
    TokenType_BinNumberLit,
    TokenType_Comment,
    TokenType_Count,
} TokenType;

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
        case TokenType_Exclamation: return LIT_TO_STR("Exclamation");
        case TokenType_Plus: return LIT_TO_STR("Plus");
        case TokenType_Minus: return LIT_TO_STR("Minus");
        case TokenType_Percent: return LIT_TO_STR("Percent");
        case TokenType_Divide: return LIT_TO_STR("Divide");
        case TokenType_Star: return LIT_TO_STR("Star");
        case TokenType_Ampersand: return LIT_TO_STR("Ampersand");
        case TokenType_Pipe: return LIT_TO_STR("Pipe");
        case TokenType_Carrot: return LIT_TO_STR("Carrot");
        case TokenType_QuestionMark: return LIT_TO_STR("QuestionMark");
        case TokenType_Equal: return LIT_TO_STR("Equal");
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
        case TokenType_NumberLit: return LIT_TO_STR("NumberLit");
        case TokenType_HexNumberLit: return LIT_TO_STR("HexNumberLit");
        case TokenType_BinNumberLit: return LIT_TO_STR("BinNumberLit");
        case TokenType_Comment: return LIT_TO_STR("Comment");
        case TokenType_Count: return LIT_TO_STR("Count");
    }
}

static TokenizeResult
allocateTokenSpace(Arena *arena, u32 capacity) {
    TokenizeResult result = {0};
    result.tokens = arrayPush(arena, Token, capacity);
    result.capacity = capacity;
    return result;
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
printToken(TokenType tokenType, String string) {
    u8 buffer[2048];
    String message = {
        .data = buffer,
        .size = 0,
    };
    formatToken(&message, tokenType, string);
    javascriptPrintStringPtr(&message);
}

static void
pushToken(TokenizeResult *result, TokenType tokenType, String string) {
    assert((void *)(result->count < result->capacity));

    printToken(tokenType, string);

    result->tokens[result->count++] = (Token){
        .type = tokenType,
        .string = string
    };
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
        } else if(isAlphabet(byte) || byte == '_') {
            String symbol = { .data = c.head - 1, .size = 1 };

            while(consumerGood(&c)) {
                u8 nextByte = peekByte(&c);
                if(nextByte == '_' || isAlphabet(nextByte) || isDigit(nextByte)) {
                    symbol.size += 1;
                    consumeByte(&c);
                } else {
                    break;
                }
            }

            if(stringMatch(symbol, LIBRARY_TOKEN)) {
                pushToken(&result, TokenType_Library, symbol);
            } else if(stringMatch(symbol, CONTRACT_TOKEN)) {
                pushToken(&result, TokenType_Contract, symbol);
            } else if(stringMatch(symbol, ABSTRACT_TOKEN)) {
                pushToken(&result, TokenType_Abstract, symbol);
            } else if(stringMatch(symbol, INTERFACE_TOKEN)) {
                pushToken(&result, TokenType_Interface, symbol);
            } else if(stringMatch(symbol, STRUCT_TOKEN)) {
                pushToken(&result, TokenType_Struct, symbol);
            } else if(stringMatch(symbol, PRIVATE_TOKEN)) {
                pushToken(&result, TokenType_Private, symbol);
            } else if(stringMatch(symbol, IMMUTABLE_TOKEN)) {
                pushToken(&result, TokenType_Immutable, symbol);
            } else if(stringMatch(symbol, CONSTANT_TOKEN)) {
                pushToken(&result, TokenType_Constant, symbol);
            } else if(stringMatch(symbol, FUNCTION_TOKEN)) {
                pushToken(&result, TokenType_Function, symbol);
            } else if(stringMatch(symbol, INTERNAL_TOKEN)) {
                pushToken(&result, TokenType_Internal, symbol);
            } else if(stringMatch(symbol, PURE_TOKEN)) {
                pushToken(&result, TokenType_Pure, symbol);
            } else if(stringMatch(symbol, PAYABLE_TOKEN)) {
                pushToken(&result, TokenType_Payable, symbol);
            } else if(stringMatch(symbol, RETURN_TOKEN)) {
                pushToken(&result, TokenType_Return, symbol);
            } else if(stringMatch(symbol, RETURNS_TOKEN)) {
                pushToken(&result, TokenType_Returns, symbol);
            } else if(stringMatch(symbol, MEMORY_TOKEN)) {
                pushToken(&result, TokenType_Memory, symbol);
            } else if(stringMatch(symbol, WHILE_TOKEN)) {
                pushToken(&result, TokenType_While, symbol);
            } else if(stringMatch(symbol, FOR_TOKEN)) {
                pushToken(&result, TokenType_For, symbol);
            } else if(stringMatch(symbol, NEW_TOKEN)) {
                pushToken(&result, TokenType_New, symbol);
            } else {
                pushToken(&result, TokenType_Symbol, symbol);
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

                pushToken(&result, TokenType_Comment, symbol);
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

                pushToken(&result, TokenType_Comment, symbol);
            } else {
                String symbol = { .data = c.head - 1, .size = 1 };
                pushToken(&result, TokenType_Divide, symbol);
            }
        } else if(byte == '"') {
            String symbol = { .data = c.head - 1, .size = 1 };
            while(consumerGood(&c)) {
                u8 nextByte = consumeByte(&c);
                symbol.size += 1;

                if(nextByte == '"') {
                    break;
                }
            }

            pushToken(&result, TokenType_StringLit, symbol);
        } else if(isDigit(byte)) {
            u8 nextByte = peekByte(&c);

            if(byte == '0' && nextByte == 'x') {
                String symbol = { .data = c.head - 1, .size = 2 };
                consumeByte(&c);
                while(consumerGood(&c)) {
                    u8 nextByte = peekByte(&c);
                    if(isHexDigit(nextByte)) {
                        symbol.size += 1;
                        consumeByte(&c);
                    } else {
                        break;
                    }
                }

                pushToken(&result, TokenType_HexNumberLit, symbol);
            } else if(byte == '0' && nextByte == 'b') {
                String symbol = { .data = c.head - 1, .size = 2 };
                consumeByte(&c);
                while(consumerGood(&c)) {
                    u8 nextByte = peekByte(&c);
                    if(isBinDigit(nextByte)) {
                        symbol.size += 1;
                        consumeByte(&c);
                    } else {
                        break;
                    }
                }

                pushToken(&result, TokenType_BinNumberLit, symbol);
            } else {
                String symbol = { .data = c.head - 1, .size = 1 };

                while(consumerGood(&c)) {
                    u8 nextByte = peekByte(&c);
                    if(!isDigit(nextByte)) {
                        break;
                    }

                    symbol.size += 1;
                    consumeByte(&c);
                }

                pushToken(&result, TokenType_NumberLit, symbol);
            }
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
            pushToken(&result, TokenType_LTick, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '>') {
            pushToken(&result, TokenType_RTick, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ':') {
            pushToken(&result, TokenType_Colon, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ';') {
            pushToken(&result, TokenType_Semicolon, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ',') {
            pushToken(&result, TokenType_Comma, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '.') {
            pushToken(&result, TokenType_Dot, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '!') {
            pushToken(&result, TokenType_Exclamation, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '+') {
            pushToken(&result, TokenType_Plus, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '-') {
            pushToken(&result, TokenType_Minus, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '%') {
            pushToken(&result, TokenType_Percent, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '*') {
            pushToken(&result, TokenType_Star, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '&') {
            pushToken(&result, TokenType_Ampersand, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '|') {
            pushToken(&result, TokenType_Pipe, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '^') {
            pushToken(&result, TokenType_Carrot, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '=') {
            pushToken(&result, TokenType_Equal, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '?') {
            pushToken(&result, TokenType_QuestionMark, (String){ .data = c.head - 1, .size = 1 });
        } else {
            assert((void *)false);
        }
    }

    return result;
}
