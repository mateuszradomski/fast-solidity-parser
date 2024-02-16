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

static TokenizeResult
allocateTokenSpace(Arena *arena, u32 capacity) {
    TokenizeResult result = {0};
    result.tokens = arrayPush(arena, Token, capacity);
    result.capacity = capacity;
    return result;
}

static void
pushToken(TokenizeResult *result, TokenType tokenType, String string) {
    assert((void *)(result->count < result->capacity));

    javascriptPrintStringPtr(&string);

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
                javascriptPrintString("-> Library");
                pushToken(&result, TokenType_Library, symbol);
            } else if(stringMatch(symbol, CONTRACT_TOKEN)) {
                javascriptPrintString("-> Contract");
                pushToken(&result, TokenType_Contract, symbol);
            } else if(stringMatch(symbol, ABSTRACT_TOKEN)) {
                javascriptPrintString("-> Abstract");
                pushToken(&result, TokenType_Abstract, symbol);
            } else if(stringMatch(symbol, INTERFACE_TOKEN)) {
                javascriptPrintString("-> Interface");
                pushToken(&result, TokenType_Interface, symbol);
            } else if(stringMatch(symbol, STRUCT_TOKEN)) {
                javascriptPrintString("-> Struct");
                pushToken(&result, TokenType_Struct, symbol);
            } else if(stringMatch(symbol, PRIVATE_TOKEN)) {
                javascriptPrintString("-> private");
                pushToken(&result, TokenType_Private, symbol);
            } else if(stringMatch(symbol, IMMUTABLE_TOKEN)) {
                javascriptPrintString("-> immutable");
                pushToken(&result, TokenType_Immutable, symbol);
            } else if(stringMatch(symbol, CONSTANT_TOKEN)) {
                javascriptPrintString("-> constant");
                pushToken(&result, TokenType_Constant, symbol);
            } else if(stringMatch(symbol, FUNCTION_TOKEN)) {
                javascriptPrintString("-> function");
                pushToken(&result, TokenType_Function, symbol);
            } else if(stringMatch(symbol, INTERNAL_TOKEN)) {
                javascriptPrintString("-> internal");
                pushToken(&result, TokenType_Internal, symbol);
            } else if(stringMatch(symbol, PURE_TOKEN)) {
                javascriptPrintString("-> pure");
                pushToken(&result, TokenType_Pure, symbol);
            } else if(stringMatch(symbol, PAYABLE_TOKEN)) {
                javascriptPrintString("-> payable");
                pushToken(&result, TokenType_Payable, symbol);
            } else if(stringMatch(symbol, RETURN_TOKEN)) {
                javascriptPrintString("-> return");
                pushToken(&result, TokenType_Return, symbol);
            } else if(stringMatch(symbol, RETURNS_TOKEN)) {
                javascriptPrintString("-> returns");
                pushToken(&result, TokenType_Returns, symbol);
            } else if(stringMatch(symbol, MEMORY_TOKEN)) {
                javascriptPrintString("-> memory");
                pushToken(&result, TokenType_Memory, symbol);
            } else if(stringMatch(symbol, WHILE_TOKEN)) {
                javascriptPrintString("-> while");
                pushToken(&result, TokenType_While, symbol);
            } else if(stringMatch(symbol, FOR_TOKEN)) {
                javascriptPrintString("-> for");
                pushToken(&result, TokenType_For, symbol);
            } else if(stringMatch(symbol, NEW_TOKEN)) {
                javascriptPrintString("-> new");
                pushToken(&result, TokenType_New, symbol);
            } else {
                javascriptPrintString("-> Symbol");
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

                javascriptPrintString("-> Comment");
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

                javascriptPrintString("-> Comment");
                pushToken(&result, TokenType_Comment, symbol);
            } else {
                String symbol = { .data = c.head - 1, .size = 1 };
                javascriptPrintString("-> Divide");
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

            javascriptPrintString("-> StringLit");
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

                javascriptPrintString("-> HexNumberLit");
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

                javascriptPrintString("-> BinNumberLit");
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

                javascriptPrintString("-> NumberLit");
                pushToken(&result, TokenType_NumberLit, symbol);
            }
        } else if(byte == '[') {
            javascriptPrintString("-> Left bracket");
            pushToken(&result, TokenType_LBracket, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ']') {
            javascriptPrintString("-> Right bracket");
            pushToken(&result, TokenType_RBracket, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '{') {
            javascriptPrintString("-> Left brace");
            pushToken(&result, TokenType_LBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '}') {
            javascriptPrintString("-> Right brace");
            pushToken(&result, TokenType_RBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '(') {
            javascriptPrintString("-> Left paren");
            pushToken(&result, TokenType_LParen, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ')') {
            javascriptPrintString("-> Right paren");
            pushToken(&result, TokenType_RParen, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '<') {
            javascriptPrintString("-> Left tick");
            pushToken(&result, TokenType_LTick, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '>') {
            javascriptPrintString("-> Right tick");
            pushToken(&result, TokenType_RTick, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ':') {
            javascriptPrintString("-> Colon");
            pushToken(&result, TokenType_Colon, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ';') {
            javascriptPrintString("-> Semicolon");
            pushToken(&result, TokenType_Semicolon, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ',') {
            javascriptPrintString("-> Comma");
            pushToken(&result, TokenType_Comma, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '.') {
            javascriptPrintString("-> Dot");
            pushToken(&result, TokenType_Dot, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '!') {
            javascriptPrintString("-> Exclamation");
            pushToken(&result, TokenType_Exclamation, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '+') {
            javascriptPrintString("-> Plus");
            pushToken(&result, TokenType_Plus, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '-') {
            javascriptPrintString("-> Minus");
            pushToken(&result, TokenType_Minus, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '%') {
            javascriptPrintString("-> Percent");
            pushToken(&result, TokenType_Percent, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '*') {
            javascriptPrintString("-> Star");
            pushToken(&result, TokenType_Star, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '&') {
            javascriptPrintString("-> Ampersand");
            pushToken(&result, TokenType_Ampersand, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '|') {
            javascriptPrintString("-> Pipe");
            pushToken(&result, TokenType_Pipe, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '^') {
            javascriptPrintString("-> Carrot");
            pushToken(&result, TokenType_Carrot, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '=') {
            javascriptPrintString("-> Equal");
            pushToken(&result, TokenType_Equal, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '?') {
            javascriptPrintString("-> QuestionMark");
            pushToken(&result, TokenType_QuestionMark, (String){ .data = c.head - 1, .size = 1 });
        } else {
            assert((void *)false);
        }
    }

    return result;
}
