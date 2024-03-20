const ASTNodeType_SourceUnit = 1;
const ASTNodeType_Import = 2;
const ASTNodeType_EnumDefinition = 3;
const ASTNodeType_StructDefinition = 4;
const ASTNodeType_BaseType = 5;
const ASTNodeType_FunctionType = 6;
const ASTNodeType_MappingType = 7;
const ASTNodeType_IdentifierPath = 8;
const ASTNodeType_ArrayType = 9;
const ASTNodeType_Error = 10;
const ASTNodeType_Event = 11;
const ASTNodeType_Typedef = 12;
const ASTNodeType_ConstVariable = 13;
const ASTNodeType_NumberLitExpression = 14;
const ASTNodeType_StringLitExpression = 15;
const ASTNodeType_BoolLitExpression = 16;
const ASTNodeType_LiteralExpression = 17;
const ASTNodeType_BinaryExpression = 18;
const ASTNodeType_TupleExpression = 19;
const ASTNodeType_UnaryExpression = 20;
const ASTNodeType_FunctionCallExpression = 21;
const ASTNodeType_MemberAccessExpression = 22;
const ASTNodeType_ArrayAccessExpression = 23;
const ASTNodeType_FunctionDefinition = 24;
const ASTNodeType_BlockStatement = 25;
const ASTNodeType_ReturnStatement = 26;
const ASTNodeType_ExpressionStatement = 27;
const ASTNodeType_IfStatement = 28;
const ASTNodeType_VariableDeclarationStatement = 29;
const ASTNodeType_VariableDeclaration = 30;
const ASTNodeType_NewExpression = 31;
const ASTNodeType_VariableDeclarationTupleStatement = 32;
const ASTNodeType_WhileStatement = 33;
const ASTNodeType_ContractDefinition = 34;
const ASTNodeType_RevertStatement = 35;
const ASTNodeType_StateVariableDeclaration = 36;
const ASTNodeType_LibraryDefinition = 37;
const ASTNodeType_TerneryExpression = 38;
const ASTNodeType_ForStatement = 39;
const ASTNodeType_BreakStatement = 40;
const ASTNodeType_ContinueStatement = 41;
const ASTNodeType_UnaryExpressionPostfix = 42;
const ASTNodeType_HexStringLitExpression = 43;
const ASTNodeType_ArraySliceExpression = 44;
const ASTNodeType_UncheckedBlockStatement = 45;
const ASTNodeType_ModifierDefinition = 46;
const ASTNodeType_FallbackFunction = 47;
const ASTNodeType_ReceiveFunction = 48;
const ASTNodeType_EmitStatement = 49;
const ASTNodeType_ConstructorDefinition = 50;
const ASTNodeType_NamedParametersExpression = 51;
const ASTNodeType_InterfaceDefinition = 52;
const ASTNodeType_AbstractContractDefinition = 53;
const ASTNodeType_InheritanceSpecifier = 54;
const ASTNodeType_NameValue = 55;
const ASTNodeType_Pragma = 56;
const ASTNodeType_ModifierInvocation = 57;
const ASTNodeType_Using = 58;
const ASTNodeType_UnicodeStringLitExpression = 59;
const ASTNodeType_InlineArrayExpression = 60;
const ASTNodeType_DoWhileStatement = 61;
const ASTNodeType_TryStatement = 62;
const ASTNodeType_AssemblyStatement = 64;
const ASTNodeType_YulBlockStatement = 65;
const ASTNodeType_YulVariableDeclaration = 66;
const ASTNodeType_YulNumberLitExpression = 67;
const ASTNodeType_YulStringLitExpression = 68;
const ASTNodeType_YulHexNumberLitExpression = 69;
const ASTNodeType_YulBoolLitExpression = 70;
const ASTNodeType_YulHexStringLitExpression = 71;
const ASTNodeType_YulMemberAccessExpression = 72;
const ASTNodeType_YulFunctionCallExpression = 73;
const ASTNodeType_YulVariableAssignment = 74;
const ASTNodeType_YulIfStatement = 75;
const ASTNodeType_YulForStatement = 76;
const ASTNodeType_YulLeaveStatement = 77;
const ASTNodeType_YulBreakStatement = 78;
const ASTNodeType_YulContinueStatement = 79;
const ASTNodeType_YulFunctionDefinition = 80;
const ASTNodeType_YulSwitchStatement = 81;

