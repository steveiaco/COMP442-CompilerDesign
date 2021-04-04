#include "ReturnAST.h"
#include "Visitor.h"

ReturnAST::ReturnAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ReturnAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
