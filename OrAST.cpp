#include "OrAST.h"
#include "Visitor.h"
OrAST::OrAST(Token token) : CompositeConceptTokenAST(token)
{
}

void OrAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
