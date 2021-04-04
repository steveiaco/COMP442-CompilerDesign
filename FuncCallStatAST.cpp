#include "FuncCallStatAST.h"
#include "Visitor.h"

FuncCallStatAST::FuncCallStatAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncCallStatAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
