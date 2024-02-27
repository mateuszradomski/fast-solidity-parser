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
    ASTNodeType_ConstVariable,
    ASTNodeType_NumberLitExpression,
    ASTNodeType_StringLitExpression,
    ASTNodeType_BoolLitExpression,
    ASTNodeType_IdentifierExpression,
    ASTNodeType_BinaryExpression,
    ASTNodeType_TupleExpression,
    ASTNodeType_UnaryExpression,
    ASTNodeType_FunctionCallExpression,
    ASTNodeType_MemberAccessExpression,
    ASTNodeType_ArrayAccessExpression,
    ASTNodeType_FunctionDefinition,
    ASTNodeType_BlockStatement,
    ASTNodeType_ReturnStatement,
    ASTNodeType_ExpressionStatement,
    ASTNodeType_IfStatement,
    ASTNodeType_VariableDeclarationStatement,
    ASTNodeType_VariableDeclaration,
    ASTNodeType_NewExpression,
    ASTNodeType_VariableDeclarationTupleStatement,
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

typedef struct ASTNodeConstVariable {
    TokenId identifier;
    ASTNode *type;
    ASTNode *expression;
} ASTNodeConstVariable;

typedef struct ASTNodeNumberLitExpression {
    TokenId value;
    TokenId subdenomination;
} ASTNodeNumberLitExpression;

typedef struct ASTNodeStringLitExpression {
    TokenId value;
} ASTNodeStringLitExpression;

typedef struct ASTNodeBinaryExpression {
    ASTNode *left;
    ASTNode *right;
    u32 operator;
} ASTNodeBinaryExpression;

typedef struct ASTNodeTupleExpression {
    ASTNodeList elements;
} ASTNodeTupleExpression;

typedef struct ASTNodeUnaryExpression {
    u32 operator;
    ASTNode *subExpression;
} ASTNodeUnaryExpression;

typedef struct ASTNodeNewExpression {
    ASTNode *typeName;
} ASTNodeNewExpression;

typedef struct ASTNodeFunctionCallExpression {
    ASTNode *expression;
    ASTNodeList arguments;
} ASTNodeFunctionCallExpression;

typedef struct ASTNodeMemberAccessExpression {
    ASTNode *expression;
    TokenId memberName;
} ASTNodeMemberAccessExpression;

typedef struct ASTNodeArrayAccessExpression {
    ASTNode *expression;
    ASTNode *indexExpression;
} ASTNodeArrayAccessExpression;

typedef struct ASTNodeFunctionDefinition {
    TokenId name;
    FunctionParameterList parameters;
    u16 visibility;
    u16 stateMutability;
    FunctionParameterList returnParameters;
    ASTNode *body;
} ASTNodeFunctionDefinition;

typedef struct ASTNodeBlockStatement {
    ASTNodeList statements;
} ASTNodeBlockStatement;

typedef struct ASTNodeReturnStatement {
    ASTNode *expression;
} ASTNodeReturnStatement;

typedef struct ASTNodeIfStatement {
    ASTNode *conditionExpression;
    ASTNode *trueStatement;
    ASTNode *falseStatement;
} ASTNodeIfStatement;

typedef struct ASTNodeVariableDeclaration {
    ASTNode *type;
    u32 name;
    u32 dataLocation;
} ASTNodeVariableDeclaration;

typedef struct ASTNodeVariableDeclarationStatement {
    ASTNode *variableDeclaration;
    ASTNode *initialValue;
} ASTNodeVariableDeclarationStatement;

