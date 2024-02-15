#include "./src/utils.c"
#include "./src/tokenize.c"

typedef struct String {
    char *data;
    int len;
} String;

static char buffer[128] = { 0 };
static String result = { 0 };

#define LIT_TO_STR(x) ((String){ .data = x, .len = sizeof(x) - 1 })

String *
entry_point(const char *string, int len) {
    String input = { .data = (char *)string, .len = len };

    result = LIT_TO_STR("Hello, World!");
    return &result;
}
