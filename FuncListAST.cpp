#include "FuncListAST.h"
#include "Visitor.h"

FuncListAST::FuncListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
