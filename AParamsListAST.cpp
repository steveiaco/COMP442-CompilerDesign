#include "AParamsListAST.h"
#include "Visitor.h"

AParamsListAST::AParamsListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void AParamsListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
