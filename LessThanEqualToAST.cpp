#include "LessThanEqualToAST.h"
#include "Visitor.h"
LessThanEqualToAST::LessThanEqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void LessThanEqualToAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
