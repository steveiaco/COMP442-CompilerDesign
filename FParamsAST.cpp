#include "FParamsAST.h"
#include "Visitor.h"

FParamsAST::FParamsAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FParamsAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
