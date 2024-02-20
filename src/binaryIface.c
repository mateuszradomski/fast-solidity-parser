static u32
pushU32(char **head, u32 value) {
    if(head) {
        u32 *ptr = (u32 *)*head;
        *ptr = value;
        *head += sizeof(u32);
    }

    return sizeof(u32);
}

static u32
pushTokenStringById(char **head, TokenizeResult tokens, TokenId token) {
    if(head) {
        if(token == INVALID_TOKEN_ID) {
            pushU32(head, INVALID_TOKEN_ID);
            pushU32(head, 0);
        } else {
            Token t = getToken(tokens, token);
            pushU32(head, (u32)t.string.data);
            pushU32(head, (u32)t.string.size);
        }
    }

    return 2 * sizeof(u32);
}

static u32
pushImportDirective(TokenizeResult tokens, char **head, ASTNode node) {
    u32 l = 0;

    l += pushTokenStringById(head, tokens, node.pathTokenId);
    l += pushTokenStringById(head, tokens, node.unitAliasTokenId);

    l += pushU32(head, node.symbols.count);
    for(u32 i = 0; i < node.symbols.count; i++) {
        // PERF-NOTE(radomski): we could pull out pushing a token string just
        // by itself since we know that the token here is never going to be
        // invalid. But in pushTokenStringById we have to check for invalid
        // which is additional overhead.

        TokenId symbol = listGetTokenId(&node.symbols, i);
        TokenId alias = listGetTokenId(&node.symbolAliases, i);
        l += pushTokenStringById(head, tokens, symbol);
        l += pushTokenStringById(head, tokens, alias);
    }

    return l;
}

static u32
pushASTNode(TokenizeResult tokens, char **head, ASTNode node) {
    u32 l = 0;

    switch(node.type) {
        case ASTNodeType_Import: {
            l = pushImportDirective(tokens, head, node);
        } break;
        default: {
            assert(0);
        } break;
    }

    return l;
};

static u32
pushSourceUnit(TokenizeResult tokens, char **head, ASTNode node) {
    u32 l = 0;

    l += pushU32(head, node.type);
    l += pushU32(head, node.children.count);

    ASTNodeLink *child = node.children.head;
    for(u32 i = 0; i < node.children.count; i++, child = child->next) {
        l += pushASTNode(tokens, head, child->node);
    }

    return l;
}

static u32
calculateResultingSize(TokenizeResult tokens, ASTNode node) {
    u32 result = pushSourceUnit(tokens, 0x0, node);
    return result;
}

static String
astNodeToBinary(TokenizeResult tokens, ASTNode node, Arena *arena) {
    u32 size = calculateResultingSize(tokens, node);
    u8 *data = arrayPush(arena, u8, size);
    String result = { .data = data, .size = size };

    pushSourceUnit(tokens, (char **)&data, node);

    return result;
}

