#include "MultiplicationAST.h"
#include "Visitor.h"
MultiplicationAST::MultiplicationAST(Token token) : CompositeConceptTokenAST(token)
{
}

void MultiplicationAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
