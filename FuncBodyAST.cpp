#include "FuncBodyAST.h"
#include "Visitor.h"

FuncBodyAST::FuncBodyAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncBodyAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
