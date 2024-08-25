#include "./src/engine/utils.c"
#include "./src/engine/tokenize.c"
#include "./src/engine/yulLexer.c"
#include "./src/engine/parser.c"

static String result = { 0 };

String *
entryPointBinaryInterface(const char *string, int len) {
    bumpPointerArenaTop = 0xffffffff;

    Arena arena = arenaCreate(len * 16, 32 * Kilobyte, 64);
    String input = neutralizeUnicode(string, len, &arena);

    TokenizeResult tokens = tokenize(input, &arena);
    Parser parser = createParser(tokens, &arena);
    ASTNode node = parseSourceUnit(&parser);

    Serializer s = createSerializer(&arena, input.data, tokens);
    result = serialize(&s, &node, len);

    memoryUsed = arenaTakenBytes(&arena);
    bumpPointerArenaTop = (unsigned int)structPush(&arena, int);

    return &result;
}
