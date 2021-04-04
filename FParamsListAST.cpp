#include "FParamsListAST.h"
#include "Visitor.h"

FParamsListAST::FParamsListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FParamsListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
