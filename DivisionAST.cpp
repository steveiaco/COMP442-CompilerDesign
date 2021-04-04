#include "DivisionAST.h"
#include "Visitor.h"
DivisionAST::DivisionAST(Token token) : CompositeConceptTokenAST(token)
{
}

void DivisionAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
