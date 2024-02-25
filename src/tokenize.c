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
static const String IMPORT_TOKEN = LIT_TO_STR("import");
static const String AS_TOKEN = LIT_TO_STR("as");
static const String IS_TOKEN = LIT_TO_STR("is");
static const String FROM_TOKEN = LIT_TO_STR("from");
static const String EXTERNAL_TOKEN = LIT_TO_STR("external");
static const String VIEW_TOKEN = LIT_TO_STR("view");
static const String PUBLIC_TOKEN = LIT_TO_STR("public");
static const String OVERRIDE_TOKEN = LIT_TO_STR("override");
static const String VIRTUAL_TOKEN = LIT_TO_STR("virtual");
static const String MODIFIER_TOKEN = LIT_TO_STR("modifier");
static const String FALLBACK_TOKEN = LIT_TO_STR("fallback");
static const String RECEIVE_TOKEN = LIT_TO_STR("receive");
static const String ENUM_TOKEN = LIT_TO_STR("enum");
static const String TYPE_TOKEN = LIT_TO_STR("type");
static const String INDEXED_TOKEN = LIT_TO_STR("indexed");
static const String EVENT_TOKEN = LIT_TO_STR("event");
static const String ANONYMOUS_TOKEN = LIT_TO_STR("anonymous");
static const String ERROR_TOKEN = LIT_TO_STR("error");
static const String USING_TOKEN = LIT_TO_STR("using");
static const String GLOBAL_TOKEN = LIT_TO_STR("global");
static const String DELETE_TOKEN = LIT_TO_STR("delete");
static const String TRUE_TOKEN = LIT_TO_STR("true");
static const String FALSE_TOKEN = LIT_TO_STR("false");
static const String UNCHECKED_TOKEN = LIT_TO_STR("unchecked");
static const String IF_TOKEN = LIT_TO_STR("if");
static const String ELSE_TOKEN = LIT_TO_STR("else");
static const String DO_TOKEN = LIT_TO_STR("do");
static const String CONTINUE_TOKEN = LIT_TO_STR("continue");
static const String BREAK_TOKEN = LIT_TO_STR("break");
static const String TRY_TOKEN = LIT_TO_STR("try");
static const String CATCH_TOKEN = LIT_TO_STR("catch");
static const String EMIT_TOKEN = LIT_TO_STR("emit");
static const String REVERT_TOKEN = LIT_TO_STR("revert");
static const String ASSEMBLY_TOKEN = LIT_TO_STR("assembly");
static const String PRAGMA_TOKEN = LIT_TO_STR("pragma");
static const String MAPPING_TOKEN = LIT_TO_STR("mapping");
static const String STORAGE_TOKEN = LIT_TO_STR("storage");
static const String CALLDATA_TOKEN = LIT_TO_STR("calldata");
static const String WEI_TOKEN = LIT_TO_STR("wei");
static const String GWEI_TOKEN = LIT_TO_STR("gwei");
static const String ETHER_TOKEN = LIT_TO_STR("ether");
static const String SECONDS_TOKEN = LIT_TO_STR("seconds");
static const String MINUTES_TOKEN = LIT_TO_STR("minutes");
static const String HOURS_TOKEN = LIT_TO_STR("hours");
static const String DAYS_TOKEN = LIT_TO_STR("days");
static const String WEEKS_TOKEN = LIT_TO_STR("weeks");
static const String YEARS_TOKEN = LIT_TO_STR("years");

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
    TokenType_EqualEqual,
    TokenType_NotEqual,
    TokenType_LogicalAnd,
    TokenType_LogicalOr,
    TokenType_QuestionMark,
    TokenType_Equal,
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
    TokenType_NumberLit,
    TokenType_HexNumberLit,
    TokenType_BinNumberLit,
    TokenType_Comment,
    TokenType_EOF,
    TokenType_Count,
} TokenType;

