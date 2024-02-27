const ASTNodeType_SourceUnit = 1
const ASTNodeType_Import = 2
const ASTNodeType_EnumDefinition = 3
const ASTNodeType_StructDefinition = 4
const ASTNodeType_BaseType = 5
const ASTNodeType_FunctionType = 6
const ASTNodeType_MappingType = 7
const ASTNodeType_IdentifierPath = 8
const ASTNodeType_ArrayType = 9
const ASTNodeType_Error = 10
const ASTNodeType_Event = 11
const ASTNodeType_Typedef = 12
const ASTNodeType_ConstVariable = 13
const ASTNodeType_NumberLitExpression = 14
const ASTNodeType_StringLitExpression = 15
const ASTNodeType_BoolLitExpression = 16
const ASTNodeType_LiteralExpression = 17
const ASTNodeType_BinaryExpression = 18
const ASTNodeType_TupleExpression = 19
const ASTNodeType_UnaryExpression = 20
const ASTNodeType_FunctionCallExpression = 21
const ASTNodeType_MemberAccessExpression = 22
const ASTNodeType_ArrayAccessExpression = 23
const ASTNodeType_FunctionDefinition = 24
const ASTNodeType_BlockStatement = 25
const ASTNodeType_ReturnStatement = 26
const ASTNodeType_ExpressionStatement = 27
const ASTNodeType_IfStatement = 28
const ASTNodeType_VariableDeclarationStatement = 29
const ASTNodeType_VariableDeclaration = 30
const ASTNodeType_NewExpression = 31

function stringToStringLiteral(str) {
    if(str === null) {
        return null
    }

    return {
        type: "StringLiteral",
        value: str,
        parts: [str],
        isUnicode: [false]
    }
}

function stringToIdentifier(str) {
    if(str === null) {
        return null
    }

    return {
        type: "Identifier",
        name: str,
    }
}

function stringToEnumValue(str) {
    if(str === null) {
        return null
    }

    return {
        type: "EnumValue",
        name: str,
    }
}

class Deserializer {
    constructor(inputString, dataView) {
        this.inputString = inputString;
        this.dataView = dataView;
        this.offset = 0;

        this.operatorStrings = {
            66: "!",
            67: "+",
            68: "-",
            69: "%",
            70: "/",
            71: "*",
            72: "**",
            73: "&",
            74: "|",
            75: "^",
            76: "<<",
            77: ">>",
            78: ">>>",
            79: "~",
            80: "++",
            81: "--",
            82: "<",
            83: ">",
            84: "<=",
            85: ">=",
            86: "==",
            87: "!=",
            88: "&&",
            89: "||",
            90: "?",
            91: "=",
        }

        this.visibilityString = [
            "default",
            "internal",
            "external",
            "private",
            "public"
        ]

        this.stateMutabilityString = [
            "default",
            "pure" ,
            "view",
            "payable",
        ]

        this.storageLocationString = [
            null,
            "memory",
            "storage",
            "calldata",
        ]
    }

    popU32() {
        const value = this.dataView.getUint32(this.offset, true);
        this.offset += 4;
        return value;
    }

    popString() {
        const offset = this.popU32();
        const length = this.popU32();

        if(offset === 0xffffffff) {
            return null;
        } else {
            return this.inputString.substring(offset, offset + length);
        }
    }

    popType() {
        const kind = this.popU32();

        if(kind === ASTNodeType_BaseType) {
            const name = this.popString();
            const payable = this.popU32();
            return {
                type: "ElementaryTypeName",
                name,
                stateMutability: payable === 0 ? null : "payable"
            }
        } else if(kind === ASTNodeType_IdentifierPath) {
            const identifiersCount = this.popU32();
            let path = ""
            for(let i = 0; i < identifiersCount; i++) {
                path += this.popString();
                if(i < identifiersCount - 1) {
                    path += ".";
                }
            }
            return {
                type: "UserDefinedTypeName",
                namePath: path,
            }
        } else if(kind === ASTNodeType_MappingType) {
            const keyType = this.popType();
            const keyIdentifier = this.popString();
            const valueType = this.popType();
            const valueIdentifier = this.popString();
            return {
                type: "Mapping",
                keyType,
                keyName: stringToIdentifier(keyIdentifier),
                valueType,
                valueName: stringToIdentifier(valueIdentifier),
            }
        } else if(kind === ASTNodeType_ArrayType) {
            const baseType = this.popType();
            return {
                type: "ArrayTypeName",
                baseTypeName: baseType,
                length: null,
            }
        } else {
            throw new Error(`Unknown/Unsupported type kind: ${kind}`);
        }
    }

    popVariableDeclaration() {
        const typeName = this.popType();
        const name = this.popString();
        const dataLocation = this.popU32();

        return {
            type: "VariableDeclaration",
            typeName,
            name,
            identifier: stringToIdentifier(name),
            storageLocation: this.storageLocationString[dataLocation],
            isStateVar: false,
            isIndexed: false,
            expression: null
        }
    }

