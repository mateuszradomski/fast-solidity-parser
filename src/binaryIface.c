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

    return -((u32)(sizeof(u32)));
}

static u32
pushString(Serializer *s, String string) {
    pushU32(s, (u32)(string.data - s->inputStringBase));
    pushU32(s, (u32)string.size);

    return 2 * sizeof(u32);
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
static u32 pushFunctionParameters(Serializer *s, FunctionParameterList *parameters);

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
        case ASTNodeType_FunctionType: {
            l += pushU32(s, node->type);
            l += pushFunctionParameters(s, &node->functionTypeNode.parameters);
            l += pushFunctionParameters(s, &node->functionTypeNode.returnParameters);
            l += pushU16(s, node->functionTypeNode.visibility);
            l += pushU16(s, node->functionTypeNode.stateMutability);
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
pushCallArgumentList(Serializer *s, ASTNodeList *expressions, TokenIdList *names) {
    u32 l = 0;

    l += pushU32(s, expressions->count);
    if(expressions->count == -1) {
        return l;
    }

    ASTNodeLink *argument = expressions->head;
    for(u32 i = 0; i < expressions->count; i++, argument = argument->next) {
        l += pushExpression(s, &argument->node);
    }

    l += pushU32(s, names->count);
    for(u32 i = 0; i < names->count; i++) {
        TokenId literal = listGetTokenId(names, i);
        l += pushTokenStringById(s, literal);
    }

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
        case ASTNodeType_UnicodeStringLitExpression:
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
        case ASTNodeType_IdentifierPath:
        case ASTNodeType_ArrayType:
        case ASTNodeType_MappingType: {
            l += pushType(s, node);
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
                l += pushU16(s, element->node.type != ASTNodeType_None);
                if(element->node.type != ASTNodeType_None) {
                    l += pushExpression(s, &element->node);
                }
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
            l += pushCallArgumentList(s, &function->argumentsExpression, &function->argumentsName);
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
        case ASTNodeType_InlineArrayExpression: {
            ASTNodeInlineArrayExpression *array = &node->inlineArrayExpressionNode;

            l += pushU32(s, array->expressions.count);
            ASTNodeLink *expression = array->expressions.head;
            for(u32 i = 0; i < array->expressions.count; i++, expression = expression->next) {
                l += pushExpression(s, &expression->node);
            }
        } break;
        case ASTNodeType_TerneryExpression: {
            ASTNodeTerneryExpression *ternery = &node->terneryExpressionNode;
            l += pushExpression(s, ternery->condition);
            l += pushExpression(s, ternery->trueExpression);
            l += pushExpression(s, ternery->falseExpression);
        } break;
        case ASTNodeType_NamedParameterExpression: {
            ASTNodeNamedParametersExpression *named = &node->namedParametersExpressionNode;
            l += pushExpression(s, named->expression);

            l += pushU32(s, named->names.count);
            ASTNodeLink *expression = named->expressions.head;
            for(u32 i = 0; i < named->expressions.count; i++, expression = expression->next) {
                l += pushTokenStringById(s, listGetTokenId(&named->names, i));
                l += pushExpression(s, &expression->node);
            }
        } break;
        case ASTNodeType_NameValue: {
            ASTNodeNameValue *nameValue = &node->nameValueNode;
            l += pushTokenStringById(s, nameValue->name);
            l += pushExpression(s, nameValue->value);
        } break;
        default: {
            javascriptPrintNumber(node->type);
            javascriptPrintString("here");
            assert(0);
        }
    }

    return l;
}

static u32 pushYulExpression(Serializer *s, ASTNode *node);

static u32
pushYulFunctionCall(Serializer *s, ASTNode *node) {
    u32 l = 0;

    ASTNodeYulFunctionCallExpression *function = &node->yulFunctionCallExpressionNode;

    l += pushTokenStringById(s, function->identifier);
    l += pushU32(s, function->arguments.count);
    ASTNodeLink *argument = function->arguments.head;
    for(u32 i = 0; i < function->arguments.count; i++, argument = argument->next) {
        l += pushYulExpression(s, &argument->node);
    }

    return l;
}

static u32
pushYulExpression(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);
    
    switch(node->type) {
        case ASTNodeType_YulNumberLitExpression: {
            l += pushTokenStringById(s, node->yulNumberLitExpressionNode.value);
        } break;
        case ASTNodeType_YulStringLitExpression: {
            l += pushTokenStringById(s, node->yulStringLitExpressionNode.value);
        } break;
        case ASTNodeType_YulHexNumberLitExpression: {
            l += pushTokenStringById(s, node->yulHexNumberLitExpressionNode.value);
        } break;
        case ASTNodeType_YulBoolLitExpression: {
            l += pushTokenStringById(s, node->yulBoolLitExpressionNode.value);
        } break;
        case ASTNodeType_YulHexStringLitExpression: {
            l += pushTokenStringById(s, node->yulHexStringLitExpressionNode.value);
        } break;
        case ASTNodeType_YulMemberAccessExpression: {
            l += pushU32(s, node->yulIdentifierPathExpressionNode.count);
            for(u32 i = 0; i < node->yulIdentifierPathExpressionNode.count; i++) {
                l += pushTokenStringById(s, node->yulIdentifierPathExpressionNode.identifiers[i]);
            }
        } break;
        case ASTNodeType_YulFunctionCallExpression: {
            l += pushYulFunctionCall(s, node);
        } break;
        default: {
            javascriptPrintNumber(node->type);
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
        case ASTNodeType_UncheckedBlockStatement: {
            ASTNodeUncheckedBlockStatement *unchecked = &node->uncheckedBlockStatementNode;
            l += pushStatement(s, unchecked->block);
        } break;
        case ASTNodeType_ReturnStatement: {
            l += pushU16(s, node->returnStatementNode.expression != 0x0);
            if(node->returnStatementNode.expression != 0x0) {
                l += pushExpression(s, node->returnStatementNode.expression);
            }
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
        case ASTNodeType_DoWhileStatement:
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
        case ASTNodeType_EmitStatement: {
            ASTNodeEmitStatement *statement = &node->emitStatementNode;

            l += pushExpression(s, statement->expression);
        } break;
        case ASTNodeType_TryStatement: {
            ASTNodeTryStatement *statement = &node->tryStatementNode;

            l += pushExpression(s, statement->expression);
            l += pushFunctionParameters(s, &statement->returnParameters);
            l += pushStatement(s, statement->body);

            l += pushU32(s, statement->catches.count);
            ASTNodeLink *catchLink = statement->catches.head;
            for(u32 i = 0; i < statement->catches.count; i++, catchLink = catchLink->next) {
                ASTNodeCatchStatement *catch = &catchLink->node.catchStatementNode;
                l += pushTokenStringById(s, catch->identifier);
                l += pushFunctionParameters(s, &catch->parameters);
                l += pushStatement(s, catch->body);
            }
        } break;
        case ASTNodeType_BreakStatement:
        case ASTNodeType_ContinueStatement: {
        } break;
        case ASTNodeType_AssemblyStatement: {
            ASTNodeAssemblyStatement *statement = &node->assemblyStatementNode;

            l += pushU16(s, statement->isEVMAsm);
            l += pushU16(s, statement->flags.count);
            for(u32 i = 0; i < statement->flags.count; i++) {
                l += pushTokenStringById(s, listGetTokenId(&statement->flags, i));
            }

            l += pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulBlockStatement: {
            ASTNodeBlockStatement *statement = &node->blockStatementNode;

            l += pushU32(s, statement->statements.count);
            ASTNodeLink *it = statement->statements.head;
            for(u32 i = 0; i < statement->statements.count; i++, it = it->next) {
                l += pushStatement(s, &it->node);
            }
        } break;
        case ASTNodeType_YulVariableDeclaration: {
            ASTNodeYulVariableDeclaration *statement = &node->yulVariableDeclarationNode;

            l += pushU32(s, statement->identifiers.count);
            for(u32 i = 0; i < statement->identifiers.count; i++) {
                l += pushTokenStringById(s, listGetTokenId(&statement->identifiers, i));
            }

            l += pushU16(s, statement->value != 0x0);
            if(statement->value != 0x0) {
                l += pushYulExpression(s, statement->value);
            }
        } break;
        case ASTNodeType_YulVariableAssignment: {
            ASTNodeYulVariableAssignment *statement = &node->yulVariableAssignmentNode;

            l += pushU32(s, statement->paths.count);
            ASTNodeLink *it = statement->paths.head;
            for(u32 i = 0; i < statement->paths.count; i++, it = it->next) {
                l += pushYulExpression(s, &it->node);
            }

            l += pushU16(s, statement->value != 0x0);
            if(statement->value != 0x0) {
                l += pushYulExpression(s, statement->value);
            }
        } break;
        case ASTNodeType_YulFunctionCallExpression: {
            l += pushYulFunctionCall(s, node);
        } break;
        case ASTNodeType_YulIfStatement: {
            ASTNodeYulIfStatement *statement = &node->yulIfStatementNode;

            l += pushYulExpression(s, statement->expression);
            l += pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulForStatement: {
            ASTNodeYulForStatement *statement = &node->yulForStatementNode;

            l += pushStatement(s, statement->variableDeclaration);
            l += pushYulExpression(s, statement->condition);
            l += pushStatement(s, statement->increment);
            l += pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulFunctionDefinition: {
            ASTNodeYulFunctionDefinition *statement = &node->yulFunctionDefinitionNode;

            l += pushTokenStringById(s, statement->identifier);
            l += pushU32(s, statement->parameters.count);
            for(u32 i = 0; i < statement->parameters.count; i++) {
                l += pushTokenStringById(s, listGetTokenId(&statement->parameters, i));
            }
            l += pushU32(s, statement->returnParameters.count);
            for(u32 i = 0; i < statement->returnParameters.count; i++) {
                l += pushTokenStringById(s, listGetTokenId(&statement->returnParameters, i));
            }
            l += pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulSwitchStatement: {
            ASTNodeYulSwitchStatement *statement = &node->yulSwitchStatementNode;

            l += pushYulExpression(s, statement->expression);
            assert(statement->caseLiterals.count == statement->caseBlocks.count);
            l += pushU32(s, statement->caseLiterals.count);

            ASTNodeLink *blkIt = statement->caseBlocks.head;
            ASTNodeLink *litIt = statement->caseLiterals.head;
            for(u32 i = 0; i < statement->caseLiterals.count; i++, litIt = litIt->next, blkIt = blkIt->next) {
                l += pushStatement(s, &blkIt->node);
                l += pushYulExpression(s, &litIt->node);
            }

            l += pushU16(s, statement->defaultBlock != 0x0);
            if(statement->defaultBlock != 0x0) {
                l += pushStatement(s, statement->defaultBlock);
            }
        } break;
        case ASTNodeType_YulLeaveStatement:
        case ASTNodeType_YulBreakStatement:
        case ASTNodeType_YulContinueStatement: {
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
    if(parameters->count == -1) {
        return l;
    }

    for(u32 i = 0; i < parameters->count; i++, param = param->next) {
        l += pushType(s, param->type);
        l += pushTokenStringById(s, param->identifier);
        l += pushU32(s, param->dataLocation);
    }

    return l;
}

static u32
pushPragma(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);
    ASTNodePragma *pragma = &node->pragmaNode;

    l += pushTokenStringById(s, pragma->major);
    assert(pragma->following.count > 0);
    TokenId firstTokenId = listGetTokenId(&pragma->following, 0);
    TokenId lastTokenId = listGetTokenId(&pragma->following, pragma->following.count - 1);
    String first = getToken(s->tokens, firstTokenId).string;
    String last = getToken(s->tokens, lastTokenId).string;
    String string = {
        .data = first.data,
        .size = (u32)(last.data - first.data) + last.size,
    };

    l += pushString(s, string);

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
pushUsing(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);
    ASTNodeUsing *using = &node->usingNode;

    ASTNodeLink *it = using->identifiers.head;
    l += pushU32(s, using->identifiers.count);
    for(u32 i = 0; i < using->identifiers.count; i++, it = it->next) {
        l += pushType(s, &it->node);
    }

    l += pushU32(s, using->operators.count);
    for(u32 i = 0; i < using->operators.count; i++) {
        l += pushU16(s, listGetU16(&using->operators, i));
    }

    l += pushU16(s, using->forType != 0x0);
    if(using->forType != 0x0) {
        l += pushType(s, using->forType);
    }
    l += pushU16(s, using->global);
    l += pushU16(s, using->onLibrary);

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
    l += pushU16(s, decl->override);

    if(decl->override != 0) {
        l += pushU32(s, decl->overrides.count);
        ASTNodeLink *override = decl->overrides.head;
        for(u32 i = 0; i < decl->overrides.count; i++, override = override->next) {
            l += pushType(s, &override->node);
        }
    }

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
    l += pushU16(s, function->override);

    if(function->override != 0) {
        l += pushU32(s, function->overrides.count);
        ASTNodeLink *override = function->overrides.head;
        for(u32 i = 0; i < function->overrides.count; i++, override = override->next) {
            l += pushType(s, &override->node);
        }
    }

    l += pushFunctionParameters(s, &function->returnParameters);
    l += pushU32(s, function->modifiers.count);
    ASTNodeLink *it = function->modifiers.head;
    for(u32 i = 0; i < function->modifiers.count; i++, it = it->next) {
        ASTNodeModifierInvocation *invocation = &it->node.modifierInvocationNode;
        l += pushType(s, invocation->identifier);
        l += pushCallArgumentList(s, &invocation->argumentsExpression, &invocation->argumentsName);
    }

    l += pushU32(s, function->body != 0x0);

    if(function->body != 0x0) {
        l += pushStatement(s, function->body);
    }

    return l;
}

static u32
pushModifierDefinition(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeFunctionDefinition *function = &node->functionDefinitionNode;
    l += pushTokenStringById(s, function->name);

    l += pushFunctionParameters(s, &function->parameters);
    l += pushU16(s, function->virtual);
    l += pushU16(s, function->override);

    if(function->override != 0) {
        l += pushU32(s, function->overrides.count);
        ASTNodeLink *override = function->overrides.head;
        for(u32 i = 0; i < function->overrides.count; i++, override = override->next) {
            l += pushType(s, &override->node);
        }
    }

    l += pushU32(s, function->body != 0x0);
    if(function->body != 0x0) {
        l += pushStatement(s, function->body);
    }

    return l;
}

static u32
pushInheritanceSpecifier(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeInheritanceSpecifier *inheritance = &node->inheritanceSpecifierNode;
    l += pushType(s, inheritance->identifier);
    l += pushCallArgumentList(s, &inheritance->argumentsExpression, &inheritance->argumentsName);

    return l;
}

static u32
pushContractDefinition(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeContractDefinition *contract = &node->contractDefinitionNode;
    l += pushTokenStringById(s, contract->name);

    l += pushU32(s, contract->baseContracts.count);
    ASTNodeLink *baseContract = contract->baseContracts.head;
    for(u32 i = 0; i < contract->baseContracts.count; i++, baseContract = baseContract->next) {
        l += pushInheritanceSpecifier(s, &baseContract->node);
    }

    l += pushU32(s, contract->elements.count);
    ASTNodeLink *element = contract->elements.head;
    for(u32 i = 0; i < contract->elements.count; i++, element = element->next) {
        l += pushASTNode(s, &element->node);
    }

    return l;
}

static u32
pushConstructorDefinition(Serializer *s, ASTNode *node) {
    u32 l = pushU32(s, node->type);

    ASTNodeConstructorDefinition *constructor = &node->constructorDefinitionNode;

    l += pushFunctionParameters(s, &constructor->parameters);
    l += pushU16(s, constructor->visibility);
    l += pushU16(s, constructor->stateMutability);

    l += pushU32(s, constructor->modifiers.count);
    ASTNodeLink *it = constructor->modifiers.head;
    for(u32 i = 0; i < constructor->modifiers.count; i++, it = it->next) {
        ASTNodeModifierInvocation *invocation = &it->node.modifierInvocationNode;
        l += pushType(s, invocation->identifier);
        l += pushCallArgumentList(s, &invocation->argumentsExpression, &invocation->argumentsName);
    }

    l += pushStatement(s, constructor->body);

    return l;
}

static u32
pushASTNode(Serializer *s, ASTNode *node) {
    u32 l = 0;

    switch(node->type) {
        case ASTNodeType_Pragma: {
            l = pushPragma(s, node);
        } break;
        case ASTNodeType_Import: {
            l = pushImportDirective(s, node);
        } break;
        case ASTNodeType_Using: {
            l = pushUsing(s, node);
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
        case ASTNodeType_FallbackFunction:
        case ASTNodeType_ReceiveFunction:
        case ASTNodeType_FunctionDefinition: {
            l = pushFunctionDefinition(s, node);
        } break;
        case ASTNodeType_ConstructorDefinition: {
            l = pushConstructorDefinition(s, node);
        } break;
        case ASTNodeType_ModifierDefinition: {
            l = pushModifierDefinition(s, node);
        } break;
        case ASTNodeType_LibraryDefinition:
        case ASTNodeType_ContractDefinition:
        case ASTNodeType_InterfaceDefinition:
        case ASTNodeType_AbstractContractDefinition: {
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