class Deserializer {
	constructor(inputString, dataView, options) {
		this.inputString = inputString;
		this.dataView = dataView;
		this.offset = 0;
		this.includeByteRange = options && options.range === true;

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
		};

		this.visibilityString = [
			"default",
			"internal",
			"external",
			"private",
			"public",
		];

		this.variableVisibilityString = [
			"default",
			"public",
			"private",
			"internal",
			"constant",
			"immutable",
		];

		this.contractKindMap = {
			[ASTNodeType_ContractDefinition]: "contract",
			[ASTNodeType_LibraryDefinition]: "library",
			[ASTNodeType_InterfaceDefinition]: "interface",
			[ASTNodeType_AbstractContractDefinition]: "abstract",
		};

		this.stateMutabilityString = [null, "pure", "view", "payable"];

		this.storageLocationString = [null, "memory", "storage", "calldata", null];
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

		if (offset === 0xffffffff) {
			return null;
		} else {
			return this.inputString.substring(offset, offset + length);
		}
	}

    popStringIdentifier() {
		const offset = this.popU32();
		const length = this.popU32();

		if (offset === 0xffffffff) {
			return null;
		} else {
			return {
                type: "Identifier",
                name: this.inputString.substring(offset, offset + length),
                range: this.includeByteRange ? [offset, offset + length - 1] : undefined,
            }
		}
    }

    popStringEnumValue() {
		const offset = this.popU32();
		const length = this.popU32();

		if (offset === 0xffffffff) {
			return null;
		} else {
			return {
                type: "EnumValue",
                name: this.inputString.substring(offset, offset + length),
                range: this.includeByteRange ? [offset, offset + length - 1] : undefined,
            }
		}
    }


    popStringLiteral() {
        const offset = this.popU32();
        const length = this.popU32();
        const str = this.inputString.substring(offset, offset + length);

        return {
            type: "StringLiteral",
            value: str,
            parts: [str],
            isUnicode: [false],
            range: this.includeByteRange ? [offset - 1, offset + length] : undefined,
        };
    }

	popType() {
		const kind = this.popU32();
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		if (kind === ASTNodeType_BaseType) {
			const name = this.popString();
			const payable = this.popU32();
			return {
				type: "ElementaryTypeName",
				name,
				stateMutability: payable === 0 ? null : "payable",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_IdentifierPath) {
			const identifiersCount = this.popU32();
			let path = "";
			for (let i = 0; i < identifiersCount; i++) {
				path += this.popString();
				if (i < identifiersCount - 1) {
					path += ".";
				}
			}
			return {
				type: "UserDefinedTypeName",
				namePath: path,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_MappingType) {
			const keyType = this.popType();
			const keyName = this.popStringIdentifier();
			const valueType = this.popType();
			const valueName = this.popStringIdentifier();
			return {
				type: "Mapping",
				keyType,
				keyName,
				valueType,
				valueName,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_FunctionType) {
			const parameterTypes = this.popFunctionParameters();
			const returnTypes = this.popFunctionParameters();
			const visibility = this.popU16();
			const stateMutability = this.popU16();

			return {
				type: "FunctionTypeName",
				parameterTypes,
				returnTypes,
				visibility: this.visibilityString[visibility],
				stateMutability: this.stateMutabilityString[stateMutability],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ArrayType) {
			const baseType = this.popType();
			const hasLengthExpression = this.popU32();
			let length = null;
			if (hasLengthExpression === 1) {
				length = this.popExpression();
			}

			return {
				type: "ArrayTypeName",
				baseTypeName: baseType,
				length,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else {
			throw new Error(`Unknown/Unsupported type kind: ${kind}`);
		}
	}

	popVariableDeclaration() {
		this.popU32(); // Discard kind
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		const typeName = this.popType();
        const identifier = this.popStringIdentifier();
		const dataLocation = this.popU32();

		return {
			type: "VariableDeclaration",
			typeName,
			name: identifier?.name ?? null,
			identifier,
			storageLocation: this.storageLocationString[dataLocation],
			isStateVar: false,
			isIndexed: dataLocation === 4,
			expression: null,
			range: this.includeByteRange ? [startOffset, endOffset] : undefined,
		};
	}

	popVariableDeclarationEventOrder() {
		this.popU32(); // Discard kind
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		const typeName = this.popType();
        const identifier = this.popStringIdentifier();
		const dataLocation = this.popU32();

		return {
			type: "VariableDeclaration",
			typeName,
			name: identifier?.name ?? null,
			identifier,
			isStateVar: false,
			isIndexed: dataLocation === 4,
			storageLocation: this.storageLocationString[dataLocation],
			expression: null,
			range: this.includeByteRange ? [startOffset, endOffset] : undefined,
		};
	}

	popVariableDeclarationTupleStatementOrder() {
		this.popU32(); // Discard kind
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		const typeName = this.popType();
        const identifier = this.popStringIdentifier();
		const dataLocation = this.popU32();

		return {
			type: "VariableDeclaration",
			name: identifier.name,
			identifier,
			typeName,
			storageLocation: this.storageLocationString[dataLocation],
			isStateVar: false,
			isIndexed: false,
			expression: null,
			range: this.includeByteRange ? [startOffset, endOffset] : undefined,
		};
	}

	popCallArgumentList() {
		const argumentCount = this.popU32();

		if (argumentCount === 0xffffffff) {
			return [null, null];
		}

		const args = [];
		for (let i = 0; i < argumentCount; i++) {
			args.push(this.popExpression());
		}

		const identifierCount = this.popU32();
		const identifier = [];
		for (let i = 0; i < identifierCount; i++) {
			identifier.push(this.popStringIdentifier());
		}

		return [args, identifier];
	}

	popExpression() {
		const kind = this.popU32();
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		if (kind === ASTNodeType_NumberLitExpression) {
			const value = this.popString();
			const subdenomination = this.popString();

			return {
				type: "NumberLiteral",
				number: value,
				subdenomination,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_StringLitExpression) {
			const count = this.popU32();
			const parts = [];
			const isUnicode = [];
			for (let i = 0; i < count; i++) {
				parts.push(this.popString());
				isUnicode.push(false);
			}

			return {
				type: "StringLiteral",
				value: parts.join(""),
				parts,
				isUnicode,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_HexStringLitExpression) {
			const count = this.popU32();
			const parts = [];
			for (let i = 0; i < count; i++) {
				parts.push(this.popString());
			}

			return {
				type: "HexLiteral",
				value: parts.join(""),
				parts,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_UnicodeStringLitExpression) {
			const count = this.popU32();
			const parts = [];
			const isUnicode = [];
			for (let i = 0; i < count; i++) {
				parts.push(this.popString());
				isUnicode.push(true);
			}

			return {
				type: "StringLiteral",
				value: parts.join(""),
				parts,
				isUnicode,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_BoolLitExpression) {
			const value = this.popString();

			return {
				type: "BooleanLiteral",
				value: value === "true",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_LiteralExpression) {
			const name = this.popString();

			return {
				type: "Identifier",
				name,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_BinaryExpression) {
			const operatorId = this.popU32();
			const lhs = this.popExpression();
			const rhs = this.popExpression();

			const operator = this.operatorStrings[operatorId];

			return {
				type: "BinaryOperation",
				operator,
				left: lhs,
				right: rhs,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_TupleExpression) {
			const elementCount = this.popU32();
			const elements = [];
			for (let i = 0; i < elementCount; i++) {
				const hasElement = this.popU16();
				if (hasElement === 1) {
					elements.push(this.popExpression());
				} else {
					elements.push(null);
				}
			}

			return {
				type: "TupleExpression",
				components: elements,
				isArray: false,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (
			kind === ASTNodeType_UnaryExpression ||
			kind === ASTNodeType_UnaryExpressionPostfix
		) {
			const operator = this.popU32();
			const subExpression = this.popExpression();

			return {
				type: "UnaryOperation",
				operator: this.operatorStrings[operator],
				subExpression,
				isPrefix: kind !== ASTNodeType_UnaryExpressionPostfix,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_NewExpression) {
			const typeName = this.popType();

			return {
				type: "NewExpression",
				typeName,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_FunctionCallExpression) {
			const expression = this.popExpression();
			const [args, identifiers] = this.popCallArgumentList();
			const names = [];
			for (let i = 0; i < identifiers.length; i++) {
				names.push(identifiers[i].name);
			}

			return {
				type: "FunctionCall",
				expression,
				arguments: args,
				names,
				identifiers,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_IdentifierPath) {
			return this.popType();
		} else if (kind === ASTNodeType_BaseType) {
			return this.popType();
		} else if (kind === ASTNodeType_MemberAccessExpression) {
			const expression = this.popExpression();
			const memberName = this.popString();

			return {
				type: "MemberAccess",
				expression,
				memberName,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ArrayAccessExpression) {
			const base = this.popExpression();
			const hasIndexExpression = this.popU32();
			let index = null;

			if (hasIndexExpression == 1) {
				index = this.popExpression();
			}

			return {
				type: "IndexAccess",
				base,
				index,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ArraySliceExpression) {
			const base = this.popExpression();

			const result = {
				type: "IndexRangeAccess",
				base,
			};

			const hasIndexStart = this.popU32();
			if (hasIndexStart == 1) {
				result.indexStart = this.popExpression();
			}

			const hasIndexEnd = this.popU32();
			if (hasIndexEnd == 1) {
				result.indexEnd = this.popExpression();
			}

            result.range = this.includeByteRange ? [startOffset, endOffset] : undefined;

			return result;
		} else if (kind === ASTNodeType_InlineArrayExpression) {
			const expressionCount = this.popU32();
			const expressions = [];
			for (let i = 0; i < expressionCount; i++) {
				expressions.push(this.popExpression());
			}

			return {
				type: "TupleExpression",
				components: expressions,
				isArray: true,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_TerneryExpression) {
			const condition = this.popExpression();
			const trueExpression = this.popExpression();
			const falseExpression = this.popExpression();

			return {
				type: "Conditional",
				condition,
				trueExpression,
				falseExpression,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_NamedParametersExpression) {
			const expression = this.popExpression();

            const nameValueListStartOffset = this.popU32();
            const nameValueListEndOffset = this.popU32();
			const count = this.popU32();
			const names = [];
			const identifiers = [];
			const parameters = [];
			for (let i = 0; i < count; i++) {
				const identifier = this.popStringIdentifier();
				names.push(identifier.name);
				identifiers.push(identifier);
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
                    range: this.includeByteRange ? [nameValueListStartOffset, nameValueListEndOffset] : undefined,
				},
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ArrayType) {
			return this.popType();
		} else if (kind === ASTNodeType_NameValue) {
			const name = this.popString();
			const value = this.popExpression();
			return {
				type: "NameValueExpression",
				name,
				value,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else {
			throw new Error(`Unknown/Unsupported expression type: ${kind}`);
		}
	}

	popYulExpression() {
		const kind = this.popU32();
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		if (kind === ASTNodeType_YulNumberLitExpression) {
			return {
				type: "DecimalNumber",
				value: this.popString(),
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulStringLitExpression) {
			const value = this.popString();
			return {
				type: "StringLiteral",
				value,
				parts: [value],
				isUnicode: [false],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulHexNumberLitExpression) {
			return {
				type: "HexNumber",
				value: this.popString(),
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulBoolLitExpression) {
			return {
				type: "BooleanLiteral",
				value: this.popString() === "true",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulHexStringLitExpression) {
			const value = this.popString();
			return {
				type: "HexLiteral",
				value,
				parts: [value],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulMemberAccessExpression) {
			const count = this.popU32();
			if (count === 1) {
				const name = this.popString();
				return {
					type: "Identifier",
					name,
					range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				};
			} else {
				const parts = [];
				for (let i = 0; i < count; i++) {
					parts.push(this.popStringIdentifier());
				}
				return {
					type: "AssemblyMemberAccess",
					expression: parts[0],
					memberName: parts[1],
					range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				};
			}
		} else if (kind === ASTNodeType_YulFunctionCallExpression) {
			const functionName = this.popString();
			const argCount = this.popU32();
			const args = [];
			for (let i = 0; i < argCount; i++) {
				args.push(this.popYulExpression());
			}
			return {
				type: "AssemblyCall",
				functionName,
				arguments: args,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else {
			throw new Error(`Unknown/Unsupported Yul expression type: ${kind}`);
		}
	}

	popStatement() {
		const kind = this.popU32();
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		if (kind === ASTNodeType_BlockStatement) {
			const count = this.popU32();
			const statements = [];
			for (let i = 0; i < count; i++) {
				statements.push(this.popStatement());
			}
			return {
				type: "Block",
				statements,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_UncheckedBlockStatement) {
			const block = this.popStatement();
			return {
				type: "UncheckedStatement",
				block,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ReturnStatement) {
			let expression = null;
			const hasExpression = this.popU16();
			if (hasExpression === 1) {
				expression = this.popExpression();
			}

			return {
				type: "ReturnStatement",
				expression,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ExpressionStatement) {
			const hasExpression = this.popU16() == 1;
			const expression = hasExpression ? this.popExpression() : null;
			return {
				type: "ExpressionStatement",
				expression,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_IfStatement) {
			const condition = this.popExpression();
			const trueBody = this.popStatement();
			const hasFalse = this.popU32();
			let falseBody = null;
			if (hasFalse) {
				falseBody = this.popStatement();
			}
			return {
				type: "IfStatement",
				condition,
				trueBody,
				falseBody,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_VariableDeclarationStatement) {
			const variable = this.popVariableDeclaration();
			const noInitialValue = this.popU32();
			let initialValue = null;
			if (noInitialValue === 0) {
				initialValue = this.popExpression();
			}

			return {
				type: "VariableDeclarationStatement",
				variables: [variable],
				initialValue,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_VariableDeclarationTupleStatement) {
			const count = this.popU32();

			const array = [];
			for (let i = 0; i < count; i++) {
				const hasDeclaration = this.popU32();
				if (hasDeclaration === 1) {
					const decl = this.popVariableDeclarationTupleStatementOrder();
					array.push(decl);
				} else {
					array.push(null);
				}
			}

			const initialValue = this.popExpression();

			return {
				type: "VariableDeclarationStatement",
				variables: array,
				initialValue,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_WhileStatement) {
			const condition = this.popExpression();
			const body = this.popStatement();

			return {
				type: "WhileStatement",
				condition,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_DoWhileStatement) {
			const condition = this.popExpression();
			const body = this.popStatement();

			return {
				type: "DoWhileStatement",
				condition,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ForStatement) {
			const hasInit = this.popU16() == 1;
			const initExpression = hasInit ? this.popStatement() : null;
			const hasCondition = this.popU16() == 1;
			const conditionExpression = hasCondition ? this.popExpression() : null;
			const loopExpression = this.popStatement();
            loopExpression.range = undefined
			const body = this.popStatement();

			return {
				type: "ForStatement",
				initExpression,
				conditionExpression,
				loopExpression,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_BreakStatement) {
			return {
				type: "BreakStatement",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ContinueStatement) {
			return {
				type: "ContinueStatement",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_RevertStatement) {
			const revertCall = this.popExpression();

			return {
				type: "RevertStatement",
				revertCall,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_EmitStatement) {
			const eventCall = this.popExpression();

			return {
				type: "EmitStatement",
				eventCall,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_TryStatement) {
			const expression = this.popExpression();
			const returnParameters = this.popFunctionParameters();
			const body = this.popStatement();

			const catchCount = this.popU32();
			const catchClauses = [];
			for (let i = 0; i < catchCount; i++) {
                const kind = this.popU32();
                const startOffset = this.popU32();
                const endOffset = this.popU32();
				const identifier = this.popString();
				const catchParams = this.popFunctionParameters();
				const catchBody = this.popStatement();
				catchClauses.push({
					type: "CatchClause",
					isReasonStringType: identifier === "Error",
					kind: identifier,
					parameters: catchParams,
					body: catchBody,
                                  range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				});
			}

			return {
				type: "TryStatement",
				expression,
				returnParameters,
				body,
				catchClauses,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_AssemblyStatement) {
			const isEVMAsm = this.popU16() === 1;
			const flagCount = this.popU16();
			const flags = [];
			for (let i = 0; i < flagCount; i++) {
				flags.push(this.popString());
			}
			const body = this.popStatement();

			return {
				type: "InlineAssemblyStatement",
				language: isEVMAsm ? "evmasm" : null,
				flags,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulBlockStatement) {
			const count = this.popU32();
			const operations = [];
			for (let i = 0; i < count; i++) {
				operations.push(this.popStatement());
			}
			return {
				type: "AssemblyBlock",
				operations,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulVariableDeclaration) {
			const count = this.popU32();
			const names = [];
			for (let i = 0; i < count; i++) {
				names.push(this.popStringIdentifier());
			}
			const hasValue = this.popU16() === 1;
			const value = hasValue ? this.popYulExpression() : null;

			return {
				type: "AssemblyLocalDefinition",
				names,
				expression: value,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulVariableAssignment) {
			const count = this.popU32();
			const names = [];
			for (let i = 0; i < count; i++) {
				names.push(this.popYulExpression());
			}
			const hasValue = this.popU16() === 1;
			const value = hasValue ? this.popYulExpression() : null;

			return {
				type: "AssemblyAssignment",
				names,
				expression: value,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulFunctionCallExpression) {
			const functionName = this.popString();
			const argCount = this.popU32();
			const args = [];
			for (let i = 0; i < argCount; i++) {
				args.push(this.popYulExpression());
			}
			return {
				type: "AssemblyCall",
				functionName,
				arguments: args,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulIfStatement) {
			const expression = this.popYulExpression();
			const body = this.popStatement();

			return {
				type: "AssemblyIf",
				condition: expression,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulForStatement) {
			const pre = this.popStatement();
			const condition = this.popYulExpression();
			const post = this.popStatement();
			const body = this.popStatement();

			return {
				type: "AssemblyFor",
				pre,
				condition,
				post,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulFunctionDefinition) {
			const identifier = this.popString();
			const parameterCount = this.popU32();
			const parameters = [];
			for (let i = 0; i < parameterCount; i++) {
				parameters.push(this.popStringIdentifier());
			}
			const returnCount = this.popU32();
			const returns = [];
			for (let i = 0; i < returnCount; i++) {
				returns.push(this.popStringIdentifier());
			}
			const body = this.popStatement();

			return {
				type: "AssemblyFunctionDefinition",
				name: identifier,
				arguments: parameters,
				returnArguments: returns,
				body,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulSwitchStatement) {
			const expression = this.popYulExpression();
			const count = this.popU32();
			const cases = [];
			for (let i = 0; i < count; i++) {
                const kind = this.popU32();
                const startOffset = this.popU32();
                const endOffset = this.popU32();
				cases.push({
					type: "AssemblyCase",
					block: this.popStatement(),
					value: this.popYulExpression(),
					default: false,
                           range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				});
			}
			const hasDefault = this.popU16() === 1;
			if (hasDefault) {
                const kind = this.popU32();
                const startOffset = this.popU32();
                const endOffset = this.popU32();

				cases.push({
					type: "AssemblyCase",
					block: this.popStatement(),
					value: null,
					default: true,
                           range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				});
			}

			return {
				type: "AssemblySwitch",
				expression,
				cases,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulLeaveStatement) {
			return {
				type: "Identifier",
				name: "leave",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulContinueStatement) {
			return {
				type: "Continue",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_YulBreakStatement) {
			return {
				type: "Break",
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else {
			throw new Error("Unknown/Unsupported statement kind " + kind);
		}
	}

	popFunctionParameters() {
		const paramCount = this.popU32();
		if (paramCount === 0xffffffff) {
			return null;
		}
		if (paramCount === 0) {
			return [];
		}
		const params = [];
		for (let i = 0; i < paramCount; i++) {
            params.push(this.popVariableDeclaration());
		}
		return params;
	}

	popASTNode() {
		const kind = this.popU32();
		const startOffset = this.popU32();
		const endOffset = this.popU32();

		if (kind === ASTNodeType_SourceUnit) {
			return {
				...this.popSourceUnit(),
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_Pragma) {
			const name = this.popString();
			const value = this.popString();
			return {
				type: "PragmaDirective",
				name,
				value,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_Import) {
            const pathLiteral = this.popStringLiteral();
			const unitAliasIdentifier = this.popStringIdentifier();
			const symbolsCount = this.popU32();

			let aliases = [];
			let aliasesIdentifiers = [];

			if (symbolsCount === 0) {
				aliases = null;
				aliasesIdentifiers = null;
			}

			for (let i = 0; i < symbolsCount; i++) {
				const symbolIdentifier = this.popStringIdentifier();
				const aliasIdentifier = this.popStringIdentifier();
				aliases.push([symbolIdentifier?.name ?? null, aliasIdentifier?.name ?? null]);
				aliasesIdentifiers.push([
					symbolIdentifier,
					aliasIdentifier,
				]);
			}

			return {
				type: "ImportDirective",
				path: pathLiteral.value,
				pathLiteral,
				unitAlias: unitAliasIdentifier?.name ?? null,
				unitAliasIdentifier,
				symbolAliases: aliases,
				symbolAliasesIdentifiers: aliasesIdentifiers,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_Using) {
			const count = this.popU32();
			const idents = [];
			for (let i = 0; i < count; i++) {
				idents.push(this.popType().namePath);
			}

			const operatorCount = this.popU32();
			const operators = [];
			for (let i = 0; i < operatorCount; i++) {
				operators.push(this.operatorStrings[this.popU16()]);
			}

			const hasForType = this.popU16();
			let typeName = null;
			if (hasForType === 1) {
				typeName = this.popType();
			}
			const isGlobal = this.popU16() === 1;
			const isLibrary = this.popU16() === 1;

			return {
				type: "UsingForDeclaration",
				isGlobal,
				typeName,
				libraryName: isLibrary ? idents[0] : null,
				functions: !isLibrary ? idents : [],
				operators: !isLibrary ? operators : [],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_EnumDefinition) {
			const name = this.popString();

			const membersCount = this.popU32();
			const members = [];
			for (let i = 0; i < membersCount; i++) {
				members.push(this.popStringEnumValue());
			}

			return {
				type: "EnumDefinition",
				name,
				members,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_StructDefinition) {
			const name = this.popString();
			const membersCount = this.popU32();
			const members = [];
			for (let i = 0; i < membersCount; i++) {
				members.push(this.popVariableDeclaration());
			}

			return {
				type: "StructDefinition",
				name,
				members,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_Error) {
			const name = this.popString();
			const paramCount = this.popU32();
			const params = [];
			for (let i = 0; i < paramCount; i++) {
                params.push(this.popVariableDeclaration());
			}

			return {
				type: "CustomErrorDefinition",
				name,
				parameters: params,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_Event) {
			const name = this.popString();
			const isAnonymous = this.popU32() === 1;
			const paramCount = this.popU32();
			const params = [];
			for (let i = 0; i < paramCount; i++) {
                params.push(this.popVariableDeclarationEventOrder());
			}

			return {
				type: "EventDefinition",
				name,
				parameters: params,
				isAnonymous,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_Typedef) {
			const name = this.popString();
			const type = this.popType();

			return {
				type: "TypeDefinition",
				name,
				definition: type,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ConstVariable) {
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
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_StateVariableDeclaration) {
			const identifier = this.popStringIdentifier();
			const typeName = this.popType();
			const visibility = this.popU16();
			const mutability = this.popU16();
			const isOverride = this.popU16();
			let override = null;
			if (isOverride === 1) {
				override = [];
				const count = this.popU32();
				for (let i = 0; i < count; i++) {
					override.push(this.popType());
				}
			}
			const hasExpression = this.popU32();

			let expression = null;
			if (hasExpression === 1) {
				expression = this.popExpression();
			}

			return {
				type: "StateVariableDeclaration",
				variables: [
					{
						type: "VariableDeclaration",
						typeName,
						name: identifier.name,
						identifier,
						expression,
						visibility: this.variableVisibilityString[visibility],
						isStateVar: true,
						isDeclaredConst: mutability === 1,
						isIndexed: false,
						isImmutable: mutability === 2,
						override,
						storageLocation: null,
                        range: this.includeByteRange ? [startOffset, endOffset] : undefined,
					},
				],
				initialValue: expression,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (
			kind === ASTNodeType_FunctionDefinition ||
			kind === ASTNodeType_FallbackFunction ||
			kind === ASTNodeType_ReceiveFunction
		) {
			let name = this.popString() ?? "";
			name = kind === ASTNodeType_FunctionDefinition ? name : null;
			const isFallback = kind === ASTNodeType_FallbackFunction;
			const isReceiveEther = kind === ASTNodeType_ReceiveFunction;

			const parameters = this.popFunctionParameters();
			const visibility = this.popU16();
			const stateMutability = this.popU16();
			const isVirtual = this.popU16();
			const isOverride = this.popU16();
			let override = null;
			if (isOverride === 1) {
				override = [];
				const count = this.popU32();
				for (let i = 0; i < count; i++) {
					override.push(this.popType());
				}
			}

			const returnParameters = this.popFunctionParameters();
			const modifierCount = this.popU32();
			const modifiers = [];
			for (let i = 0; i < modifierCount; i++) {
                const kind = this.popU32();
                const startOffset = this.popU32();
                const endOffset = this.popU32();
				const name = this.popType().namePath;
				const [args, names] = this.popCallArgumentList();

				modifiers.push({
					type: "ModifierInvocation",
					name,
					arguments: args,
                   range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				});
			}

			const hasBody = this.popU32();
			let body = null;
			if (hasBody) {
				body = this.popStatement();
			}

			return {
				type: "FunctionDefinition",
				name,
				parameters,
				returnParameters,
				body,
				visibility: this.visibilityString[visibility],
				modifiers,
				override,
				isConstructor: false,
				isReceiveEther,
				isFallback,
				isVirtual: isVirtual == 1,
				stateMutability: this.stateMutabilityString[stateMutability],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ModifierDefinition) {
			const name = this.popString();
			const parameters = this.popFunctionParameters();
			const isVirtual = this.popU16();
			const isOverride = this.popU16();
			let override = null;
			if (isOverride === 1) {
				override = [];
				const count = this.popU32();
				for (let i = 0; i < count; i++) {
					override.push(this.popType());
				}
			}

			const hasBody = this.popU32();
			let body = null;
			if (hasBody) {
				body = this.popStatement();
			}

			return {
				type: "ModifierDefinition",
				name,
				parameters,
				body,
				isVirtual: isVirtual == 1,
				override,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (
			kind === ASTNodeType_ContractDefinition ||
			kind === ASTNodeType_LibraryDefinition ||
			kind === ASTNodeType_InterfaceDefinition ||
			kind === ASTNodeType_AbstractContractDefinition
		) {
			const name = this.popString();
			const baseContractCount = this.popU32();
			const baseContracts = [];

			for (let i = 0; i < baseContractCount; i++) {
				baseContracts.push(this.popASTNode());
			}

			const subNodeCount = this.popU32();
			const subNodes = [];

			for (let i = 0; i < subNodeCount; i++) {
				subNodes.push(this.popASTNode());
			}

			return {
				type: "ContractDefinition",
				name,
				baseContracts,
				subNodes,
				kind: this.contractKindMap[kind],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_ConstructorDefinition) {
			const parameters = this.popFunctionParameters();
			const visibility = this.popU16();
			const stateMutability = this.popU16();

			const modifierCount = this.popU32();
			const modifiers = [];
			for (let i = 0; i < modifierCount; i++) {
                const kind = this.popU32();
                const startOffset = this.popU32();
                const endOffset = this.popU32();
				const name = this.popType().namePath;
				const [args, names] = this.popCallArgumentList();

				modifiers.push({
					type: "ModifierInvocation",
					name,
					arguments: args,
                               range: this.includeByteRange ? [startOffset, endOffset] : undefined,
				});
			}
			const body = this.popStatement();

			return {
				type: "FunctionDefinition",
				name: null,
				parameters,
				returnParameters: null,
				body,
				visibility: this.visibilityString[visibility],
				modifiers,
				override: null,
				isConstructor: true,
				isReceiveEther: false,
				isFallback: false,
				isVirtual: false,
				stateMutability: this.stateMutabilityString[stateMutability],
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else if (kind === ASTNodeType_InheritanceSpecifier) {
			const identifier = this.popType();
			const [args, names] = this.popCallArgumentList();

			return {
				type: "InheritanceSpecifier",
				baseName: identifier,
				arguments: args,
				range: this.includeByteRange ? [startOffset, endOffset] : undefined,
			};
		} else {
			throw new Error(`Unknown/Unsupported ASTNode kind: ${kind}`);
		}
	}

	popSourceUnit() {
		const kind = this.popU32();
		const startOffset = this.popU32();
		const endOffset = this.popU32();
		if (kind !== ASTNodeType_SourceUnit) {
			throw new Error("Invalid SourceUnit type");
		}

		const childrenCount = this.popU32();
		const children = new Array(childrenCount);

		for (let i = 0; i < childrenCount; i++) {
			children[i] = this.popASTNode();
		}

		return {
			type: "SourceUnit",
			children,
			range: this.includeByteRange ? [startOffset, endOffset] : undefined,
		};
	}
}

module.exports = Deserializer;
