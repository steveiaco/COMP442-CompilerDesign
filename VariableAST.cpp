#include "VariableAST.h"
#include "Visitor.h"

VariableAST::VariableAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VariableAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
