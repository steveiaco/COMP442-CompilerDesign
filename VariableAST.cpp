#include "VariableAST.h"
#include "Visitor.h"

VariableAST::VariableAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VariableAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
