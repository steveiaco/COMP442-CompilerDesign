#include "OrAST.h"
#include "Visitor.h"
OrAST::OrAST(Token token) : CompositeConceptTokenAST(token)
{
}

void OrAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
