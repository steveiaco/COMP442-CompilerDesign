#include "FParamsListAST.h"
#include "Visitor.h"

FParamsListAST::FParamsListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FParamsListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
