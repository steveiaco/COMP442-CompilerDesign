#include "LessThanAST.h"
#include "Visitor.h"
LessThanAST::LessThanAST(Token token) : CompositeConceptTokenAST(token)
{
}

void LessThanAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
