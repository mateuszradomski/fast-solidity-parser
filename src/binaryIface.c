static u32
pushSourceUnit(TokenizeResult tokens, char **head, ASTNode node) {
    return 0;
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

