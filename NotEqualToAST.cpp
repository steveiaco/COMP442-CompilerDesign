#include "NotEqualToAST.h"
#include "Visitor.h"
NotEqualToAST::NotEqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void NotEqualToAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
