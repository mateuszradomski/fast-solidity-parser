typedef struct Serializer {
    Arena *arena;
    TokenizeResult tokens;
    const u8 *inputStringBase;
    char **head;
} Serializer;

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
pushU32(Serializer *s, u32 value) {
    if(s->head) {
        u32 *ptr = (u32 *)*s->head;
        *ptr = value;
        *s->head += sizeof(u32);
    }

    return sizeof(u32);
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

static u32
pushType(Serializer *s, ASTNode node) {
    u32 l = 0;

    switch(node.type) {
        case ASTNodeType_BaseType: {
            l += pushU32(s, node.type);
            l += pushTokenStringById(s, node.baseTypeNode.typeName);
            l += pushU32(s, node.baseTypeNode.payable);
        } break;
        case ASTNodeType_IdentifierPath: {
            l += pushU32(s, node.type);
            l += pushU32(s, node.identifierPathNode.identifiers.count);
            for(u32 i = 0; i < node.identifierPathNode.identifiers.count; i++) {
                TokenId part = listGetTokenId(&node.identifierPathNode.identifiers, i);
                l += pushTokenStringById(s, part);
            }
        } break;
        case ASTNodeType_MappingType: {
            l += pushU32(s, node.type);
            l += pushType(s, *node.mappingNode.keyType);
            l += pushTokenStringById(s, node.mappingNode.keyIdentifier);
            l += pushType(s, *node.mappingNode.valueType);
            l += pushTokenStringById(s, node.mappingNode.valueIdentifier);
        } break;
        case ASTNodeType_ArrayType: {
            l += pushU32(s, node.type);
            l += pushType(s, *node.arrayTypeNode.elementType);
        } break;
        default: {
            assert(0);
        }
    }

    return l;
}

static u32
pushImportDirective(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    l += pushTokenStringById(s, node.pathTokenId);
    l += pushTokenStringById(s, node.unitAliasTokenId);

    l += pushU32(s, node.symbols.count);
    for(u32 i = 0; i < node.symbols.count; i++) {
        // PERF-NOTE(radomski): we could pull out pushing a token string just
        // by itself since we know that the token here is never going to be
        // invalid. But in pushTokenStringById we have to check for invalid
        // which is additional overhead.

        TokenId symbol = listGetTokenId(&node.symbols, i);
        TokenId alias = listGetTokenId(&node.symbolAliases, i);
        l += pushTokenStringById(s, symbol);
        l += pushTokenStringById(s, alias);
    }

    return l;
}

static u32
pushEnumDefinition(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    l += pushTokenStringById(s, node.nameTokenId);

    l += pushU32(s, node.values.count);
    for(u32 i = 0; i < node.values.count; i++) {
        TokenId value = listGetTokenId(&node.values, i);
        l += pushTokenStringById(s, value);
    }

    return l;
}

static u32
pushStruct(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    l += pushTokenStringById(s, node.structNode.nameTokenId);

    assert(node.structNode.memberTypes.count == node.structNode.memberNames.count);
    l += pushU32(s, node.structNode.memberTypes.count);

    ASTNodeLink *typeLink = node.structNode.memberTypes.head;
    for(u32 i = 0; i < node.structNode.memberTypes.count; i++, typeLink = typeLink->next) {
        TokenId name = listGetTokenId(&node.structNode.memberNames, i);
        l += pushType(s, typeLink->node);
        l += pushTokenStringById(s, name);
    }

    return l;
}

static u32
pushError(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    ASTNodeError *error = &node.errorNode;
    l += pushTokenStringById(s, error->identifier);

    FunctionParameter *param = error->parameters.head;
    l += pushU32(s, error->parameters.count);
    for(u32 i = 0; i < error->parameters.count; i++, param = param->next) {
        l += pushType(s, *param->type);
        l += pushTokenStringById(s, param->identifier);
    }

    return l;
}

static u32
pushEvent(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    ASTNodeEvent *event = &node.eventNode;
    l += pushTokenStringById(s, event->identifier);
    l += pushU32(s, event->anonymous);

    FunctionParameter *param = event->parameters.head;
    l += pushU32(s, node.eventNode.parameters.count);
    for(u32 i = 0; i < event->parameters.count; i++, param = param->next) {
        l += pushType(s, *param->type);
        l += pushTokenStringById(s, param->identifier);
        l += pushU32(s, param->dataLocation);
    }

    return l;
}

static u32
pushASTNode(Serializer *s, ASTNode node) {
    u32 l = 0;

    switch(node.type) {
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
        default: {
            assert(0);
        } break;
    }

    return l;
};

static u32
pushSourceUnit(Serializer *s, ASTNode node) {
    u32 l = 0;

    l += pushU32(s, node.type);
    l += pushU32(s, node.children.count);

    ASTNodeLink *child = node.children.head;
    for(u32 i = 0; i < node.children.count; i++, child = child->next) {
        l += pushASTNode(s, child->node);
    }

    return l;
}

static u32
calculateResultingSize(Serializer *s, ASTNode node) {
    assert(s->head == 0x0);
    u32 result = pushSourceUnit(s, node);
    return result;
}

static String
astNodeToBinary(Serializer *s, ASTNode node) {
    u32 size = calculateResultingSize(s, node);
    u8 *data = arrayPush(s->arena, u8, size);
    String result = { .data = data, .size = size };
    s->head = (char **)&data;

    pushSourceUnit(s, node);

    return result;
}

