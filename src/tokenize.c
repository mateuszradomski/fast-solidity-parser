static const String LIBRARY_TOKEN = LIT_TO_STR("library");
static const String STRUCT_TOKEN = LIT_TO_STR("struct");
static const String PRIVATE_TOKEN = LIT_TO_STR("private");
static const String CONSTANT_TOKEN = LIT_TO_STR("constant");

typedef enum TokenType {
    TokenType_None,
    TokenType_Library,
    TokenType_Struct,
    TokenType_Private,
    TokenType_Constant,
    TokenType_Equal,
    TokenType_LBrace,
    TokenType_RBrace,
    TokenType_LParen,
    TokenType_RParen,
    TokenType_Semicolumn,
    TokenType_Symbol,
    TokenType_StringLit,
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
            } else if(stringMatch(symbol, STRUCT_TOKEN)) {
                javascriptPrintString("-> Struct");
                pushToken(&result, TokenType_Struct, symbol);
            } else if(stringMatch(symbol, PRIVATE_TOKEN)) {
                javascriptPrintString("-> private");
                pushToken(&result, TokenType_Private, symbol);
            } else if(stringMatch(symbol, CONSTANT_TOKEN)) {
                javascriptPrintString("-> constant");
                pushToken(&result, TokenType_Constant, symbol);
            } else {
                javascriptPrintString("-> Symbol");
                pushToken(&result, TokenType_Symbol, symbol);
            }
        } else if(byte == '/') {
            u8 nextByte = peekByte(&c);
            assert((void*)(nextByte == '/' || nextByte == '*'));

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
        } else if(byte == '{') {
            javascriptPrintString("-> Left brace");
            pushToken(&result, TokenType_LBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '}') {
            javascriptPrintString("-> Right brace");
            pushToken(&result, TokenType_RBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '(') {
            javascriptPrintString("-> Left paren");
            pushToken(&result, TokenType_RBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ')') {
            javascriptPrintString("-> Right paren");
            pushToken(&result, TokenType_RBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == ';') {
            javascriptPrintString("-> Semicolumn");
            pushToken(&result, TokenType_RBrace, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '=') {
            javascriptPrintString("-> Equal");
            pushToken(&result, TokenType_Equal, (String){ .data = c.head - 1, .size = 1 });
        }
    }

    return result;
}
