typedef struct Serializer {
    Arena *arena;
    TokenizeResult tokens;
    const u8 *inputStringBase;
    char **head;
} Serializer;

static u32 pushASTNode(Serializer *s, ASTNode *node);

static Serializer
createSerializer(Arena *arena, const void *inputStringBase, TokenizeResult tokens) {
    Serializer s = {
        .arena = arena,
        .tokens = tokens,
        .inputStringBase = (const u8 *)inputStringBase,
        .head = 0x0,
    };

    return s;
}

static u32
pushU16(Serializer *s, u16 value) {
    if(s->head) {
        u16 *ptr = (u16 *)*s->head;
        *ptr = value;
        *s->head += sizeof(u16);
    }

    return sizeof(u16);
}

static u32
pushU32(Serializer *s, u32 value) {
    if(s->head) {
        u32 *ptr = (u32 *)*s->head;
        *ptr = value;
        *s->head += sizeof(u32);
    }

    return sizeof(u32);
}

static u32
popU32(Serializer *s) {
    if(s->head) {
        *s->head -= sizeof(u32);
    }

    return -sizeof(u32);
}

static u32
pushTokenStringById(Serializer *s, TokenId token) {
    if(s->head) {
        if(token == INVALID_TOKEN_ID) {
            pushU32(s, INVALID_TOKEN_ID);
            pushU32(s, 0);
        } else {
            Token t = getToken(s->tokens, token);
            pushU32(s, (u32)(t.string.data - s->inputStringBase));
            pushU32(s, (u32)t.string.size);
        }
    }

    return 2 * sizeof(u32);
}

static u32 pushExpression(Serializer *s, ASTNode *node);

static u32
pushType(Serializer *s, ASTNode *node) {
    u32 l = 0;

    switch(node->type) {
        case ASTNodeType_BaseType: {
            l += pushU32(s, node->type);
            l += pushTokenStringById(s, node->baseTypeNode.typeName);
            l += pushU32(s, node->baseTypeNode.payable);
        } break;
        case ASTNodeType_IdentifierPath: {
            l += pushU32(s, node->type);
            l += pushU32(s, node->identifierPathNode.identifiers.count);
            for(u32 i = 0; i < node->identifierPathNode.identifiers.count; i++) {
                TokenId part = listGetTokenId(&node->identifierPathNode.identifiers, i);
                l += pushTokenStringById(s, part);
            }
        } break;
        case ASTNodeType_MappingType: {
            l += pushU32(s, node->type);
            l += pushType(s, node->mappingNode.keyType);
            l += pushTokenStringById(s, node->mappingNode.keyIdentifier);
            l += pushType(s, node->mappingNode.valueType);
            l += pushTokenStringById(s, node->mappingNode.valueIdentifier);
        } break;
        case ASTNodeType_ArrayType: {
            l += pushU32(s, node->type);
            l += pushType(s, node->arrayTypeNode.elementType);
            l += pushU32(s, node->arrayTypeNode.lengthExpression != 0x0);
            if(node->arrayTypeNode.lengthExpression != 0x0) {
                l += pushExpression(s, node->arrayTypeNode.lengthExpression);
            }
        } break;
        default: {
            assert(0);
        }
    }

    return l;
}

static u32
pushVariableDeclaration(Serializer *s, ASTNode *node) {
    u32 l = 0;

    ASTNodeVariableDeclaration *decl = &node->variableDeclarationNode;
    l += pushType(s, decl->type);
    l += pushTokenStringById(s, decl->name);
    l += pushU32(s, decl->dataLocation);

    return l;
}

