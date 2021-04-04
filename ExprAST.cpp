#include "ExprAST.h"
#include "Visitor.h"

ExprAST::ExprAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ExprAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
