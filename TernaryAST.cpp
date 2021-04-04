#include "TernaryAST.h"
#include "Visitor.h"
TernaryAST::TernaryAST(Token token) : CompositeConceptTokenAST(token)
{
}

void TernaryAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
