#include "IfAST.h"
#include "Visitor.h"

IfAST::IfAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void IfAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
