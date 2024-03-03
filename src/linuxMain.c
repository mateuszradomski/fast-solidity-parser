#include "./src/utils.c"
#include "./src/tokenize.c"
#include "./src/parser.c"

String entryPointBinaryInterface(const char *string, int len) {
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };

    TokenizeResult tokens = tokenize(input, &arena);
    Parser parser = createParser(tokens, &arena);
    ASTNode node = parseSourceUnit(&parser);

    Serializer s = createSerializer(&arena, string, tokens);
    return astNodeToBinary(&s, &node);
}

int main() {
    const char *str = "function helper(uint x) pure returns (uint) { min = min > max ? max : min; }";
    u32 length = strlen(str);

    String result = entryPointBinaryInterface(str, length);
}
