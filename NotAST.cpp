#include "NotAST.h"
#include "Visitor.h"
NotAST::NotAST(Token token) : CompositeConceptTokenAST(token)
{
}

void NotAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
