typedef enum ASTNodeType_Enum {
    ASTNodeType_None,
    ASTNodeType_SourceUnit,
    ASTNodeType_Import, ASTNodeType_EnumDefinition,
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
    ASTNodeType_WhileStatement,
    ASTNodeType_ContractDefinition,
    ASTNodeType_RevertStatement,
    ASTNodeType_StateVariableDeclaration,
    ASTNodeType_LibraryDefinition,
    ASTNodeType_TerneryExpression,
    ASTNodeType_ForStatement,
    ASTNodeType_BreakStatement,
    ASTNodeType_ContinueStatement,
    ASTNodeType_UnaryExpressionPostfix,
    ASTNodeType_HexStringLitExpression,
    ASTNodeType_ArraySliceExpression,
    ASTNodeType_UncheckedBlockStatement,
    ASTNodeType_ModifierDefinition,
    ASTNodeType_FallbackFunction,
    ASTNodeType_ReceiveFunction,
    ASTNodeType_EmitStatement,
    ASTNodeType_ConstructorDefinition,
    ASTNodeType_NamedParameterExpression,
    ASTNodeType_InterfaceDefinition,
    ASTNodeType_AbstractContractDefinition,
    ASTNodeType_InheritanceSpecifier,
    ASTNodeType_NameValue,
    ASTNodeType_Pragma,
    ASTNodeType_ModifierInvocation,
    ASTNodeType_Using,
    ASTNodeType_UnicodeStringLitExpression,
    ASTNodeType_InlineArrayExpression,
    ASTNodeType_DoWhileStatement,
    ASTNodeType_TryStatement,
    ASTNodeType_CatchStatement,
    ASTNodeType_AssemblyStatement,
    ASTNodeType_YulBlockStatement,
    ASTNodeType_YulVariableDeclaration,
    ASTNodeType_YulNumberLitExpression,
    ASTNodeType_YulStringLitExpression,
    ASTNodeType_YulHexNumberLitExpression,
    ASTNodeType_YulBoolLitExpression,
    ASTNodeType_YulHexStringLitExpression,
    ASTNodeType_YulMemberAccessExpression,
    ASTNodeType_YulFunctionCallExpression,
    ASTNodeType_YulVariableAssignment,
    ASTNodeType_YulIfStatement,
    ASTNodeType_YulForStatement,
    ASTNodeType_YulLeaveStatement,
    ASTNodeType_YulBreakStatement,
    ASTNodeType_YulContinueStatement,
    ASTNodeType_YulFunctionDefinition,
    ASTNodeType_YulSwitchStatement,
    ASTNodeType_YulCaseStatement,
    ASTNodeType_Count,
} ASTNodeType_Enum;

typedef u32 ASTNodeType;

typedef struct ASTNode ASTNode;
typedef struct ASTNodeLink ASTNodeLink;

typedef struct ASTNodeList {
    ASTNodeLink *head;
    ASTNodeLink *last;
    u32 count;
} ASTNodeList;

typedef struct ASTNodeStruct {
    TokenId nameTokenId;
    ASTNodeList members;
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
    ASTNodeList parameters;
    u16 visibility;
    u16 stateMutability;
    ASTNodeList returnParameters;
} ASTNodeFunctionType;

typedef struct ASTNodeArrayType {
    ASTNode *elementType;
    ASTNode *lengthExpression;
} ASTNodeArrayType;

typedef struct ASTNodeError {
    TokenId identifier;
    ASTNodeList parameters;
} ASTNodeError;

typedef struct ASTNodeEvent {
    TokenId identifier;
    ASTNodeList parameters;
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
    u8 visibility;
    u8 mutability;
    u8 override;
    ASTNodeList overrides;
} ASTNodeConstVariable;

typedef struct ASTNodeNumberLitExpression {
    TokenId value;
    TokenId subdenomination;
} ASTNodeNumberLitExpression;

typedef struct ASTNodeStringLitExpression {
    TokenIdList values;
} ASTNodeStringLitExpression;

typedef struct ASTNodeTokenLitExpression {
    TokenId value;
} ASTNodeTokenLitExpression;

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
    ASTNodeList argumentsExpression;
    TokenIdList argumentsName;
} ASTNodeFunctionCallExpression;

typedef struct ASTNodeMemberAccessExpression {
    ASTNode *expression;
    TokenId memberName;
} ASTNodeMemberAccessExpression;

typedef struct ASTNodeArrayAccessExpression {
    ASTNode *expression;
    ASTNode *indexExpression;
} ASTNodeArrayAccessExpression;

typedef struct ASTNodeArraySliceExpression {
    ASTNode *expression;
    ASTNode *leftFenceExpression;
    ASTNode *rightFenceExpression;
} ASTNodeArraySliceExpression;

typedef struct ASTNodeTerneryExpression {
    ASTNode *condition;
    ASTNode *trueExpression;
    ASTNode *falseExpression;
} ASTNodeTerneryExpression;

