#include "FuncHeadAST.h"
#include "Visitor.h"

FuncHeadAST::FuncHeadAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncHeadAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
