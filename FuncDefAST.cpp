#include "FuncDefAST.h"
#include "Visitor.h"

FuncDefAST::FuncDefAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncDefAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
