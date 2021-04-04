#include "StartAST.h"
#include "Visitor.h"

StartAST::StartAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void StartAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
