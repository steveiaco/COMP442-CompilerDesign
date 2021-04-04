#include "AssignStatAST.h"
#include "Visitor.h"

AssignStatAST::AssignStatAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void AssignStatAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
