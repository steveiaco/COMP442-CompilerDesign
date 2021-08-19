#include "FunctionAST.h"
#include "Visitor.h"

FunctionAST::FunctionAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FunctionAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
