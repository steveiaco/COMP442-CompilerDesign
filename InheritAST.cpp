#include "InheritAST.h"
#include "Visitor.h"

InheritAST::InheritAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void InheritAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
