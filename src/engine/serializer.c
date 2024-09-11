typedef struct Buffer {
    u8 *data;
    size_t size;
    size_t capacity;
} Buffer;

typedef struct Serializer {
    Arena *arena;
    TokenizeResult tokens;
    const u8 *inputStringBase;
    Buffer buffers[16];
    u32 bufferCount;
    u32 activeBuffer;
} Serializer;

static void pushASTNode(Serializer *s, ASTNode *node);

static void
pushOutputBuffer(Serializer *s, u32 size) {
    u8 *data = arrayPush(s->arena, u8, size);

    s->buffers[s->bufferCount++] = (Buffer){ .data = data, .size = 0, .capacity = size };
    s->activeBuffer += 1;
}

static Buffer *
getCurrentOutputBuffer(Serializer *s) {
    return s->buffers + s->activeBuffer;
}

static String
mergeOutputBuffers(Serializer *s) {
    if(s->bufferCount == 1) {
        return (String){ .data = s->buffers[0].data, .size = s->buffers[0].size };
    }

    u32 totalMemoryUsed = 0;
    for(u32 i = 0; i < s->bufferCount; i++) {
        totalMemoryUsed += s->buffers[i].capacity;
    }

    u8 *data = arrayPush(s->arena, u8, totalMemoryUsed);
    u8 *head = data;
    u32 outputSize = 0;
    for(u32 i = 0; i < s->bufferCount; i++) {
        u32 count = s->buffers[i].size;
        outputSize += count;

        memcpy(head, s->buffers[i].data, count);
        head += count;
    }

    return (String) { .data = data, .size = outputSize };
}

static Serializer
createSerializer(Arena *arena, const void *inputStringBase, TokenizeResult tokens) {
    Serializer s = {
        .arena = arena,
        .tokens = tokens,
        .inputStringBase = (const u8 *)inputStringBase,
        .activeBuffer = ((u32)-1),
    };

    return s;
}

static void
pushU16(Serializer *s, u16 value) {
    Buffer *buffer = getCurrentOutputBuffer(s);
    if(buffer->size + sizeof(u16) >= buffer->capacity) {
        pushOutputBuffer(s, buffer->capacity);
        buffer = getCurrentOutputBuffer(s);
    }

    u16 *ptr = (u16 *)(buffer->data + buffer->size);
    *ptr = value;
    buffer->size += sizeof(u16);
}

static void
pushU32(Serializer *s, u32 value) {
    Buffer *buffer = getCurrentOutputBuffer(s);
    if(buffer->size + sizeof(u32) >= buffer->capacity) {
        pushOutputBuffer(s, buffer->capacity);
        buffer = getCurrentOutputBuffer(s);
    }

    u32 *ptr = (u32 *)(buffer->data + buffer->size);
    *ptr = value;
    buffer->size += sizeof(u32);
}

static void
popU32(Serializer *s) {
    Buffer *buffer = getCurrentOutputBuffer(s);
    if(buffer->size < 4) {
        assert(s->activeBuffer != 0);
        s->activeBuffer -= 1;

        buffer = getCurrentOutputBuffer(s);
    }

    buffer->size -= 4;
}

static void
pushString(Serializer *s, String string) {
    pushU32(s, (u32)(string.data - s->inputStringBase));
    pushU32(s, (u32)string.size);
}

static void
pushTokenStringById(Serializer *s, TokenId token) {
    if(token == INVALID_TOKEN_ID) {
        pushU32(s, INVALID_TOKEN_ID);
        pushU32(s, 0);
    } else {
        String string = getTokenString(s->tokens, token);
        pushU32(s, (u32)(string.data - s->inputStringBase));
        pushU32(s, (u32)string.size);
    }
}

static void
pushByteRanges(Serializer *s, TokenId start, TokenId end) {
    String startTokenString = getTokenString(s->tokens, start);
    String endTokenString = getTokenString(s->tokens, end);
    TokenType startTokenType = getTokenType(s->tokens, start);
    TokenType endTokenType = getTokenType(s->tokens, end);
    u32 startOffset = (u32)(startTokenString.data - s->inputStringBase);
    u32 endOffset = (u32)(endTokenString.data - s->inputStringBase + endTokenString.size) - 1;

    if(startTokenType == TokenType_StringLit) { startOffset--; }
    if(startTokenType == TokenType_HexStringLit) { startOffset -= 4; }
    if(startTokenType == TokenType_UnicodeStringLit) { startOffset -= 8; }
    if(endTokenType == TokenType_StringLit) { endOffset++; }
    if(endTokenType == TokenType_HexStringLit) { endOffset++; }
    if(endTokenType == TokenType_UnicodeStringLit) { endOffset++; }
    pushU32(s, startOffset);
    pushU32(s, endOffset);
}

