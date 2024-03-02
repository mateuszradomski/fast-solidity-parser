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
const ASTNodeType_VariableDeclarationTupleStatement = 32
const ASTNodeType_WhileStatement = 33
const ASTNodeType_ContractDefinition = 34
const ASTNodeType_RevertStatement = 35
const ASTNodeType_StateVariableDeclaration = 36
const ASTNodeType_LibraryDefinition = 37
const ASTNodeType_TerneryExpression = 38
const ASTNodeType_ForStatement = 39
const ASTNodeType_BreakStatement = 40
const ASTNodeType_ContinueStatement = 41
const ASTNodeType_UnaryExpressionPostfix = 42
const ASTNodeType_HexStringLitExpression = 43
const ASTNodeType_ArraySliceExpression = 44
const ASTNodeType_UncheckedBlockStatement = 45
const ASTNodeType_ModifierDefinition = 46
const ASTNodeType_FallbackFunction = 47
const ASTNodeType_ReceiveFunction = 48
const ASTNodeType_EmitStatement = 49
const ASTNodeType_ConstructorDefinition = 50
const ASTNodeType_NamedParametersExpression = 51
const ASTNodeType_InterfaceDefinition = 52
const ASTNodeType_AbstractContractDefinition = 53
const ASTNodeType_InheritanceSpecifier = 54

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
            39: "delete",
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
            92: "|=",
            93: "^=",
            94: "&=",
            95: "<<=",
            96: ">>=",
            97: "+=",
            98: "-=",
            99: "*=",
            100: "/=",
            101: "%=",
        }

        this.visibilityString = [
            "default",
            "internal",
            "external",
            "private",
            "public"
        ]

        this.variableVisibilityString = [
            "default",
            "public",
            "private",
            "internal",
            "constant",
            "immutable"
        ]

        this.stateMutabilityString = [
            null,
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

    popU16() {
        const value = this.dataView.getUint16(this.offset, true);
        this.offset += 2;
        return value;
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
            const hasLengthExpression = this.popU32();
            let length = null
            if(hasLengthExpression === 1) {
                length = this.popExpression();
            }

            return {
                type: "ArrayTypeName",
                baseTypeName: baseType,
                length,
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

    popVariableDeclarationTupleStatementOrder() {
        const typeName = this.popType();
        const name = this.popString();
        const dataLocation = this.popU32();

        return {
            type: "VariableDeclaration",
            name,
            identifier: stringToIdentifier(name),
            typeName,
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
            const count = this.popU32();
            const parts = []
            const isUnicode = []
            for(let i = 0; i < count; i++) {
                parts.push(this.popString());
                isUnicode.push(false)
            }

            return {
                type: "StringLiteral",
                value: parts.join(""),
                parts,
                isUnicode
            }
        } else if(type === ASTNodeType_HexStringLitExpression) {
            const count = this.popU32();
            const parts = []
            for(let i = 0; i < count; i++) {
                parts.push(this.popString());
            }

            return {
                type: "HexLiteral",
                value: parts.join(""),
                parts,
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
        } else if(type === ASTNodeType_UnaryExpression || type === ASTNodeType_UnaryExpressionPostfix) {
            const operator = this.popU32();
            const subExpression = this.popExpression();

            return {
                type: "UnaryOperation",
                operator: this.operatorStrings[operator],
                subExpression,
                isPrefix: type !== ASTNodeType_UnaryExpressionPostfix
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
            const hasIndexExpression = this.popU32();
            let index = null
            
            if(hasIndexExpression == 1) {
                index = this.popExpression();
            }

            return {
                type: "IndexAccess",
                base,
                index,
            }
        } else if(type === ASTNodeType_ArraySliceExpression) {
            const base = this.popExpression();

            const result =  {
                type: "IndexRangeAccess",
                base,
            }

            const hasIndexStart = this.popU32();
            if(hasIndexStart == 1) {
                result.indexStart = this.popExpression();
            }

            const hasIndexEnd = this.popU32();
            if(hasIndexEnd == 1) {
                result.indexEnd = this.popExpression();
            }

            return result;
        } else if(type === ASTNodeType_TerneryExpression) {
            const condition = this.popExpression();
            const trueExpression = this.popExpression();
            const falseExpression = this.popExpression();

            return {
                type: "Conditional",
                condition,
                trueExpression,
                falseExpression,
            }
        } else if(type === ASTNodeType_NamedParametersExpression) {
            const expression = this.popExpression();
            const count = this.popU32();

            const names = []
            const identifiers = []
            const parameters = []
            for(let i = 0; i < count; i++) {
                const name = this.popString()
                names.push(name);
                identifiers.push(stringToIdentifier(name))
                parameters.push(this.popExpression());
            }

            return {
                type: "NameValueExpression",
                expression,
                arguments: {
                    type: "NameValueList",
                    names,
                    identifiers,
                    arguments: parameters,
                }
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
        } else if(type === ASTNodeType_UncheckedBlockStatement) {
            const block = this.popStatement();
            return {
                type: "UncheckedStatement",
                block,
            }
        } else if(type === ASTNodeType_ReturnStatement) {
            return {
                type: "ReturnStatement",
                expression: this.popExpression()
            }
        } else if(type === ASTNodeType_ExpressionStatement) {
            const hasExpression = this.popU16() == 1;
            const expression = hasExpression ? this.popExpression() : null;
            return {
                type: "ExpressionStatement",
                expression
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
        } else if(type === ASTNodeType_VariableDeclarationTupleStatement) {
            const count = this.popU32();

            const array = []
            for (let i = 0; i < count; i++) {
                const hasDeclaration = this.popU32();
                if(hasDeclaration === 1) {
                    const decl = this.popVariableDeclarationTupleStatementOrder();
                    array.push(decl)
                } else {
                    array.push(null)
                }
            }

            const initialValue = this.popExpression();

            return {
                type: "VariableDeclarationStatement",
                variables: array,
                initialValue
            }
        } else if(type === ASTNodeType_WhileStatement) {
            const condition = this.popExpression();
            const body = this.popStatement();

            return {
                type: "WhileStatement",
                condition,
                body
            }
        } else if(type === ASTNodeType_ForStatement) {
            const hasInit = this.popU16() == 1;
            const initExpression = hasInit ? this.popStatement() : null;
            const hasCondition = this.popU16() == 1;
            const conditionExpression = hasCondition ? this.popExpression() : null;
            const loopExpression = this.popStatement()
            const body = this.popStatement();

            return {
                type: "ForStatement",
                initExpression,
                conditionExpression,
                loopExpression,
                body
            }
        } else if(type === ASTNodeType_BreakStatement) {
            return { type: "BreakStatement" }
        } else if(type === ASTNodeType_ContinueStatement) {
            return { type: "ContinueStatement" }
        } else if(type === ASTNodeType_RevertStatement) {
            const revertCall = this.popExpression();

            return {
                type: "RevertStatement",
                revertCall,
            }
        } else if(type === ASTNodeType_EmitStatement) {
            const eventCall = this.popExpression();

            return {
                type: "EmitStatement",
                eventCall,
            }
        } else {
            throw new Error("Unknown/Unsupported statement kind " + type)
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
        if(paramCount === 0xffffffff) {
            return null
        }
        if(paramCount === 0) {
            return []
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

    popStateVariableDeclaration() {
        const name = this.popString();
        const typeName = this.popType();
        const visibility = this.popU16();
        const mutability = this.popU16();
        const hasExpression = this.popU32();

        let expression = null
        if(hasExpression === 1) {
            expression = this.popExpression();
        }

        return {
            type: "StateVariableDeclaration",
            variables: [
                {
                    type: "VariableDeclaration",
                    typeName,
                    name,
                    identifier: stringToIdentifier(name),
                    expression,
                    visibility: this.variableVisibilityString[visibility],
                    isStateVar: true,
                    isDeclaredConst: mutability === 1,
                    isIndexed: false,
                    isImmutable: mutability === 2,
                    override: null,
                    storageLocation: null,
                }
            ],
            initialValue: expression
        }
    }

    popFunctionDefinition() {
        const name = this.popString();
        const parameters = this.popFunctionParameters();
        const visibility = this.popU16();
        const stateMutability = this.popU16();
        const isVirtual = this.popU16();
        const isOverride = this.popU16();
        let override = null 
        if(isOverride === 1) {
            override = []
            const count = this.popU32();
            for(let i = 0; i < count; i++) {
                override.push(this.popType());
            }
        }


        const returnParameters = this.popFunctionParameters();
        const hasBody = this.popU32();

        let body = null;
        if(hasBody) {
            body = this.popStatement();
        }

        return {
            type: "FunctionDefinition",
            name,
            parameters,
            returnParameters,
            body,
            visibility: this.visibilityString[visibility],
            modifiers: [],
            override,
            isConstructor: false,
            isReceiveEther: false,
            isFallback: false,
            isVirtual: isVirtual == 1,
            stateMutability: this.stateMutabilityString[stateMutability]
        }
    }

    popModifierDefinition() {
        const name = this.popString();
        const parameters = this.popFunctionParameters();
        const isVirtual = this.popU16();
        const isOverride = this.popU16();
        let override = null 
        if(isOverride === 1) {
            override = []
            const count = this.popU32();
            for(let i = 0; i < count; i++) {
                override.push(this.popType());
            }
        }

        const hasBody = this.popU32();
        let body = null;
        if(hasBody) {
            body = this.popStatement();
        }

        return {
            type: "ModifierDefinition",
            name,
            parameters,
            body,
            isVirtual: isVirtual == 1,
            override,
        }
    }

    popInheritanceSpecifier() {
        const identifier = this.popType();

        const argCount = this.popU32();
        const args = []
        for(let k = 0; k < argCount; k++) {
            args.push(this.popExpression());
        }

        return {
            type: "InheritanceSpecifier",
            baseName: identifier,
            arguments: args,
        };
    }

    popContractDefinition() {
        const name = this.popString();
        const baseContractCount = this.popU32();
        const baseContracts = []

        for(let i = 0; i < baseContractCount; i++) {
            baseContracts.push(this.popASTNode());
        }

        const subNodeCount = this.popU32();
        const subNodes = []

        for(let i = 0; i < subNodeCount; i++) {
            subNodes.push(this.popASTNode());
        }

        return {
            type: "ContractDefinition",
            name,
            baseContracts,
            subNodes,
            kind: "contract"
        }
    }

    popConstructorDefinition() {
        const parameters = this.popFunctionParameters();
        const visibility = this.popU16();
        const stateMutability = this.popU16();
        const body = this.popStatement();

        return {
            type: "FunctionDefinition",
            name: null,
            parameters,
            returnParameters: null,
            body,
            visibility: this.visibilityString[visibility],
            modifiers: [],
            override: null,
            isConstructor: true,
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
        } else if(type === ASTNodeType_StateVariableDeclaration) {
            return this.popStateVariableDeclaration();
        } else if(type === ASTNodeType_FunctionDefinition) {
            return this.popFunctionDefinition();
        } else if(type === ASTNodeType_FallbackFunction) {
            const result = this.popFunctionDefinition();
            result.name = null
            result.isFallback = true;

            return result
        } else if(type === ASTNodeType_ReceiveFunction) {
            const result = this.popFunctionDefinition();
            result.name = null
            result.isReceiveEther = true;
            return result
        } else if(type === ASTNodeType_ModifierDefinition) {
            return this.popModifierDefinition();
        } else if(type === ASTNodeType_ContractDefinition) {
            return this.popContractDefinition();
        } else if(type === ASTNodeType_LibraryDefinition) {
            const result = this.popContractDefinition();
            result.kind = "library"
            return result
        } else if(type === ASTNodeType_InterfaceDefinition) {
            const result = this.popContractDefinition();
            result.kind = "interface"
            return result
        } else if(type === ASTNodeType_AbstractContractDefinition) {
            const result = this.popContractDefinition();
            result.kind = "abstract"
            return result
        } else if(type === ASTNodeType_ConstructorDefinition) {
            return this.popConstructorDefinition();
        } else if(type === ASTNodeType_InheritanceSpecifier) {
            return this.popInheritanceSpecifier();
        } else {
            throw new Error(`Unknown/Unsupported ASTNode kind: ${type}`);
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
