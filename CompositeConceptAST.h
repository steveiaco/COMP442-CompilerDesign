#pragma once

#include "AST.h"
#include "EnumDeclarations.h"
#include <string>

using std::string;

class CompositeConceptAST : public AST {
	CompositeConcept cconcept;
public:
	CompositeConceptAST(CompositeConcept t);
	string toString();
	CompositeConcept getCompositeConcept();

	// Inherited via AST
	virtual void accept(Visitor* visitor) override;
};