static void
pushNodeHeader(Serializer *s, ASTNode *node) {
    pushU32(s, node->type);
    pushByteRanges(s, node->startToken, node->endToken);
}

static void pushExpression(Serializer *s, ASTNode *node);
static void pushParameters(Serializer *s, ASTNodeList *list);

static void
pushType(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    switch(node->type) {
        case ASTNodeType_BaseType: {
            pushTokenStringById(s, node->baseTypeNode.typeName);
            pushU32(s, node->baseTypeNode.payable);
        } break;
        case ASTNodeType_IdentifierPath: {
            pushU32(s, node->identifierPathNode.identifiers.count);
            for(u32 i = 0; i < node->identifierPathNode.identifiers.count; i++) {
                TokenId part = listGetTokenId(&node->identifierPathNode.identifiers, i);
                pushTokenStringById(s, part);
            }
        } break;
        case ASTNodeType_MappingType: {
            pushType(s, node->mappingNode.keyType);
            pushTokenStringById(s, node->mappingNode.keyIdentifier);
            pushType(s, node->mappingNode.valueType);
            pushTokenStringById(s, node->mappingNode.valueIdentifier);
        } break;
        case ASTNodeType_ArrayType: {
            pushType(s, node->arrayTypeNode.elementType);
            pushU32(s, node->arrayTypeNode.lengthExpression != 0x0);
            if(node->arrayTypeNode.lengthExpression != 0x0) {
                pushExpression(s, node->arrayTypeNode.lengthExpression);
            }
        } break;
        case ASTNodeType_FunctionType: {
            pushParameters(s, &node->functionTypeNode.parameters);
            pushParameters(s, &node->functionTypeNode.returnParameters);
            pushU16(s, node->functionTypeNode.visibility);
            pushU16(s, node->functionTypeNode.stateMutability);
        } break;
        default: {
            assert(0);
        }
    }
}

static void
pushVariableDeclaration(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeVariableDeclaration *decl = &node->variableDeclarationNode;
    pushType(s, decl->type);
    pushTokenStringById(s, decl->name);
    pushU32(s, decl->dataLocation);
}

static void
pushCallArgumentList(Serializer *s, ASTNodeList *expressions, TokenIdList *names) {
    pushU32(s, expressions->count);
    if(expressions->count == -1) {
        return;
    }

    ASTNodeLink *argument = expressions->head;
    for(u32 i = 0; i < expressions->count; i++, argument = argument->next) {
        pushExpression(s, &argument->node);
    }

    pushU32(s, names->count);
    for(u32 i = 0; i < names->count; i++) {
        TokenId literal = listGetTokenId(names, i);
        pushTokenStringById(s, literal);
    }
}

