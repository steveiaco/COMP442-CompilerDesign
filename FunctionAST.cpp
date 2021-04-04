#include "FunctionAST.h"
#include "Visitor.h"

FunctionAST::FunctionAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FunctionAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