typedef struct ASTNodeVariableDeclarationTupleStatement {
    ASTNodeList declarations;
    ASTNode *initialValue;
} ASTNodeVariableDeclarationTupleStatement;

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
        ASTNodeConstVariable constVariableNode;
        ASTNodeNumberLitExpression numberLitExpressionNode;
        ASTNodeStringLitExpression stringLitExpressionNode;
        ASTNodeStringLitExpression boolLitExpressionNode;
        ASTNodeStringLitExpression identifierExpressionNode;
        ASTNodeBinaryExpression binaryExpressionNode;
        ASTNodeTupleExpression tupleExpressionNode;
        ASTNodeUnaryExpression unaryExpressionNode;
        ASTNodeNewExpression newExpressionNode;
        ASTNodeFunctionCallExpression functionCallExpressionNode;
        ASTNodeMemberAccessExpression memberAccessExpressionNode;
        ASTNodeArrayAccessExpression arrayAccessExpressionNode;
        ASTNodeFunctionDefinition functionDefinitionNode;
        ASTNodeBlockStatement blockStatementNode;
        ASTNodeReturnStatement returnStatementNode;
        ASTNodeReturnStatement expressionStatementNode;
        ASTNodeIfStatement ifStatementNode;
        ASTNodeVariableDeclarationStatement variableDeclarationStatementNode;
        ASTNodeVariableDeclaration variableDeclarationNode;
        ASTNodeVariableDeclarationTupleStatement variableDeclarationTupleStatementNode;
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

    Arena *arena;
} Parser;

