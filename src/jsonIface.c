static u32
pushStringJSON(char **head, String string) {
    if(head) {
        memcpy(*head, string.data, string.size);
        *head += string.size;
    }

    return string.size;
}

static u32
pushStringWithoutQuoteJSON(char **head, String string) {
    string.data += 1;
    string.size -= 2;

    return pushStringJSON(head, string);
}

static u32
pushStringLiteralJSON(char **head, String string) {
    u32 result = 0;
    result += pushStringJSON(head, LIT_TO_STR("{\"type\":\"StringLiteral\",\"value\":\""));
    result += pushStringWithoutQuoteJSON(head, string);
    result += pushStringJSON(head, LIT_TO_STR("\",\"parts\":[\""));
    result += pushStringWithoutQuoteJSON(head, string);
    result += pushStringJSON(head, LIT_TO_STR("\"],\"isUnicode\":[false]}"));
    return result;
}

static u32
pushIdentifierJSON(char **head, String string) {
    u32 result = 0;
    result += pushStringJSON(head, LIT_TO_STR("{\"type\":\"Identifier\",\"name\":\""));
    result += pushStringJSON(head, string);
    result += pushStringJSON(head, LIT_TO_STR("\"}"));
    return result;
}

static u32
pushASTNodeJSON(TokenizeResult tokens, char **head, ASTNode node) {
    u32 result = 0;

    Token pathToken = getToken(tokens, node.pathTokenId);

    result += pushStringJSON(head, LIT_TO_STR("{\"type\":\"ImportDirective\","));
    result += pushStringJSON(head, LIT_TO_STR("\"path\":\""));
    result += pushStringWithoutQuoteJSON(head, pathToken.string);
    result += pushStringJSON(head, LIT_TO_STR("\",\"pathLiteral\":"));
    result += pushStringLiteralJSON(head, pathToken.string);

    result += pushStringJSON(head, LIT_TO_STR(",\"unitAlias\":"));
    if(node.unitAliasTokenId == INVALID_TOKEN_ID) {
        result += pushStringJSON(head, LIT_TO_STR("null"));
    } else {
        Token unitAlias = getToken(tokens, node.unitAliasTokenId);
        result += pushStringJSON(head, LIT_TO_STR("\""));
        result += pushStringJSON(head, unitAlias.string);
        result += pushStringJSON(head, LIT_TO_STR("\""));
    }
    result += pushStringJSON(head, LIT_TO_STR(",\"unitAliasIdentifier\":"));
    if(node.unitAliasTokenId == INVALID_TOKEN_ID) {
        result += pushStringJSON(head, LIT_TO_STR("null"));
    } else {
        Token unitAlias = getToken(tokens, node.unitAliasTokenId);
        result += pushIdentifierJSON(head, unitAlias.string);
    }

    result += pushStringJSON(head, LIT_TO_STR(",\"symbolAliases\":"));
    if(node.symbols.count == 0) {
        result += pushStringJSON(head, LIT_TO_STR("null"));
    } else {
        result += pushStringJSON(head, LIT_TO_STR("["));
        for(u32 i = 0; i < node.symbols.count; i++) {
            result += pushStringJSON(head, LIT_TO_STR("[\""));

            TokenId symbol = listGetTokenId(&node.symbols, i);
            result += pushStringJSON(head, getToken(tokens, symbol).string);

            result += pushStringJSON(head, LIT_TO_STR("\","));

            TokenId alias = listGetTokenId(&node.symbolAliases, i);
            if(alias == INVALID_TOKEN_ID) {
                result += pushStringJSON(head, LIT_TO_STR("null"));
            } else {
                result += pushStringJSON(head, LIT_TO_STR("\""));
                result += pushStringJSON(head, getToken(tokens, alias).string);
                result += pushStringJSON(head, LIT_TO_STR("\""));
            }

            result += pushStringJSON(head, LIT_TO_STR("]"));
            if(i != node.symbols.count - 1) {
                result += pushStringJSON(head, LIT_TO_STR(","));
            }
        }
        result += pushStringJSON(head, LIT_TO_STR("]"));
    }

    result += pushStringJSON(head, LIT_TO_STR(",\"symbolAliasesIdentifiers\":"));
    if(node.symbols.count == 0) {
        result += pushStringJSON(head, LIT_TO_STR("null"));
    } else {
        result += pushStringJSON(head, LIT_TO_STR("["));
        for(u32 i = 0; i < node.symbols.count; i++) {
            result += pushStringJSON(head, LIT_TO_STR("["));

            TokenId symbol = listGetTokenId(&node.symbols, i);
            result += pushIdentifierJSON(head, getToken(tokens, symbol).string);

            result += pushStringJSON(head, LIT_TO_STR(","));

            TokenId alias = listGetTokenId(&node.symbolAliases, i);
            if(alias != INVALID_TOKEN_ID) {
                result += pushIdentifierJSON(head, getToken(tokens, alias).string);
            } else {
                result += pushStringJSON(head, LIT_TO_STR("null"));
            }

            result += pushStringJSON(head, LIT_TO_STR("]"));
            if(i != node.symbols.count - 1) {
                result += pushStringJSON(head, LIT_TO_STR(","));
            }
        }
        result += pushStringJSON(head, LIT_TO_STR("]"));
    }

    result += pushStringJSON(head, LIT_TO_STR("}"));

    return result;
};

static u32
pushSourceUnitJSON(TokenizeResult tokens, char **head, ASTNode node) {
    u32 part1 = pushStringJSON(head, LIT_TO_STR("{")) +
        pushStringJSON(head, LIT_TO_STR("\"type\":\"SourceUnit\",")) +
        pushStringJSON(head, LIT_TO_STR("\"children\":["));
    u32 childrenSize = 0;

    ASTNodeLink *child = node.children.head;
    for(u32 i = 0; i < node.children.count; i++, child = child->next) {
        childrenSize += pushASTNodeJSON(tokens, head, child->node);
        if(i != node.children.count - 1) {
            childrenSize += pushStringJSON(head, LIT_TO_STR(","));
        }
    }
    u32 part2 = pushStringJSON(head, LIT_TO_STR("]}"));

    return part1 + childrenSize + part2;
}

static u32
calculateResultingSizeJSON(TokenizeResult tokens, ASTNode node) {
    u32 result = pushSourceUnitJSON(tokens, 0x0, node);
    return result;
}

static String
astNodeToString(TokenizeResult tokens, ASTNode node, Arena *arena) {
    u32 size = calculateResultingSizeJSON(tokens, node);
    u8 *data = arrayPush(arena, u8, size);
    String result = { .data = data, .size = size };

    pushSourceUnitJSON(tokens, (char **)&data, node);

    return result;
}

