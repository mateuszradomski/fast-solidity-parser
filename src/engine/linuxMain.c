#include "./src/engine/utils.c"
#include "./src/engine/tokenize.c"
#include "./src/engine/yulLexer.c"
#include "./src/engine/parser.c"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
    const char *filepath = "tests/parserbuilding.sol";

    struct stat fileStat;
    int success = stat(filepath, &fileStat);
    assert(success == 0);

    u32 contentLength = fileStat.st_size;
    char *content = (char *)malloc(contentLength + 1);
    int fd = open(filepath, O_RDWR);
    read(fd, content, contentLength);
    close(fd);
    content[contentLength] = 0;
    printf("Content length = %u\n", contentLength);

    String result = entryPointBinaryInterface(content, contentLength);
    printf("Result size    = %zu\n", result.size);
}