    popExpression() {
        const type = this.popU32();

        if(type === ASTNodeType_NumberLitExpression) {
            const value = this.popString();
            const subdenomination = this.popString();

            return {
                type: "NumberLiteral",
                number: value,
                subdenomination
            }
        } else if(type === ASTNodeType_StringLitExpression) {
            const value = this.popString();

            return {
                type: "StringLiteral",
                value,
                parts: [value],
                isUnicode: [false]
            }
        } else if(type === ASTNodeType_BoolLitExpression) {
            const value = this.popString();

            return {
                type: "BooleanLiteral",
                value: value === "true"
            }
        } else if(type === ASTNodeType_LiteralExpression) {
            const name = this.popString();

            return {
                type: "Identifier",
                name
            }
        } else if(type === ASTNodeType_BinaryExpression) {
            const operatorId = this.popU32();
            const lhs = this.popExpression();
            const rhs = this.popExpression();

            const operator = this.operatorStrings[operatorId];

            return {
                type: "BinaryOperation",
                operator,
                left: lhs,
                right: rhs
            }
        } else if(type === ASTNodeType_TupleExpression) {
            const elementCount = this.popU32();
            const elements = []
            for(let i = 0; i < elementCount; i++) {
                elements.push(this.popExpression());
            }

            return {
                type: "TupleExpression",
                components: elements,
                isArray: false
            }
        } else if(type === ASTNodeType_UnaryExpression) {
            const operator = this.popU32();
            const subExpression = this.popExpression();

            return {
                type: "UnaryOperation",
                operator: this.operatorStrings[operator],
                subExpression,
                isPrefix: true
            }
        } else if(type === ASTNodeType_NewExpression) {
            const typeName = this.popType();

            return {
                type: "NewExpression",
                typeName,
            }
        } else if(type === ASTNodeType_FunctionCallExpression) {
            const expression = this.popExpression();
            const argumentCount = this.popU32();
            const args = []
            for(let i = 0; i < argumentCount; i++) {
                args.push(this.popExpression());
            }

            return {
                type: "FunctionCall",
                expression,
                arguments: args,
                names: [],
                identifiers: [],
            }
        } else if(type === ASTNodeType_BaseType) {
            return this.popType()
        } else if(type === ASTNodeType_MemberAccessExpression) {
            const expression = this.popExpression();
            const memberName = this.popString();

            return {
                type: "MemberAccess",
                expression,
                memberName,
            }
        } else if(type === ASTNodeType_ArrayAccessExpression) {
            const base = this.popExpression();
            const index = this.popExpression();

            return {
                type: "IndexAccess",
                base,
                index,
            }
        } else {
            throw new Error(`Unknown/Unsupported expression type: ${type}`);
        }
    }

    popStatement() {
        const type = this.popU32();

        if(type === ASTNodeType_BlockStatement) {
            const count = this.popU32();
            const statements = []
            for(let i = 0; i < count; i++) {
                statements.push(this.popStatement())
            }
            return {
                type: "Block",
                statements,
            }
        } else if(type === ASTNodeType_ReturnStatement) {
            return {
                type: "ReturnStatement",
                expression: this.popExpression()
            }
        } else if(type === ASTNodeType_ExpressionStatement) {
            return {
                type: "ExpressionStatement",
                expression: this.popExpression()
            }
        } else if(type === ASTNodeType_IfStatement) {
            const condition = this.popExpression();
            const trueBody = this.popStatement();
            const hasFalse = this.popU32();
            let falseBody = null
            if(hasFalse) {
                falseBody = this.popStatement();
            }
            return {
                type: "IfStatement",
                condition,
                trueBody,
                falseBody,
            }
        } else if(type === ASTNodeType_VariableDeclarationStatement) {
            const variable = this.popVariableDeclaration();
            const noInitialValue = this.popU32();
            let initialValue = null;
            if(noInitialValue === 0) {
                initialValue = this.popExpression();
            }

            return {
                type: "VariableDeclarationStatement",
                variables: [variable],
                initialValue,
            }
        } else {
            throw new Error(`Unknown/Unsupported type: ${type}`);
        }
    }

    popImport() {
        const path = this.popString();
        const unitAlias = this.popString();
        const symbolsCount = this.popU32();

        let aliases = [];
        let aliasesIdentifiers = [];

        if(symbolsCount === 0) {
            aliases = null;
            aliasesIdentifiers = null;
        }

        for (let i = 0; i < symbolsCount; i++) {
            const symbol = this.popString();
            const alias = this.popString();
            aliases.push([symbol, alias]);
            aliasesIdentifiers.push([ stringToIdentifier(symbol), stringToIdentifier(alias) ]);
        }

        return {
            type: "ImportDirective",
            path,
            pathLiteral: stringToStringLiteral(path),
            unitAlias,
            unitAliasIdentifier: stringToIdentifier(unitAlias),
            symbolAliases: aliases,
            symbolAliasesIdentifiers: aliasesIdentifiers
        }
    }

