#include "./src/utils.c"
#include "./src/tokenize.c"
#include "./src/parser.c"

static String result = { 0 };

String *
entryPointJSONInterface(const char *string, int len) {
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };
    TokenizeResult tokens = tokenize(input, &arena);
    Parser parser = createParser(tokens, &arena);
    ASTNode node = parseSourceUnit(&parser);
    result = astNodeToString(tokens, node, &arena);

    return &result;
}

String *
entryPointBinaryInterface(const char *string, int len) {
    traceBegin(1);
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };
    traceEnd();

    traceBegin(2);
    TokenizeResult tokens = tokenize(input, &arena);
    traceEnd();
    traceBegin(3);
    Parser parser = createParser(tokens, &arena);
    ASTNode node = parseSourceUnit(&parser);
    traceEnd();

    traceBegin(4);
    Serializer s = createSerializer(&arena, string, tokens);
    result = astNodeToBinary(&s, &node);
    traceEnd();

    return &result;
}
