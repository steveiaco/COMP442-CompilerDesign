#include "FParamsAST.h"
#include "Visitor.h"

FParamsAST::FParamsAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FParamsAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
