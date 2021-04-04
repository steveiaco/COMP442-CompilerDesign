#include "ArithExprAST.h"
#include "Visitor.h"

ArithExprAST::ArithExprAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ArithExprAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
