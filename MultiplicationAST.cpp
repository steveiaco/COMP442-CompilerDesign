#include "MultiplicationAST.h"
#include "Visitor.h"
MultiplicationAST::MultiplicationAST(Token token) : CompositeConceptTokenAST(token)
{
}

void MultiplicationAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