static void
pushExpression(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    switch(node->type){
        case ASTNodeType_NumberLitExpression: {
            pushTokenStringById(s, node->numberLitExpressionNode.value);
            pushTokenStringById(s, node->numberLitExpressionNode.subdenomination);
        } break;
        case ASTNodeType_HexStringLitExpression:
        case ASTNodeType_UnicodeStringLitExpression:
        case ASTNodeType_StringLitExpression: {
            ASTNodeStringLitExpression *expression = &node->stringLitExpressionNode;

            pushU32(s, expression->values.count);
            for(u32 i = 0; i < expression->values.count; i++) {
                // PERF-NOTE(radomski): we could pull out pushing a token string just
                // by itself since we know that the token here is never going to be
                // invalid. But in pushTokenStringById we have to check for invalid
                // which is additional overhead.

                TokenId literal = listGetTokenId(&expression->values, i);
                pushTokenStringById(s, literal);
            }
        } break;
        case ASTNodeType_BoolLitExpression: {
            pushTokenStringById(s, node->boolLitExpressionNode.value);
        } break;
        case ASTNodeType_IdentifierPath:
        case ASTNodeType_ArrayType:
        case ASTNodeType_MappingType: {
            pushType(s, node);
        } break;
        case ASTNodeType_IdentifierExpression: {
            pushTokenStringById(s, node->identifierExpressionNode.value);
        } break;
        case ASTNodeType_BinaryExpression: {
            pushU32(s, node->binaryExpressionNode.operator);
            pushExpression(s, node->binaryExpressionNode.left);
            pushExpression(s, node->binaryExpressionNode.right);
        } break;
        case ASTNodeType_TupleExpression: {
            ASTNodeTupleExpression *tuple = &node->tupleExpressionNode;

            pushU32(s, tuple->elements.count);
            ASTNodeLink *element = tuple->elements.head;
            for(u32 i = 0; i < tuple->elements.count; i++, element = element->next) {
                pushU16(s, element->node.type != ASTNodeType_None);
                if(element->node.type != ASTNodeType_None) {
                    pushExpression(s, &element->node);
                }
            }
        } break;
        case ASTNodeType_UnaryExpression:
        case ASTNodeType_UnaryExpressionPostfix: {
            pushU32(s, node->unaryExpressionNode.operator);
            pushExpression(s, node->unaryExpressionNode.subExpression);
        } break;
        case ASTNodeType_NewExpression: {
            pushType(s, node->newExpressionNode.typeName);
        } break;
        case ASTNodeType_FunctionCallExpression: {
            ASTNodeFunctionCallExpression *function = &node->functionCallExpressionNode;

            pushExpression(s, function->expression);
            pushCallArgumentList(s, &function->argumentsExpression, &function->argumentsName);
        } break;
        case ASTNodeType_BaseType: {
            String tokenString = getTokenString(s->tokens, node->baseTypeNode.typeName);

            // NOTE(radomski): @HACK: the solidity parser when parsing
            // `address(this)` will not return the address as a type name but
            // as an identifier.
            if(stringMatch(tokenString, LIT_TO_STR("address"))) {
                popU32(s);
                popU32(s);
                popU32(s);

                pushU32(s, ASTNodeType_IdentifierExpression);
                pushByteRanges(s, node->startToken, node->endToken);

                pushTokenStringById(s, node->baseTypeNode.typeName);
            } else {
                pushType(s, node);
            }
        } break;
        case ASTNodeType_MemberAccessExpression: {
            ASTNodeMemberAccessExpression *member = &node->memberAccessExpressionNode;
            pushExpression(s, member->expression);
            pushTokenStringById(s, member->memberName);
        } break;
        case ASTNodeType_ArrayAccessExpression: {
            ASTNodeArrayAccessExpression *array = &node->arrayAccessExpressionNode;
            pushExpression(s, array->expression);
            pushU32(s, array->indexExpression != 0x0);
            if(array->indexExpression != 0x0) {
                pushExpression(s, array->indexExpression);
            }
        } break;
        case ASTNodeType_ArraySliceExpression: {
            ASTNodeArraySliceExpression *array = &node->arraySliceExpressionNode;
            pushExpression(s, array->expression);

            pushU32(s, array->leftFenceExpression != 0x0);
            if(array->leftFenceExpression != 0x0) {
                pushExpression(s, array->leftFenceExpression);
            }
            pushU32(s, array->rightFenceExpression != 0x0);
            if(array->rightFenceExpression != 0x0) {
                pushExpression(s, array->rightFenceExpression);
            }
        } break;
        case ASTNodeType_InlineArrayExpression: {
            ASTNodeInlineArrayExpression *array = &node->inlineArrayExpressionNode;

            pushU32(s, array->expressions.count);
            ASTNodeLink *expression = array->expressions.head;
            for(u32 i = 0; i < array->expressions.count; i++, expression = expression->next) {
                pushExpression(s, &expression->node);
            }
        } break;
        case ASTNodeType_TerneryExpression: {
            ASTNodeTerneryExpression *ternery = &node->terneryExpressionNode;
            pushExpression(s, ternery->condition);
            pushExpression(s, ternery->trueExpression);
            pushExpression(s, ternery->falseExpression);
        } break;
        case ASTNodeType_NamedParameterExpression: {
            ASTNodeNamedParametersExpression *named = &node->namedParametersExpressionNode;
            pushExpression(s, named->expression);

            pushByteRanges(s, named->listStartToken, named->listEndToken);
            pushU32(s, named->names.count);
            ASTNodeLink *expression = named->expressions.head;
            for(u32 i = 0; i < named->expressions.count; i++, expression = expression->next) {
                pushTokenStringById(s, listGetTokenId(&named->names, i));
                pushExpression(s, &expression->node);
            }
        } break;
        default: {
            javascriptPrintNumber(node->type);
            javascriptPrintString("here");
            assert(0);
        }
    }
}

