#include "GreaterThanEqualToAST.h"
#include "Visitor.h"
GreaterThanEqualToAST::GreaterThanEqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void GreaterThanEqualToAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
