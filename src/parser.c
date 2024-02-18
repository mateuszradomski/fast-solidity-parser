#include "./src/utils.c"
#include "./src/tokenize.c"

static String result = { 0 };

typedef enum ASTNodeType {
    ASTNodeType_None,
    ASTNodeType_SourceUnit,
    ASTNodeType_Import,
    ASTNodeType_Count,
} ASTNodeType;

typedef struct ASTNodeLink ASTNodeLink;

typedef struct ASTNodeList {
    ASTNodeLink *head;
    ASTNodeLink *last;
    u32 count;
} ASTNodeList;

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
    };
} ASTNode;

typedef struct ASTNodeLink {
    ASTNode node;
    struct ASTNodeLink *next;
} ASTNodeLink;

#include "./src/astprint.c"

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

        while(acceptToken(parser, TokenType_Comma)) {
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
        }

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

String *
entry_point(const char *string, int len) {
    Arena arena = arenaCreate(64 * Megabyte, 32 * Kilobyte, 64);
    String input = { .data = (u8 *)string, .size = len };
    TokenizeResult tokens = tokenize(input, &arena);
    Parser parser = createParser(tokens);
    ASTNode node = parseSourceUnit(&parser, &arena);
    result = astNodeToString(tokens, node, &arena);

    return &result;
}
