#include "InheritListAST.h"
#include "Visitor.h"

InheritListAST::InheritListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void InheritListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
