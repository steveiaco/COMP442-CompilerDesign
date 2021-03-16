#pragma once

#include "AST.h"
#include "EnumDeclarations.h"
#include <string>

using std::string;

class CompositeConceptAST : public AST {
	CompositeConcept concept;
public:
	CompositeConceptAST(CompositeConcept t);
	string toString();
};