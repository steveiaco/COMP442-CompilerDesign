#include "SymTabCreationVisitor.h"
#include <vector>

using std::vector;

void SymTabCreationVisitor::visit_VARDECL(CompositeConceptAST* n)
{
	string type;
	string name;
	vector<int> arrayInd;

	int childIndex = 0;
	AST* child = n->getChild(childIndex);
	while (child != nullptr) {
		// type
		if (childIndex == 0) {
			GeneralTokenAST* typeAST = dynamic_cast<GeneralTokenAST*>(child);
			type = typeAST->getToken().getLexeme();
		}
		// id
		else if (childIndex == 1) {
			GeneralTokenAST* nameAST = dynamic_cast<GeneralTokenAST*>(child);
			name = nameAST->getToken().getLexeme();
		}
		// arraysizereptlist
		else if (childIndex == 2) {
			CompositeConceptAST* arrayAST = dynamic_cast<CompositeConceptAST*>(child);
			AST* arrayDimension = arrayAST->leftMostChild;
			while (arrayDimension != nullptr) {

				arrayDimension = arrayDimension->rightSibling;
			}
			
		}
		childIndex++;
		child = n->getChild(childIndex);
	}
}

SymTabCreationVisitor::SymTabCreationVisitor()
{
}

void SymTabCreationVisitor::visit(CompositeConceptAST* n) {
	switch (n->getCompositeConcept()) {
	// Not part of the grammar
	case CompositeConcept::APARAMSLIST:
		break;
	case CompositeConcept::ARRAYDIMENSION:
		break;
	case CompositeConcept::ARRAYSIZEREPTLIST:
		break;
	case CompositeConcept::ASSIGNSTAT:
		break;
	case CompositeConcept::CLASSDECLBODYLIST:
		break;
	case CompositeConcept::CLASSLIST:
		break;
	case CompositeConcept::FPARAMSLIST:
		break;
	case CompositeConcept::FUNCCALLSTAT:
		break;
	case CompositeConcept::FUNCLIST:
		break;
	case CompositeConcept::FUNCORVARLIST:
		break;
	case CompositeConcept::INDICEREPLIST:
		break;
	case CompositeConcept::INHERITLIST:
		break;
	case CompositeConcept::TERNARY:
		break;
	case CompositeConcept::VARCALLSTAT:
		break;
	case CompositeConcept::VARDECLLIST:
		break;

	// Part of the grammar
	case CompositeConcept::ARITHEXPR:
		break;
	case CompositeConcept::CLASSDECL:
		break;
	case CompositeConcept::CLASSDECLBODY:
		break;
	case CompositeConcept::CLASSMETHOD:
		break;
	case CompositeConcept::EXPR:
		break;
	case CompositeConcept::FPARAMS:
		break;
	case CompositeConcept::FUNCBODY:
		break;
	case CompositeConcept::FUNCDECL:
		break;
	case CompositeConcept::FUNCDEF:
		break;
	case CompositeConcept::FUNCHEAD:
		break;
	case CompositeConcept::FUNCSTAT:
		break;
	case CompositeConcept::FUNCTION:
		break;
	case CompositeConcept::IF:
		break;
	case CompositeConcept::INDICEREP:
		break;
	case CompositeConcept::INHERIT:
		break;
	case CompositeConcept::PROG:
		break;
	case CompositeConcept::READ:
		break;
	case CompositeConcept::RETURN:
		break;
	case CompositeConcept::START:
		break;
	case CompositeConcept::STATEMENT:
		break;
	case CompositeConcept::STATEMENTLIST:
		break;
	case CompositeConcept::VARDECL:
		break;
	case CompositeConcept::VARIABLE:
		break;
	case CompositeConcept::WHILE:
		break;
	case CompositeConcept::WRITE:
		break;
	}
}

void SymTabCreationVisitor::visit(GeneralTokenAST* n) {
	switch (n->getToken().getTokenType()) {
	// Types
	case TokenType::INTEGER_ID:
	case TokenType::FLOAT_ID:
	case TokenType::STRING_ID:

	// Literals
	case TokenType::ID:
	case TokenType::FLOAT:
	case TokenType::INTEGER:
	case TokenType::STRING:
	case TokenType::PUBLIC:
	case TokenType::PRIVATE:
	// Relational Operators
	case TokenType::EQUAL_TO:
	case TokenType::NOT_EQUAL_TO:
	case TokenType::LESS_THAN:
	case TokenType::GREATER_THAN:
	case TokenType::LESS_THAN_EQUAL_TO:
	case TokenType::GREATER_THAN_EQUAL_TO:
	// Add Operators
	case TokenType::ADDITION:
	case TokenType::SUBTRACTION:
	case TokenType::OR:
	// Multiplication Operators
	case TokenType::MULTIPLICATION:
	case TokenType::DIVISION:
	case TokenType::AND:
	// Statement types
	case TokenType::BREAK:
	case TokenType::CONTINUE:
	// Assignment
	case TokenType::ASSIGNMENT:

	case TokenType::NOT:
	case TokenType::VOID:
	case TokenType::PERIOD:
		break;
	}
}
