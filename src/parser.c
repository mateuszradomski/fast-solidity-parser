static String result = { 0 };

typedef enum ASTNodeType_Enum {
    ASTNodeType_None,
    ASTNodeType_SourceUnit,
    ASTNodeType_Import,
    ASTNodeType_EnumDefinition,
    ASTNodeType_Struct,
    ASTNodeType_BaseType,
    ASTNodeType_FunctionType,
    ASTNodeType_MappingType,
    ASTNodeType_IdentifierPath,
    ASTNodeType_ArrayType,
    ASTNodeType_Error,
    ASTNodeType_Event,
    ASTNodeType_Typedef,
    ASTNodeType_Count,
} ASTNodeType_Enum;

typedef u32 ASTNodeType;

typedef struct ASTNode ASTNode;
typedef struct ASTNodeLink ASTNodeLink;

typedef struct FunctionParameter {
    ASTNode *type;
    u32 dataLocation;
    TokenId identifier;
    struct FunctionParameter *next;
} FunctionParameter;

typedef struct FunctionParameterList {
    FunctionParameter *head;
    FunctionParameter *last;
    u32 count;
} FunctionParameterList;

typedef struct ASTNodeList {
    ASTNodeLink *head;
    ASTNodeLink *last;
    u32 count;
} ASTNodeList;

typedef struct ASTNodeStruct {
    TokenId nameTokenId;
    ASTNodeList memberTypes;
    TokenIdList memberNames;
} ASTNodeStruct;

typedef struct ASTNodeBaseType {
    TokenId typeName;
    u32 payable;
} ASTNodeBaseType;

typedef struct ASTNodeIdentifierPath {
    TokenIdList identifiers;
} ASTNodeIdentifierPath;

typedef struct ASTNodeMapping {
    ASTNode *keyType;
    TokenId keyIdentifier;
    ASTNode *valueType;
    TokenId valueIdentifier;
} ASTNodeMapping;

typedef struct ASTNodeFunctionType {
    FunctionParameterList parameters;
    u16 visibility;
    u16 stateMutability;
    FunctionParameterList returnParameters;
} ASTNodeFunctionType;

typedef struct ASTNodeArrayType {
    ASTNode *elementType;
} ASTNodeArrayType;

typedef struct ASTNodeError {
    TokenId identifier;
    FunctionParameterList parameters;
} ASTNodeError;

typedef struct ASTNodeEvent {
    TokenId identifier;
    FunctionParameterList parameters;
    u32 anonymous;
} ASTNodeEvent;

typedef struct ASTNodeTypedef {
    TokenId identifier;
    ASTNode *type;
} ASTNodeTypedef;

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
        ASTNodeBaseType baseTypeNode;
        ASTNodeIdentifierPath identifierPathNode;
        ASTNodeMapping mappingNode;
        ASTNodeFunctionType functionTypeNode;
        ASTNodeArrayType arrayTypeNode;
        ASTNodeError errorNode;
        ASTNodeEvent eventNode;
        ASTNodeTypedef typedefNode;
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

