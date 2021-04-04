#include "ProgAST.h"
#include "Visitor.h"

ProgAST::ProgAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ProgAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
