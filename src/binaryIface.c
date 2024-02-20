typedef struct Serializer {
    Arena *arena;
    TokenizeResult tokens;
    const u8 *inputStringBase;
    char **head;
} Serializer;

static Serializer
createSerializer(Arena *arena, const void *inputStringBase, TokenizeResult tokens) {
    Serializer s = {
        .arena = arena,
        .tokens = tokens,
        .inputStringBase = (const u8 *)inputStringBase,
        .head = 0x0,
    };

    return s;
}

static u32
pushU32(Serializer *s, u32 value) {
    if(s->head) {
        u32 *ptr = (u32 *)*s->head;
        *ptr = value;
        *s->head += sizeof(u32);
    }

    return sizeof(u32);
}

static u32
pushTokenStringById(Serializer *s, TokenId token) {
    if(s->head) {
        if(token == INVALID_TOKEN_ID) {
            pushU32(s, INVALID_TOKEN_ID);
            pushU32(s, 0);
        } else {
            Token t = getToken(s->tokens, token);
            pushU32(s, (u32)(t.string.data - s->inputStringBase));
            pushU32(s, (u32)t.string.size);
        }
    }

    return 2 * sizeof(u32);
}

static u32
pushImportDirective(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    l += pushTokenStringById(s, node.pathTokenId);
    l += pushTokenStringById(s, node.unitAliasTokenId);

    l += pushU32(s, node.symbols.count);
    for(u32 i = 0; i < node.symbols.count; i++) {
        // PERF-NOTE(radomski): we could pull out pushing a token string just
        // by itself since we know that the token here is never going to be
        // invalid. But in pushTokenStringById we have to check for invalid
        // which is additional overhead.

        TokenId symbol = listGetTokenId(&node.symbols, i);
        TokenId alias = listGetTokenId(&node.symbolAliases, i);
        l += pushTokenStringById(s, symbol);
        l += pushTokenStringById(s, alias);
    }

    return l;
}

static u32
pushASTNode(Serializer *s, ASTNode node) {
    u32 l = 0;

    switch(node.type) {
        case ASTNodeType_Import: {
            l = pushImportDirective(s, node);
        } break;
        default: {
            assert(0);
        } break;
    }

    return l;
};

static u32
pushSourceUnit(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    l += pushU32(s, node.children.count);

    ASTNodeLink *child = node.children.head;
    for(u32 i = 0; i < node.children.count; i++, child = child->next) {
        l += pushASTNode(s, child->node);
    }

    return l;
}

static u32
calculateResultingSize(Serializer *s, ASTNode node) {
    assert(s->head == 0x0);
    u32 result = pushSourceUnit(s, node);
    return result;
}

static String
astNodeToBinary(Serializer *s, ASTNode node) {
    u32 size = calculateResultingSize(s, node);
    u8 *data = arrayPush(s->arena, u8, size);
    String result = { .data = data, .size = size };
    s->head = (char **)&data;

    pushSourceUnit(s, node);

    return result;
}

