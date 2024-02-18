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
pushIdentifier(char **head, String string) {
    u32 result = 0;
    result += pushString(head, LIT_TO_STR("{\"type\":\"Identifier\",\"name\":\""));
    result += pushString(head, string);
    result += pushString(head, LIT_TO_STR("\"}"));
    return result;
}

static u32
pushASTNode(TokenizeResult tokens, char **head, ASTNode node) {
    u32 result = 0;

    Token pathToken = getToken(tokens, node.pathTokenId);

    result += pushString(head, LIT_TO_STR("{\"type\":\"ImportDirective\","));
    result += pushString(head, LIT_TO_STR("\"path\":\""));
    result += pushStringWithoutQuote(head, pathToken.string);
    result += pushString(head, LIT_TO_STR("\",\"pathLiteral\":"));
    result += pushStringLiteral(head, pathToken.string);

    result += pushString(head, LIT_TO_STR(",\"unitAlias\":"));
    if(node.unitAliasTokenId == INVALID_TOKEN_ID) {
        result += pushString(head, LIT_TO_STR("null"));
    } else {
        Token unitAlias = getToken(tokens, node.unitAliasTokenId);
        result += pushString(head, LIT_TO_STR("\""));
        result += pushString(head, unitAlias.string);
        result += pushString(head, LIT_TO_STR("\""));
    }
    result += pushString(head, LIT_TO_STR(",\"unitAliasIdentifier\":"));
    if(node.unitAliasTokenId == INVALID_TOKEN_ID) {
        result += pushString(head, LIT_TO_STR("null"));
    } else {
        Token unitAlias = getToken(tokens, node.unitAliasTokenId);
        result += pushIdentifier(head, unitAlias.string);
    }

    result += pushString(head, LIT_TO_STR(",\"symbolAliases\":"));
    if(node.symbols.count == 0) {
        result += pushString(head, LIT_TO_STR("null"));
    } else {
        result += pushString(head, LIT_TO_STR("["));
        for(u32 i = 0; i < node.symbols.count; i++) {
            result += pushString(head, LIT_TO_STR("[\""));

            TokenId symbol = listGetTokenId(&node.symbols, i);
            result += pushString(head, getToken(tokens, symbol).string);

            result += pushString(head, LIT_TO_STR("\","));

            TokenId alias = listGetTokenId(&node.symbolAliases, i);
            if(alias == INVALID_TOKEN_ID) {
                result += pushString(head, LIT_TO_STR("null"));
            } else {
                result += pushString(head, LIT_TO_STR("\""));
                result += pushString(head, getToken(tokens, alias).string);
                result += pushString(head, LIT_TO_STR("\""));
            }

            result += pushString(head, LIT_TO_STR("]"));
            if(i != node.symbols.count - 1) {
                result += pushString(head, LIT_TO_STR(","));
            }
        }
        result += pushString(head, LIT_TO_STR("]"));
    }

    result += pushString(head, LIT_TO_STR(",\"symbolAliasesIdentifiers\":"));
    if(node.symbols.count == 0) {
        result += pushString(head, LIT_TO_STR("null"));
    } else {
        result += pushString(head, LIT_TO_STR("["));
        for(u32 i = 0; i < node.symbols.count; i++) {
            result += pushString(head, LIT_TO_STR("["));

            TokenId symbol = listGetTokenId(&node.symbols, i);
            result += pushIdentifier(head, getToken(tokens, symbol).string);

            result += pushString(head, LIT_TO_STR(","));

            TokenId alias = listGetTokenId(&node.symbolAliases, i);
            if(alias != INVALID_TOKEN_ID) {
                result += pushIdentifier(head, getToken(tokens, alias).string);
            } else {
                result += pushString(head, LIT_TO_STR("null"));
            }

            result += pushString(head, LIT_TO_STR("]"));
            if(i != node.symbols.count - 1) {
                result += pushString(head, LIT_TO_STR(","));
            }
        }
        result += pushString(head, LIT_TO_STR("]"));
    }

    result += pushString(head, LIT_TO_STR("}"));

    return result;
};

static u32
pushSourceUnit(TokenizeResult tokens, char **head, ASTNode node) {
    u32 part1 = pushString(head, LIT_TO_STR("{")) +
        pushString(head, LIT_TO_STR("\"type\":\"SourceUnit\",")) +
        pushString(head, LIT_TO_STR("\"children\":["));
    u32 childrenSize = 0;

    ASTNodeLink *child = node.children.head;
    for(u32 i = 0; i < node.children.count; i++, child = child->next) {
        childrenSize += pushASTNode(tokens, head, child->node);
        if(i != node.children.count - 1) {
            childrenSize += pushString(head, LIT_TO_STR(","));
        }
    }
    u32 part2 = pushString(head, LIT_TO_STR("]}"));

    return part1 + childrenSize + part2;
}

static u32
calculateResultingSize(TokenizeResult tokens, ASTNode node) {
    u32 result = pushSourceUnit(tokens, 0x0, node);
    return result;
}

static String
astNodeToString(TokenizeResult tokens, ASTNode node, Arena *arena) {
    u32 size = calculateResultingSize(tokens, node);
    u8 *data = arrayPush(arena, u8, size);
    String result = { .data = data, .size = size };

    pushSourceUnit(tokens, (char **)&data, node);

    return result;
}

