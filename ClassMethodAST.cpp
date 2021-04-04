#include "ClassMethodAST.h"
#include "Visitor.h"

ClassMethodAST::ClassMethodAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassMethodAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
