#include "FuncCallStatAST.h"
#include "Visitor.h"

FuncCallStatAST::FuncCallStatAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncCallStatAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
