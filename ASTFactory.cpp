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
#include "TokenAST.h"

vector<std::shared_ptr<AST>> ASTFactory::treesProduced;

AST* ASTFactory::makeNode(Token t)
{
	// TODO add the rest of the class types here
	switch (t.getTokenType()) {
	case TokenType::ID:
		treesProduced.push_back(shared_ptr<AST>(new IdAST(t)));
		break;
		// TYPES
	case TokenType::INTEGER:
		treesProduced.push_back(shared_ptr<AST>(new IntegerAST(t)));
		break;
	case TokenType::FLOAT:
		treesProduced.push_back(shared_ptr<AST>(new FloatAST(t)));
		break;
	case TokenType::STRING:
		treesProduced.push_back(shared_ptr<AST>(new StringAST(t)));
		break;
		// KEYWORDS
	case TokenType::INTEGER_ID:
		treesProduced.push_back(shared_ptr<AST>(new IntegerIdAST(t)));
		break;
	case TokenType::FLOAT_ID:
		treesProduced.push_back(shared_ptr<AST>(new FloatIdAST(t)));
		break;
	case TokenType::STRING_ID:
		treesProduced.push_back(shared_ptr<AST>(new StringIdAST(t)));
		break;
	case TokenType::VOID:
		treesProduced.push_back(shared_ptr<AST>(new VoidAST(t)));
		break;
	case TokenType::PUBLIC:
		treesProduced.push_back(shared_ptr<AST>(new PublicAST(t)));
		break;
	case TokenType::PRIVATE:
		treesProduced.push_back(shared_ptr<AST>(new PrivateAST(t)));
		break;
	case TokenType::BREAK:
		treesProduced.push_back(shared_ptr<AST>(new BreakAST(t)));
		break;
	case TokenType::CONTINUE:
		treesProduced.push_back(shared_ptr<AST>(new ContinueAST(t)));
		break;
		// OPERATORS
	case TokenType::EQUAL_TO:
		treesProduced.push_back(shared_ptr<AST>(new EqualToAST(t)));
		break;
	case TokenType::NOT_EQUAL_TO:
		treesProduced.push_back(shared_ptr<AST>(new NotEqualToAST(t)));
		break;
	case TokenType::LESS_THAN:
		treesProduced.push_back(shared_ptr<AST>(new LessThanAST(t)));
		break;
	case TokenType::GREATER_THAN:
		treesProduced.push_back(shared_ptr<AST>(new GreaterThanAST(t)));
		break;
	case TokenType::LESS_THAN_EQUAL_TO:
		treesProduced.push_back(shared_ptr<AST>(new LessThanEqualToAST(t)));
		break;
	case TokenType::GREATER_THAN_EQUAL_TO:
		treesProduced.push_back(shared_ptr<AST>(new GreaterThanEqualToAST(t)));
		break;
		// MATH
	case TokenType::ADDITION:
		treesProduced.push_back(shared_ptr<AST>(new AdditionAST(t)));
		break;
	case TokenType::SUBTRACTION:
		treesProduced.push_back(shared_ptr<AST>(new SubtractionAST(t)));
		break;
	case TokenType::MULTIPLICATION:
		treesProduced.push_back(shared_ptr<AST>(new MultiplicationAST(t)));
		break;
	case TokenType::DIVISION:
		treesProduced.push_back(shared_ptr<AST>(new DivisionAST(t)));
		break;
	case TokenType::ASSIGNMENT:
		treesProduced.push_back(shared_ptr<AST>(new AssignmentAST(t)));
		break;
	case TokenType::OR:
		treesProduced.push_back(shared_ptr<AST>(new OrAST(t)));
		break;
	case TokenType::AND:
		treesProduced.push_back(shared_ptr<AST>(new AndAST(t)));
		break;
	case TokenType::NOT:
		treesProduced.push_back(shared_ptr<AST>(new NotAST(t)));
		break;
	case TokenType::QUESTION_MARK:
		treesProduced.push_back(shared_ptr<AST>(new TernaryAST(t)));
		break;
	default:
		//we got an issue...
		throw "missing token type";
	}

	return treesProduced[treesProduced.size() - 1].get();
}