static void pushYulExpression(Serializer *s, ASTNode *node);

static void
pushYulFunctionCall(Serializer *s, ASTNode *node) {
    ASTNodeYulFunctionCallExpression *function = &node->yulFunctionCallExpressionNode;

    pushTokenStringById(s, function->identifier);
    pushU32(s, function->arguments.count);
    ASTNodeLink *argument = function->arguments.head;
    for(u32 i = 0; i < function->arguments.count; i++, argument = argument->next) {
        pushYulExpression(s, &argument->node);
    }
}

static void
pushYulExpression(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);
    
    switch(node->type) {
        case ASTNodeType_YulNumberLitExpression: {
            pushTokenStringById(s, node->yulNumberLitExpressionNode.value);
        } break;
        case ASTNodeType_YulStringLitExpression: {
            pushTokenStringById(s, node->yulStringLitExpressionNode.value);
        } break;
        case ASTNodeType_YulHexNumberLitExpression: {
            pushTokenStringById(s, node->yulHexNumberLitExpressionNode.value);
        } break;
        case ASTNodeType_YulBoolLitExpression: {
            pushTokenStringById(s, node->yulBoolLitExpressionNode.value);
        } break;
        case ASTNodeType_YulHexStringLitExpression: {
            pushTokenStringById(s, node->yulHexStringLitExpressionNode.value);
        } break;
        case ASTNodeType_YulMemberAccessExpression: {
            pushU32(s, node->yulIdentifierPathExpressionNode.count);
            for(u32 i = 0; i < node->yulIdentifierPathExpressionNode.count; i++) {
                pushTokenStringById(s, node->yulIdentifierPathExpressionNode.identifiers[i]);
            }
        } break;
        case ASTNodeType_YulFunctionCallExpression: {
            pushYulFunctionCall(s, node);
        } break;
        default: {
            javascriptPrintNumber(node->type);
            assert(0);
        }
    }
}

