static String result = { 0 };

typedef enum ASTNodeType_Enum {
    ASTNodeType_None,
    ASTNodeType_SourceUnit,
    ASTNodeType_Import,
    ASTNodeType_EnumDefinition,
    ASTNodeType_Struct,
    ASTNodeType_Count,
} ASTNodeType_Enum;

typedef u32 ASTNodeType;

typedef struct ASTNodeLink ASTNodeLink;

typedef struct ASTNodeList {
    ASTNodeLink *head;
    ASTNodeLink *last;
    u32 count;
} ASTNodeList;

typedef struct ASTNodeStruct {
    TokenId nameTokenId;
    TokenIdList memberTypes;
    TokenIdList memberNames;
} ASTNodeStruct;

typedef struct ASTNode {
    ASTNodeType type;

    union {
        struct { // ASTNodeType_SourceUnit
            ASTNodeList children;
        };
        struct { // ASTNodeType_Import
            TokenId pathTokenId;
            TokenId unitAliasTokenId;
            TokenIdList symbols;
            TokenIdList symbolAliases;
        };
        struct { // ASTNodeType_EnumDefinition
            TokenId nameTokenId;
            TokenIdList values;
        };
        ASTNodeStruct structNode;
    };
} ASTNode;

typedef struct ASTNodeLink {
    ASTNode node;
    struct ASTNodeLink *next;
} ASTNodeLink;

#include "./src/jsonIface.c"
#include "./src/binaryIface.c"

typedef struct Parser {
    Token *tokens;
    u32 tokenCount;
    u32 current;
} Parser;

static Parser
createParser(TokenizeResult tokens) {
    Parser parser = {
        .tokens = tokens.tokens,
        .tokenCount = tokens.count,
        .current = 0,
    };
    return parser;
}

static Token
peekToken(Parser *parser) {
    return parser->tokens[parser->current];
}

static u32
peekLastTokenId(Parser *parser) {
    assert(parser->current > 0);
    return parser->current - 1;
}

static Token
advanceToken(Parser *parser) {
    return parser->tokens[parser->current++];
}

static bool
acceptToken(Parser *parser, TokenType type) {
    if(peekToken(parser).type == type) {
        advanceToken(parser);
        return true;
    }

    return false;
}

static void
expectToken(Parser *parser, TokenType type) {
    assert(acceptToken(parser, type));
}

static TokenId
parseIdentifier(Parser *parser) {
    if(acceptToken(parser, TokenType_Symbol)) {
    } else if(acceptToken(parser, TokenType_From)) {
    } else if(acceptToken(parser, TokenType_Receive)) {
    } else if(acceptToken(parser, TokenType_Revert)) {
    } else if(acceptToken(parser, TokenType_Error)) {
    } else if(acceptToken(parser, TokenType_Global)) {
    } else if(acceptToken(parser, TokenType_Payable)) {
    } else {
        return INVALID_TOKEN_ID;
    }

    return peekLastTokenId(parser);
}

static TokenId
parseType(Parser *parser) {
    return parseIdentifier(parser);
}

static bool
parseImport(Parser *parser, Arena *arena, ASTNode *node) {
    if(acceptToken(parser, TokenType_StringLit)) {
        node->pathTokenId = peekLastTokenId(parser);

        node->unitAliasTokenId = INVALID_TOKEN_ID;
        if(acceptToken(parser, TokenType_As)) {
            TokenId unitAliasTokenId = parseIdentifier(parser);
            assert(unitAliasTokenId > 0);
            node->unitAliasTokenId = unitAliasTokenId;
        }
    } else if(acceptToken(parser, TokenType_Star)) {
        expectToken(parser, TokenType_As);
        TokenId unitAliasTokenId = parseIdentifier(parser);
        assert(unitAliasTokenId > 0);
        node->unitAliasTokenId = unitAliasTokenId;
        expectToken(parser, TokenType_From);
        expectToken(parser, TokenType_StringLit);
        node->pathTokenId = peekLastTokenId(parser);
    } else if(acceptToken(parser, TokenType_LBrace)) {
       do {
            TokenId symbolName = parseIdentifier(parser);
            assert(symbolName > 0);
            listPushTokenId(&node->symbols, symbolName, arena);

            if(acceptToken(parser, TokenType_As)) {
                TokenId symbolAliasName = parseIdentifier(parser);
                assert(symbolAliasName > 0);
                listPushTokenId(&node->symbolAliases, symbolAliasName, arena);
            } else {
                listPushTokenId(&node->symbolAliases, INVALID_TOKEN_ID, arena);
            }
        } while(acceptToken(parser, TokenType_Comma));

        expectToken(parser, TokenType_RBrace);
        expectToken(parser, TokenType_From);
        expectToken(parser, TokenType_StringLit);
        node->pathTokenId = peekLastTokenId(parser);
        node->unitAliasTokenId = INVALID_TOKEN_ID;
    } else {
        return false;
    }

    node->type = ASTNodeType_Import;

    expectToken(parser, TokenType_Semicolon);

    return true;
}

static bool
parseEnum(Parser *parser, Arena *arena, ASTNode *node) {
    node->type = ASTNodeType_EnumDefinition;

    TokenId nameTokenId = parseIdentifier(parser);
    assert(nameTokenId > 0);
    node->nameTokenId = nameTokenId;
    expectToken(parser, TokenType_LBrace);

    do {
        TokenId valueName = parseIdentifier(parser);
        assert(valueName > 0);
        listPushTokenId(&node->values, valueName, arena);
    } while(acceptToken(parser, TokenType_Comma));

    expectToken(parser, TokenType_RBrace);
    return true;
}

static bool
parseStruct(Parser *parser, Arena *arena, ASTNode *baseNode) {
    baseNode->type = ASTNodeType_Struct;
    ASTNodeStruct *node = &baseNode->structNode;

    TokenId nameTokenId = parseIdentifier(parser);
    assert(nameTokenId > 0);
    node->nameTokenId = nameTokenId;
    expectToken(parser, TokenType_LBrace);

    while(!acceptToken(parser, TokenType_RBrace)) {
        TokenId type = parseType(parser);
        assert(type > 0);
        listPushTokenId(&node->memberTypes, type, arena);

        TokenId name = parseIdentifier(parser);
        assert(name > 0);
        listPushTokenId(&node->memberNames, name, arena);

        expectToken(parser, TokenType_Semicolon);
    }

    return true;
}

static ASTNode
parseSourceUnit(Parser *parser, Arena *arena) {
    ASTNode node = { .type = ASTNodeType_SourceUnit };

    while(true) {
        ASTNodeLink *child = arrayPush(arena, ASTNodeLink, 1);

        if(acceptToken(parser, TokenType_Pragma)) {
            assert(parseIdentifier(parser));
            expectToken(parser, TokenType_Symbol);
            expectToken(parser, TokenType_Semicolon);
        } else if(acceptToken(parser, TokenType_Import)) {
            assert(parseImport(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_Enum)) {
            assert(parseEnum(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_Struct)) {
            assert(parseStruct(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_EOF)) {
            break;
        } else if(acceptToken(parser, TokenType_Comment)) {
            continue;
        } else {
            assert(false);
        }

        SLL_QUEUE_PUSH(node.children.head, node.children.last, child);
        node.children.count += 1;
    }

    return node;
}