static u32
pushExpression(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    switch(node->type){
        case ASTNodeType_NumberLitExpression: {
            l += pushTokenStringById(s, node->numberLitExpressionNode.value);
            l += pushTokenStringById(s, node->numberLitExpressionNode.subdenomination);
        } break;
        case ASTNodeType_HexStringLitExpression:
        case ASTNodeType_StringLitExpression: {
            ASTNodeStringLitExpression *expression = &node->stringLitExpressionNode;

            l += pushU32(s, expression->values.count);
            for(u32 i = 0; i < expression->values.count; i++) {
                // PERF-NOTE(radomski): we could pull out pushing a token string just
                // by itself since we know that the token here is never going to be
                // invalid. But in pushTokenStringById we have to check for invalid
                // which is additional overhead.

                TokenId literal = listGetTokenId(&expression->values, i);
                l += pushTokenStringById(s, literal);
            }
        } break;
        case ASTNodeType_BoolLitExpression: {
            l += pushTokenStringById(s, node->boolLitExpressionNode.value);
        } break;
        case ASTNodeType_IdentifierExpression: {
            l += pushTokenStringById(s, node->identifierExpressionNode.value);
        } break;
        case ASTNodeType_BinaryExpression: {
            l += pushU32(s, node->binaryExpressionNode.operator);
            l += pushExpression(s, node->binaryExpressionNode.left);
            l += pushExpression(s, node->binaryExpressionNode.right);
        } break;
        case ASTNodeType_TupleExpression: {
            ASTNodeTupleExpression *tuple = &node->tupleExpressionNode;

            l += pushU32(s, tuple->elements.count);
            ASTNodeLink *element = tuple->elements.head;
            for(u32 i = 0; i < tuple->elements.count; i++, element = element->next) {
                l += pushExpression(s, &element->node);
            }
        } break;
        case ASTNodeType_UnaryExpression:
        case ASTNodeType_UnaryExpressionPostfix: {
            l += pushU32(s, node->unaryExpressionNode.operator);
            l += pushExpression(s, node->unaryExpressionNode.subExpression);
        } break;
        case ASTNodeType_NewExpression: {
            l += pushType(s, node->newExpressionNode.typeName);
        } break;
        case ASTNodeType_FunctionCallExpression: {
            ASTNodeFunctionCallExpression *function = &node->functionCallExpressionNode;

            l += pushExpression(s, function->expression);
            l += pushU32(s, function->arguments.count);

            ASTNodeLink *argument = function->arguments.head;
            for(u32 i = 0; i < function->arguments.count; i++, argument = argument->next) {
                l += pushExpression(s, &argument->node);
            }
        } break;
        case ASTNodeType_BaseType: {
            Token token = getToken(s->tokens, node->baseTypeNode.typeName);

            // NOTE(radomski): @HACK: the solidity parser when parsing
            // `address(this)` will not return the address as a type name but
            // as an identifier.
            if(stringMatch(token.string, LIT_TO_STR("address"))) {
                l += popU32(s);
                l += pushU32(s, ASTNodeType_IdentifierExpression);
                l += pushTokenStringById(s, node->baseTypeNode.typeName);
            } else {
                l += pushType(s, node);
            }
        } break;
        case ASTNodeType_MemberAccessExpression: {
            ASTNodeMemberAccessExpression *member = &node->memberAccessExpressionNode;
            l += pushExpression(s, member->expression);
            l += pushTokenStringById(s, member->memberName);
        } break;
        case ASTNodeType_ArrayAccessExpression: {
            ASTNodeArrayAccessExpression *array = &node->arrayAccessExpressionNode;
            l += pushExpression(s, array->expression);
            l += pushU32(s, array->indexExpression != 0x0);
            if(array->indexExpression != 0x0) {
                l += pushExpression(s, array->indexExpression);
            }
        } break;
        case ASTNodeType_ArraySliceExpression: {
            ASTNodeArraySliceExpression *array = &node->arraySliceExpressionNode;
            l += pushExpression(s, array->expression);

            l += pushU32(s, array->leftFenceExpression != 0x0);
            if(array->leftFenceExpression != 0x0) {
                l += pushExpression(s, array->leftFenceExpression);
            }
            l += pushU32(s, array->rightFenceExpression != 0x0);
            if(array->rightFenceExpression != 0x0) {
                l += pushExpression(s, array->rightFenceExpression);
            }
        } break;
        case ASTNodeType_TerneryExpression: {
            ASTNodeTerneryExpression *ternery = &node->terneryExpressionNode;
            l += pushExpression(s, ternery->condition);
            l += pushExpression(s, ternery->trueExpression);
            l += pushExpression(s, ternery->falseExpression);
        } break;
        default: {
            javascriptPrintNumber(node->type);
            javascriptPrintString("here");
            assert(0);
        }
    }

    return l;
}