typedef struct ASTNodeFunctionDefinition {
    TokenId name;                 // 4 bytes
    ASTNodeList parameters;       // 12 bytes
    u8 visibility;                // 1 byte
    u8 stateMutability;           // 1 byte
    u8 virtual;                   // 1 byte
    u8 override;                  // 1 byte
    ASTNodeList overrides;        // 12 bytes
    ASTNodeList modifiers;        // 12 bytes
    ASTNodeList returnParameters; // 12 bytes
    ASTNode *body;                // 4 bytes
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

typedef struct ASTNodeWhileStatement {
    ASTNode *expression;
    ASTNode *body;
} ASTNodeWhileStatement;

typedef struct ASTNodeInheritanceSpecifier {
    ASTNode *identifier;
    TokenIdList argumentsName;
    ASTNodeList argumentsExpression;
} ASTNodeInheritanceSpecifier;

typedef ASTNodeInheritanceSpecifier ASTNodeModifierInvocation;

typedef struct ASTNodeContractDefinition {
    TokenId name;
    ASTNodeList elements;
    ASTNodeList baseContracts;
} ASTNodeContractDefinition;

typedef struct ASTNodeLibraryDefinition {
    TokenId name;
    ASTNodeList elements;
} ASTNodeLibraryDefinition;

typedef struct ASTNodeForStatement {
    ASTNode *variableStatement;
    ASTNode *conditionExpression;
    ASTNode *incrementExpression;
    ASTNode *body;
} ASTNodeForStatement;

typedef struct ASTNodeUncheckedBlockStatement {
    ASTNode *block;
} ASTNodeUncheckedBlockStatement;

typedef struct ASTNodeRevertStatement {
    ASTNode *expression;
    ASTNodeList argumentExpressions;
    ASTNodeList argumentNames;
} ASTNodeRevertStatement;

typedef struct ASTNodeEmitStatement {
    ASTNode *expression;
} ASTNodeEmitStatement;

typedef struct ASTNodeConstructorDefinition {
    ASTNodeList parameters;
    u8 visibility;
    u8 stateMutability;
    u8 virtual;
    ASTNodeList modifiers;
    ASTNode *body;
} ASTNodeConstructorDefinition;

typedef struct ASTNodeNamedParametersExpression {
    ASTNode *expression;
    // TODO(radomski): This probably should be a different node, but I'm lazy
    // so I'm going to store the start and end token inline
    u32 listStartToken;
    u32 listEndToken;
    TokenIdList names;
    ASTNodeList expressions;
} ASTNodeNamedParametersExpression;

typedef struct ASTNodeNameValue {
    TokenId name;
    ASTNode *value;
} ASTNodeNameValue;

typedef struct ASTNodePragma {
    TokenId major;
    TokenIdList following;
} ASTNodePragma;

typedef struct ASTNodeUsing {
    ASTNodeList identifiers;
    U16List operators;
    ASTNode *forType;
    u8 global;
    u8 onLibrary;
} ASTNodeUsing;

typedef struct ASTNodeInlineArrayExpression {
    ASTNodeList expressions;
} ASTNodeInlineArrayExpression;

typedef struct ASTNodeTryStatement {
    ASTNode *expression;
    ASTNodeList returnParameters;
    ASTNode *body;
    ASTNodeList catches;
} ASTNodeTryStatement;

typedef struct ASTNodeCatchStatement {
    TokenId identifier;
    ASTNodeList parameters;
    ASTNode *body;
} ASTNodeCatchStatement;

typedef struct ASTNodeAssemblyStatement {
    u8 isEVMAsm;
    TokenIdList flags;
    ASTNode *body;
} ASTNodeAssemblyStatement;

typedef struct ASTNodeYulVariableDeclaration {
    TokenIdList identifiers;
    ASTNode *value;
} ASTNodeYulVariableDeclaration;

typedef struct ASTNodeYulVariableAssignment {
    ASTNodeList paths;
    ASTNode *value;
} ASTNodeYulVariableAssignment;

typedef struct ASTNodeYulNumberLitExpression {
    TokenId value;
} ASTNodeYulNumberLitExpression;

typedef struct ASTNodeYulIdentifierPathExpression {
    u32 count;
    TokenId identifiers[2];
} ASTNodeYulIdentifierPathExpression;

typedef struct ASTNodeYulFunctionCallExpression {
    TokenId identifier;
    ASTNodeList arguments;
} ASTNodeYulFunctionCallExpression;

typedef struct ASTNodeYulIfStatement {
    ASTNode *expression;
    ASTNode *body;
} ASTNodeYulIfStatement;

typedef struct ASTNodeYulForStatement {
    ASTNode *variableDeclaration;
    ASTNode *condition;
    ASTNode *increment;
    ASTNode *body;
} ASTNodeYulForStatement;

typedef struct ASTNodeYulFunctionDefinition {
    TokenId identifier;
    TokenIdList parameters;
    TokenIdList returnParameters;
    ASTNode *body;
} ASTNodeYulFunctionDefinition;

typedef struct ASTNodeYulCase {
    ASTNode *literal;
    ASTNode *block;
} ASTNodeYulCase;

typedef struct ASTNodeYulSwitchStatement {
    ASTNode *expression;
    ASTNodeList cases;
    ASTNode *defaultBlock;
} ASTNodeYulSwitchStatement;

typedef struct ASTNode {
    ASTNodeType type;

    u32 startToken;
    u32 endToken;

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
        ASTNodePragma pragmaNode;
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
        ASTNodeConstVariable stateVariableDeclarataion;
        ASTNodeNumberLitExpression numberLitExpressionNode;
        ASTNodeStringLitExpression stringLitExpressionNode;
        ASTNodeTokenLitExpression boolLitExpressionNode;
        ASTNodeTokenLitExpression identifierExpressionNode;
        ASTNodeBinaryExpression binaryExpressionNode;
        ASTNodeTupleExpression tupleExpressionNode;
        ASTNodeUnaryExpression unaryExpressionNode;
        ASTNodeNewExpression newExpressionNode;
        ASTNodeFunctionCallExpression functionCallExpressionNode;
        ASTNodeMemberAccessExpression memberAccessExpressionNode;
        ASTNodeArrayAccessExpression arrayAccessExpressionNode;
        ASTNodeArraySliceExpression arraySliceExpressionNode;
        ASTNodeTerneryExpression terneryExpressionNode;
        ASTNodeNamedParametersExpression namedParametersExpressionNode;
        ASTNodeInlineArrayExpression inlineArrayExpressionNode;
        ASTNodeFunctionDefinition functionDefinitionNode;
        ASTNodeBlockStatement blockStatementNode;
        ASTNodeUncheckedBlockStatement uncheckedBlockStatementNode;
        ASTNodeReturnStatement returnStatementNode;
        ASTNodeReturnStatement expressionStatementNode;
        ASTNodeIfStatement ifStatementNode;
        ASTNodeVariableDeclarationStatement variableDeclarationStatementNode;
        ASTNodeVariableDeclaration variableDeclarationNode;
        ASTNodeVariableDeclarationTupleStatement variableDeclarationTupleStatementNode;
        ASTNodeWhileStatement whileStatementNode;
        ASTNodeWhileStatement doWhileStatementNode;
        ASTNodeInheritanceSpecifier inheritanceSpecifierNode;
        ASTNodeModifierInvocation modifierInvocationNode;
        ASTNodeContractDefinition contractDefinitionNode;
        ASTNodeLibraryDefinition libraryDefinitionNode;
        ASTNodeRevertStatement revertStatementNode;
        ASTNodeForStatement forStatementNode;
        ASTNodeEmitStatement emitStatementNode;
        ASTNodeTryStatement tryStatementNode;
        ASTNodeCatchStatement catchStatementNode;
        ASTNodeAssemblyStatement assemblyStatementNode;
        ASTNodeConstructorDefinition constructorDefinitionNode;
        ASTNodeNameValue nameValueNode;
        ASTNodeUsing usingNode;

        ASTNodeBlockStatement yulBlockStatementNode;
        ASTNodeYulVariableDeclaration yulVariableDeclarationNode;
        ASTNodeYulNumberLitExpression yulNumberLitExpressionNode;
        ASTNodeYulNumberLitExpression yulStringLitExpressionNode;
        ASTNodeYulNumberLitExpression yulHexNumberLitExpressionNode;
        ASTNodeYulNumberLitExpression yulBoolLitExpressionNode;
        ASTNodeYulNumberLitExpression yulHexStringLitExpressionNode;
        ASTNodeYulIdentifierPathExpression yulIdentifierPathExpressionNode;
        ASTNodeYulFunctionCallExpression yulFunctionCallExpressionNode;
        ASTNodeYulVariableAssignment yulVariableAssignmentNode;
        ASTNodeYulIfStatement yulIfStatementNode;
        ASTNodeYulForStatement yulForStatementNode;
        ASTNodeYulFunctionDefinition yulFunctionDefinitionNode;
        ASTNodeYulSwitchStatement yulSwitchStatementNode;
        ASTNodeYulCase yulCaseNode;
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

#define reportError(parser, userErrorFormat, ...) _reportError(parser, __FILE__, __LINE__, userErrorFormat, ##__VA_ARGS__)
#define assertError(condition, parser, userErrorFormat, ...) _assertError((bool)(condition), parser, __FILE__, __LINE__, userErrorFormat, ##__VA_ARGS__)

static void
reportErrorVarArgs(Parser *parser, const char *file, u32 line, const char *userErrorFormat, va_list args) {
    va_list copiedArgs;
    va_copy(copiedArgs, args);
    String userError = stringPushfv(parser->arena, userErrorFormat, copiedArgs);
    va_end(copiedArgs);

    u32 byteOffset = parser->tokens[parser->current].string.data - parser->tokens[0].string.data;
    String error = stringPushf(parser->arena, "ERROR [%s:%d] - [%d]: %S", file, line, byteOffset, userError);

    memoryUsed = arenaTakenBytes(parser->arena);
    bumpPointerArenaTop = (unsigned int)structPush(parser->arena, int);
    javascriptPrintStringPtr(&error);
    unreachable();
}

static void
_reportError(Parser *parser, const char *file, u32 line, const char *userErrorFormat, ...) {
    va_list args;
    va_start(args, userErrorFormat);
    reportErrorVarArgs(parser, file, line, userErrorFormat, args);
    va_end(args);
}

static void
_assertError(bool condition, Parser *parser, const char *file, u32 line, const char *userErrorFormat, ...) {
    if(!condition) {
        va_list args;
        va_start(args, userErrorFormat);
        reportErrorVarArgs(parser, file, line, userErrorFormat, args);
        va_end(args);
    }
}

static Token
peekToken(Parser *parser) {
    return parser->tokens[parser->current];
}

static u32
peekLastTokenId(Parser *parser) {
    assertError(parser->current > 0, parser, "No tokens to peek");
    return parser->current - 1;
}

static Token
peekLastToken(Parser *parser) {
    assertError(parser->current > 0, parser, "No tokens to peek");
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

static bool
nextTokenIs(Parser *parser, TokenType type) {
    if(peekToken(parser).type == type) {
        return true;
    }

    return false;
}

static void
_expectToken(Parser *parser, TokenType type, const char *file, u32 line) {
    bool success = acceptToken(parser, type);
    if(!success) {
        _reportError(parser, file, line, "Unexpected token => encountered (%S) but wanted (%S)", tokenTypeToString(peekToken(parser).type), tokenTypeToString(type));
    }
}

#define expectToken(parser, type) _expectToken(parser, type, __FILE__, __LINE__)

static u32
getCurrentParserPosition(Parser *parser) {
    return parser->current;
}

static void
setCurrentParserPosition(Parser *parser, u32 newPosition) {
    parser->current = newPosition;
}

static bool parseExpression(Parser *parser, ASTNode *node);

static bool
acceptYulToken(YulLexer *lexer, YulTokenType type) {
    if(peekYulToken(lexer).type == type) {
        advanceYulToken(lexer);
        return true;
    }

    return false;
}

#define expectYulToken(parser, lexer, type) _expectYulToken(parser, lexer, type, __FILE__, __LINE__)

static void
_expectYulToken(Parser *parser, YulLexer *lexer, YulTokenType type, const char *file, u32 line) {
    bool success = acceptYulToken(lexer, type);
    if(!success) {
        _reportError(parser, file, line, "Unexpected token => encountered (%d) but wanted (%d)", peekYulToken(lexer).type, type);
    }
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

static bool
isFixedPointNumberType(String string, String fixedPointPrefix) {
    if(stringStartsWith(string, fixedPointPrefix)) {
        String suffix = {
            .data = string.data + fixedPointPrefix.size,
            .size = string.size - fixedPointPrefix.size
        };

        SplitIterator it = stringSplit(suffix, 'x');
        String MString = stringNextInSplit(&it);
        String NString = stringNextInSplit(&it);

        if(MString.data == 0x0 && NString.data == 0x0) {
            return false;
        }

        if(!stringIsInteger(MString) || !stringIsInteger(NString)) {
            return false;
        }

        u32 M = stringToInteger(MString);
        u32 N = stringToInteger(NString);

        if(M < 8 || M > 256 || (M % 8) != 0) {
            return false;
        }

        if(N > 80) {
            return false;
        }

        return true;
    }

    return false;
}

// TODO(radomski): This is obviously stupid
static bool
isBaseTypeName(String string) {
    static String elementaryTypeNames[] = {
        LIT_TO_STR("address"),
        LIT_TO_STR("bool"),
        LIT_TO_STR("string"),
        LIT_TO_STR("byte"),
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
        LIT_TO_STR("var"),
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

    bool isFixed = isFixedPointNumberType(string, LIT_TO_STR("fixed"));
    bool isUFixed = isFixedPointNumberType(string, LIT_TO_STR("ufixed"));

    return isFixed || isUFixed;
}

static bool parseType(Parser *parser, ASTNode *node);

static bool
parseVariableDeclarationIntoList(Parser *parser, ASTNodeList *list) {
    ASTNodeLink *parameter = structPush(parser->arena, ASTNodeLink);
    ASTNode *node = &parameter->node;
    node->type = ASTNodeType_VariableDeclaration;
    node->startToken = parser->current;
    ASTNodeVariableDeclaration *variableDeclaration = &node->variableDeclarationNode;

    variableDeclaration->type = structPush(parser->arena, ASTNode);
    bool isSuccess = parseType(parser, variableDeclaration->type);
    if(!isSuccess) {
        return false;
    }

    variableDeclaration->dataLocation = 0;
    if(acceptToken(parser, TokenType_Memory)) {
        variableDeclaration->dataLocation = 1;
    } else if(acceptToken(parser, TokenType_Storage)) {
        variableDeclaration->dataLocation = 2;
    } else if(acceptToken(parser, TokenType_Calldata)) {
        variableDeclaration->dataLocation = 3;
    } else if(acceptToken(parser, TokenType_Indexed)) {
        variableDeclaration->dataLocation = 4;
    }

    variableDeclaration->name = parseIdentifier(parser);
    node->endToken = parser->current - 1;

    SLL_QUEUE_PUSH(list->head, list->last, parameter);
    list->count += 1;

    return true;
}

static void
parseFunctionParameters(Parser *parser, ASTNodeList *list) {
    parseVariableDeclarationIntoList(parser, list);
    while(acceptToken(parser, TokenType_Comma)) {
        assertError(parseVariableDeclarationIntoList(parser, list),
                    parser, "Expected variable declaration after comma");
    }
}

static bool
parseType(Parser *parser, ASTNode *node) {
    TokenId identifier = INVALID_TOKEN_ID;

    u32 startToken = parser->current;
    node->startToken = startToken;
    if(acceptToken(parser, TokenType_Mapping)) {
        node->type = ASTNodeType_MappingType;
        ASTNodeMapping *mapping = &node->mappingNode;

        expectToken(parser, TokenType_LParen);
        mapping->keyType = structPush(parser->arena, ASTNode);
        parseType(parser, mapping->keyType);
        assertError(mapping->keyType->type == ASTNodeType_BaseType ||
                    mapping->keyType->type == ASTNodeType_IdentifierPath,
                    parser, "Mapping key type must be a base type or an identifier path");
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
        if(!acceptToken(parser, TokenType_LParen)) {
            return false;
        }

        if(!acceptToken(parser, TokenType_RParen)) {
            parseFunctionParameters(parser, &function->parameters);
            expectToken(parser, TokenType_RParen);
        }

        function->stateMutability = 0;
        function->visibility = 0;
        for(;;) {
            if(acceptToken(parser, TokenType_Internal)) {
                if(function->visibility != 0) {
                    parser->current -= 1;
                    break;
                }
                function->visibility = 1;
            } else if(acceptToken(parser, TokenType_External)) {
                if(function->visibility != 0) { 
                    parser->current -= 1;
                    break;
                }
                function->visibility = 2;
            } else if(acceptToken(parser, TokenType_Private)) {
                if(function->visibility != 0) {
                    parser->current -= 1;
                    break;
                }
                function->visibility = 3;
            } else if(acceptToken(parser, TokenType_Public)) {
                if(function->visibility != 0) {
                    parser->current -= 1;
                    break;
                }
                function->visibility = 4;
            } else if(acceptToken(parser, TokenType_Pure)) {
                function->stateMutability = 1;
            } else if(acceptToken(parser, TokenType_View)) {
                function->stateMutability = 2;
            } else if(acceptToken(parser, TokenType_Payable)) {
                function->stateMutability = 3;
            } else {
                break;
            }
        }

        if(acceptToken(parser, TokenType_Returns)) {
            expectToken(parser, TokenType_LParen);

            if(!acceptToken(parser, TokenType_RParen)) {
                parseFunctionParameters(parser, &function->returnParameters);
                assertError(function->returnParameters.count > 0, parser, "Expected return parameters");
                expectToken(parser, TokenType_RParen);
            }
        }
    } else if((identifier = parseIdentifier(parser)) != INVALID_TOKEN_ID) {
        if(isBaseTypeName(parser->tokens[identifier].string)) {
            node->type = ASTNodeType_BaseType;
            node->baseTypeNode.typeName = identifier;

            node->baseTypeNode.payable = 0;
            if(acceptToken(parser, TokenType_Payable)) {
                bool isAddress = stringMatch(parser->tokens[identifier].string, LIT_TO_STR("address"));
                if(!isAddress) {
                    reportError(parser, "Only address types can be payable");
                }
                node->baseTypeNode.payable = 1;
            }
        } else {
            node->type = ASTNodeType_IdentifierPath;
            listPushTokenId(&node->identifierPathNode.identifiers, identifier, parser->arena);
            while(acceptToken(parser, TokenType_Dot)) {
                TokenId nextIdentifier = parseIdentifier(parser);
                assertError(nextIdentifier != INVALID_TOKEN_ID, parser,
                            "Expected identifier after dot, received (%S)", tokenTypeToString(peekToken(parser).type));
                listPushTokenId(&node->identifierPathNode.identifiers, nextIdentifier, parser->arena);
            }
        }
    } else {
        return false;
    }
    node->endToken = parser->current - 1;

    while(acceptToken(parser, TokenType_LBracket)) {
        ASTNode *copy = structPush(parser->arena, ASTNode);
        *copy = *node;

        node->startToken = startToken;
        node->type = ASTNodeType_ArrayType;
        node->arrayTypeNode.elementType = copy;
        node->arrayTypeNode.lengthExpression = 0x0;
        if(acceptToken(parser, TokenType_Colon)) {
            return false;
        }

        if(!acceptToken(parser, TokenType_RBracket)) {
            node->arrayTypeNode.lengthExpression = structPush(parser->arena, ASTNode);
            parseExpression(parser, node->arrayTypeNode.lengthExpression);
            if(!acceptToken(parser, TokenType_RBracket)) {
                return false;
            }
        }
        node->endToken = parser->current - 1;
    }

    return true;
}

static bool
parsePragma(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    node->type = ASTNodeType_Pragma;
    ASTNodePragma *pragma = &node->pragmaNode;

    pragma->major = parseIdentifier(parser);
    assertError(pragma->major != INVALID_TOKEN_ID, parser,
                "Expected identifier after pragma, received (%S)", tokenTypeToString(peekToken(parser).type));

    while(!acceptToken(parser, TokenType_Semicolon)) {
        if(acceptToken(parser, TokenType_EOF)) {
            reportError(parser, "Unexpected EOF while parsing pragma");
        }

        TokenId part = parser->current++;
        listPushTokenId(&pragma->following, part, parser->arena);
    }
    assertError(pragma->following.count > 0, parser, "Expected pragma body");

    node->endToken = parser->current - 1;

    return true;
}

static bool
parseImport(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    if(acceptToken(parser, TokenType_StringLit)) {
        node->pathTokenId = peekLastTokenId(parser);

        node->unitAliasTokenId = INVALID_TOKEN_ID;
        if(acceptToken(parser, TokenType_As)) {
            TokenId unitAliasTokenId = parseIdentifier(parser);
            assertError(unitAliasTokenId != INVALID_TOKEN_ID, parser,
                        "Expected identifier in import alias, received (%S)", tokenTypeToString(peekToken(parser).type));
            node->unitAliasTokenId = unitAliasTokenId;
        }
    } else if(acceptToken(parser, TokenType_Star)) {
        expectToken(parser, TokenType_As);
        TokenId unitAliasTokenId = parseIdentifier(parser);
        assertError(unitAliasTokenId != INVALID_TOKEN_ID, parser,
                    "Expected identifier in import alias, received (%S)", tokenTypeToString(peekToken(parser).type));
        node->unitAliasTokenId = unitAliasTokenId;
        expectToken(parser, TokenType_From);
        expectToken(parser, TokenType_StringLit);
        node->pathTokenId = peekLastTokenId(parser);
    } else if(acceptToken(parser, TokenType_LBrace)) {
       do {
            TokenId symbolName = parseIdentifier(parser);
            assertError(symbolName != INVALID_TOKEN_ID, parser,
                        "Expected identifier in import symbol list, received (%S)", tokenTypeToString(peekToken(parser).type));
            listPushTokenId(&node->symbols, symbolName, parser->arena);

            if(acceptToken(parser, TokenType_As)) {
                TokenId symbolAliasName = parseIdentifier(parser);
                assertError(symbolAliasName != INVALID_TOKEN_ID, parser,
                            "Expected identifier in import symbol alias, received (%S)", tokenTypeToString(peekToken(parser).type));
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
        reportError(parser, "Unexpected token while parsing import - %S",
                    tokenTypeToString(peekToken(parser).type));
    }

    node->type = ASTNodeType_Import;

    expectToken(parser, TokenType_Semicolon);
    node->endToken = parser->current - 1;

    return true;
}

static u16
parseUserDefinableOperator(Parser *parser) {
    if(nextTokenIs(parser, TokenType_Ampersand) |
       nextTokenIs(parser, TokenType_Tylde) |
       nextTokenIs(parser, TokenType_Pipe) |
       nextTokenIs(parser, TokenType_Carrot) |
       nextTokenIs(parser, TokenType_Plus) |
       nextTokenIs(parser, TokenType_Divide) |
       nextTokenIs(parser, TokenType_Percent) |
       nextTokenIs(parser, TokenType_Star) |
       nextTokenIs(parser, TokenType_Minus) |
       nextTokenIs(parser, TokenType_EqualEqual) |
       nextTokenIs(parser, TokenType_RTick) |
       nextTokenIs(parser, TokenType_RightEqual) |
       nextTokenIs(parser, TokenType_LTick) |
       nextTokenIs(parser, TokenType_LeftEqual) |
       nextTokenIs(parser, TokenType_NotEqual)
      ) {
        return advanceToken(parser).type;
    }

    reportError(parser, "Unexpected token while parsing user definable operators - %S",
                tokenTypeToString(peekToken(parser).type));
    return 0;
}

static bool
parseUsing(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    if(acceptToken(parser, TokenType_LParen)) { 
        reportError(parser, "Using statement with parenthesis is not supported");
    }

    node->type = ASTNodeType_Using;
    ASTNodeUsing *using = &node->usingNode;

    if(acceptToken(parser, TokenType_LBrace)) {
        using->onLibrary = 0;
        do {
            ASTNodeLink *identifierLink = structPush(parser->arena, ASTNodeLink);
            bool isSuccess = parseType(parser, &identifierLink->node);
            assertError(isSuccess, parser, "Expected type in using statement, received (%S)", tokenTypeToString(peekToken(parser).type));
            SLL_QUEUE_PUSH(using->identifiers.head, using->identifiers.last, identifierLink);
            using->identifiers.count += 1;

            u16 operator = 0;
            if(acceptToken(parser, TokenType_As)) {
                operator = parseUserDefinableOperator(parser);
            }
            listPushU16(&using->operators, operator, parser->arena);
        } while(acceptToken(parser, TokenType_Comma));

        expectToken(parser, TokenType_RBrace);
    } else {
        using->onLibrary = 1;
        ASTNodeLink *identifierLink = structPush(parser->arena, ASTNodeLink);
        parseType(parser, &identifierLink->node);
        SLL_QUEUE_PUSH(using->identifiers.head, using->identifiers.last, identifierLink);
        using->identifiers.count += 1;
    }

    expectToken(parser, TokenType_For);

    if(acceptToken(parser, TokenType_Star)) {
        using->forType = 0x0;
    } else {
        using->forType = structPush(parser->arena, ASTNode);
        parseType(parser, using->forType);
    }

    using->global = 0;
    if(acceptToken(parser, TokenType_Global)) {
        using->global = 1;
    }

    expectToken(parser, TokenType_Semicolon);
    node->endToken = parser->current - 1;

    return true;
}

static bool
parseEnum(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    node->type = ASTNodeType_EnumDefinition;

    TokenId nameTokenId = parseIdentifier(parser);
    assertError(nameTokenId != INVALID_TOKEN_ID, parser,
                "Name of enum must be an identifier, received (%S)", tokenTypeToString(peekToken(parser).type));
    node->nameTokenId = nameTokenId;
    expectToken(parser, TokenType_LBrace);

    if(!acceptToken(parser, TokenType_RBrace)) {
        do {
            TokenId valueName = parseIdentifier(parser);
            assertError(valueName != INVALID_TOKEN_ID, parser,
                        "Enum value must be an identifier, received (%S)", tokenTypeToString(peekToken(parser).type));
            listPushTokenId(&node->values, valueName, parser->arena);
        } while(acceptToken(parser, TokenType_Comma));

        expectToken(parser, TokenType_RBrace);
    }

    node->endToken = parser->current - 1;

    return true;
}

static bool
parseStruct(Parser *parser, ASTNode *baseNode) {
    baseNode->startToken = parser->current - 1;
    baseNode->type = ASTNodeType_Struct;
    ASTNodeStruct *node = &baseNode->structNode;

    TokenId nameTokenId = parseIdentifier(parser);
    assertError(nameTokenId != INVALID_TOKEN_ID, parser,
                "Name of struct must be an identifier, received (%S)", tokenTypeToString(peekToken(parser).type));
    node->nameTokenId = nameTokenId;
    expectToken(parser, TokenType_LBrace);

    while(!acceptToken(parser, TokenType_RBrace)) {
        parseVariableDeclarationIntoList(parser, &node->members);
        expectToken(parser, TokenType_Semicolon);
    }

    baseNode->endToken = parser->current - 1;
    return true;
}

static bool
parseError(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    node->type = ASTNodeType_Error;
    ASTNodeError *error = &node->errorNode;
    error->identifier = parseIdentifier(parser);
    assertError(error->identifier != INVALID_TOKEN_ID, parser,
                "Name of error must be an identifier, received (%S)", tokenTypeToString(peekToken(parser).type));

    expectToken(parser, TokenType_LParen);
    if(!acceptToken(parser, TokenType_RParen)) {
        parseFunctionParameters(parser, &error->parameters);
        expectToken(parser, TokenType_RParen);
    }
    expectToken(parser, TokenType_Semicolon);
    node->endToken = parser->current - 1;
    return true;
}

static bool
parseEvent(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    node->type = ASTNodeType_Event;
    ASTNodeEvent *event = &node->eventNode;
    event->identifier = parseIdentifier(parser);
    assertError(event->identifier != INVALID_TOKEN_ID, parser,
                "Name of event must be an identifier, received (%S)", tokenTypeToString(peekToken(parser).type));

    expectToken(parser, TokenType_LParen);

    if(!acceptToken(parser, TokenType_RParen)) {
        parseFunctionParameters(parser, &event->parameters);
        expectToken(parser, TokenType_RParen);
    }

    if(acceptToken(parser, TokenType_Anonymous)) {
        event->anonymous = 1;
    }

    expectToken(parser, TokenType_Semicolon);
    node->endToken = parser->current - 1;
    return true;
}

static bool
parseTypedef(Parser *parser, ASTNode *node) {
    node->startToken = parser->current - 1;
    node->type = ASTNodeType_Typedef;
    ASTNodeTypedef *typedefNode = &node->typedefNode;

    typedefNode->identifier = parseIdentifier(parser);
    assertError(typedefNode->identifier != INVALID_TOKEN_ID, parser,
                "Name of typedef must be an identifier, received (%S)", tokenTypeToString(peekToken(parser).type));

    expectToken(parser, TokenType_Is);

    typedefNode->type = structPush(parser->arena, ASTNode);
    parseType(parser, typedefNode->type);
    assertError(typedefNode->type->type == ASTNodeType_BaseType, parser,
                "Typedef type must be a base type");
    expectToken(parser, TokenType_Semicolon);
    node->endToken = parser->current - 1;
    return true;
}

static bool
isOperator(TokenType type) {
    switch(type) {
        case TokenType_PlusPlus:
        case TokenType_MinusMinus:
        case TokenType_Dot:
        case TokenType_LParen:
        case TokenType_LBrace:
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
        case TokenType_PercentEqual:
        case TokenType_QuestionMark: return true;
        default: return false;
    }
}

static u32
getOperatorPrecedence(Parser *parser, TokenType type) {
    switch(type) {
        case TokenType_PlusPlus:
        case TokenType_MinusMinus:
        case TokenType_Dot:
        case TokenType_LParen:
        case TokenType_LBrace:
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
        case TokenType_QuestionMark: return -14;
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
        case TokenType_PercentEqual: return -15;
        default: reportError(parser, "Found token is not an operator - %S", tokenTypeToString(type));
    }

    return 0;
}

static bool
isUnaryOperator(TokenType type) {
    switch(type) {
        case TokenType_New:
        case TokenType_Exclamation:
        case TokenType_Minus:
        case TokenType_Plus:
        case TokenType_Tylde:
        case TokenType_PlusPlus:
        case TokenType_MinusMinus:
        case TokenType_Delete: return true;
        default: return false;
    }
}

static u32
getUnaryOperatorPrecedence(Parser *parser, TokenType type) {
    switch(type) {
        case TokenType_New: return -1;
        case TokenType_Exclamation:
        case TokenType_Minus:
        case TokenType_Plus:
        case TokenType_Tylde:
        case TokenType_PlusPlus:
        case TokenType_MinusMinus:
        case TokenType_Delete: return -2;
        default: reportError(parser, "Found token is not an unary operator - %S", tokenTypeToString(type));
    }

    return 0;
}

static bool parseExpressionImpl(Parser *parser, ASTNode *node, u32 previousPrecedence);

static void
parseCallArgumentList(Parser *parser, ASTNodeList *expressions, TokenIdList *names) {
    if(!acceptToken(parser, TokenType_RParen)) {
        if(acceptToken(parser, TokenType_LBrace)) {
            do {
                TokenId identifier = parseIdentifier(parser);
                assertError(identifier != INVALID_TOKEN_ID, parser,
                            "Expected identifier in call argument list, received (%S)", tokenTypeToString(peekToken(parser).type));
                listPushTokenId(names, identifier, parser->arena);

                expectToken(parser, TokenType_Colon);

                ASTNodeLink *expression = structPush(parser->arena, ASTNodeLink);
                parseExpressionImpl(parser, &expression->node, 0);

                SLL_QUEUE_PUSH(expressions->head, expressions->last, expression);
                expressions->count += 1;
            } while(acceptToken(parser, TokenType_Comma));
            expectToken(parser, TokenType_RBrace);
        } else {
            do {
                ASTNodeLink *argument = structPush(parser->arena, ASTNodeLink);
                parseExpressionImpl(parser, &argument->node, 0);

                SLL_QUEUE_PUSH(expressions->head, expressions->last, argument);
                expressions->count += 1;
            } while(acceptToken(parser, TokenType_Comma));
        }
        expectToken(parser, TokenType_RParen);
    }
}

static ASTNode *
parseFunctionCallExpression(Parser *parser, ASTNode *node) {
    ASTNode *expression = structPush(parser->arena, ASTNode);
    *expression = *node;
    expression->endToken = parser->current - 2;

    memset(node, 0, sizeof(ASTNode));
    node->startToken = expression->startToken;
    node->type = ASTNodeType_FunctionCallExpression;
    ASTNodeFunctionCallExpression *functionCall = &node->functionCallExpressionNode;

    functionCall->expression = expression;
    parseCallArgumentList(parser, &functionCall->argumentsExpression, &functionCall->argumentsName);

    return node;
}

static bool
parseExpressionImpl(Parser *parser, ASTNode *node, u32 previousPrecedence) {
    u32 startPosition = getCurrentParserPosition(parser);
    node->startToken = parser->current;

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
        do {
            TokenId literal = peekLastTokenId(parser);
            listPushTokenId(&node->stringLitExpressionNode.values, literal, parser->arena);
        } while(acceptToken(parser, TokenType_StringLit));
    } else if(acceptToken(parser, TokenType_HexStringLit)) {
        node->type = ASTNodeType_HexStringLitExpression;
        do {
            TokenId literal = peekLastTokenId(parser);
            listPushTokenId(&node->stringLitExpressionNode.values, literal, parser->arena);
        } while(acceptToken(parser, TokenType_HexStringLit));
    } else if(acceptToken(parser, TokenType_UnicodeStringLit)) {
        node->type = ASTNodeType_UnicodeStringLitExpression;
        do {
            TokenId literal = peekLastTokenId(parser);
            listPushTokenId(&node->stringLitExpressionNode.values, literal, parser->arena);
        } while(acceptToken(parser, TokenType_UnicodeStringLit));
    } else if(acceptToken(parser, TokenType_True) || acceptToken(parser, TokenType_False)) {
        node->type = ASTNodeType_BoolLitExpression;
        node->boolLitExpressionNode.value = peekLastTokenId(parser);
    } else if(acceptToken(parser, TokenType_LParen)) {
        node->type = ASTNodeType_TupleExpression;

        if(!acceptToken(parser, TokenType_RParen)) {
            do {
                ASTNodeLink *element = structPush(parser->arena, ASTNodeLink);
                element->node.type = ASTNodeType_None;

                if(!nextTokenIs(parser, TokenType_RParen) && !nextTokenIs(parser, TokenType_Comma)) {
                    parseExpressionImpl(parser, &element->node, 0);
                }
                SLL_QUEUE_PUSH(node->tupleExpressionNode.elements.head, node->tupleExpressionNode.elements.last, element);
                node->tupleExpressionNode.elements.count += 1;
            } while (acceptToken(parser, TokenType_Comma));

            expectToken(parser, TokenType_RParen);
        }
    } else if(acceptToken(parser, TokenType_LBracket)) {
        node->type = ASTNodeType_InlineArrayExpression;
        ASTNodeInlineArrayExpression *array = &node->inlineArrayExpressionNode;

        do {
            ASTNodeLink *element = structPush(parser->arena, ASTNodeLink);
            parseExpressionImpl(parser, &element->node, 0);
            SLL_QUEUE_PUSH(array->expressions.head, array->expressions.last, element);
            array->expressions.count += 1;
        } while(acceptToken(parser, TokenType_Comma));

        expectToken(parser, TokenType_RBracket);
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

            u32 precedence = getUnaryOperatorPrecedence(parser, node->unaryExpressionNode.operator);
            parseExpressionImpl(parser, node->unaryExpressionNode.subExpression, precedence);
        }
    } else if(parseIdentifier(parser) != INVALID_TOKEN_ID) {
        const Token ident = peekLastToken(parser);

        if(isBaseTypeName(ident.string)) {
            u32 startPosition = getCurrentParserPosition(parser);
            parser->current -= 1;
            if(!parseType(parser, node)) {
                setCurrentParserPosition(parser, startPosition);
                u32 startPosition = getCurrentParserPosition(parser);
                node->type = ASTNodeType_BaseType;
                node->baseTypeNode.typeName = peekLastTokenId(parser);

                node->baseTypeNode.payable = 0;
                if(acceptToken(parser, TokenType_Payable)) {
                    assertError(stringMatch(parser->tokens[node->baseTypeNode.typeName].string, LIT_TO_STR("address")),
                                parser, "Only address types can be payable");
                    node->baseTypeNode.payable = 1;
                }
            }
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
        reportError(parser, "Unexpected token while parsing expression - %S",
                    tokenTypeToString(peekToken(parser).type));
    }

    while(true) {
        startPosition = getCurrentParserPosition(parser);
        TokenType type = peekToken(parser).type;
        if(!isOperator(type)) {
            break;
        }

        u32 precedence = getOperatorPrecedence(parser, type);
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
            expression->endToken = parser->current - 2;

            ASTNode *firstExpression = 0x0;
            ASTNode *secondExpression = 0x0;

            ASTNodeType type = ASTNodeType_ArrayAccessExpression;
            if(!acceptToken(parser, TokenType_RBracket)) {
                if(!nextTokenIs(parser, TokenType_Colon)) {
                    firstExpression = structPush(parser->arena, ASTNode);
                    parseExpressionImpl(parser, firstExpression, 0);
                }

                if(acceptToken(parser, TokenType_Colon)) {
                    type = ASTNodeType_ArraySliceExpression;
                    if(!acceptToken(parser, TokenType_RBracket)) {
                        secondExpression = structPush(parser->arena, ASTNode);
                        parseExpressionImpl(parser, secondExpression, 0);
                        expectToken(parser, TokenType_RBracket);
                    }
                } else {
                    expectToken(parser, TokenType_RBracket);
                }
            }

            node->type = type;
            if(type == ASTNodeType_ArrayAccessExpression) {
                node->arrayAccessExpressionNode.expression = expression;
                node->arrayAccessExpressionNode.indexExpression = firstExpression;
            } else {
                node->arraySliceExpressionNode.expression = expression;
                node->arraySliceExpressionNode.leftFenceExpression = firstExpression;
                node->arraySliceExpressionNode.rightFenceExpression = secondExpression;
            }
            continue;
        } else if(type == TokenType_LBrace) {
            ASTNode *expression = structPush(parser->arena, ASTNode);
            *expression = *node;
            expression->endToken = parser->current - 2;

            memset(node, 0, sizeof(ASTNode));
            node->startToken = expression->startToken;
            node->type = ASTNodeType_NamedParameterExpression;
            node->namedParametersExpressionNode.expression = expression;

            node->namedParametersExpressionNode.listStartToken = parser->current;
            do {
                TokenId identifier = parseIdentifier(parser);

                if(identifier == INVALID_TOKEN_ID) {
                    setCurrentParserPosition(parser, startPosition);
                    *node = *expression;
                    return false;
                }

                assertError(identifier != INVALID_TOKEN_ID, parser,
                            "Expected identifier in named parameter list, received (%S)", tokenTypeToString(peekToken(parser).type));
                listPushTokenId(&node->namedParametersExpressionNode.names, identifier, parser->arena);

                if(!acceptToken(parser, TokenType_Colon)) {
                    setCurrentParserPosition(parser, startPosition);
                    *node = *expression;
                    return false;
                }

                ASTNodeLink *expression = structPush(parser->arena, ASTNodeLink);
                parseExpressionImpl(parser, &expression->node, 0);

                SLL_QUEUE_PUSH(node->namedParametersExpressionNode.expressions.head,
                               node->namedParametersExpressionNode.expressions.last,
                               expression);
                node->namedParametersExpressionNode.expressions.count += 1;
            } while(acceptToken(parser, TokenType_Comma));

            node->namedParametersExpressionNode.listEndToken = parser->current - 1;

            expectToken(parser, TokenType_RBrace);
            continue;
        } else if(type == TokenType_Dot) {
            ASTNode *expression = structPush(parser->arena, ASTNode);
            *expression = *node;
            expression->endToken = parser->current - 2;

            node->type = ASTNodeType_MemberAccessExpression;
            node->memberAccessExpressionNode.expression = expression;
            node->memberAccessExpressionNode.memberName = parseIdentifier(parser);
            continue;
        } else if(type == TokenType_QuestionMark) {
            ASTNode *expression = structPush(parser->arena, ASTNode);
            *expression = *node;
            expression->endToken = parser->current - 2;

            node->type = ASTNodeType_TerneryExpression;
            node->terneryExpressionNode.condition = expression;
            node->terneryExpressionNode.trueExpression = structPush(parser->arena, ASTNode);
            node->terneryExpressionNode.falseExpression = structPush(parser->arena, ASTNode);

            parseExpressionImpl(parser, node->terneryExpressionNode.trueExpression, 0);
            expectToken(parser, TokenType_Colon);
            parseExpressionImpl(parser, node->terneryExpressionNode.falseExpression, 0);
            continue;
        } else if(type == TokenType_PlusPlus | type == TokenType_MinusMinus) {
            ASTNode *expression = structPush(parser->arena, ASTNode);
            *expression = *node;
            expression->endToken = parser->current - 2;

            node->type = ASTNodeType_UnaryExpressionPostfix;
            node->unaryExpressionNode.operator = type;
            node->unaryExpressionNode.subExpression = expression;
            continue;
        }

        ASTNode *left = structPush(parser->arena, ASTNode);
        *left = *node;
        left->endToken = parser->current - 2;

        node->type = ASTNodeType_BinaryExpression;
        node->startToken = left->startToken;
        node->binaryExpressionNode.left = left;
        node->binaryExpressionNode.right = structPush(parser->arena, ASTNode);
        node->binaryExpressionNode.operator = type;
        node->endToken = parser->current - 1;

        // Exponentiation has right associativity
        precedence -= type == TokenType_StarStar;

        if(!parseExpressionImpl(parser, node->binaryExpressionNode.right, precedence)) {
            break;
        }

        node->endToken = parser->current - 1;
    }

    node->endToken = parser->current - 1;
    return true;
}

static bool
parseExpression(Parser *parser, ASTNode *node) {
    return parseExpressionImpl(parser, node, 0);
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

        declaration->node.startToken = parser->current;
        if(peekToken(parser).type != TokenType_Comma && peekToken(parser).type != TokenType_RParen) {
            if(!tryParseVariableDeclaration(parser, &declaration->node)) {
                setCurrentParserPosition(parser, startPosition);
                return false;
            }
        }

        declaration->node.endToken = parser->current - 1;
        SLL_QUEUE_PUSH(tuple->declarations.head, tuple->declarations.last, declaration);
        tuple->declarations.count += 1;
    } while(acceptToken(parser, TokenType_Comma));

    expectToken(parser, TokenType_RParen);
    expectToken(parser, TokenType_Equal);

    tuple->initialValue = structPush(parser->arena, ASTNode);
    parseExpression(parser, tuple->initialValue);

    node->type = ASTNodeType_VariableDeclarationTupleStatement;

    return true;
}

static bool
parseYulExpression(Parser *parser, ASTNode *node, YulLexer *lexer) {
    node->startToken = lexer->currentPosition;

    if(acceptYulToken(lexer, YulTokenType_NumberLit)) {
        node->type = ASTNodeType_YulNumberLitExpression;
        node->yulNumberLitExpressionNode.value = peekYulLastToken(lexer);
    } else if(acceptYulToken(lexer, YulTokenType_StringLit)) {
        node->type = ASTNodeType_YulStringLitExpression;
        node->yulStringLitExpressionNode.value = peekYulLastToken(lexer);
    } else if(acceptYulToken(lexer, YulTokenType_HexNumberLit)) {
        node->type = ASTNodeType_YulHexNumberLitExpression;
        node->yulHexNumberLitExpressionNode.value = peekYulLastToken(lexer);
    } else if(acceptYulToken(lexer, YulTokenType_BoolLit)) {
        node->type = ASTNodeType_YulBoolLitExpression;
        node->yulBoolLitExpressionNode.value = peekYulLastToken(lexer);
    } else if(acceptYulToken(lexer, YulTokenType_HexStringLit)) {
        node->type = ASTNodeType_YulHexStringLitExpression;
        node->yulHexStringLitExpressionNode.value = peekYulLastToken(lexer);
    } else if(acceptYulToken(lexer, YulTokenType_Identifier)) {
        TokenId identifier = peekYulLastToken(lexer);


        if(acceptYulToken(lexer, YulTokenType_Dot)) {
            node->type = ASTNodeType_YulMemberAccessExpression;
            node->yulIdentifierPathExpressionNode.identifiers[0] = identifier;
            node->yulIdentifierPathExpressionNode.identifiers[1] = parseYulIdentifier(lexer);
            node->yulIdentifierPathExpressionNode.count = 2;
        } else {
            node->type = ASTNodeType_YulFunctionCallExpression;
            ASTNodeYulFunctionCallExpression *functionCall = &node->yulFunctionCallExpressionNode;
            functionCall->identifier = identifier;

            if(acceptYulToken(lexer, YulTokenType_LParen)) {
                if(!acceptYulToken(lexer, YulTokenType_RParen)) {
                    do {
                        ASTNodeLink *argument = structPush(parser->arena, ASTNodeLink);
                        parseYulExpression(parser, &argument->node, lexer);
                        SLL_QUEUE_PUSH(functionCall->arguments.head, functionCall->arguments.last, argument);
                        functionCall->arguments.count += 1;
                    } while(acceptYulToken(lexer, YulTokenType_Comma));
                    expectYulToken(parser, lexer, YulTokenType_RParen);
                }
            }
        }
    } else {
        reportError(parser, "Unexpected token while parsing Yul expression - %S", peekYulToken(lexer).string);
    }

    node->endToken = lexer->currentPosition - 1;
    return true;
}

static bool
parseYulStatement(Parser *parser, ASTNode *node, YulLexer *lexer) {
    node->startToken = lexer->currentPosition;

    if(acceptYulToken(lexer, YulTokenType_LBrace)) {
        node->type = ASTNodeType_YulBlockStatement;

        while(!acceptYulToken(lexer, YulTokenType_RBrace)) {
            ASTNodeLink *statement = structPush(parser->arena, ASTNodeLink);
            if(!parseYulStatement(parser, &statement->node, lexer)) {
                continue;
            }

            SLL_QUEUE_PUSH(node->blockStatementNode.statements.head, node->blockStatementNode.statements.last, statement);
            node->blockStatementNode.statements.count += 1;
        }
    } else if(acceptYulToken(lexer, YulTokenType_Let)) {
        node->type = ASTNodeType_YulVariableDeclaration;
        ASTNodeYulVariableDeclaration *declaration = &node->yulVariableDeclarationNode;

        declaration->identifiers.count = 0;
        listPushTokenId(&declaration->identifiers, parseYulIdentifier(lexer), parser->arena);
        while(acceptYulToken(lexer, YulTokenType_Comma)) {
            listPushTokenId(&declaration->identifiers, parseYulIdentifier(lexer), parser->arena);
        }
        if(acceptYulToken(lexer, YulTokenType_ColonEqual)) {
            declaration->value = structPush(parser->arena, ASTNode);
            parseYulExpression(parser, declaration->value, lexer);
        }
    } else if(acceptYulToken(lexer, YulTokenType_Identifier)) {
        TokenId identifier = peekYulLastToken(lexer);

        if(acceptYulToken(lexer, YulTokenType_LParen)) {
            node->type = ASTNodeType_YulFunctionCallExpression;
            ASTNodeYulFunctionCallExpression *functionCall = &node->yulFunctionCallExpressionNode;
            functionCall->identifier = identifier;

            if(!acceptYulToken(lexer, YulTokenType_RParen)) {
                do {
                    ASTNodeLink *argument = structPush(parser->arena, ASTNodeLink);
                    parseYulExpression(parser, &argument->node, lexer);
                    SLL_QUEUE_PUSH(functionCall->arguments.head, functionCall->arguments.last, argument);
                    functionCall->arguments.count += 1;
                } while(acceptYulToken(lexer, YulTokenType_Comma));
                expectYulToken(parser, lexer, YulTokenType_RParen);
            }
        } else {
            node->type = ASTNodeType_YulVariableAssignment;
            ASTNodeYulVariableAssignment *assignment = &node->yulVariableAssignmentNode;

            assignment->paths.count = 0;
            ASTNodeLink *path = structPush(parser->arena, ASTNodeLink);
            path->node.type = ASTNodeType_YulMemberAccessExpression;
            path->node.startToken = lexer->currentPosition - 1;
            path->node.yulIdentifierPathExpressionNode.count = 1;
            path->node.yulIdentifierPathExpressionNode.identifiers[0] = identifier;
            if(acceptYulToken(lexer, YulTokenType_Dot)) {
                path->node.yulIdentifierPathExpressionNode.count++;
                path->node.yulIdentifierPathExpressionNode.identifiers[1] = parseYulIdentifier(lexer);
            }
            path->node.endToken = lexer->currentPosition - 1;
            SLL_QUEUE_PUSH(assignment->paths.head, assignment->paths.last, path);
            assignment->paths.count += 1;

            while(acceptYulToken(lexer, YulTokenType_Comma)) {
                ASTNodeLink *path = structPush(parser->arena, ASTNodeLink);
                path->node.type = ASTNodeType_YulMemberAccessExpression;
                path->node.yulIdentifierPathExpressionNode.count = 1;
                path->node.yulIdentifierPathExpressionNode.identifiers[0] = identifier;
                if(acceptYulToken(lexer, YulTokenType_Dot)) {
                    path->node.yulIdentifierPathExpressionNode.count++;
                    path->node.yulIdentifierPathExpressionNode.identifiers[1] = parseYulIdentifier(lexer);
                }
                SLL_QUEUE_PUSH(assignment->paths.head, assignment->paths.last, path);
                assignment->paths.count += 1;
            }
            if(acceptYulToken(lexer, YulTokenType_ColonEqual)) {
                assignment->value = structPush(parser->arena, ASTNode);
                parseYulExpression(parser, assignment->value, lexer);
            }
        }
    } else if(acceptYulToken(lexer, YulTokenType_If)) {
        node->type = ASTNodeType_YulIfStatement;
        ASTNodeYulIfStatement *ifStatement = &node->yulIfStatementNode;

        ifStatement->expression = structPush(parser->arena, ASTNode);
        parseYulExpression(parser, ifStatement->expression, lexer);
        ifStatement->body = structPush(parser->arena, ASTNode);
        parseYulStatement(parser, ifStatement->body, lexer);
    } else if(acceptYulToken(lexer, YulTokenType_For)) {
        node->type = ASTNodeType_YulForStatement;
        ASTNodeYulForStatement *forStatement = &node->yulForStatementNode;
        
        forStatement->variableDeclaration = structPush(parser->arena, ASTNode);
        forStatement->condition = structPush(parser->arena, ASTNode);
        forStatement->increment = structPush(parser->arena, ASTNode);
        forStatement->body = structPush(parser->arena, ASTNode);

        parseYulStatement(parser, forStatement->variableDeclaration, lexer);
        parseYulExpression(parser, forStatement->condition, lexer);
        parseYulStatement(parser, forStatement->increment, lexer);
        parseYulStatement(parser, forStatement->body, lexer);
    } else if(acceptYulToken(lexer, YulTokenType_Function)) {
        node->type = ASTNodeType_YulFunctionDefinition;
        ASTNodeYulFunctionDefinition *function = &node->yulFunctionDefinitionNode;

        function->identifier = parseYulIdentifier(lexer);
        expectYulToken(parser, lexer, YulTokenType_LParen);
        if(!acceptYulToken(lexer, YulTokenType_RParen)) {
            do {
                TokenId identifier = parseYulIdentifier(lexer);
                assertError(identifier != INVALID_TOKEN_ID, parser,
                            "Expected identifier in Yul function parameter list, received (%S)", peekYulToken(lexer).string);
                listPushTokenId(&function->parameters, identifier, parser->arena);
            } while(acceptYulToken(lexer, YulTokenType_Comma));
            expectYulToken(parser, lexer, YulTokenType_RParen);
        }

        if(acceptYulToken(lexer, YulTokenType_RightArrow)) {
            do {
                TokenId identifier = parseYulIdentifier(lexer);
                assertError(identifier != INVALID_TOKEN_ID, parser,
                            "Expected identifier in Yul function return parameter list, received (%S)", peekYulToken(lexer).string);
                listPushTokenId(&function->returnParameters, identifier, parser->arena);
            } while(acceptYulToken(lexer, YulTokenType_Comma));
        }

        function->body = structPush(parser->arena, ASTNode);
        parseYulStatement(parser, function->body, lexer);
    } else if(acceptYulToken(lexer, YulTokenType_Switch)) {
        node->type = ASTNodeType_YulSwitchStatement;
        ASTNodeYulSwitchStatement *switchStatement = &node->yulSwitchStatementNode;

        switchStatement->expression = structPush(parser->arena, ASTNode);
        parseYulExpression(parser, switchStatement->expression, lexer);

        switchStatement->cases.count = 0;
        while(acceptYulToken(lexer, YulTokenType_Case)) {
            ASTNodeLink *caseLink = structPush(parser->arena, ASTNodeLink);
            ASTNode *c = &caseLink->node;
            c->type = ASTNodeType_YulCaseStatement;
            c->startToken = lexer->currentPosition - 1;

            c->yulCaseNode.literal = structPush(parser->arena, ASTNode);
            c->yulCaseNode.block = structPush(parser->arena, ASTNode);

            // TODO(radomski): error on non-literal
            parseYulExpression(parser, c->yulCaseNode.literal, lexer);
            parseYulStatement(parser, c->yulCaseNode.block, lexer);

            c->endToken = lexer->currentPosition - 1;
            SLL_QUEUE_PUSH(switchStatement->cases.head, switchStatement->cases.last, caseLink);
            switchStatement->cases.count += 1;
        }

        bool defaultRequired = switchStatement->cases.count == 0;
        bool hasDefault = acceptYulToken(lexer, YulTokenType_Default);

        if(hasDefault) {
            ASTNode *defaultBlock = structPush(parser->arena, ASTNode);
            switchStatement->defaultBlock = defaultBlock;
            defaultBlock->type = ASTNodeType_YulCaseStatement;
            defaultBlock->startToken = lexer->currentPosition - 1;
            defaultBlock->yulCaseNode.literal = 0x0;
            defaultBlock->yulCaseNode.block = structPush(parser->arena, ASTNode);

            parseYulStatement(parser, defaultBlock->yulCaseNode.block, lexer);

            defaultBlock->endToken = lexer->currentPosition - 1;
        }

        if(defaultRequired && !hasDefault) {
            reportError(parser, "Switch statement requires a default case");
        }
    } else if(acceptYulToken(lexer, YulTokenType_Leave)) {
        node->type = ASTNodeType_YulLeaveStatement;
    } else if(acceptYulToken(lexer, YulTokenType_Break)) {
        node->type = ASTNodeType_YulBreakStatement;
    } else if(acceptYulToken(lexer, YulTokenType_Continue)) {
        node->type = ASTNodeType_YulContinueStatement;
    } else if(acceptYulToken(lexer, YulTokenType_Comment)) {
        return false;
    } else {
        reportError(parser, "Unhandeled Yul statement for token - %S", peekYulToken(lexer).string);
    }

    node->endToken = lexer->currentPosition - 1;

    return true;
}

static bool
parseYulBlock(Parser *parser, ASTNode *node) {
    YulLexer lexer = createYulLexer(parser->tokens, parser->tokenCount, parser->current);
    bool result = parseYulStatement(parser, node, &lexer);

    parser->current = lexer.currentPosition;
    return result;
}

static bool
parseStatement(Parser *parser, ASTNode *node) {
    if(acceptToken(parser, TokenType_Return)) {
        node->startToken = parser->current - 1;
        ASTNode *returnStatement = node;
        returnStatement->type = ASTNodeType_ReturnStatement;
        returnStatement->returnStatementNode.expression = 0x0;

        if(!acceptToken(parser, TokenType_Semicolon)) {
            returnStatement->returnStatementNode.expression = structPush(parser->arena, ASTNode);
            parseExpression(parser, returnStatement->returnStatementNode.expression);
            expectToken(parser, TokenType_Semicolon);
        }
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_If)) {
        node->startToken = parser->current - 1;
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
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_LBrace)) {
        node->type = ASTNodeType_BlockStatement;
        node->startToken = parser->current - 1;

        while(!acceptToken(parser, TokenType_RBrace)) {
            ASTNodeLink *statement = structPush(parser->arena, ASTNodeLink);
            if(!parseStatement(parser, &statement->node)) {
                continue;
            }

            SLL_QUEUE_PUSH(node->blockStatementNode.statements.head, node->blockStatementNode.statements.last, statement);
            node->blockStatementNode.statements.count += 1;
        }
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Unchecked)) {
        node->type = ASTNodeType_UncheckedBlockStatement;
        node->startToken = parser->current - 1;
        ASTNodeUncheckedBlockStatement *statement = &node->uncheckedBlockStatementNode;
        statement->block = structPush(parser->arena, ASTNode);
        parseStatement(parser, statement->block);
        assertError(statement->block->type == ASTNodeType_BlockStatement, parser, "A block statement must follow the unchecked keyword");
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_While)) {
        node->type = ASTNodeType_WhileStatement;
        node->startToken = parser->current - 1;
        ASTNodeWhileStatement *statement = &node->whileStatementNode;

        expectToken(parser, TokenType_LParen);
        statement->expression = structPush(parser->arena, ASTNode);
        parseExpression(parser, statement->expression);
        expectToken(parser, TokenType_RParen);

        statement->body = structPush(parser->arena, ASTNode);
        parseStatement(parser, statement->body);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Do)) {
        node->type = ASTNodeType_DoWhileStatement;
        node->startToken = parser->current - 1;
        ASTNodeWhileStatement *statement = &node->doWhileStatementNode;

        statement->body = structPush(parser->arena, ASTNode);
        parseStatement(parser, statement->body);

        expectToken(parser, TokenType_While);
        expectToken(parser, TokenType_LParen);
        statement->expression = structPush(parser->arena, ASTNode);
        parseExpression(parser, statement->expression);
        expectToken(parser, TokenType_RParen);
        expectToken(parser, TokenType_Semicolon);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_For)) {
        node->type = ASTNodeType_ForStatement;
        node->startToken = parser->current - 1;
        ASTNodeForStatement *statement = &node->forStatementNode;

        expectToken(parser, TokenType_LParen);

        statement->variableStatement = 0x0;
        if(!acceptToken(parser, TokenType_Semicolon)) {
            statement->variableStatement = structPush(parser->arena, ASTNode);
            parseStatement(parser, statement->variableStatement);
            assertError(statement->variableStatement->type == ASTNodeType_ExpressionStatement || 
                        statement->variableStatement->type == ASTNodeType_VariableDeclarationStatement,
                        parser, "Expected variable declaration or expression statement in for loop initializer");
        }

        statement->conditionExpression = 0x0;
        if(!acceptToken(parser, TokenType_Semicolon)) {
            statement->conditionExpression = structPush(parser->arena, ASTNode);
            parseExpression(parser, statement->conditionExpression);
            expectToken(parser, TokenType_Semicolon);
        }

        statement->incrementExpression = 0x0;
        if(!acceptToken(parser, TokenType_RParen)) {
            statement->incrementExpression = structPush(parser->arena, ASTNode);
            parseExpression(parser, statement->incrementExpression);
            acceptToken(parser, TokenType_RParen);
        }

        statement->body = structPush(parser->arena, ASTNode);
        parseStatement(parser, statement->body);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Revert)) {
        node->type = ASTNodeType_RevertStatement;
        node->startToken = parser->current - 1;
        ASTNodeRevertStatement *statement = &node->revertStatementNode;

        statement->expression = structPush(parser->arena, ASTNode);
        parseExpression(parser, statement->expression);
        expectToken(parser, TokenType_Semicolon);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Break)) {
        node->type = ASTNodeType_BreakStatement;
        node->startToken = parser->current - 1;
        expectToken(parser, TokenType_Semicolon);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Continue)) {
        node->type = ASTNodeType_ContinueStatement;
        node->startToken = parser->current - 1;
        expectToken(parser, TokenType_Semicolon);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Emit)) {
        node->type = ASTNodeType_EmitStatement;
        node->startToken = parser->current - 1;
        node->emitStatementNode.expression = structPush(parser->arena, ASTNode);
        parseExpression(parser, node->emitStatementNode.expression);
        assertError(node->emitStatementNode.expression->type == ASTNodeType_FunctionCallExpression,
                    parser, "Expected function call expression after emit keyword");
        expectToken(parser, TokenType_Semicolon);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Try)) {
        node->type = ASTNodeType_TryStatement;
        node->startToken = parser->current - 1;
        ASTNodeTryStatement *statement = &node->tryStatementNode;

        statement->expression = structPush(parser->arena, ASTNode);
        parseExpression(parser, statement->expression);

        statement->returnParameters.count = -1;
        if(acceptToken(parser, TokenType_Returns)) {
            statement->returnParameters.count = 0;
            expectToken(parser, TokenType_LParen);

            parseFunctionParameters(parser, &statement->returnParameters);
            assertError(statement->returnParameters.count > 0, parser, "Returns parameters must be specified");
            expectToken(parser, TokenType_RParen);
        }

        statement->body = structPush(parser->arena, ASTNode);
        parseStatement(parser, statement->body);

        while(acceptToken(parser, TokenType_Catch)) {
            ASTNodeLink *catchLink = structPush(parser->arena, ASTNodeLink);
            catchLink->node.type = ASTNodeType_CatchStatement;
            catchLink->node.startToken = parser->current - 1;
            ASTNodeCatchStatement *catchStatement = &catchLink->node.catchStatementNode;

            catchStatement->identifier = INVALID_TOKEN_ID;
            catchStatement->parameters.count = -1;

            if(!acceptToken(parser, TokenType_LBrace)) {
                if(!acceptToken(parser, TokenType_LParen)) {
                    catchStatement->identifier = parseIdentifier(parser);
                    expectToken(parser, TokenType_LParen);
                }

                catchStatement->parameters.count = 0;
                parseFunctionParameters(parser, &catchStatement->parameters);
                assertError(catchStatement->parameters.count > 0, parser, "Catch parameters must be specified");
                expectToken(parser, TokenType_RParen);
            } else {
                parser->current -= 1;
            }

            catchStatement->body = structPush(parser->arena, ASTNode);
            parseStatement(parser, catchStatement->body);
            catchLink->node.endToken = parser->current - 1;

            SLL_QUEUE_PUSH(statement->catches.head, statement->catches.last, catchLink);
            statement->catches.count += 1;
        }
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Assembly)) {
        node->type = ASTNodeType_AssemblyStatement;
        node->startToken = parser->current - 1;
        ASTNodeAssemblyStatement *statement = &node->assemblyStatementNode;
        if(acceptToken(parser, TokenType_StringLit)) {
            statement->isEVMAsm = stringMatch(peekLastToken(parser).string, LIT_TO_STR("evmasm"));
            if(!statement->isEVMAsm) {
                reportError(parser, "Expected (\"evmasm\") as string literal, but got (\"%S\")", peekLastToken(parser).string);
            }
        }

        if(acceptToken(parser, TokenType_LParen)) {
            do {
                expectToken(parser, TokenType_StringLit);
                listPushTokenId(&statement->flags, peekLastTokenId(parser), parser->arena);
            } while(acceptToken(parser, TokenType_Comma));
            expectToken(parser, TokenType_RParen);
        }

        statement->body = structPush(parser->arena, ASTNode);
        parseYulBlock(parser, statement->body);
        node->endToken = parser->current - 1;
    } else if(acceptToken(parser, TokenType_Comment)) {
        return false;
    } else {
        u32 startToken = parser->current;
        if(tryParseVariableDeclaration(parser, node)) {
            ASTNode *varDeclNode = structPush(parser->arena, ASTNode);
            node->endToken = parser->current - 1;
            *varDeclNode = *node;

            node->startToken = startToken;
            node->type = ASTNodeType_VariableDeclarationStatement;
            ASTNodeVariableDeclarationStatement *statement = &node->variableDeclarationStatementNode;
            statement->variableDeclaration = varDeclNode;

            statement->initialValue = 0x0;
            if(acceptToken(parser, TokenType_Equal)) {
                statement->initialValue = structPush(parser->arena, ASTNode);
                parseExpression(parser, statement->initialValue);
            }

            expectToken(parser, TokenType_Semicolon);
            node->endToken = parser->current - 1;
        } else if(tryParseVariableDeclarationTuple(parser, node)) {
            node->startToken = startToken;
            expectToken(parser, TokenType_Semicolon);
            node->endToken = parser->current - 1;
        } else {
            node->startToken = parser->current;
            node->type = ASTNodeType_ExpressionStatement;
            node->expressionStatementNode.expression = structPush(parser->arena, ASTNode);

            parseExpression(parser, node->expressionStatementNode.expression);
            expectToken(parser, TokenType_Semicolon);
            node->endToken = parser->current - 1;
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
    node->startToken = parser->current - 1;
    ASTNodeConstVariable *constVariable = &node->constVariableNode;

    constVariable->type = type;
    constVariable->identifier = parseIdentifier(parser);
    assertError(constVariable->identifier != INVALID_TOKEN_ID,
                parser, "Constant variable declaration name can only be an identifier");

    expectToken(parser, TokenType_Equal);

    constVariable->expression = structPush(parser->arena, ASTNode);
    parseExpression(parser, constVariable->expression);

    expectToken(parser, TokenType_Semicolon);
    node->endToken = parser->current - 1;
    return true;
}

static void
parseOverrideSpecifierArgs(Parser *parser, ASTNodeList *list) {
    if(acceptToken(parser, TokenType_LParen)) {
        do {
            ASTNodeLink *argument = structPush(parser->arena, ASTNodeLink);
            parseType(parser, &argument->node);
            assertError(argument->node.type == ASTNodeType_IdentifierPath,
                        parser, "Expected identifier path in override specifier arguments");

            SLL_QUEUE_PUSH(list->head, list->last, argument);
            list->count += 1;
        } while(acceptToken(parser, TokenType_Comma));

        expectToken(parser, TokenType_RParen);
    }
}

static bool
tryParseStateVariableDeclaration(Parser *parser, ASTNode *node) {
    u32 startPosition = getCurrentParserPosition(parser);
    node->startToken = parser->current;
    node->type = ASTNodeType_StateVariableDeclaration;
    ASTNodeConstVariable *decl = &node->constVariableNode;

    decl->type = structPush(parser->arena, ASTNode);
    if(!parseType(parser, decl->type)) {
        setCurrentParserPosition(parser, startPosition);
        return false;
    }

    decl->visibility = 0;
    for(;;) {
        if (acceptToken(parser, TokenType_Internal)) {
            assertError(decl->visibility == 0, parser, "Visibility modifier already set");
            decl->visibility = 3;
        } else if (acceptToken(parser, TokenType_Private)) {
            assertError(decl->visibility == 0, parser, "Visibility modifier already set");
            decl->visibility = 2;
        } else if (acceptToken(parser, TokenType_Public)) {
            assertError(decl->visibility == 0, parser, "Visibility modifier already set");
            decl->visibility = 1;
        } else if(acceptToken(parser, TokenType_Constant)) {
            assertError(decl->mutability == 0, parser, "Mutability modifier already set");
            decl->mutability = 1;
        } else if(acceptToken(parser, TokenType_Immutable)) {
            assertError(decl->mutability == 0, parser, "Mutability modifier already set");
            decl->mutability = 2;
        } else if(acceptToken(parser, TokenType_Override)) {
            assertError(decl->override == 0, parser, "Override modifier already set");
            decl->override = 1;
            parseOverrideSpecifierArgs(parser, &decl->overrides);
        } else {
            break;
        }
    }

    decl->identifier = parseIdentifier(parser);
    if(decl->identifier == INVALID_TOKEN_ID) {
        setCurrentParserPosition(parser, startPosition);
        return false;
    }

    if(acceptToken(parser, TokenType_Equal)) {
        decl->expression = structPush(parser->arena, ASTNode);
        parseExpression(parser, decl->expression);
    }

    if(!acceptToken(parser, TokenType_Semicolon)) {
        setCurrentParserPosition(parser, startPosition);
        return false;
    }

    node->endToken = parser->current - 1;
    return true;
}

static void
parseModifierInvocation(Parser *parser, ASTNode *node, ASTNode *identifierPath) {
    node->type = ASTNodeType_ModifierInvocation;
    node->startToken = parser->current - 1;
    ASTNodeModifierInvocation *invocation = &node->modifierInvocationNode;

    invocation->identifier = structPush(parser->arena, ASTNode);
    *invocation->identifier = *identifierPath;

    invocation->argumentsExpression.count = -1;
    if(acceptToken(parser, TokenType_LParen)) {
        invocation->argumentsExpression.count = 0;
        parseCallArgumentList(parser, &invocation->argumentsExpression, &invocation->argumentsName);
    }
    node->endToken = parser->current - 1;
}

static bool
parseFunction(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_FunctionDefinition;
    node->startToken = parser->current - 1;

    TokenId name = parseIdentifier(parser);
    if(name == INVALID_TOKEN_ID) {
        if(acceptToken(parser, TokenType_Fallback) ||
           acceptToken(parser, TokenType_Receive) ||
           peekLastToken(parser).type == TokenType_Receive ||
           peekLastToken(parser).type == TokenType_Fallback) {
            name = peekLastTokenId(parser);
        }
    }
    ASTNodeFunctionDefinition *function = &node->functionDefinitionNode;
    function->name = name;

    expectToken(parser, TokenType_LParen);
    if(!acceptToken(parser, TokenType_RParen)) {
        parseFunctionParameters(parser, &function->parameters);
        expectToken(parser, TokenType_RParen);
    }

    function->visibility = 0;
    function->stateMutability = 0;
    function->virtual = 0;
    for(;;) {
        if (acceptToken(parser, TokenType_Internal)) {
            assertError(function->visibility == 0, parser, "Visibility modifier already set");
            function->visibility = 1;
        } else if (acceptToken(parser, TokenType_External)) {
            assertError(function->visibility == 0, parser, "Visibility modifier already set");
            function->visibility = 2;
        } else if (acceptToken(parser, TokenType_Private)) {
            assertError(function->visibility == 0, parser, "Visibility modifier already set");
            function->visibility = 3;
        } else if (acceptToken(parser, TokenType_Public)) {
            assertError(function->visibility == 0, parser, "Visibility modifier already set");
            function->visibility = 4;
        } else if (acceptToken(parser, TokenType_Pure)) {
            assertError(function->stateMutability == 0, parser, "State mutability modifier already set");
            function->stateMutability = 1;
        } else if (acceptToken(parser, TokenType_View)) {
            assertError(function->stateMutability == 0, parser, "State mutability modifier already set");
            function->stateMutability = 2;
        } else if (acceptToken(parser, TokenType_Payable)) {
            assertError(function->stateMutability == 0, parser, "State mutability modifier already set");
            function->stateMutability = 3;
        } else if (acceptToken(parser, TokenType_Constant)) {
            assertError(function->stateMutability == 0, parser, "State mutability modifier already set");
            function->stateMutability = 4;
        } else if (acceptToken(parser, TokenType_Virtual)) {
            assertError(function->virtual == 0, parser, "Virtual modifier already set");
            function->virtual = 1;
        } else if (acceptToken(parser, TokenType_Override)) {
            assertError(function->override == 0, parser, "Override modifier already set");
            function->override = 1;
            parseOverrideSpecifierArgs(parser, &function->overrides);
        } else {
            ASTNode testExpression = { 0 };
            bool isSuccess = parseType(parser, &testExpression);
            if(isSuccess) {
                assertError(testExpression.type == ASTNodeType_IdentifierPath,
                            parser, "Expected identifier path in function modifier invocation");
                ASTNodeLink *link = structPush(parser->arena, ASTNodeLink);
                parseModifierInvocation(parser, &link->node, &testExpression);

                SLL_QUEUE_PUSH(function->modifiers.head, function->modifiers.last, link);
                function->modifiers.count += 1;
                continue;
            }

            break;
        }
    }

    function->returnParameters.count = -1;
    if(acceptToken(parser, TokenType_Returns)) {
        function->returnParameters.count = 0;
        expectToken(parser, TokenType_LParen);
        parseFunctionParameters(parser, &function->returnParameters);
        assertError(function->returnParameters.count > 0, parser, "Returns parameters must be specified");
        expectToken(parser, TokenType_RParen);
    }

    function->body = 0x0;
    if(!acceptToken(parser, TokenType_Semicolon)) {
        function->body = structPush(parser->arena, ASTNode);
        parseBlock(parser, function->body);
    }

    node->endToken = parser->current - 1;

    return true;
}

static bool
parseModifier(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_ModifierDefinition;
    node->startToken = parser->current - 1;
    TokenId name = parseIdentifier(parser);
    assertError(name != INVALID_TOKEN_ID, parser, "Modifier name must be an identifier");
    ASTNodeFunctionDefinition *modifier = &node->functionDefinitionNode;
    modifier->name = name;

    modifier->parameters.count = -1;
    if(acceptToken(parser, TokenType_LParen)) {
        modifier->parameters.count = 0;
        if(!acceptToken(parser, TokenType_RParen)) {
            parseFunctionParameters(parser, &modifier->parameters);
            expectToken(parser, TokenType_RParen);
        }
    }

    modifier->stateMutability = 0;
    modifier->virtual = 0;
    for(;;) {
        if (acceptToken(parser, TokenType_Virtual)) {
            assertError(modifier->virtual == 0, parser, "Virtual modifier already set");
            modifier->virtual = 1;
        } else if(acceptToken(parser, TokenType_Override)) {
            assertError(modifier->override == 0, parser, "Override modifier already set");
            modifier->override = 1;
            parseOverrideSpecifierArgs(parser, &modifier->overrides);
        } else {
            break;
        }
    }

    modifier->body = 0x0;
    if(!acceptToken(parser, TokenType_Semicolon)) {
        modifier->body = structPush(parser->arena, ASTNode);
        parseBlock(parser, modifier->body);
    }

    node->endToken = parser->current - 1;
    return true;
}

static bool
parseConstructor(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_ConstructorDefinition;
    node->startToken = parser->current - 1;
    ASTNodeConstructorDefinition *constructor = &node->constructorDefinitionNode;

    expectToken(parser, TokenType_LParen);
    constructor->parameters.count = 0;
    if(!acceptToken(parser, TokenType_RParen)) {
        parseFunctionParameters(parser, &constructor->parameters);
        expectToken(parser, TokenType_RParen);
    }

    constructor->stateMutability = 0;
    constructor->visibility = 0;
    for(;;) {
        if (acceptToken(parser, TokenType_Payable)) {
            assertError(constructor->stateMutability == 0, parser, "State mutability modifier already set");
            constructor->stateMutability = 3;
        } else if(acceptToken(parser, TokenType_Internal)) {
            assertError(constructor->visibility == 0, parser, "Visibility modifier already set");
            constructor->visibility = 1;
        } else if (acceptToken(parser, TokenType_Public)) {
            assertError(constructor->visibility == 0, parser, "Visibility modifier already set");
            constructor->visibility = 4;
        } else {
            ASTNode testExpression = { 0 };
            bool isSuccess = parseType(parser, &testExpression);
            if(isSuccess) {
                assertError(testExpression.type == ASTNodeType_IdentifierPath,
                            parser, "Expected identifier path in constructor modifier invocation");
                ASTNodeLink *link = structPush(parser->arena, ASTNodeLink);
                parseModifierInvocation(parser, &link->node, &testExpression);

                SLL_QUEUE_PUSH(constructor->modifiers.head, constructor->modifiers.last, link);
                constructor->modifiers.count += 1;
                continue;
            }

            break;
        }
    }

    constructor->body = structPush(parser->arena, ASTNode);
    parseBlock(parser, constructor->body);

    node->endToken = parser->current - 1;
    return true;
}

static bool
parseContractBody(Parser *parser, ASTNodeList *elements) {
    expectToken(parser, TokenType_LBrace);
    while(!acceptToken(parser, TokenType_RBrace)) {
        ASTNodeLink *element = structPush(parser->arena, ASTNodeLink);

        if(acceptToken(parser, TokenType_Constructor)) {
            parseConstructor(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Function)) {
            parser->current -= 1;
            if(!tryParseStateVariableDeclaration(parser, &element->node)) {
                parser->current += 1;
                memset(&element->node, 0, sizeof(ASTNode));

                parseFunction(parser, &element->node);
            }
        } else if(acceptToken(parser, TokenType_Modifier)) {
            parseModifier(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Fallback)) {
            parseFunction(parser, &element->node);
            element->node.type = ASTNodeType_FallbackFunction;
        } else if(acceptToken(parser, TokenType_Receive)) {
            parseFunction(parser, &element->node);
            element->node.type = ASTNodeType_ReceiveFunction;
        } else if(acceptToken(parser, TokenType_Struct)) {
            parseStruct(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Using)) {
            parseUsing(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Enum)) {
            parseEnum(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Type)) {
            parseTypedef(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Event)) {
            parseEvent(parser, &element->node);
        } else if(acceptToken(parser, TokenType_Error)) {
            parser->current -= 1;
            if(!tryParseStateVariableDeclaration(parser, &element->node)) {
                parser->current += 1;
                memset(&element->node, 0, sizeof(ASTNode));

                parseError(parser, &element->node);
            }
        } else if(acceptToken(parser, TokenType_EOF)) {
            break;
        } else if(acceptToken(parser, TokenType_Comment)) {
            continue;
        } else {
            assertError(tryParseStateVariableDeclaration(parser, &element->node),
                        parser, "Expected state variable declaration");
        }

        SLL_QUEUE_PUSH(elements->head, elements->last, element);
        elements->count += 1;
    }

    return true;
}

static bool
parseContract(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_ContractDefinition;
    node->startToken = parser->current - 1;
    ASTNodeContractDefinition *contract = &node->contractDefinitionNode;

    contract->name = parseIdentifier(parser);

    if(acceptToken(parser, TokenType_Is)) {
        do {
            ASTNodeLink *baseContractLink = structPush(parser->arena, ASTNodeLink);

            baseContractLink->node.type = ASTNodeType_InheritanceSpecifier;
            baseContractLink->node.startToken = parser->current;
            ASTNodeInheritanceSpecifier *inheritance = &baseContractLink->node.inheritanceSpecifierNode;

            inheritance->identifier = structPush(parser->arena, ASTNode);
            parseType(parser, inheritance->identifier);
            assertError(inheritance->identifier->type == ASTNodeType_IdentifierPath,
                        parser, "Expected identifier path in inheritance specifier");

            if(acceptToken(parser, TokenType_LParen)) {
                parseCallArgumentList(parser, &inheritance->argumentsExpression, &inheritance->argumentsName);
            }

            baseContractLink->node.endToken = parser->current - 1;

            SLL_QUEUE_PUSH(contract->baseContracts.head, contract->baseContracts.last, baseContractLink);
            contract->baseContracts.count += 1;
        } while(acceptToken(parser, TokenType_Comma));
    }

    parseContractBody(parser, &contract->elements);

    node->endToken = parser->current - 1;
    return true;
}

static bool
parseInterface(Parser *parser, ASTNode *node) {
    u32 startPosition = parser->current - 1;
    parseContract(parser, node);
    u32 endPosition = parser->current - 1;
    node->type = ASTNodeType_InterfaceDefinition;

    node->startToken = startPosition;
    node->endToken = endPosition;

    return true;
}

static bool
parseAbstractContract(Parser *parser, ASTNode *node) {
    u32 startPosition = parser->current - 1;
    expectToken(parser, TokenType_Contract);
    parseContract(parser, node);
    u32 endPosition = parser->current - 1;

    node->type = ASTNodeType_AbstractContractDefinition;
    node->startToken = startPosition;
    node->endToken = endPosition;

    return true;
}

static bool
parseLibrary(Parser *parser, ASTNode *node) {
    node->type = ASTNodeType_LibraryDefinition;
    node->startToken = parser->current - 1;
    ASTNodeLibraryDefinition *library = &node->libraryDefinitionNode;

    library->name = parseIdentifier(parser);

    parseContractBody(parser, &library->elements);
    node->endToken = parser->current - 1;

    return true;
}

static ASTNode
parseSourceUnit(Parser *parser) {
    ASTNode node = { .type = ASTNodeType_SourceUnit };

#if 0
    log(parser->arena, "ASTNode                                   %d", sizeof(ASTNode));
    log(parser->arena, "ASTNodeStruct                             %d", sizeof(ASTNodeStruct));
    log(parser->arena, "ASTNodeBaseType                           %d", sizeof(ASTNodeBaseType));
    log(parser->arena, "ASTNodeIdentifierPath                     %d", sizeof(ASTNodeIdentifierPath));
    log(parser->arena, "ASTNodeMapping                            %d", sizeof(ASTNodeMapping));
    log(parser->arena, "ASTNodeFunctionType                       %d", sizeof(ASTNodeFunctionType));
    log(parser->arena, "ASTNodeArrayType                          %d", sizeof(ASTNodeArrayType));
    log(parser->arena, "ASTNodeError                              %d", sizeof(ASTNodeError));
    log(parser->arena, "ASTNodeEvent                              %d", sizeof(ASTNodeEvent));
    log(parser->arena, "ASTNodeTypedef                            %d", sizeof(ASTNodeTypedef));
    log(parser->arena, "ASTNodeConstVariable                      %d", sizeof(ASTNodeConstVariable));
    log(parser->arena, "ASTNodeConstVariable                      %d", sizeof(ASTNodeConstVariable));
    log(parser->arena, "ASTNodeNumberLitExpression                %d", sizeof(ASTNodeNumberLitExpression));
    log(parser->arena, "ASTNodeStringLitExpression                %d", sizeof(ASTNodeStringLitExpression));
    log(parser->arena, "ASTNodeTokenLitExpression                 %d", sizeof(ASTNodeTokenLitExpression));
    log(parser->arena, "ASTNodeTokenLitExpression                 %d", sizeof(ASTNodeTokenLitExpression));
    log(parser->arena, "ASTNodeBinaryExpression                   %d", sizeof(ASTNodeBinaryExpression));
    log(parser->arena, "ASTNodeTupleExpression                    %d", sizeof(ASTNodeTupleExpression));
    log(parser->arena, "ASTNodeUnaryExpression                    %d", sizeof(ASTNodeUnaryExpression));
    log(parser->arena, "ASTNodeNewExpression                      %d", sizeof(ASTNodeNewExpression));
    log(parser->arena, "ASTNodeFunctionCallExpression             %d", sizeof(ASTNodeFunctionCallExpression));
    log(parser->arena, "ASTNodeMemberAccessExpression             %d", sizeof(ASTNodeMemberAccessExpression));
    log(parser->arena, "ASTNodeArrayAccessExpression              %d", sizeof(ASTNodeArrayAccessExpression));
    log(parser->arena, "ASTNodeArraySliceExpression               %d", sizeof(ASTNodeArraySliceExpression));
    log(parser->arena, "ASTNodeTerneryExpression                  %d", sizeof(ASTNodeTerneryExpression));
    log(parser->arena, "ASTNodeNamedParametersExpression          %d", sizeof(ASTNodeNamedParametersExpression));
    log(parser->arena, "ASTNodeInlineArrayExpression              %d", sizeof(ASTNodeInlineArrayExpression));
    log(parser->arena, "ASTNodeFunctionDefinition                 %d", sizeof(ASTNodeFunctionDefinition));
    log(parser->arena, "ASTNodeBlockStatement                     %d", sizeof(ASTNodeBlockStatement));
    log(parser->arena, "ASTNodeUncheckedBlockStatement            %d", sizeof(ASTNodeUncheckedBlockStatement));
    log(parser->arena, "ASTNodeReturnStatement                    %d", sizeof(ASTNodeReturnStatement));
    log(parser->arena, "ASTNodeReturnStatement                    %d", sizeof(ASTNodeReturnStatement));
    log(parser->arena, "ASTNodeIfStatement                        %d", sizeof(ASTNodeIfStatement));
    log(parser->arena, "ASTNodeVariableDeclarationStatement       %d", sizeof(ASTNodeVariableDeclarationStatement));
    log(parser->arena, "ASTNodeVariableDeclaration                %d", sizeof(ASTNodeVariableDeclaration));
    log(parser->arena, "ASTNodeVariableDeclarationTupleStatement  %d", sizeof(ASTNodeVariableDeclarationTupleStatement));
    log(parser->arena, "ASTNodeWhileStatement                     %d", sizeof(ASTNodeWhileStatement));
    log(parser->arena, "ASTNodeWhileStatement                     %d", sizeof(ASTNodeWhileStatement));
    log(parser->arena, "ASTNodeInheritanceSpecifier               %d", sizeof(ASTNodeInheritanceSpecifier));
    log(parser->arena, "ASTNodeModifierInvocation                 %d", sizeof(ASTNodeModifierInvocation));
    log(parser->arena, "ASTNodeContractDefinition                 %d", sizeof(ASTNodeContractDefinition));
    log(parser->arena, "ASTNodeLibraryDefinition                  %d", sizeof(ASTNodeLibraryDefinition));
    log(parser->arena, "ASTNodeRevertStatement                    %d", sizeof(ASTNodeRevertStatement));
    log(parser->arena, "ASTNodeForStatement                       %d", sizeof(ASTNodeForStatement));
    log(parser->arena, "ASTNodeEmitStatement                      %d", sizeof(ASTNodeEmitStatement));
    log(parser->arena, "ASTNodeTryStatement                       %d", sizeof(ASTNodeTryStatement));
    log(parser->arena, "ASTNodeCatchStatement                     %d", sizeof(ASTNodeCatchStatement));
    log(parser->arena, "ASTNodeAssemblyStatement                  %d", sizeof(ASTNodeAssemblyStatement));
    log(parser->arena, "ASTNodeConstructorDefinition              %d", sizeof(ASTNodeConstructorDefinition));
    log(parser->arena, "ASTNodeNameValue                          %d", sizeof(ASTNodeNameValue));
    log(parser->arena, "ASTNodeUsing                              %d", sizeof(ASTNodeUsing));

    log(parser->arena, "ASTNodeBlockStatement                     %d", sizeof(ASTNodeBlockStatement));
    log(parser->arena, "ASTNodeYulVariableDeclaration             %d", sizeof(ASTNodeYulVariableDeclaration));
    log(parser->arena, "ASTNodeYulNumberLitExpression             %d", sizeof(ASTNodeYulNumberLitExpression));
    log(parser->arena, "ASTNodeYulNumberLitExpression             %d", sizeof(ASTNodeYulNumberLitExpression));
    log(parser->arena, "ASTNodeYulNumberLitExpression             %d", sizeof(ASTNodeYulNumberLitExpression));
    log(parser->arena, "ASTNodeYulNumberLitExpression             %d", sizeof(ASTNodeYulNumberLitExpression));
    log(parser->arena, "ASTNodeYulNumberLitExpression             %d", sizeof(ASTNodeYulNumberLitExpression));
    log(parser->arena, "ASTNodeYulIdentifierPathExpression        %d", sizeof(ASTNodeYulIdentifierPathExpression));
    log(parser->arena, "ASTNodeYulFunctionCallExpression          %d", sizeof(ASTNodeYulFunctionCallExpression));
    log(parser->arena, "ASTNodeYulVariableAssignment              %d", sizeof(ASTNodeYulVariableAssignment));
    log(parser->arena, "ASTNodeYulIfStatement                     %d", sizeof(ASTNodeYulIfStatement));
    log(parser->arena, "ASTNodeYulForStatement                    %d", sizeof(ASTNodeYulForStatement));
    log(parser->arena, "ASTNodeYulFunctionDefinition              %d", sizeof(ASTNodeYulFunctionDefinition));
    log(parser->arena, "ASTNodeYulSwitchStatement                 %d", sizeof(ASTNodeYulSwitchStatement));
#endif
    u32 parsingMemory = arenaFreeBytes(parser->arena);

    while(true) {
        ASTNodeLink *child = arrayPush(parser->arena, ASTNodeLink, 1);

        if(acceptToken(parser, TokenType_Pragma)) {
            parsePragma(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Import)) {
            parseImport(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Using)) {
            parseUsing(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Enum)) {
            parseEnum(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Struct)) {
            parseStruct(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Error)) {
            parseError(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Event)) {
            parseEvent(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Type)) {
            parseTypedef(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Function)) {
            parseFunction(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Contract)) {
            parseContract(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Abstract)) {
            parseAbstractContract(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Interface)) {
            parseInterface(parser, &child->node);
        } else if(acceptToken(parser, TokenType_Library)) {
            parseLibrary(parser, &child->node);
        } else if(acceptToken(parser, TokenType_EOF)) {
            node.endToken = parser->current - 2;
            break;
        } else if(acceptToken(parser, TokenType_Comment)) {
            continue;
        } else {
            u32 startToken = parser->current;
            ASTNode *type = structPush(parser->arena, ASTNode);
            bool success = parseType(parser, type);
            if(!success) {
                reportError(parser, "Expected type, but got (\"%S\")", peekLastToken(parser).string);
            }
            expectToken(parser, TokenType_Constant);
            parseConstVariable(parser, &child->node, type);
            child->node.startToken = startToken;
        }

        SLL_QUEUE_PUSH(node.children.head, node.children.last, child);
        node.children.count += 1;
    }

    parsingMemory -= arenaFreeBytes(parser->arena);
    // log(parser->arena, "parsing memory needed     = %d", parsingMemory);

    return node;
}
