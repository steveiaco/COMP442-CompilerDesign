#include "WhileAST.h"
#include "Visitor.h"

WhileAST::WhileAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void WhileAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
