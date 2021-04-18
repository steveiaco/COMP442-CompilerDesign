#include "GreaterThanAST.h"
#include "Visitor.h"
GreaterThanAST::GreaterThanAST(Token token) : CompositeConceptTokenAST(token)
{
}

void GreaterThanAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
