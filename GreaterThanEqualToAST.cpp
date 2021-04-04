#include "GreaterThanEqualToAST.h"
#include "Visitor.h"
GreaterThanEqualToAST::GreaterThanEqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void GreaterThanEqualToAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
