#include "AParamsListAST.h"
#include "Visitor.h"

AParamsListAST::AParamsListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void AParamsListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
