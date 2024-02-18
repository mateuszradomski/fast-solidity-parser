static u32
pushString(char **head, String string) {
    if(head) {
        memcpy(*head, string.data, string.size);
        *head += string.size;
    }

    return string.size;
}

static u32
pushStringWithoutQuote(char **head, String string) {
    string.data += 1;
    string.size -= 2;

    return pushString(head, string);
}

static u32
pushStringLiteral(char **head, String string) {
    u32 result = 0;
    result += pushString(head, LIT_TO_STR("{\"type\":\"StringLiteral\",\"value\":\""));
    result += pushStringWithoutQuote(head, string);
    result += pushString(head, LIT_TO_STR("\",\"parts\":[\""));
    result += pushStringWithoutQuote(head, string);
    result += pushString(head, LIT_TO_STR("\"],\"isUnicode\":[false]}"));
    return result;
}

static u32
pushASTNode(char **head, ASTNode node) {
    u32 result = 0;
    result += pushString(head, LIT_TO_STR("{\"type\":\"ImportDirective\","));
    result += pushString(head, LIT_TO_STR("\"path\":"));
    result += pushString(head, node.path);
    result += pushString(head, LIT_TO_STR(",\"pathLiteral\":"));
    result += pushStringLiteral(head, node.path);
    result += pushString(head, LIT_TO_STR(",\"unitAlias\":null,"));
    result += pushString(head, LIT_TO_STR("\"unitAliasIdentifier\":null,"));
    result += pushString(head, LIT_TO_STR("\"symbolAliases\":null,"));
    result += pushString(head, LIT_TO_STR("\"symbolAliasesIdentifiers\":null}"));
    return result;
};

static u32
pushSourceUnit(char **head, ASTNode node) {
    u32 part1 = pushString(head, LIT_TO_STR("{")) +
        pushString(head, LIT_TO_STR("\"type\":\"SourceUnit\",")) +
        pushString(head, LIT_TO_STR("\"children\":["));
    u32 childrenSize = 0;

    ASTNodeLink *child = node.children.head;
    for(u32 i = 0; i < node.children.count; i++, child = child->next) {
        childrenSize += pushASTNode(head, child->node);
        if(i != node.children.count - 1) {
            childrenSize += pushString(head, LIT_TO_STR(","));
        }
    }
    u32 part2 = pushString(head, LIT_TO_STR("]}"));

    return part1 + childrenSize + part2;
}

static u32
calculateResultingSize(ASTNode node) {
    u32 result = pushSourceUnit(0x0, node);
    return result;
}

static String
astNodeToString(ASTNode node, Arena *arena) {
    u32 size = calculateResultingSize(node);
    u8 *data = arrayPush(arena, u8, size);
    String result = { .data = data, .size = size };

    pushSourceUnit((char **)&data, node);

    return result;
}