// TODO(radomski): This is obviously stupid
static bool
isBaseTypeName(String string) {
    static String elementaryTypeNames[] = {
        LIT_TO_STR("address"),
        LIT_TO_STR("bool"),
        LIT_TO_STR("string"),
        LIT_TO_STR("bytes"),
        LIT_TO_STR("int"),
        LIT_TO_STR("int8"),
        LIT_TO_STR("int16"),
        LIT_TO_STR("int24"),
        LIT_TO_STR("int32"),
        LIT_TO_STR("int40"),
        LIT_TO_STR("int48"),
        LIT_TO_STR("int56"),
        LIT_TO_STR("int64"),
        LIT_TO_STR("int72"),
        LIT_TO_STR("int80"),
        LIT_TO_STR("int88"),
        LIT_TO_STR("int96"),
        LIT_TO_STR("int104"),
        LIT_TO_STR("int112"),
        LIT_TO_STR("int120"),
        LIT_TO_STR("int128"),
        LIT_TO_STR("int136"),
        LIT_TO_STR("int144"),
        LIT_TO_STR("int152"),
        LIT_TO_STR("int160"),
        LIT_TO_STR("int168"),
        LIT_TO_STR("int176"),
        LIT_TO_STR("int184"),
        LIT_TO_STR("int192"),
        LIT_TO_STR("int200"),
        LIT_TO_STR("int208"),
        LIT_TO_STR("int216"),
        LIT_TO_STR("int224"),
        LIT_TO_STR("int232"),
        LIT_TO_STR("int240"),
        LIT_TO_STR("int248"),
        LIT_TO_STR("int256"),
        LIT_TO_STR("uint"),
        LIT_TO_STR("uint8"),
        LIT_TO_STR("uint16"),
        LIT_TO_STR("uint24"),
        LIT_TO_STR("uint32"),
        LIT_TO_STR("uint40"),
        LIT_TO_STR("uint48"),
        LIT_TO_STR("uint56"),
        LIT_TO_STR("uint64"),
        LIT_TO_STR("uint72"),
        LIT_TO_STR("uint80"),
        LIT_TO_STR("uint88"),
        LIT_TO_STR("uint96"),
        LIT_TO_STR("uint104"),
        LIT_TO_STR("uint112"),
        LIT_TO_STR("uint120"),
        LIT_TO_STR("uint128"),
        LIT_TO_STR("uint136"),
        LIT_TO_STR("uint144"),
        LIT_TO_STR("uint152"),
        LIT_TO_STR("uint160"),
        LIT_TO_STR("uint168"),
        LIT_TO_STR("uint176"),
        LIT_TO_STR("uint184"),
        LIT_TO_STR("uint192"),
        LIT_TO_STR("uint200"),
        LIT_TO_STR("uint208"),
        LIT_TO_STR("uint216"),
        LIT_TO_STR("uint224"),
        LIT_TO_STR("uint232"),
        LIT_TO_STR("uint240"),
        LIT_TO_STR("uint248"),
        LIT_TO_STR("uint256"),
        LIT_TO_STR("bytes1"),
        LIT_TO_STR("bytes2"),
        LIT_TO_STR("bytes3"),
        LIT_TO_STR("bytes4"),
        LIT_TO_STR("bytes5"),
        LIT_TO_STR("bytes6"),
        LIT_TO_STR("bytes7"),
        LIT_TO_STR("bytes8"),
        LIT_TO_STR("bytes9"),
        LIT_TO_STR("bytes10"),
        LIT_TO_STR("bytes11"),
        LIT_TO_STR("bytes12"),
        LIT_TO_STR("bytes13"),
        LIT_TO_STR("bytes14"),
        LIT_TO_STR("bytes15"),
        LIT_TO_STR("bytes16"),
        LIT_TO_STR("bytes17"),
        LIT_TO_STR("bytes18"),
        LIT_TO_STR("bytes19"),
        LIT_TO_STR("bytes20"),
        LIT_TO_STR("bytes21"),
        LIT_TO_STR("bytes22"),
        LIT_TO_STR("bytes23"),
        LIT_TO_STR("bytes24"),
        LIT_TO_STR("bytes25"),
        LIT_TO_STR("bytes26"),
        LIT_TO_STR("bytes27"),
        LIT_TO_STR("bytes28"),
        LIT_TO_STR("bytes29"),
        LIT_TO_STR("bytes30"),
        LIT_TO_STR("bytes31"),
        LIT_TO_STR("bytes32"),
        LIT_TO_STR("fixed"),
        LIT_TO_STR("ufixed"),
    };

    for(u32 i = 0; i < ARRAY_LENGTH(elementaryTypeNames); i++) {
        if(stringMatch(string, elementaryTypeNames[i])) {
            return true;
        }
    }

    return false;
}

