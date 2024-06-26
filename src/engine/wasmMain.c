#include "./src/engine/utils.c"
#include "./src/engine/tokenize.c"
#include "./src/engine/yulLexer.c"
#include "./src/engine/parser.c"

static String result = { 0 };

String *
entryPointBinaryInterface(const char *string, int len) {
    bumpPointerArenaTop = 0xffffffff;

    traceBegin(1);
    Arena arena = arenaCreate(len * 16, 32 * Kilobyte, 64);
    traceEnd();

    traceBegin(2);
    String input = neutralizeUnicode(string, len, &arena);
    traceEnd();

    traceBegin(3);
    TokenizeResult tokens = tokenize(input, &arena);
    traceEnd();
    traceBegin(4);
    Parser parser = createParser(tokens, &arena);
    ASTNode node = parseSourceUnit(&parser);
    traceEnd();

    traceBegin(5);
    Serializer s = createSerializer(&arena, input.data, tokens);
    result = astNodeToBinary(&s, &node);
    traceEnd();

    memoryUsed = arenaTakenBytes(&arena);
    bumpPointerArenaTop = (unsigned int)structPush(&arena, int);

    return &result;
}
