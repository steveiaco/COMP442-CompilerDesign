#include "NotAST.h"
#include "Visitor.h"
NotAST::NotAST(Token token) : CompositeConceptTokenAST(token)
{
}

void NotAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
