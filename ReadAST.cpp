#include "ReadAST.h"
#include "Visitor.h"

ReadAST::ReadAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ReadAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