static void
pushStatement(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    switch(node->type) {
        case ASTNodeType_BlockStatement: {
            ASTNodeBlockStatement *block = &node->blockStatementNode;
            pushU32(s, block->statements.count);
            ASTNodeLink *statement = block->statements.head;
            for(u32 i = 0; i < block->statements.count; i++, statement = statement->next) {
                pushStatement(s, &statement->node);
            }
        } break;
        case ASTNodeType_UncheckedBlockStatement: {
            ASTNodeUncheckedBlockStatement *unchecked = &node->uncheckedBlockStatementNode;
            pushStatement(s, unchecked->block);
        } break;
        case ASTNodeType_ReturnStatement: {
            pushU16(s, node->returnStatementNode.expression != 0x0);
            if(node->returnStatementNode.expression != 0x0) {
                pushExpression(s, node->returnStatementNode.expression);
            }
        } break;
        case ASTNodeType_ExpressionStatement: {
            pushU16(s, node->expressionStatementNode.expression != 0x0);
            if(node->expressionStatementNode.expression != 0x0) {
                pushExpression(s, node->expressionStatementNode.expression);
            }
        } break;
        case ASTNodeType_IfStatement: {
            pushExpression(s, node->ifStatementNode.conditionExpression);
            pushStatement(s, node->ifStatementNode.trueStatement);
            if(node->ifStatementNode.falseStatement == 0x0) {
                pushU32(s, 0);
            } else {
                pushU32(s, 1);
                pushStatement(s, node->ifStatementNode.falseStatement);
            }
        } break;
        case ASTNodeType_VariableDeclarationStatement: {
            ASTNodeVariableDeclarationStatement *statement = &node->variableDeclarationStatementNode;

            pushVariableDeclaration(s, statement->variableDeclaration);
            pushU32(s, statement->initialValue == 0x0);
            if(statement->initialValue != 0x0) {
                pushExpression(s, statement->initialValue);
            }
        } break;
        case ASTNodeType_VariableDeclarationTupleStatement: {
            ASTNodeVariableDeclarationTupleStatement *statement = &node->variableDeclarationTupleStatementNode;

            ASTNodeLink *decl = statement->declarations.head;
            pushU32(s, statement->declarations.count);
            for(u32 i = 0; i < statement->declarations.count; i++, decl = decl->next) {
                pushU32(s, decl->node.type != ASTNodeType_None);
                if(decl->node.type != ASTNodeType_None) {
                    pushVariableDeclaration(s, &decl->node);
                }
            }

            pushExpression(s, statement->initialValue);
        } break;
        case ASTNodeType_DoWhileStatement:
        case ASTNodeType_WhileStatement: {
            ASTNodeWhileStatement *statement = &node->whileStatementNode;

            pushExpression(s, statement->expression);
            pushStatement(s, statement->body);
        } break;
        case ASTNodeType_ForStatement: {
            ASTNodeForStatement *statement = &node->forStatementNode;

            pushU16(s, statement->variableStatement != 0x0);
            if(statement->variableStatement != 0x0) {
                pushStatement(s, statement->variableStatement);
            }
            pushU16(s, statement->conditionExpression != 0x0);
            if(statement->conditionExpression != 0x0) {
                pushExpression(s, statement->conditionExpression);
            }

            ASTNode virtualExpressionStatement = { 0 };
            virtualExpressionStatement.type = ASTNodeType_ExpressionStatement;
            virtualExpressionStatement.expressionStatementNode.expression = statement->incrementExpression;
            pushStatement(s, &virtualExpressionStatement);

            pushStatement(s, statement->body);
        } break;
        case ASTNodeType_RevertStatement: {
            ASTNodeRevertStatement *statement = &node->revertStatementNode;

            pushExpression(s, statement->expression);
        } break;
        case ASTNodeType_EmitStatement: {
            ASTNodeEmitStatement *statement = &node->emitStatementNode;

            pushExpression(s, statement->expression);
        } break;
        case ASTNodeType_TryStatement: {
            ASTNodeTryStatement *statement = &node->tryStatementNode;

            pushExpression(s, statement->expression);
            pushParameters(s, &statement->returnParameters);
            pushStatement(s, statement->body);

            pushU32(s, statement->catches.count);
            ASTNodeLink *catchLink = statement->catches.head;
            for(u32 i = 0; i < statement->catches.count; i++, catchLink = catchLink->next) {
                ASTNodeCatchStatement *catch = &catchLink->node.catchStatementNode;
                pushNodeHeader(s, &catchLink->node);
                pushTokenStringById(s, catch->identifier);
                pushParameters(s, &catch->parameters);
                pushStatement(s, catch->body);
            }
        } break;
        case ASTNodeType_BreakStatement:
        case ASTNodeType_ContinueStatement: {
        } break;
        case ASTNodeType_AssemblyStatement: {
            ASTNodeAssemblyStatement *statement = &node->assemblyStatementNode;

            pushU16(s, statement->isEVMAsm);
            pushU16(s, statement->flags.count);
            for(u32 i = 0; i < statement->flags.count; i++) {
                pushTokenStringById(s, listGetTokenId(&statement->flags, i));
            }

            pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulBlockStatement: {
            ASTNodeBlockStatement *statement = &node->blockStatementNode;

            pushU32(s, statement->statements.count);
            ASTNodeLink *it = statement->statements.head;
            for(u32 i = 0; i < statement->statements.count; i++, it = it->next) {
                pushStatement(s, &it->node);
            }
        } break;
        case ASTNodeType_YulVariableDeclaration: {
            ASTNodeYulVariableDeclaration *statement = &node->yulVariableDeclarationNode;

            pushU32(s, statement->identifiers.count);
            for(u32 i = 0; i < statement->identifiers.count; i++) {
                pushTokenStringById(s, listGetTokenId(&statement->identifiers, i));
            }

            pushU16(s, statement->value != 0x0);
            if(statement->value != 0x0) {
                pushYulExpression(s, statement->value);
            }
        } break;
        case ASTNodeType_YulVariableAssignment: {
            ASTNodeYulVariableAssignment *statement = &node->yulVariableAssignmentNode;

            pushU32(s, statement->paths.count);
            ASTNodeLink *it = statement->paths.head;
            for(u32 i = 0; i < statement->paths.count; i++, it = it->next) {
                pushYulExpression(s, &it->node);
            }

            pushU16(s, statement->value != 0x0);
            if(statement->value != 0x0) {
                pushYulExpression(s, statement->value);
            }
        } break;
        case ASTNodeType_YulFunctionCallExpression: {
            pushYulFunctionCall(s, node);
        } break;
        case ASTNodeType_YulIfStatement: {
            ASTNodeYulIfStatement *statement = &node->yulIfStatementNode;

            pushYulExpression(s, statement->expression);
            pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulForStatement: {
            ASTNodeYulForStatement *statement = &node->yulForStatementNode;

            pushStatement(s, statement->variableDeclaration);
            pushYulExpression(s, statement->condition);
            pushStatement(s, statement->increment);
            pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulFunctionDefinition: {
            ASTNodeYulFunctionDefinition *statement = &node->yulFunctionDefinitionNode;

            pushTokenStringById(s, statement->identifier);
            pushU32(s, statement->parameters.count);
            for(u32 i = 0; i < statement->parameters.count; i++) {
                pushTokenStringById(s, listGetTokenId(&statement->parameters, i));
            }
            pushU32(s, statement->returnParameters.count);
            for(u32 i = 0; i < statement->returnParameters.count; i++) {
                pushTokenStringById(s, listGetTokenId(&statement->returnParameters, i));
            }
            pushStatement(s, statement->body);
        } break;
        case ASTNodeType_YulSwitchStatement: {
            ASTNodeYulSwitchStatement *statement = &node->yulSwitchStatementNode;

            pushYulExpression(s, statement->expression);
            pushU32(s, statement->cases.count);

            ASTNodeLink *it = statement->cases.head;
            for(u32 i = 0; i < statement->cases.count; i++, it = it->next) {
                pushNodeHeader(s, &it->node);
                pushStatement(s, it->node.yulCaseNode.block);
                pushYulExpression(s, it->node.yulCaseNode.literal);
            }

            pushU16(s, statement->defaultBlock != 0x0);
            if(statement->defaultBlock != 0x0) {
                pushNodeHeader(s, statement->defaultBlock);
                pushStatement(s, statement->defaultBlock->yulCaseNode.block);
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
}

static void
pushParameters(Serializer *s, ASTNodeList *list) {
    if(list == 0x0) {
        pushU32(s, 0xffffffff);
        return;
    }

    pushU32(s, list->count);
    if(list->count == -1) {
        return;
    }

    ASTNodeLink *it = list->head;
    for(u32 i = 0; i < list->count; i++, it = it->next) {
        ASTNodeVariableDeclaration *decl = &it->node.variableDeclarationNode;
        pushNodeHeader(s, &it->node);
        pushType(s, decl->type);
        pushTokenStringById(s, decl->name);
        pushU32(s, decl->dataLocation);
    }
}

static void
pushPragma(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);
    ASTNodePragma *pragma = &node->pragmaNode;

    pushTokenStringById(s, pragma->major);
    TokenId firstTokenId = listGetTokenId(&pragma->following, 0);
    TokenId lastTokenId = listGetTokenId(&pragma->following, pragma->following.count - 1);
    String first = getTokenString(s->tokens, firstTokenId);
    String last = getTokenString(s->tokens, lastTokenId);
    String string = {
        .data = first.data,
        .size = (u32)(last.data - first.data) + last.size,
    };

    pushString(s, string);
}


static void
pushImportDirective(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    pushTokenStringById(s, node->pathTokenId);
    pushTokenStringById(s, node->unitAliasTokenId);

    pushU32(s, node->symbols.count);
    for(u32 i = 0; i < node->symbols.count; i++) {
        // PERF-NOTE(radomski): we could pull out pushing a token string just
        // by itself since we know that the token here is never going to be
        // invalid. But in pushTokenStringById we have to check for invalid
        // which is additional overhead.

        TokenId symbol = listGetTokenId(&node->symbols, i);
        TokenId alias = listGetTokenId(&node->symbolAliases, i);
        pushTokenStringById(s, symbol);
        pushTokenStringById(s, alias);
    }
}

static void
pushUsing(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);
    ASTNodeUsing *using = &node->usingNode;

    ASTNodeLink *it = using->identifiers.head;
    pushU32(s, using->identifiers.count);
    for(u32 i = 0; i < using->identifiers.count; i++, it = it->next) {
        pushType(s, &it->node);
    }

    pushU32(s, using->operators.count);
    for(u32 i = 0; i < using->operators.count; i++) {
        pushU16(s, listGetU16(&using->operators, i));
    }

    pushU16(s, using->forType != 0x0);
    if(using->forType != 0x0) {
        pushType(s, using->forType);
    }
    pushU16(s, using->global);
    pushU16(s, using->onLibrary);
}

static void
pushEnumDefinition(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    pushTokenStringById(s, node->nameTokenId);
    pushU32(s, node->values.count);

    for(u32 i = 0; i < node->values.count; i++) {
        TokenId value = listGetTokenId(&node->values, i);
        pushTokenStringById(s, value);
    }
}

static void
pushStruct(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    pushTokenStringById(s, node->structNode.nameTokenId);
    pushParameters(s, &node->structNode.members);
}

static void
pushError(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeError *error = &node->errorNode;
    pushTokenStringById(s, error->identifier);
    pushParameters(s, &error->parameters);
}

static void
pushEvent(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeEvent *event = &node->eventNode;
    pushTokenStringById(s, event->identifier);
    pushU32(s, event->anonymous);
    pushParameters(s, &event->parameters);
}

static void
pushTypedef(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeTypedef *typedefNode = &node->typedefNode;
    pushTokenStringById(s, typedefNode->identifier);
    pushType(s, typedefNode->type);
}

static void
pushConstVariable(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeConstVariable *constNode = &node->constVariableNode;
    pushTokenStringById(s, constNode->identifier);
    pushType(s, constNode->type);
    pushExpression(s, constNode->expression);
}

static void
pushStateVariableDeclaration(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeConstVariable *decl = &node->constVariableNode;

    pushTokenStringById(s, decl->identifier);
    pushType(s, decl->type);
    pushU16(s, decl->visibility);
    pushU16(s, decl->mutability);
    pushU16(s, decl->override);

    if(decl->override != 0) {
        pushU32(s, decl->overrides.count);
        ASTNodeLink *override = decl->overrides.head;
        for(u32 i = 0; i < decl->overrides.count; i++, override = override->next) {
            pushType(s, &override->node);
        }
    }

    pushU32(s, decl->expression != 0x0);
    if(decl->expression != 0x0) {
        pushExpression(s, decl->expression);
    }
}

static void
pushFunctionDefinition(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeFunctionDefinition *function = &node->functionDefinitionNode;
    pushTokenStringById(s, function->name);

    pushParameters(s, &function->parameters);
    pushU16(s, function->visibility);
    pushU16(s, function->stateMutability);
    pushU16(s, function->virtual);
    pushU16(s, function->override);

    if(function->override != 0) {
        pushU32(s, function->overrides->count);
        ASTNodeLink *override = function->overrides->head;
        for(u32 i = 0; i < function->overrides->count; i++, override = override->next) {
            pushType(s, &override->node);
        }
    }

    pushParameters(s, function->returnParameters);
    if(function->modifiers == 0) {
        pushU32(s, 0);
    } else {
        pushU32(s, function->modifiers->count);
        ASTNodeLink *it = function->modifiers->head;
        for(u32 i = 0; i < function->modifiers->count; i++, it = it->next) {
            ASTNodeModifierInvocation *invocation = &it->node.modifierInvocationNode;
            pushNodeHeader(s, &it->node);
            pushType(s, invocation->identifier);
            pushCallArgumentList(s, &invocation->argumentsExpression, &invocation->argumentsName);
        }
    }

    pushU32(s, function->body != 0x0);

    if(function->body != 0x0) {
        pushStatement(s, function->body);
    }
}

static void
pushModifierDefinition(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeFunctionDefinition *function = &node->functionDefinitionNode;
    pushTokenStringById(s, function->name);

    pushParameters(s, &function->parameters);
    pushU16(s, function->virtual);
    pushU16(s, function->override);

    if(function->override != 0) {
        pushU32(s, function->overrides->count);
        ASTNodeLink *override = function->overrides->head;
        for(u32 i = 0; i < function->overrides->count; i++, override = override->next) {
            pushType(s, &override->node);
        }
    }

    pushU32(s, function->body != 0x0);
    if(function->body != 0x0) {
        pushStatement(s, function->body);
    }
}

static void
pushInheritanceSpecifier(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeInheritanceSpecifier *inheritance = &node->inheritanceSpecifierNode;
    pushType(s, inheritance->identifier);
    pushCallArgumentList(s, &inheritance->argumentsExpression, &inheritance->argumentsName);
}

static void
pushContractDefinition(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeContractDefinition *contract = &node->contractDefinitionNode;
    pushTokenStringById(s, contract->name);

    pushU32(s, contract->baseContracts.count);
    ASTNodeLink *baseContract = contract->baseContracts.head;
    for(u32 i = 0; i < contract->baseContracts.count; i++, baseContract = baseContract->next) {
        pushInheritanceSpecifier(s, &baseContract->node);
    }

    pushU32(s, contract->elements.count);
    ASTNodeLink *element = contract->elements.head;
    for(u32 i = 0; i < contract->elements.count; i++, element = element->next) {
        pushASTNode(s, &element->node);
    }
}

static void
pushConstructorDefinition(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);

    ASTNodeConstructorDefinition *constructor = &node->constructorDefinitionNode;

    pushParameters(s, &constructor->parameters);
    pushU16(s, constructor->visibility);
    pushU16(s, constructor->stateMutability);

    pushU32(s, constructor->modifiers.count);
    ASTNodeLink *it = constructor->modifiers.head;
    for(u32 i = 0; i < constructor->modifiers.count; i++, it = it->next) {
        ASTNodeModifierInvocation *invocation = &it->node.modifierInvocationNode;
        pushNodeHeader(s, &it->node);
        pushType(s, invocation->identifier);
        pushCallArgumentList(s, &invocation->argumentsExpression, &invocation->argumentsName);
    }

    pushStatement(s, constructor->body);
}

static void
pushASTNode(Serializer *s, ASTNode *node) {
    switch(node->type) {
        case ASTNodeType_Pragma: {
            pushPragma(s, node);
        } break;
        case ASTNodeType_Import: {
            pushImportDirective(s, node);
        } break;
        case ASTNodeType_Using: {
            pushUsing(s, node);
        } break;
        case ASTNodeType_EnumDefinition: {
            pushEnumDefinition(s, node);
        } break;
        case ASTNodeType_Struct: {
            pushStruct(s, node);
        } break;
        case ASTNodeType_Error: {
            pushError(s, node);
        } break;
        case ASTNodeType_Event: {
            pushEvent(s, node);
        } break;
        case ASTNodeType_Typedef: {
            pushTypedef(s, node);
        } break;
        case ASTNodeType_ConstVariable: {
            pushConstVariable(s, node);
        } break;
        case ASTNodeType_StateVariableDeclaration: {
            pushStateVariableDeclaration(s, node);
        } break;
        case ASTNodeType_FallbackFunction:
        case ASTNodeType_ReceiveFunction:
        case ASTNodeType_FunctionDefinition: {
            pushFunctionDefinition(s, node);
        } break;
        case ASTNodeType_ConstructorDefinition: {
            pushConstructorDefinition(s, node);
        } break;
        case ASTNodeType_ModifierDefinition: {
            pushModifierDefinition(s, node);
        } break;
        case ASTNodeType_LibraryDefinition:
        case ASTNodeType_ContractDefinition:
        case ASTNodeType_InterfaceDefinition:
        case ASTNodeType_AbstractContractDefinition: {
            pushContractDefinition(s, node);
        } break;
        default: {
            assert(0);
        } break;
    }
};

static void
pushSourceUnit(Serializer *s, ASTNode *node) {
    pushNodeHeader(s, node);
    pushU32(s, node->children.count);

    ASTNodeLink *child = node->children.head;
    for(u32 i = 0; i < node->children.count; i++, child = child->next) {
        pushASTNode(s, &child->node);
    }
}

static String
serialize(Serializer *s, ASTNode *node, u32 inputSize) {
    u32 initialGuess = 8 * inputSize;
    pushOutputBuffer(s, initialGuess);

    pushSourceUnit(s, node);

    return mergeOutputBuffers(s);
}

