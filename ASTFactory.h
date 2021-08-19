#pragma once
#include "Token.h"
#include "AST.h"
#include "RecursiveDescentPredictiveParser.h"
#include <variant>

// Atomic Concepts
#include <vector>

using std::vector;
using std::shared_ptr;

class ASTFactory {
private:
	static vector<AST*> treesProduced;
public:
	// Node of specific type
	static AST* makeNode(Token t);
	static AST* makeNode(CompositeConcept t);

	// generates a family with n children under a parent operator
	static AST* makeFamily(CompositeConcept t, vector<AST*> children);
	static void makeFamily(AST* parent, vector<AST*> children);
};