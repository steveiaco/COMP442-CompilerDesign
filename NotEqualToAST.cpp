#include "NotEqualToAST.h"
#include "Visitor.h"
NotEqualToAST::NotEqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void NotEqualToAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