static u32
pushStatement(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    switch(node->type) {
        case ASTNodeType_BlockStatement: {
            ASTNodeBlockStatement *block = &node->blockStatementNode;
            l += pushU32(s, block->statements.count);
            ASTNodeLink *statement = block->statements.head;
            for(u32 i = 0; i < block->statements.count; i++, statement = statement->next) {
                l += pushStatement(s, &statement->node);
            }
        } break;
        case ASTNodeType_ReturnStatement: {
            l += pushExpression(s, node->returnStatementNode.expression);
        } break;
        case ASTNodeType_ExpressionStatement: {
            l += pushU16(s, node->expressionStatementNode.expression != 0x0);
            if(node->expressionStatementNode.expression != 0x0) {
                l += pushExpression(s, node->expressionStatementNode.expression);
            }
        } break;
        case ASTNodeType_IfStatement: {
            l += pushExpression(s, node->ifStatementNode.conditionExpression);
            l += pushStatement(s, node->ifStatementNode.trueStatement);
            if(node->ifStatementNode.falseStatement == 0x0) {
                l += pushU32(s, 0);
            } else {
                l += pushU32(s, 1);
                l += pushStatement(s, node->ifStatementNode.falseStatement);
            }
        } break;
        case ASTNodeType_VariableDeclarationStatement: {
            ASTNodeVariableDeclarationStatement *statement = &node->variableDeclarationStatementNode;

            l += pushVariableDeclaration(s, statement->variableDeclaration);
            l += pushU32(s, statement->initialValue == 0x0);
            if(statement->initialValue != 0x0) {
                l += pushExpression(s, statement->initialValue);
            }
        } break;
        case ASTNodeType_VariableDeclarationTupleStatement: {
            ASTNodeVariableDeclarationTupleStatement *statement = &node->variableDeclarationTupleStatementNode;

            ASTNodeLink *decl = statement->declarations.head;
            l += pushU32(s, statement->declarations.count);
            for(u32 i = 0; i < statement->declarations.count; i++, decl = decl->next) {
                l += pushU32(s, decl->node.type != ASTNodeType_None);
                if(decl->node.type != ASTNodeType_None) {
                    l += pushVariableDeclaration(s, &decl->node);
                }
            }

            l += pushExpression(s, statement->initialValue);
        } break;
        case ASTNodeType_WhileStatement: {
            ASTNodeWhileStatement *statement = &node->whileStatementNode;

            l += pushExpression(s, statement->expression);
            l += pushStatement(s, statement->body);
        } break;
        case ASTNodeType_ForStatement: {
            ASTNodeForStatement *statement = &node->forStatementNode;

            l += pushU16(s, statement->variableStatement != 0x0);
            if(statement->variableStatement != 0x0) {
                l += pushStatement(s, statement->variableStatement);
            }
            l += pushU16(s, statement->conditionExpression != 0x0);
            if(statement->conditionExpression != 0x0) {
                l += pushExpression(s, statement->conditionExpression);
            }

            ASTNode virtualExpressionStatement = { 0 };
            virtualExpressionStatement.type = ASTNodeType_ExpressionStatement;
            virtualExpressionStatement.expressionStatementNode.expression = statement->incrementExpression;
            l += pushStatement(s, &virtualExpressionStatement);

            l += pushStatement(s, statement->body);
        } break;
        case ASTNodeType_RevertStatement: {
            ASTNodeRevertStatement *statement = &node->revertStatementNode;

            l += pushExpression(s, statement->expression);
        } break;
        case ASTNodeType_BreakStatement:
        case ASTNodeType_ContinueStatement: {
        } break;
        default: {
            javascriptPrintString("Unreachable, unhandled statement type = ");
            javascriptPrintNumber(node->type);
            assert(0);
        }
    }

    return l;
}

static u32
pushFunctionParameters(Serializer *s, FunctionParameterList *parameters) {
    u32 l = 0;

    FunctionParameter *param = parameters->head;
    l += pushU32(s, parameters->count);
    for(u32 i = 0; i < parameters->count; i++, param = param->next) {
        l += pushType(s, param->type);
        l += pushTokenStringById(s, param->identifier);
        l += pushU32(s, param->dataLocation);
    }

    return l;
}

static u32
pushImportDirective(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    l += pushTokenStringById(s, node->pathTokenId);
    l += pushTokenStringById(s, node->unitAliasTokenId);

    l += pushU32(s, node->symbols.count);
    for(u32 i = 0; i < node->symbols.count; i++) {
        // PERF-NOTE(radomski): we could pull out pushing a token string just
        // by itself since we know that the token here is never going to be
        // invalid. But in pushTokenStringById we have to check for invalid
        // which is additional overhead.

        TokenId symbol = listGetTokenId(&node->symbols, i);
        TokenId alias = listGetTokenId(&node->symbolAliases, i);
        l += pushTokenStringById(s, symbol);
        l += pushTokenStringById(s, alias);
    }

    return l;
}

static u32
pushEnumDefinition(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    l += pushTokenStringById(s, node->nameTokenId);

    l += pushU32(s, node->values.count);
    for(u32 i = 0; i < node->values.count; i++) {
        TokenId value = listGetTokenId(&node->values, i);
        l += pushTokenStringById(s, value);
    }

    return l;
}

static u32
pushStruct(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    l += pushTokenStringById(s, node->structNode.nameTokenId);

    assert(node->structNode.memberTypes.count == node->structNode.memberNames.count);
    l += pushU32(s, node->structNode.memberTypes.count);

    ASTNodeLink *typeLink = node->structNode.memberTypes.head;
    for(u32 i = 0; i < node->structNode.memberTypes.count; i++, typeLink = typeLink->next) {
        TokenId name = listGetTokenId(&node->structNode.memberNames, i);
        l += pushType(s, &typeLink->node);
        l += pushTokenStringById(s, name);
    }

    return l;
}

