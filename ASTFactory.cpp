#include "ASTFactory.h"
#include "IntegerAST.h"
#include "IdAST.h"
#include "FloatAST.h"
#include "StringAST.h"
#include "PublicAST.h"
#include "PrivateAST.h"
#include "IntegerIdAST.h"
#include "FloatIdAST.h"
#include "StringIdAST.h"
#include "CompositeConceptAST.h"
#include "TokenAST.h"
#include "VoidAST.h"
#include "BreakAST.h"
#include "ContinueAST.h"
#include "EqualToAST.h"
#include "NotEqualToAST.h"
#include "LessThanAST.h"
#include "GreaterThanAST.h"
#include "LessThanEqualToAST.h"
#include "GreaterThanEqualToAST.h"
#include "AdditionAST.h"
#include "SubtractionAST.h"
#include "MultiplicationAST.h"
#include "DivisionAST.h"
#include "AssignmentAST.h"
#include "OrAST.h"
#include "AndAST.h"
#include "NotAST.h"
#include "TernaryAST.h"
#include "PeriodAST.h"
#include "TokenAST.h"
#include "AParamsListAST.h"
#include "ArrayDimensionAST.h"
#include "ArraySizeReptListAST.h"
#include "AssignStatAST.h"
#include "ClassDeclBodyListAST.h"
#include "ClassListAST.h"
#include "FParamsListAST.h"
#include "FuncCallStatAST.h"
#include "FuncListAST.h"
#include "FuncOrVarListAST.h"
#include "IndiceRepListAST.h"
#include "InheritListAST.h"
#include "VarCallStatAST.h"
#include "VarDeclListAST.h"
#include "ArithExprAST.h"
#include "ClassDeclAST.h"
#include "ClassDeclBodyAST.h"
#include "ClassMethodAST.h"
#include "ExprAST.h"
#include "FParamsAST.h"
#include "FuncBodyAST.h"
#include "FuncDeclAST.h"
#include "FuncDefAST.h"
#include "FuncHeadAST.h"
#include "FuncStatAST.h"
#include "FunctionAST.h"
#include "IfAST.h"
#include "IndiceRepAST.h"
#include "InheritAST.h"
#include "ProgAST.h"
#include "ReadAST.h"
#include "ReturnAST.h"
#include "StartAST.h"
#include "StatementAST.h"
#include "StatementListAST.h"
#include "VarDeclAST.h"
#include "VariableAST.h"
#include "WhileAST.h"
#include "WriteAST.h"

vector<AST*> ASTFactory::treesProduced;

AST* ASTFactory::makeNode(Token t)
{
	// TODO add the rest of the class types here
	switch (t.getTokenType()) {
	case TokenType::ID:
		treesProduced.push_back(new IdAST(t));
		break;
		// TYPES
	case TokenType::INTEGER:
		treesProduced.push_back(new IntegerAST(t));
		break;
	case TokenType::FLOAT:
		treesProduced.push_back(new FloatAST(t));
		break;
	case TokenType::STRING:
		treesProduced.push_back(new StringAST(t));
		break;
		// KEYWORDS
	case TokenType::INTEGER_ID:
		treesProduced.push_back(new IntegerIdAST(t));
		break;
	case TokenType::FLOAT_ID:
		treesProduced.push_back(new FloatIdAST(t));
		break;
	case TokenType::STRING_ID:
		treesProduced.push_back(new StringIdAST(t));
		break;
	case TokenType::VOID:
		treesProduced.push_back(new VoidAST(t));
		break;
	case TokenType::PUBLIC:
		treesProduced.push_back(new PublicAST(t));
		break;
	case TokenType::PRIVATE:
		treesProduced.push_back(new PrivateAST(t));
		break;
	case TokenType::BREAK:
		treesProduced.push_back(new BreakAST(t));
		break;
	case TokenType::CONTINUE:
		treesProduced.push_back(new ContinueAST(t));
		break;
		// OPERATORS
	case TokenType::EQUAL_TO:
		treesProduced.push_back(new EqualToAST(t));
		break;
	case TokenType::NOT_EQUAL_TO:
		treesProduced.push_back(new NotEqualToAST(t));
		break;
	case TokenType::LESS_THAN:
		treesProduced.push_back(new LessThanAST(t));
		break;
	case TokenType::GREATER_THAN:
		treesProduced.push_back(new GreaterThanAST(t));
		break;
	case TokenType::LESS_THAN_EQUAL_TO:
		treesProduced.push_back(new LessThanEqualToAST(t));
		break;
	case TokenType::GREATER_THAN_EQUAL_TO:
		treesProduced.push_back(new GreaterThanEqualToAST(t));
		break;
		// MATH
	case TokenType::ADDITION:
		treesProduced.push_back(new AdditionAST(t));
		break;
	case TokenType::SUBTRACTION:
		treesProduced.push_back(new SubtractionAST(t));
		break;
	case TokenType::MULTIPLICATION:
		treesProduced.push_back(new MultiplicationAST(t));
		break;
	case TokenType::DIVISION:
		treesProduced.push_back(new DivisionAST(t));
		break;
	case TokenType::ASSIGNMENT:
		treesProduced.push_back(new AssignmentAST(t));
		break;
	case TokenType::OR:
		treesProduced.push_back(new OrAST(t));
		break;
	case TokenType::AND:
		treesProduced.push_back(new AndAST(t));
		break;
	case TokenType::NOT:
		treesProduced.push_back(new NotAST(t));
		break;
	case TokenType::QUESTION_MARK:
		treesProduced.push_back(new TernaryAST(t));
		break;
	case TokenType::PERIOD:
		treesProduced.push_back(new PeriodAST(t));
		break;
	default:
		//we got an issue...
		throw "missing token type";
	}

	return treesProduced.back();
}

