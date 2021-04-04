#include "LessThanEqualToAST.h"
#include "Visitor.h"
LessThanEqualToAST::LessThanEqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void LessThanEqualToAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