    popEnumDefinition() {
        const name = this.popString();

        const membersCount = this.popU32();
        const members = []
        for(let i = 0; i < membersCount; i++) {
            members.push(stringToEnumValue(this.popString()));
        }

        return {
            type: "EnumDefinition",
            name,
            members,
        }
    }

    popStructDefinition() {
        const name = this.popString();
        const membersCount = this.popU32();
        const members = []
        for(let i = 0; i < membersCount; i++) {
            const typeName = this.popType();
            const memberName = this.popString();
            members.push({
                type: "VariableDeclaration",
                typeName,
                name: memberName,
                identifier: stringToIdentifier(memberName),
                storageLocation: null,
                isStateVar: false,
                isIndexed: false,
                expression: null,
            });
        }

        return {
            type: "StructDefinition",
            name,
            members,
        }
    }

    popFunctionParameters() {
        const paramCount = this.popU32();
        if(paramCount === 0) {
            return null
        }
        const params = []
        for(let i = 0; i < paramCount; i++) {
            const typeName = this.popType();
            const paramName = this.popString();
            const dataLocation = this.popU32();
            params.push({
                        type: "VariableDeclaration",
                        typeName,
                        name: paramName,
                        identifier: stringToIdentifier(paramName),
                        storageLocation: this.storageLocationString[dataLocation],
                        isStateVar: false,
                        isIndexed: false,
                        expression: null
            });
        }
        return params;
    }

    popError() {
        const name = this.popString();
        const paramCount = this.popU32();
        const params = []
        for(let i = 0; i < paramCount; i++) {
            const typeName = this.popType();
            const paramName = this.popString();
            const dataLocation = this.popU32();
            params.push({
                        type: "VariableDeclaration",
                        typeName,
                        name: paramName,
                        identifier: stringToIdentifier(paramName),
                        storageLocation: this.storageLocationString[dataLocation],
                        isStateVar: false,
                        isIndexed: false,
                        expression: null
            });
        }

        return {
            type: "CustomErrorDefinition",
            name,
            parameters: params
        }
    }

    popEvent() {
        const name = this.popString();
        const isAnonymous = this.popU32() === 1;
        const paramCount = this.popU32();
        const params = []
        for(let i = 0; i < paramCount; i++) {
            const typeName = this.popType();
            const paramName = this.popString();
            const indexed = this.popU32();
            params.push({
                        type: "VariableDeclaration",
                        typeName,
                        name: paramName,
                        identifier: stringToIdentifier(paramName),
                        isStateVar: false,
                        isIndexed: indexed === 1,
                        storageLocation: null,
                        expression: null
            });
        }


        return {
            type: "EventDefinition",
            name,
            parameters: params,
            isAnonymous
        }

    }

    popTypedef() {
        const name = this.popString();
        const type = this.popType();

        return {
            type: "TypeDefinition",
            name,
            definition: type
        }
    }

    popConstVariable() {
        const name = this.popString();
        const typeName = this.popType();
        const initialValue = this.popExpression();

        return {
            type: "FileLevelConstant",
            typeName,
            name,
            initialValue,
            isDeclaredConst: true,
            isImmutable: false,
        }
    }

    popFunctionDefinition() {
        const name = this.popString();
        const parameters = this.popFunctionParameters();
        const visibility = this.popU32();
        const stateMutability = this.popU32();
        const returnParameters = this.popFunctionParameters();
        const body = this.popStatement();

        return {
            type: "FunctionDefinition",
            name,
            parameters,
            returnParameters,
            body,
            visibility: this.visibilityString[visibility],
            modifiers: [],
            override: null,
            isConstructor: false,
            isReceiveEther: false,
            isFallback: false,
            isVirtual: false,
            stateMutability: this.stateMutabilityString[stateMutability]
        }
    }

    popASTNode() {
        const type = this.popU32();

        if(type === ASTNodeType_SourceUnit) {
            return this.popSourceUnit();
        } else if(type === ASTNodeType_Import) {
            return this.popImport();
        } else if(type === ASTNodeType_EnumDefinition) {
            return this.popEnumDefinition();
        } else if(type === ASTNodeType_StructDefinition) {
            return this.popStructDefinition();
        } else if(type === ASTNodeType_Error) {
            return this.popError();
        } else if(type === ASTNodeType_Event) {
            return this.popEvent();
        } else if(type === ASTNodeType_Typedef) {
            return this.popTypedef();
        } else if(type === ASTNodeType_ConstVariable) {
            return this.popConstVariable();
        } else if(type === ASTNodeType_FunctionDefinition) {
            return this.popFunctionDefinition();
        }
        
    }

    popSourceUnit() {
        const type = this.popU32();
        if(type !== ASTNodeType_SourceUnit) {
            throw new Error("Invalid SourceUnit type");
        }

        const childrenCount = this.popU32();
        const children = new Array(childrenCount);

        for(let i = 0; i < childrenCount; i++) {
            children[i] = this.popASTNode();
        }

        return {
            type: "SourceUnit",
            children
        }
    }
}

module.exports = Deserializer;
