#include "GreaterThanAST.h"
#include "Visitor.h"
GreaterThanAST::GreaterThanAST(Token token) : CompositeConceptTokenAST(token) 
{
}

void GreaterThanAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