AST* ASTFactory::makeNode(CompositeConcept t)
{
	// TODO introduce individual class types here
	switch (t) {
		// Not part of the grammar
	case CompositeConcept::APARAMSLIST:
		treesProduced.push_back(shared_ptr<AST>(new AParamsListAST(t)));
		break;
	case CompositeConcept::ARRAYDIMENSION:
		treesProduced.push_back(shared_ptr<AST>(new ArrayDimensionAST(t)));
		break;
	case CompositeConcept::ARRAYSIZEREPTLIST:
		treesProduced.push_back(shared_ptr<AST>(new ArraySizeReptListAST(t)));
		break;
	case CompositeConcept::ASSIGNSTAT:
		treesProduced.push_back(shared_ptr<AST>(new AssignStatAST(t)));
		break;
	case CompositeConcept::CLASSDECLBODYLIST:
		treesProduced.push_back(shared_ptr<AST>(new ClassDeclBodyListAST(t)));
		break;
	case CompositeConcept::CLASSLIST:
		treesProduced.push_back(shared_ptr<AST>(new ClassListAST(t)));
		break;
	case CompositeConcept::FPARAMSLIST:
		treesProduced.push_back(shared_ptr<AST>(new FParamsListAST(t)));
		break;
	case CompositeConcept::FUNCCALLSTAT:
		treesProduced.push_back(shared_ptr<AST>(new FuncCallStatAST(t)));
		break;
	case CompositeConcept::FUNCLIST:
		treesProduced.push_back(shared_ptr<AST>(new FuncListAST(t)));
		break;
	case CompositeConcept::FUNCORVARLIST:
		treesProduced.push_back(shared_ptr<AST>(new FuncOrVarListAST(t)));
		break;
	case CompositeConcept::INDICEREPLIST:
		treesProduced.push_back(shared_ptr<AST>(new IndiceRepListAST(t)));
		break;
	case CompositeConcept::INHERITLIST:
		treesProduced.push_back(shared_ptr<AST>(new InheritListAST(t)));
		break;
	case CompositeConcept::TERNARY:
		treesProduced.push_back(shared_ptr<AST>(new TernaryAST(t)));
		break;
	case CompositeConcept::VARCALLSTAT:
		treesProduced.push_back(shared_ptr<AST>(new VarCallStatAST(t)));
		break;
	case CompositeConcept::VARDECLLIST:
		treesProduced.push_back(shared_ptr<AST>(new VarDeclListAST(t)));
		break;

		// Part of the grammar
	case CompositeConcept::ARITHEXPR:
		treesProduced.push_back(shared_ptr<AST>(new ArithExprAST(t)));
		break;
	case CompositeConcept::CLASSDECL:
		treesProduced.push_back(shared_ptr<AST>(new ClassDeclAST(t)));
		break;
	case CompositeConcept::CLASSDECLBODY:
		treesProduced.push_back(shared_ptr<AST>(new ClassDeclBodyAST(t)));
		break;
	case CompositeConcept::CLASSMETHOD:
		treesProduced.push_back(shared_ptr<AST>(new ClassMethodAST(t)));
		break;
	case CompositeConcept::EXPR:
		treesProduced.push_back(shared_ptr<AST>(new ExprAST(t)));
		break;
	case CompositeConcept::FPARAMS:
		treesProduced.push_back(shared_ptr<AST>(new FParamsAST(t)));
		break;
	case CompositeConcept::FUNCBODY:
		treesProduced.push_back(shared_ptr<AST>(new FuncBodyAST(t)));
		break;
	case CompositeConcept::FUNCDECL:
		treesProduced.push_back(shared_ptr<AST>(new FuncDeclAST(t)));
		break;
	case CompositeConcept::FUNCDEF:
		treesProduced.push_back(shared_ptr<AST>(new FuncDefAST(t)));
		break;
	case CompositeConcept::FUNCHEAD:
		treesProduced.push_back(shared_ptr<AST>(new FuncHeadAST(t)));
		break;
	case CompositeConcept::FUNCSTAT:
		treesProduced.push_back(shared_ptr<AST>(new FuncStatAST(t)));
		break;
	case CompositeConcept::FUNCTION:
		treesProduced.push_back(shared_ptr<AST>(new FunctionAST(t)));
		break;
	case CompositeConcept::IF:
		treesProduced.push_back(shared_ptr<AST>(new IfAST(t)));
		break;
	case CompositeConcept::INDICEREP:
		treesProduced.push_back(shared_ptr<AST>(new IndiceRepAST(t)));
		break;
	case CompositeConcept::INHERIT:
		treesProduced.push_back(shared_ptr<AST>(new InheritAST(t)));
		break;
	case CompositeConcept::PROG:
		treesProduced.push_back(shared_ptr<AST>(new ProgAST(t)));
		break;
	case CompositeConcept::READ:
		treesProduced.push_back(shared_ptr<AST>(new ReadAST(t)));
		break;
	case CompositeConcept::RETURN:
		treesProduced.push_back(shared_ptr<AST>(new ReturnAST(t)));
		break;
	case CompositeConcept::START:
		treesProduced.push_back(shared_ptr<AST>(new StartAST(t)));
		break;
	case CompositeConcept::STATEMENT:
		treesProduced.push_back(shared_ptr<AST>(new StatementAST(t)));
		break;
	case CompositeConcept::STATEMENTLIST:
		treesProduced.push_back(shared_ptr<AST>(new StatementListAST(t)));
		break;
	case CompositeConcept::VARDECL:
		treesProduced.push_back(shared_ptr<AST>(new VarDeclAST(t)));
		break;
	case CompositeConcept::VARIABLE:
		treesProduced.push_back(shared_ptr<AST>(new VariableAST(t)));
		break;
	case CompositeConcept::WHILE:
		treesProduced.push_back(shared_ptr<AST>(new WhileAST(t)));
		break;
	case CompositeConcept::WRITE:
		treesProduced.push_back(shared_ptr<AST>(new WriteAST(t)));
		break;
	}
	treesProduced.push_back(shared_ptr<AST>(new CompositeConceptAST(t)));
	return treesProduced[treesProduced.size() - 1].get();
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