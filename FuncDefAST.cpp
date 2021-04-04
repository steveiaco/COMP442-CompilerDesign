#include "FuncDefAST.h"
#include "Visitor.h"

FuncDefAST::FuncDefAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncDefAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
