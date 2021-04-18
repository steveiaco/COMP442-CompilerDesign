#include "FuncBodyAST.h"
#include "Visitor.h"

FuncBodyAST::FuncBodyAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncBodyAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