AST* ASTFactory::makeNode(CompositeConcept t)
{
	// TODO introduce individual class types here
	switch (t) {
		// Not part of the grammar
	case CompositeConcept::APARAMSLIST:
		treesProduced.push_back(new AParamsListAST(t));
		break;
	case CompositeConcept::ARRAYDIMENSION:
		treesProduced.push_back(new ArrayDimensionAST(t));
		break;
	case CompositeConcept::ARRAYSIZEREPTLIST:
		treesProduced.push_back(new ArraySizeReptListAST(t));
		break;
	case CompositeConcept::ASSIGNSTAT:
		treesProduced.push_back(new AssignStatAST(t));
		break;
	case CompositeConcept::CLASSDECLBODYLIST:
		treesProduced.push_back(new ClassDeclBodyListAST(t));
		break;
	case CompositeConcept::CLASSLIST:
		treesProduced.push_back(new ClassListAST(t));
		break;
	case CompositeConcept::FPARAMSLIST:
		treesProduced.push_back(new FParamsListAST(t));
		break;
	case CompositeConcept::FUNCCALLSTAT:
		treesProduced.push_back(new FuncCallStatAST(t));
		break;
	case CompositeConcept::FUNCLIST:
		treesProduced.push_back(new FuncListAST(t));
		break;
	case CompositeConcept::FUNCORVARLIST:
		treesProduced.push_back(new FuncOrVarListAST(t));
		break;
	case CompositeConcept::INDICEREPLIST:
		treesProduced.push_back(new IndiceRepListAST(t));
		break;
	case CompositeConcept::INHERITLIST:
		treesProduced.push_back(new InheritListAST(t));
		break;
	case CompositeConcept::VARCALLSTAT:
		treesProduced.push_back(new VarCallStatAST(t));
		break;
	case CompositeConcept::VARDECLLIST:
		treesProduced.push_back(new VarDeclListAST(t));
		break;

		// Part of the grammar
	case CompositeConcept::ARITHEXPR:
		treesProduced.push_back(new ArithExprAST(t));
		break;
	case CompositeConcept::CLASSDECL:
		treesProduced.push_back(new ClassDeclAST(t));
		break;
	case CompositeConcept::CLASSDECLBODY:
		treesProduced.push_back(new ClassDeclBodyAST(t));
		break;
	case CompositeConcept::CLASSMETHOD:
		treesProduced.push_back(new ClassMethodAST(t));
		break;
	case CompositeConcept::EXPR:
		treesProduced.push_back(new ExprAST(t));
		break;
	case CompositeConcept::FPARAMS:
		treesProduced.push_back(new FParamsAST(t));
		break;
	case CompositeConcept::FUNCBODY:
		treesProduced.push_back(new FuncBodyAST(t));
		break;
	case CompositeConcept::FUNCDECL:
		treesProduced.push_back(new FuncDeclAST(t));
		break;
	case CompositeConcept::FUNCDEF:
		treesProduced.push_back(new FuncDefAST(t));
		break;
	case CompositeConcept::FUNCHEAD:
		treesProduced.push_back(new FuncHeadAST(t));
		break;
	case CompositeConcept::FUNCSTAT:
		treesProduced.push_back(new FuncStatAST(t));
		break;
	case CompositeConcept::FUNCTION:
		treesProduced.push_back(new FunctionAST(t));
		break;
	case CompositeConcept::IF:
		treesProduced.push_back(new IfAST(t));
		break;
	case CompositeConcept::INDICEREP:
		treesProduced.push_back(new IndiceRepAST(t));
		break;
	case CompositeConcept::INHERIT:
		treesProduced.push_back(new InheritAST(t));
		break;
	case CompositeConcept::PROG:
		treesProduced.push_back(new ProgAST(t));
		break;
	case CompositeConcept::READ:
		treesProduced.push_back(new ReadAST(t));
		break;
	case CompositeConcept::RETURN:
		treesProduced.push_back(new ReturnAST(t));
		break;
	case CompositeConcept::START:
		treesProduced.push_back(new StartAST(t));
		break;
	case CompositeConcept::STATEMENT:
		treesProduced.push_back(new StatementAST(t));
		break;
	case CompositeConcept::STATEMENTLIST:
		treesProduced.push_back(new StatementListAST(t));
		break;
	case CompositeConcept::VARDECL:
		treesProduced.push_back(new VarDeclAST(t));
		break;
	case CompositeConcept::VARIABLE:
		treesProduced.push_back(new VariableAST(t));
		break;
	case CompositeConcept::WHILE:
		treesProduced.push_back(new WhileAST(t));
		break;
	case CompositeConcept::WRITE:
		treesProduced.push_back(new WriteAST(t));
		break;
	default:
		throw "we got an issue";
	}
	//TODO DEBUG THIS
	//treesProduced.push_back(new CompositeConceptAST(t));
	return treesProduced.back();
}

AST* ASTFactory::makeFamily(CompositeConcept t, vector<AST*> children)
{
	AST* parent = makeNode(t);

	makeFamily(parent, children);

	return parent;
}

void ASTFactory::makeFamily(AST* parent, vector<AST*> children)
{
	AST* firstValidChild = nullptr;

	for (AST* child : children) {
		if (child) {
			if (!firstValidChild) {
				// the first non-null sibling is found
				firstValidChild = child;
				continue;
			}
			firstValidChild->makeSiblings(child);
		}
	}

	if (firstValidChild) {
		parent->adoptChildren(firstValidChild);
	}
}