static void
parseType(Parser *parser, ASTNode *node, Arena *arena) {
    TokenId identifier = INVALID_TOKEN_ID;

    if(acceptToken(parser, TokenType_Mapping)) {
        node->type = ASTNodeType_MappingType;
        ASTNodeMapping *mapping = &node->mappingNode;

        expectToken(parser, TokenType_LParen);
        mapping->keyType = structPush(arena, ASTNode);
        parseType(parser, mapping->keyType, arena);
        assert(mapping->keyType->type == ASTNodeType_BaseType ||
               mapping->keyType->type == ASTNodeType_IdentifierPath);
        mapping->keyIdentifier = parseIdentifier(parser);

        expectToken(parser, TokenType_Equal);
        expectToken(parser, TokenType_RTick);

        mapping->valueType = structPush(arena, ASTNode);
        parseType(parser, mapping->valueType, arena);
        mapping->valueIdentifier = parseIdentifier(parser);
        expectToken(parser, TokenType_RParen);
    } else if(acceptToken(parser, TokenType_Function)) {
        node->type = ASTNodeType_FunctionType;
        ASTNodeFunctionType *function = &node->functionTypeNode;
        expectToken(parser, TokenType_LParen);

        if(!acceptToken(parser, TokenType_RParen)) {
            do {
                FunctionParameter *parameter = structPush(arena, FunctionParameter);
                parameter->type = structPush(arena, ASTNode);
                parseType(parser, parameter->type, arena);
                if(acceptToken(parser, TokenType_Payable)) {
                    parameter->dataLocation = 1;
                } else if(acceptToken(parser, TokenType_Storage)) {
                    parameter->dataLocation = 2;
                } else if(acceptToken(parser, TokenType_Calldata)) {
                    parameter->dataLocation = 3;
                } else {
                    assert(0);
                }

                parameter->identifier = parseIdentifier(parser);

                SLL_QUEUE_PUSH(function->parameters.head, function->parameters.last, parameter);
                function->parameters.count += 1;
            } while(acceptToken(parser, TokenType_Comma));
        }

        expectToken(parser, TokenType_RParen);
        
        if(acceptToken(parser, TokenType_Internal)) {
            function->visibility = 1;
        } else if(acceptToken(parser, TokenType_External)) {
            function->visibility = 2;
        } else if(acceptToken(parser, TokenType_Private)) {
            function->visibility = 3;
        } else if(acceptToken(parser, TokenType_Public)) {
            function->visibility = 4;
        } else {
            assert(0);
        }

        if(acceptToken(parser, TokenType_Pure)) {
            function->stateMutability = 1;
        } else if(acceptToken(parser, TokenType_View)) {
            function->stateMutability = 2;
        } else if(acceptToken(parser, TokenType_Payable)) {
            function->stateMutability = 3;
        } else {
            function->stateMutability = 0;
        }

        expectToken(parser, TokenType_Returns);
        expectToken(parser, TokenType_LParen);

        if(!acceptToken(parser, TokenType_RParen)) {
            do {
                FunctionParameter *parameter = structPush(arena, FunctionParameter);
                parameter->type = structPush(arena, ASTNode);
                parseType(parser, parameter->type, arena);
                if(acceptToken(parser, TokenType_Payable)) {
                    parameter->dataLocation = 1;
                } else if(acceptToken(parser, TokenType_Storage)) {
                    parameter->dataLocation = 2;
                } else if(acceptToken(parser, TokenType_Calldata)) {
                    parameter->dataLocation = 3;
                } else {
                    assert(0);
                }

                parameter->identifier = parseIdentifier(parser);

                SLL_QUEUE_PUSH(function->parameters.head, function->parameters.last, parameter);
                function->parameters.count += 1;
            } while(acceptToken(parser, TokenType_Comma));
        }
        expectToken(parser, TokenType_RParen);
    } else if((identifier = parseIdentifier(parser)) != INVALID_TOKEN_ID) {
        if(isBaseTypeName(parser->tokens[identifier].string)) {
            node->type = ASTNodeType_BaseType;
            node->baseTypeNode.typeName = identifier;

            if(acceptToken(parser, TokenType_Payable)) {
                assert(stringMatch(parser->tokens[identifier].string, LIT_TO_STR("address")));
                node->baseTypeNode.payable = 1;
            }
        } else {
            node->type = ASTNodeType_IdentifierPath;
            listPushTokenId(&node->identifierPathNode.identifiers, identifier, arena);
            while(acceptToken(parser, TokenType_Dot)) {
                TokenId nextIdentifier = parseIdentifier(parser);
                assert(nextIdentifier > 0);
                listPushTokenId(&node->identifierPathNode.identifiers, nextIdentifier, arena);
            }
        }
    } else {
        assert(0);
    }

    while(acceptToken(parser, TokenType_LBracket)) {
        ASTNode *copy = structPush(arena, ASTNode);
        *copy = *node;
        node->type = ASTNodeType_ArrayType;
        node->arrayTypeNode.elementType = copy;
        expectToken(parser, TokenType_RBracket);
    }
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
        ASTNodeLink *typeLink = structPush(arena, ASTNodeLink);
        parseType(parser, &typeLink->node, arena);
        SLL_QUEUE_PUSH(node->memberTypes.head, node->memberTypes.last, typeLink);
        node->memberTypes.count += 1;

        TokenId name = parseIdentifier(parser);
        assert(name > 0);
        listPushTokenId(&node->memberNames, name, arena);

        expectToken(parser, TokenType_Semicolon);
    }

    return true;
}

