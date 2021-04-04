#include "FuncListAST.h"
#include "Visitor.h"

FuncListAST::FuncListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