static Parser
createParser(TokenizeResult tokens, Arena *arena) {
    Parser parser = {
        .tokens = tokens.tokens,
        .tokenCount = tokens.count,
        .current = 0,
        .arena = arena,
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
peekLastToken(Parser *parser) {
    assert(parser->current > 0);
    return parser->tokens[parser->current - 1];
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

static u32
getCurrentParserPosition(Parser *parser) {
    return parser->current;
}

static void
setCurrentParserPosition(Parser *parser, u32 newPosition) {
    parser->current = newPosition;
}

static TokenId
parseIdentifier(Parser *parser) {
    Token token = peekToken(parser);

    u32 isIdent =
        token.type == TokenType_Symbol |
        token.type == TokenType_From |
        token.type == TokenType_Receive |
        token.type == TokenType_Revert |
        token.type == TokenType_Error |
        token.type == TokenType_Global |
        token.type == TokenType_Payable;

    if(isIdent) {
        acceptToken(parser, token.type);
        return peekLastTokenId(parser);
    } else {
        return INVALID_TOKEN_ID;
    }

    return peekLastTokenId(parser);
}

static TokenId
parseSubdenomination(Parser *parser) {
    Token token = peekToken(parser);

    u32 isSubdenomination =
        token.type == TokenType_Wei |
        token.type == TokenType_Gwei |
        token.type == TokenType_Ether |
        token.type == TokenType_Seconds |
        token.type == TokenType_Minutes |
        token.type == TokenType_Hours |
        token.type == TokenType_Days |
        token.type == TokenType_Weeks |
        token.type == TokenType_Years;

    if(isSubdenomination) {
        acceptToken(parser, token.type);
        return peekLastTokenId(parser);
    } else {
        return INVALID_TOKEN_ID;
    }
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

static bool
parseType(Parser *parser, ASTNode *node) {
    TokenId identifier = INVALID_TOKEN_ID;

    if(acceptToken(parser, TokenType_Mapping)) {
        node->type = ASTNodeType_MappingType;
        ASTNodeMapping *mapping = &node->mappingNode;

        expectToken(parser, TokenType_LParen);
        mapping->keyType = structPush(parser->arena, ASTNode);
        parseType(parser, mapping->keyType);
        assert(mapping->keyType->type == ASTNodeType_BaseType ||
               mapping->keyType->type == ASTNodeType_IdentifierPath);
        mapping->keyIdentifier = parseIdentifier(parser);

        expectToken(parser, TokenType_Equal);
        expectToken(parser, TokenType_RTick);

        mapping->valueType = structPush(parser->arena, ASTNode);
        parseType(parser, mapping->valueType);
        mapping->valueIdentifier = parseIdentifier(parser);
        expectToken(parser, TokenType_RParen);
    } else if(acceptToken(parser, TokenType_Function)) {
        node->type = ASTNodeType_FunctionType;
        ASTNodeFunctionType *function = &node->functionTypeNode;
        expectToken(parser, TokenType_LParen);

        if(!acceptToken(parser, TokenType_RParen)) {
            do {
                FunctionParameter *parameter = structPush(parser->arena, FunctionParameter);
                parameter->type = structPush(parser->arena, ASTNode);
                parseType(parser, parameter->type);
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
                FunctionParameter *parameter = structPush(parser->arena, FunctionParameter);
                parameter->type = structPush(parser->arena, ASTNode);
                parseType(parser, parameter->type);
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
            listPushTokenId(&node->identifierPathNode.identifiers, identifier, parser->arena);
            while(acceptToken(parser, TokenType_Dot)) {
                TokenId nextIdentifier = parseIdentifier(parser);
                assert(nextIdentifier > 0);
                listPushTokenId(&node->identifierPathNode.identifiers, nextIdentifier, parser->arena);
            }
        }
    } else {
        return false;
    }

    while(acceptToken(parser, TokenType_LBracket)) {
        ASTNode *copy = structPush(parser->arena, ASTNode);
        *copy = *node;
        node->type = ASTNodeType_ArrayType;
        node->arrayTypeNode.elementType = copy;
        expectToken(parser, TokenType_RBracket);
    }

    return true;
}

static bool
parseImport(Parser *parser, ASTNode *node) {
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
            listPushTokenId(&node->symbols, symbolName, parser->arena);

            if(acceptToken(parser, TokenType_As)) {
                TokenId symbolAliasName = parseIdentifier(parser);
                assert(symbolAliasName > 0);
                listPushTokenId(&node->symbolAliases, symbolAliasName, parser->arena);
            } else {
                listPushTokenId(&node->symbolAliases, INVALID_TOKEN_ID, parser->arena);
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
parseEnum(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_EnumDefinition;

    TokenId nameTokenId = parseIdentifier(parser);
    assert(nameTokenId > 0);
    node->nameTokenId = nameTokenId;
    expectToken(parser, TokenType_LBrace);

    do {
        TokenId valueName = parseIdentifier(parser);
        assert(valueName > 0);
        listPushTokenId(&node->values, valueName, parser->arena);
    } while(acceptToken(parser, TokenType_Comma));

    expectToken(parser, TokenType_RBrace);
    return true;
}

static bool
parseStruct(Parser *parser, ASTNode *baseNode) {
    baseNode->type = ASTNodeType_Struct;
    ASTNodeStruct *node = &baseNode->structNode;

    TokenId nameTokenId = parseIdentifier(parser);
    assert(nameTokenId > 0);
    node->nameTokenId = nameTokenId;
    expectToken(parser, TokenType_LBrace);

    while(!acceptToken(parser, TokenType_RBrace)) {
        ASTNodeLink *typeLink = structPush(parser->arena, ASTNodeLink);
        parseType(parser, &typeLink->node);
        SLL_QUEUE_PUSH(node->memberTypes.head, node->memberTypes.last, typeLink);
        node->memberTypes.count += 1;

        TokenId name = parseIdentifier(parser);
        assert(name > 0);
        listPushTokenId(&node->memberNames, name, parser->arena);

        expectToken(parser, TokenType_Semicolon);
    }

    return true;
}

static bool
parseError(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_Error;
    ASTNodeError *error = &node->errorNode;
    error->identifier = parseIdentifier(parser);
    assert(error->identifier > 0);

    expectToken(parser, TokenType_LParen);

    if(!acceptToken(parser, TokenType_RParen)) {
        do {
            FunctionParameter *parameter = structPush(parser->arena, FunctionParameter);
            parameter->type = structPush(parser->arena, ASTNode);
            parseType(parser, parameter->type);
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
parseEvent(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_Event;
    ASTNodeEvent *event = &node->eventNode;
    event->identifier = parseIdentifier(parser);
    assert(event->identifier > 0);

    expectToken(parser, TokenType_LParen);

    if(!acceptToken(parser, TokenType_RParen)) {
        do {
            FunctionParameter *parameter = structPush(parser->arena, FunctionParameter);
            parameter->type = structPush(parser->arena, ASTNode);
            parseType(parser, parameter->type);

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
parseTypedef(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_Typedef;
    ASTNodeTypedef *typedefNode = &node->typedefNode;

    typedefNode->identifier = parseIdentifier(parser);
    assert(typedefNode->identifier > 0);

    expectToken(parser, TokenType_Is);

    typedefNode->type = structPush(parser->arena, ASTNode);
    parseType(parser, typedefNode->type);
    assert(typedefNode->type->type == ASTNodeType_BaseType);

    expectToken(parser, TokenType_Semicolon);
    return true;
}

static bool
isOperator(TokenType type) {
    switch(type) {
        case TokenType_Dot:
        case TokenType_LParen:
        case TokenType_LBracket:
        case TokenType_StarStar:
        case TokenType_Star:
        case TokenType_Divide:
        case TokenType_Percent:
        case TokenType_Plus:
        case TokenType_Minus:
        case TokenType_Ampersand:
        case TokenType_Carrot:
        case TokenType_Pipe:
        case TokenType_LeftShift:
        case TokenType_RightShift:
        case TokenType_RightShiftZero:
        case TokenType_LeftEqual:
        case TokenType_RightEqual:
        case TokenType_LTick:
        case TokenType_RTick:
        case TokenType_EqualEqual:
        case TokenType_NotEqual:
        case TokenType_LogicalAnd:
        case TokenType_LogicalOr:
        case TokenType_Equal:
        case TokenType_OrEqual:
        case TokenType_XorEqual:
        case TokenType_AndEqual:
        case TokenType_LeftShiftEqual:
        case TokenType_RightShiftEqual:
        case TokenType_PlusEqual:
        case TokenType_MinusEqual:
        case TokenType_StarEqual:
        case TokenType_DivideEqual:
        case TokenType_PercentEqual: return true;
        default: return false;
    }
}

static u32
getOperatorPrecedence(TokenType type) {
    switch(type) {
        case TokenType_Dot:
        case TokenType_LParen:
        case TokenType_LBracket: return -1;
        case TokenType_StarStar: return -3;
        case TokenType_Star:
        case TokenType_Divide:
        case TokenType_Percent: return -4;
        case TokenType_Plus:
        case TokenType_Minus: return -5;
        case TokenType_LeftShift:
        case TokenType_RightShift:
        case TokenType_RightShiftZero: return -6;
        case TokenType_Ampersand: return -7;
        case TokenType_Carrot: return -8;
        case TokenType_Pipe: return -9;
        case TokenType_LeftEqual:
        case TokenType_RightEqual:
        case TokenType_LTick:
        case TokenType_RTick: return -10;
        case TokenType_EqualEqual:
        case TokenType_NotEqual: return -11;
        case TokenType_LogicalAnd: return -12;
        case TokenType_LogicalOr: return -13;
        case TokenType_Equal:
        case TokenType_OrEqual:
        case TokenType_XorEqual:
        case TokenType_AndEqual:
        case TokenType_LeftShiftEqual:
        case TokenType_RightShiftEqual:
        case TokenType_PlusEqual:
        case TokenType_MinusEqual:
        case TokenType_StarEqual:
        case TokenType_DivideEqual:
        case TokenType_PercentEqual: return -14;
        default: assert(0);
    }

    return 0;
}

static bool
isUnaryOperator(TokenType type) {
    switch(type) {
        case TokenType_New:
        case TokenType_Exclamation:
        case TokenType_Minus:
        case TokenType_Tylde:
        case TokenType_PlusPlus:
        case TokenType_MinusMinus:
        case TokenType_Delete: return true;
        default: return false;
    }
}

static u32
getUnaryOperatorPrecedence(TokenType type) {
    switch(type) {
        case TokenType_New: return -1;
        case TokenType_Exclamation:
        case TokenType_Minus:
        case TokenType_Tylde:
        case TokenType_PlusPlus:
        case TokenType_MinusMinus:
        case TokenType_Delete: return -2;
        default: assert(0);
    }

    return 0;
}

static ASTNode *parseExpressionImpl(Parser *parser, ASTNode *node, u32 previousPrecedence);

static ASTNode *
parseFunctionCallExpression(Parser *parser, ASTNode *node) {
    ASTNode *expression = structPush(parser->arena, ASTNode);
    *expression = *node;

    memset(node, 0, sizeof(ASTNode));
    node->type = ASTNodeType_FunctionCallExpression;
    node->functionCallExpressionNode.expression = expression;
    if(!acceptToken(parser, TokenType_RParen)) {
        do {
            ASTNodeLink *argument = structPush(parser->arena, ASTNodeLink);
            parseExpressionImpl(parser, &argument->node, 0);
            ASTNodeFunctionCallExpression *functionCall = &node->functionCallExpressionNode;
            SLL_QUEUE_PUSH(functionCall->arguments.head, functionCall->arguments.last, argument);
            node->functionCallExpressionNode.arguments.count += 1;
        } while(acceptToken(parser, TokenType_Comma));
        expectToken(parser, TokenType_RParen);
    }

    return node;
}

static ASTNode *
parseExpressionImpl(Parser *parser, ASTNode *node, u32 previousPrecedence) {
    if(acceptToken(parser, TokenType_HexNumberLit)) {
        node->type = ASTNodeType_NumberLitExpression;
        node->numberLitExpressionNode.value = peekLastTokenId(parser);
        node->numberLitExpressionNode.subdenomination = INVALID_TOKEN_ID;
    } else if(acceptToken(parser, TokenType_NumberLit)) {
        node->type = ASTNodeType_NumberLitExpression;
        node->numberLitExpressionNode.value = peekLastTokenId(parser);
        node->numberLitExpressionNode.subdenomination = parseSubdenomination(parser);
    } else if(acceptToken(parser, TokenType_StringLit)) {
        node->type = ASTNodeType_StringLitExpression;
        node->stringLitExpressionNode.value = peekLastTokenId(parser);
    } else if(acceptToken(parser, TokenType_True) || acceptToken(parser, TokenType_False)) {
        node->type = ASTNodeType_BoolLitExpression;
        node->boolLitExpressionNode.value = peekLastTokenId(parser);
    } else if(acceptToken(parser, TokenType_LParen)) {
        node->type = ASTNodeType_TupleExpression;

        if(!acceptToken(parser, TokenType_RParen)) {
            do {
                ASTNodeLink *element = structPush(parser->arena, ASTNodeLink);

                parseExpressionImpl(parser, &element->node, previousPrecedence);

                SLL_QUEUE_PUSH(node->tupleExpressionNode.elements.head, node->tupleExpressionNode.elements.last, element);
                node->tupleExpressionNode.elements.count += 1;
            } while (acceptToken(parser, TokenType_Comma));

            expectToken(parser, TokenType_RParen);
        }
    } else if(isUnaryOperator(peekToken(parser).type)) {
        u32 operator = peekToken(parser).type;

        if(operator == TokenType_New) {
            node->type = ASTNodeType_NewExpression;
            node->newExpressionNode.typeName = structPush(parser->arena, ASTNode);
            advanceToken(parser);

            parseType(parser, node->newExpressionNode.typeName);
        } else {
            node->type = ASTNodeType_UnaryExpression;
            node->unaryExpressionNode.operator = operator;
            node->unaryExpressionNode.subExpression = structPush(parser->arena, ASTNode);
            advanceToken(parser);

            u32 precedence = getUnaryOperatorPrecedence(node->unaryExpressionNode.operator);
            parseExpressionImpl(parser, node->unaryExpressionNode.subExpression, precedence);
        }
    } else if(parseIdentifier(parser) != INVALID_TOKEN_ID) {
        const Token ident = peekLastToken(parser);
        if(isBaseTypeName(ident.string)) {
            node->type = ASTNodeType_BaseType;
            node->baseTypeNode.typeName = peekLastTokenId(parser);
            node->baseTypeNode.payable = 0;
        } else {
            node->type = ASTNodeType_IdentifierExpression;
            node->identifierExpressionNode.value = peekLastTokenId(parser);
        }
    } else if(acceptToken(parser, TokenType_Type)) {
        node->type = ASTNodeType_IdentifierExpression;
        node->identifierExpressionNode.value = peekLastTokenId(parser);

        expectToken(parser, TokenType_LParen);
        parseFunctionCallExpression(parser, node);
    } else {
        assert(false);
    }

    while(true) {
        TokenType type = peekToken(parser).type;
        if(!isOperator(type)) {
            break;
        }

        u32 precedence = getOperatorPrecedence(type);
        if(precedence <= previousPrecedence) {
            break;
        }
        advanceToken(parser);

        if(type == TokenType_LParen) {
            parseFunctionCallExpression(parser, node);
            continue;
        } else if(type == TokenType_LBracket) {
            ASTNode *expression = structPush(parser->arena, ASTNode);
            *expression = *node;

            ASTNode *indexExpression = structPush(parser->arena, ASTNode);
            parseExpressionImpl(parser, indexExpression, 0);
            expectToken(parser, TokenType_RBracket);

            node->type = ASTNodeType_ArrayAccessExpression;
            node->arrayAccessExpressionNode.expression = expression;
            node->arrayAccessExpressionNode.indexExpression = indexExpression;

            continue;
        } else if(type == TokenType_Dot) {
            ASTNode *expression = structPush(parser->arena, ASTNode);
            *expression = *node;

            node->type = ASTNodeType_MemberAccessExpression;
            node->memberAccessExpressionNode.expression = expression;
            node->memberAccessExpressionNode.memberName = parseIdentifier(parser);
            continue;
        }

        ASTNode *left = structPush(parser->arena, ASTNode);
        *left = *node;

        node->type = ASTNodeType_BinaryExpression;
        node->binaryExpressionNode.left = left;
        node->binaryExpressionNode.right = structPush(parser->arena, ASTNode);
        node->binaryExpressionNode.operator = type;

        parseExpressionImpl(parser, node->binaryExpressionNode.right, precedence);
    }

    return node;
}

static bool
parseExpression(Parser *parser, ASTNode *node) {
    return parseExpressionImpl(parser, node, 0) != 0x0;
}

static bool
tryParseVariableDeclaration(Parser *parser, ASTNode *node) {
    u32 startPosition = getCurrentParserPosition(parser);
    if(!parseType(parser, node)) {
        setCurrentParserPosition(parser, startPosition);
        return false;
    }

    u32 dataLocation = 0;
    if(acceptToken(parser, TokenType_Memory)) {
        dataLocation = 1;
    } else if(acceptToken(parser, TokenType_Storage)) {
        dataLocation = 2;
    } else if(acceptToken(parser, TokenType_Calldata)) {
        dataLocation = 3;
    }

    TokenId name = parseIdentifier(parser);
    if(name == INVALID_TOKEN_ID) {
        setCurrentParserPosition(parser, startPosition);
        return false;
    }

    ASTNode *type = structPush(parser->arena, ASTNode);
    *type = *node;

    node->type = ASTNodeType_VariableDeclaration;
    ASTNodeVariableDeclaration *decl = &node->variableDeclarationNode;
    decl->type = type;
    decl->name = name;
    decl->dataLocation = dataLocation;

    return true;
}

static bool
tryParseVariableDeclarationTuple(Parser *parser, ASTNode *node) {
    u32 startPosition = getCurrentParserPosition(parser);
    
    if(!acceptToken(parser, TokenType_LParen)) {
        setCurrentParserPosition(parser, startPosition);
        return false;
    }

    ASTNodeVariableDeclarationTupleStatement *tuple = &node->variableDeclarationTupleStatementNode;
    do {
        ASTNodeLink *declaration = structPush(parser->arena, ASTNodeLink);
        declaration->node.type = ASTNodeType_None;

        if(peekToken(parser).type != TokenType_Comma) {
            if(!tryParseVariableDeclaration(parser, &declaration->node)) {
                setCurrentParserPosition(parser, startPosition);
                return false;
            }
        }

        SLL_QUEUE_PUSH(tuple->declarations.head, tuple->declarations.last, declaration);
        tuple->declarations.count += 1;
    } while(acceptToken(parser, TokenType_Comma));

    expectToken(parser, TokenType_RParen);
    expectToken(parser, TokenType_Equal);

    parseExpression(parser, tuple->initialValue);

    node->type = ASTNodeType_VariableDeclarationTupleStatement;

    return true;
}

static bool
parseStatement(Parser *parser, ASTNode *node) {
    if(acceptToken(parser, TokenType_Return)) {
        ASTNode *returnStatement = node;
        returnStatement->type = ASTNodeType_ReturnStatement;
        returnStatement->returnStatementNode.expression = structPush(parser->arena, ASTNode);

        parseExpression(parser, returnStatement->returnStatementNode.expression);
        expectToken(parser, TokenType_Semicolon);
    } else if(acceptToken(parser, TokenType_If)) {
        node->type = ASTNodeType_IfStatement;
        ASTNodeIfStatement *ifStatement = &node->ifStatementNode;
        ifStatement->conditionExpression = structPush(parser->arena, ASTNode);

        expectToken(parser, TokenType_LParen);
        parseExpression(parser, ifStatement->conditionExpression);
        expectToken(parser, TokenType_RParen);

        ifStatement->trueStatement = structPush(parser->arena, ASTNode);
        parseStatement(parser, ifStatement->trueStatement);

        if(acceptToken(parser, TokenType_Else)) {
            ifStatement->falseStatement = structPush(parser->arena, ASTNode);
            parseStatement(parser, ifStatement->falseStatement);
        }
    } else if(acceptToken(parser, TokenType_LBrace)) {
        node->type = ASTNodeType_BlockStatement;

        while(!acceptToken(parser, TokenType_RBrace)) {
            ASTNodeLink *statement = structPush(parser->arena, ASTNodeLink);
            if(!parseStatement(parser, &statement->node)) {
                continue;
            }

            SLL_QUEUE_PUSH(node->blockStatementNode.statements.head, node->blockStatementNode.statements.last, statement);
            node->blockStatementNode.statements.count += 1;
        }
    } else if(acceptToken(parser, TokenType_Comment)) {
        return false;
    } else {
        if(tryParseVariableDeclaration(parser, node)) {
            ASTNode *varDeclNode = structPush(parser->arena, ASTNode);
            *varDeclNode = *node;

            node->type = ASTNodeType_VariableDeclarationStatement;
            ASTNodeVariableDeclarationStatement *statement = &node->variableDeclarationStatementNode;
            statement->variableDeclaration = varDeclNode;

            statement->initialValue = 0x0;
            if(acceptToken(parser, TokenType_Equal)) {
                statement->initialValue = structPush(parser->arena, ASTNode);
                parseExpression(parser, statement->initialValue);
            }

            expectToken(parser, TokenType_Semicolon);
        } else if(tryParseVariableDeclarationTuple(parser, node)) {
            expectToken(parser, TokenType_Semicolon);
        } else {
            ASTNode *expressionStatement = node;
            expressionStatement->type = ASTNodeType_ExpressionStatement;
            expressionStatement->expressionStatementNode.expression = structPush(parser->arena, ASTNode);

            parseExpression(parser, expressionStatement->expressionStatementNode.expression);
            expectToken(parser, TokenType_Semicolon);
        }
    }

    return true;
}

static bool
parseBlock(Parser *parser, ASTNode *node) {
    return parseStatement(parser, node);
}

static bool
parseConstVariable(Parser *parser, ASTNode *node, ASTNode *type) {
    node->type = ASTNodeType_ConstVariable;
    ASTNodeConstVariable *constVariable = &node->constVariableNode;

    constVariable->type = type;
    constVariable->identifier = parseIdentifier(parser);
    assert(constVariable->identifier > 0);

    expectToken(parser, TokenType_Equal);

    constVariable->expression = structPush(parser->arena, ASTNode);
    parseExpression(parser, constVariable->expression);

    expectToken(parser, TokenType_Semicolon);
    return true;
}

static bool
parseFunction(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_FunctionDefinition;
    TokenId name = parseIdentifier(parser);
    if(name == INVALID_TOKEN_ID) {
        if(acceptToken(parser, TokenType_Fallback) ||
           acceptToken(parser, TokenType_Receive)) {
            name = peekLastTokenId(parser);
        }
    }
    assert(name != INVALID_TOKEN_ID);
    ASTNodeFunctionDefinition *function = &node->functionDefinitionNode;
    function->name = name;

    expectToken(parser, TokenType_LParen);
    if(!acceptToken(parser, TokenType_RParen)) {
        do {
            FunctionParameter *parameter = structPush(parser->arena, FunctionParameter);
            parameter->type = structPush(parser->arena, ASTNode);
            parseType(parser, parameter->type);
            if(acceptToken(parser, TokenType_Memory)) {
                parameter->dataLocation = 1;
            } else if(acceptToken(parser, TokenType_Storage)) {
                parameter->dataLocation = 2;
            } else if(acceptToken(parser, TokenType_Calldata)) {
                parameter->dataLocation = 3;
            } else {
                parameter->dataLocation = 0;
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
        function->visibility = 0;
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

    if(acceptToken(parser, TokenType_Returns)) {
        expectToken(parser, TokenType_LParen);
        do {
            FunctionParameter *parameter = structPush(parser->arena, FunctionParameter);
            parameter->type = structPush(parser->arena, ASTNode);
            parseType(parser, parameter->type);
            if(acceptToken(parser, TokenType_Memory)) {
                parameter->dataLocation = 1;
            } else if(acceptToken(parser, TokenType_Storage)) {
                parameter->dataLocation = 2;
            } else if(acceptToken(parser, TokenType_Calldata)) {
                parameter->dataLocation = 3;
            } else {
                parameter->dataLocation = 0;
            }

            parameter->identifier = parseIdentifier(parser);

            SLL_QUEUE_PUSH(function->returnParameters.head, function->returnParameters.last, parameter);
            function->returnParameters.count += 1;
        } while(acceptToken(parser, TokenType_Comma));
        expectToken(parser, TokenType_RParen);
    }

    if(!acceptToken(parser, TokenType_Semicolon)) {
        function->body = structPush(parser->arena, ASTNode);
        parseBlock(parser, function->body);
    }

    return true;
}

static ASTNode
parseSourceUnit(Parser *parser) {
    ASTNode node = { .type = ASTNodeType_SourceUnit };

    while(true) {
        ASTNodeLink *child = arrayPush(parser->arena, ASTNodeLink, 1);

        if(acceptToken(parser, TokenType_Pragma)) {
            assert(parseIdentifier(parser));
            expectToken(parser, TokenType_Symbol);
            expectToken(parser, TokenType_Semicolon);
        } else if(acceptToken(parser, TokenType_Import)) {
            assert(parseImport(parser, &child->node));
        } else if(acceptToken(parser, TokenType_Enum)) {
            assert(parseEnum(parser, &child->node));
        } else if(acceptToken(parser, TokenType_Struct)) {
            assert(parseStruct(parser, &child->node));
        } else if(acceptToken(parser, TokenType_Error)) {
            assert(parseError(parser, &child->node));
        } else if(acceptToken(parser, TokenType_Event)) {
            assert(parseEvent(parser, &child->node));
        } else if(acceptToken(parser, TokenType_Type)) {
            assert(parseTypedef(parser, &child->node));
        } else if(acceptToken(parser, TokenType_Function)) {
            assert(parseFunction(parser, &child->node));
        } else if(acceptToken(parser, TokenType_EOF)) {
            break;
        } else if(acceptToken(parser, TokenType_Comment)) {
            continue;
        } else {
            ASTNode *type = structPush(parser->arena, ASTNode);
            parseType(parser, type);
            if(acceptToken(parser, TokenType_Constant)) {
                parseConstVariable(parser, &child->node, type);
            }
        }

        SLL_QUEUE_PUSH(node.children.head, node.children.last, child);
        node.children.count += 1;
    }

    return node;
}
