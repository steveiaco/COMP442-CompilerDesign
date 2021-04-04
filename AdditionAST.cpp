#include "AdditionAST.h"
#include "Visitor.h"
AdditionAST::AdditionAST(Token token) : CompositeConceptTokenAST(token)
{
}

void AdditionAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
