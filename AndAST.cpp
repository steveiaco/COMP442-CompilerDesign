#include "AndAST.h"
#include "Visitor.h"
AndAST::AndAST(Token token) : CompositeConceptTokenAST(token)
{
}

void AndAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
