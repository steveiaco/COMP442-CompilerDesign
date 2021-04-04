#include "FuncHeadAST.h"
#include "Visitor.h"

FuncHeadAST::FuncHeadAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncHeadAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