#define INVALID_TOKEN_ID (-1)
typedef s32 TokenId;

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
        case TokenType_Equal: return LIT_TO_STR("Equal");
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
        case TokenType_NumberLit: return LIT_TO_STR("NumberLit");
        case TokenType_HexNumberLit: return LIT_TO_STR("HexNumberLit");
        case TokenType_BinNumberLit: return LIT_TO_STR("BinNumberLit");
        case TokenType_Comment: return LIT_TO_STR("Comment");
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

    //printToken(tokenType, string);

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
            } else if(stringMatch(symbol, IMPORT_TOKEN)) {
                pushToken(&result, TokenType_Import, symbol);
            } else if(stringMatch(symbol, AS_TOKEN)) {
                pushToken(&result, TokenType_As, symbol);
            } else if(stringMatch(symbol, IS_TOKEN)) {
                pushToken(&result, TokenType_Is, symbol);
            } else if(stringMatch(symbol, FROM_TOKEN)) {
                pushToken(&result, TokenType_From, symbol);
            } else if(stringMatch(symbol, EXTERNAL_TOKEN)) {
                pushToken(&result, TokenType_External, symbol);
            } else if(stringMatch(symbol, VIEW_TOKEN)) {
                pushToken(&result, TokenType_View, symbol);
            } else if(stringMatch(symbol, PUBLIC_TOKEN)) {
                pushToken(&result, TokenType_Public, symbol);
            } else if(stringMatch(symbol, OVERRIDE_TOKEN)) {
                pushToken(&result, TokenType_Override, symbol);
            } else if(stringMatch(symbol, VIRTUAL_TOKEN)) {
                pushToken(&result, TokenType_Virtual, symbol);
            } else if(stringMatch(symbol, MODIFIER_TOKEN)) {
                pushToken(&result, TokenType_Modifier, symbol);
            } else if(stringMatch(symbol, FALLBACK_TOKEN)) {
                pushToken(&result, TokenType_Fallback, symbol);
            } else if(stringMatch(symbol, RECEIVE_TOKEN)) {
                pushToken(&result, TokenType_Receive, symbol);
            } else if(stringMatch(symbol, ENUM_TOKEN)) {
                pushToken(&result, TokenType_Enum, symbol);
            } else if(stringMatch(symbol, TYPE_TOKEN)) {
                pushToken(&result, TokenType_Type, symbol);
            } else if(stringMatch(symbol, INDEXED_TOKEN)) {
                pushToken(&result, TokenType_Indexed, symbol);
            } else if(stringMatch(symbol, EVENT_TOKEN)) {
                pushToken(&result, TokenType_Event, symbol);
            } else if(stringMatch(symbol, ANONYMOUS_TOKEN)) {
                pushToken(&result, TokenType_Anonymous, symbol);
            } else if(stringMatch(symbol, ERROR_TOKEN)) {
                pushToken(&result, TokenType_Error, symbol);
            } else if(stringMatch(symbol, USING_TOKEN)) {
                pushToken(&result, TokenType_Using, symbol);
            } else if(stringMatch(symbol, GLOBAL_TOKEN)) {
                pushToken(&result, TokenType_Global, symbol);
            } else if(stringMatch(symbol, DELETE_TOKEN)) {
                pushToken(&result, TokenType_Delete, symbol);
            } else if(stringMatch(symbol, TRUE_TOKEN)) {
                pushToken(&result, TokenType_True, symbol);
            } else if(stringMatch(symbol, FALSE_TOKEN)) {
                pushToken(&result, TokenType_False, symbol);
            } else if(stringMatch(symbol, UNCHECKED_TOKEN)) {
                pushToken(&result, TokenType_Unchecked, symbol);
            } else if(stringMatch(symbol, IF_TOKEN)) {
                pushToken(&result, TokenType_If, symbol);
            } else if(stringMatch(symbol, ELSE_TOKEN)) {
                pushToken(&result, TokenType_Else, symbol);
            } else if(stringMatch(symbol, DO_TOKEN)) {
                pushToken(&result, TokenType_Do, symbol);
            } else if(stringMatch(symbol, CONTINUE_TOKEN)) {
                pushToken(&result, TokenType_Continue, symbol);
            } else if(stringMatch(symbol, BREAK_TOKEN)) {
                pushToken(&result, TokenType_Break, symbol);
            } else if(stringMatch(symbol, TRY_TOKEN)) {
                pushToken(&result, TokenType_Try, symbol);
            } else if(stringMatch(symbol, CATCH_TOKEN)) {
                pushToken(&result, TokenType_Catch, symbol);
            } else if(stringMatch(symbol, EMIT_TOKEN)) {
                pushToken(&result, TokenType_Emit, symbol);
            } else if(stringMatch(symbol, REVERT_TOKEN)) {
                pushToken(&result, TokenType_Revert, symbol);
            } else if(stringMatch(symbol, ASSEMBLY_TOKEN)) {
                pushToken(&result, TokenType_Assembly, symbol);
            } else if(stringMatch(symbol, PRAGMA_TOKEN)) {
                pushToken(&result, TokenType_Pragma, symbol);
            } else if(stringMatch(symbol, MAPPING_TOKEN)) {
                pushToken(&result, TokenType_Mapping, symbol);
            } else if(stringMatch(symbol, STORAGE_TOKEN)) {
                pushToken(&result, TokenType_Storage, symbol);
            } else if(stringMatch(symbol, CALLDATA_TOKEN)) {
                pushToken(&result, TokenType_Calldata, symbol);
            } else if(stringMatch(symbol, WEI_TOKEN)) {
                pushToken(&result, TokenType_Wei, symbol);
            } else if(stringMatch(symbol, GWEI_TOKEN)) {
                pushToken(&result, TokenType_Gwei, symbol);
            } else if(stringMatch(symbol, ETHER_TOKEN)) {
                pushToken(&result, TokenType_Ether, symbol);
            } else if(stringMatch(symbol, SECONDS_TOKEN)) {
                pushToken(&result, TokenType_Seconds, symbol);
            } else if(stringMatch(symbol, MINUTES_TOKEN)) {
                pushToken(&result, TokenType_Minutes, symbol);
            } else if(stringMatch(symbol, HOURS_TOKEN)) {
                pushToken(&result, TokenType_Hours, symbol);
            } else if(stringMatch(symbol, DAYS_TOKEN)) {
                pushToken(&result, TokenType_Days, symbol);
            } else if(stringMatch(symbol, WEEKS_TOKEN)) {
                pushToken(&result, TokenType_Weeks, symbol);
            } else if(stringMatch(symbol, YEARS_TOKEN)) {
                pushToken(&result, TokenType_Years, symbol);
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
            String symbol = { .data = c.head, .size = 0 };
            while(consumerGood(&c)) {
                u8 nextByte = consumeByte(&c);
                if(nextByte == '"') {
                    break;
                }

                symbol.size += 1;
            }

            pushToken(&result, TokenType_StringLit, symbol);
        } else if(byte == '\'') {
            String symbol = { .data = c.head, .size = 0 };
            while(consumerGood(&c)) {
                u8 nextByte = consumeByte(&c);
                if(nextByte == '\'') {
                    break;
                }

                symbol.size += 1;
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

                if(peekByte(&c) == '.') {
                    symbol.size += 1;
                    consumeByte(&c);
                }

                while(consumerGood(&c)) {
                    u8 nextByte = peekByte(&c);
                    if(!(isDigit(nextByte) || nextByte == '_')) {
                        break;
                    }

                    symbol.size += 1;
                    consumeByte(&c);
                }

                if(peekByte(&c) == 'e' || peekByte(&c) == 'E') {
                    symbol.size += 1;
                    consumeByte(&c);

                    if(peekByte(&c) == '-') {
                        symbol.size += 1;
                        consumeByte(&c);
                    }

                    while(consumerGood(&c)) {
                        u8 nextByte = peekByte(&c);
                        if(isDigit(nextByte) || nextByte == '_') {
                            symbol.size += 1;
                            consumeByte(&c);
                        } else {
                            break;
                        }
                    }
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
            u8 nextByte = peekByte(&c);
            if(nextByte == '<') {
                consumeByte(&c);
                pushToken(&result, TokenType_LeftShift, (String){ .data = c.head - 2, .size = 2 });
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
                } else {
                    pushToken(&result, TokenType_RightShift, (String){ .data = c.head - 2, .size = 2 });
                }
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
            pushToken(&result, TokenType_Dot, (String){ .data = c.head - 1, .size = 1 });
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
            } else {
                pushToken(&result, TokenType_Plus, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '-') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '-') {
                consumeByte(&c);
                pushToken(&result, TokenType_MinusMinus, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Minus, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '%') {
            pushToken(&result, TokenType_Percent, (String){ .data = c.head - 1, .size = 1 });
        } else if(byte == '*') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '*') {
                consumeByte(&c);
                pushToken(&result, TokenType_StarStar, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Star, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '&') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '&') {
                consumeByte(&c);
                pushToken(&result, TokenType_LogicalAnd, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Ampersand, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '|') {
            u8 nextByte = peekByte(&c);
            if(nextByte == '|') {
                consumeByte(&c);
                pushToken(&result, TokenType_LogicalOr, (String){ .data = c.head - 2, .size = 2 });
            } else {
                pushToken(&result, TokenType_Pipe, (String){ .data = c.head - 1, .size = 1 });
            }
        } else if(byte == '^') {
            pushToken(&result, TokenType_Carrot, (String){ .data = c.head - 1, .size = 1 });
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
            assert(false);
        }
    }

    pushToken(&result, TokenType_EOF, (String){0});

    return result;
}
