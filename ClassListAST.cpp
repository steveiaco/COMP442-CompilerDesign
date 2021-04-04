#include "ClassListAST.h"
#include "Visitor.h"

ClassListAST::ClassListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
