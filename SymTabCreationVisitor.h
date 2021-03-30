#pragma once
#include "Visitor.h"
class SymTabCreationVisitor : public Visitor
{
private:
	// visitor functions
	void visit_VARDECL(CompositeConceptAST* n);

	void visit(CompositeConceptAST* n);
	void visit(GeneralTokenAST* n);

public:
	SymTabCreationVisitor();
};

