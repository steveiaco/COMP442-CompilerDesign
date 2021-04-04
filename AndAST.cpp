#include "AndAST.h"
#include "Visitor.h"
AndAST::AndAST(Token token) : CompositeConceptTokenAST(token)
{
}

void AndAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