static u32
pushError(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    ASTNodeError *error = &node->errorNode;
    l += pushTokenStringById(s, error->identifier);
    l += pushFunctionParameters(s, &error->parameters);

    return l;
}

static u32
pushEvent(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    ASTNodeEvent *event = &node->eventNode;
    l += pushTokenStringById(s, event->identifier);
    l += pushU32(s, event->anonymous);

    FunctionParameter *param = event->parameters.head;
    l += pushU32(s, node->eventNode.parameters.count);
    for(u32 i = 0; i < event->parameters.count; i++, param = param->next) {
        l += pushType(s, param->type);
        l += pushTokenStringById(s, param->identifier);
        l += pushU32(s, param->dataLocation);
    }

    return l;
}

static u32
pushTypedef(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    ASTNodeTypedef *typedefNode = &node->typedefNode;
    l += pushTokenStringById(s, typedefNode->identifier);
    l += pushType(s, typedefNode->type);

    return l;
}

static u32
pushConstVariable(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    ASTNodeConstVariable *constNode = &node->constVariableNode;
    l += pushTokenStringById(s, constNode->identifier);
    l += pushType(s, constNode->type);
    l += pushExpression(s, constNode->expression);

    return l;
}

static u32
pushStateVariableDeclaration(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeConstVariable *decl = &node->constVariableNode;

    l += pushTokenStringById(s, decl->identifier);
    l += pushType(s, decl->type);
    l += pushU16(s, decl->visibility);
    l += pushU16(s, decl->mutability);
    l += pushU32(s, decl->expression != 0x0);
    if(decl->expression != 0x0) {
        l += pushExpression(s, decl->expression);
    }

    return l;
}

static u32
pushFunctionDefinition(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeFunctionDefinition *function = &node->functionDefinitionNode;
    l += pushTokenStringById(s, function->name);

    l += pushFunctionParameters(s, &function->parameters);
    l += pushU16(s, function->visibility);
    l += pushU16(s, function->stateMutability);
    l += pushU16(s, function->virtual);
    l += pushFunctionParameters(s, &function->returnParameters);
    l += pushU32(s, function->body != 0x0);

    if(function->body != 0x0) {
        l += pushStatement(s, function->body);
    }

    return l;
}

static u32
pushContractDefinition(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeContractDefintion *contract = &node->contractDefintionNode;
    l += pushTokenStringById(s, contract->name);
    l += pushU32(s, contract->elements.count);

    ASTNodeLink *element = contract->elements.head;
    for(u32 i = 0; i < contract->elements.count; i++, element = element->next) {
        l += pushASTNode(s, &element->node);
    }

    return l;
}

static u32
pushASTNode(Serializer *s, ASTNode *node) {
    u32 l = 0;

    switch(node->type) {
        case ASTNodeType_Import: {
            l = pushImportDirective(s, node);
        } break;
        case ASTNodeType_EnumDefinition: {
            l = pushEnumDefinition(s, node);
        } break;
        case ASTNodeType_Struct: {
            l = pushStruct(s, node);
        } break;
        case ASTNodeType_Error: {
            l = pushError(s, node);
        } break;
        case ASTNodeType_Event: {
            l = pushEvent(s, node);
        } break;
        case ASTNodeType_Typedef: {
            l = pushTypedef(s, node);
        } break;
        case ASTNodeType_ConstVariable: {
            l = pushConstVariable(s, node);
        } break;
        case ASTNodeType_StateVariableDeclaration: {
            l = pushStateVariableDeclaration(s, node);
        } break;
        case ASTNodeType_FunctionDefinition: {
            l = pushFunctionDefinition(s, node);
        } break;
        case ASTNodeType_LibraryDefinition:
        case ASTNodeType_ContractDefinition: {
            l = pushContractDefinition(s, node);
        } break;
        default: {
            assert(0);
        } break;
    }

    return l;
};

static u32
pushSourceUnit(Serializer *s, ASTNode *node) {
    u32 l = 0;

    l += pushU32(s, node->type);
    l += pushU32(s, node->children.count);

    ASTNodeLink *child = node->children.head;
    for(u32 i = 0; i < node->children.count; i++, child = child->next) {
        l += pushASTNode(s, &child->node);
    }

    return l;
}

static u32
calculateResultingSize(Serializer *s, ASTNode *node) {
    assert(s->head == 0x0);
    u32 result = pushSourceUnit(s, node);
    return result;
}

static String
astNodeToBinary(Serializer *s, ASTNode *node) {
    u32 size = calculateResultingSize(s, node);
    u8 *data = arrayPush(s->arena, u8, size);
    String result = { .data = data, .size = size };
    s->head = (char **)&data;

    pushSourceUnit(s, node);

    return result;
}

