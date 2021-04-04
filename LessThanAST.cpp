#include "LessThanAST.h"
#include "Visitor.h"
LessThanAST::LessThanAST(Token token) : CompositeConceptTokenAST(token)
{
}

void LessThanAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