static bool
parseError(Parser *parser, Arena *arena, ASTNode *node) {
    node->type = ASTNodeType_Error;
    ASTNodeError *error = &node->errorNode;
    error->identifier = parseIdentifier(parser);
    assert(error->identifier > 0);

    expectToken(parser, TokenType_LParen);

    if(!acceptToken(parser, TokenType_RParen)) {
        do {
            FunctionParameter *parameter = structPush(arena, FunctionParameter);
            parameter->type = structPush(arena, ASTNode);
            parseType(parser, parameter->type, arena);
            parameter->identifier = parseIdentifier(parser);

            SLL_QUEUE_PUSH(error->parameters.head, error->parameters.last, parameter);
            error->parameters.count += 1;
        } while(acceptToken(parser, TokenType_Comma));
        expectToken(parser, TokenType_RParen);
    }

    expectToken(parser, TokenType_Semicolon);
    return true;
}

static bool
parseEvent(Parser *parser, Arena *arena, ASTNode *node) {
    node->type = ASTNodeType_Event;
    ASTNodeEvent *event = &node->eventNode;
    event->identifier = parseIdentifier(parser);
    assert(event->identifier > 0);

    expectToken(parser, TokenType_LParen);

    if(!acceptToken(parser, TokenType_RParen)) {
        do {
            FunctionParameter *parameter = structPush(arena, FunctionParameter);
            parameter->type = structPush(arena, ASTNode);
            parseType(parser, parameter->type, arena);

            if(acceptToken(parser, TokenType_Indexed)) {
                parameter->dataLocation = 1;
            }

            parameter->identifier = parseIdentifier(parser);

            SLL_QUEUE_PUSH(event->parameters.head, event->parameters.last, parameter);
            event->parameters.count += 1;
        } while(acceptToken(parser, TokenType_Comma));
        expectToken(parser, TokenType_RParen);
    }

    if(acceptToken(parser, TokenType_Anonymous)) {
        event->anonymous = 1;
    }

    expectToken(parser, TokenType_Semicolon);
    return true;
}

static bool
parseTypedef(Parser *parser, Arena *arena, ASTNode *node) {
    node->type = ASTNodeType_Typedef;
    ASTNodeTypedef *typedefNode = &node->typedefNode;

    typedefNode->identifier = parseIdentifier(parser);
    assert(typedefNode->identifier > 0);

    expectToken(parser, TokenType_Is);

    typedefNode->type = structPush(arena, ASTNode);
    parseType(parser, typedefNode->type, arena);
    assert(typedefNode->type->type == ASTNodeType_BaseType);

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
        } else if(acceptToken(parser, TokenType_Enum)) {
            assert(parseEnum(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_Struct)) {
            assert(parseStruct(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_Error)) {
            assert(parseError(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_Event)) {
            assert(parseEvent(parser, arena, &child->node));
        } else if(acceptToken(parser, TokenType_Type)) {
            assert(parseTypedef(parser, arena, &child->node));
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
