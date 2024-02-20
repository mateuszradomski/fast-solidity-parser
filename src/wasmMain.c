#include "./src/utils.c"
#include "./src/tokenize.c"
#include "./src/parser.c"

String *
entryPointJSONInterface(const char *string, int len) {
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };
    TokenizeResult tokens = tokenize(input, &arena);
    Parser parser = createParser(tokens);
    ASTNode node = parseSourceUnit(&parser, &arena);
    result = astNodeToString(tokens, node, &arena);

    return &result;
}

String *
entryPointBinaryInterface(const char *string, int len) {
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };
    TokenizeResult tokens = tokenize(input, &arena);
    Parser parser = createParser(tokens);
    ASTNode node = parseSourceUnit(&parser, &arena);

    Serializer s = createSerializer(&arena, string, tokens);
    result = astNodeToBinary(&s, node);

    return &result;
}
