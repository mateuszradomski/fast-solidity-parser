#include "./src/utils.c"
#include "./src/tokenize.c"

static String result = { 0 };

const u32 Kilobyte = 1024;
const u32 Megabyte = Kilobyte * 1024;

String *
entry_point(const char *string, int len) {
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };
    TokenizeResult tokens = tokenize(input, &arena);

    result = LIT_TO_STR("Hello, World!");
    return &result;
}
