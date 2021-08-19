#include "AdditionAST.h"
#include "Visitor.h"
AdditionAST::AdditionAST(Token token) : CompositeConceptTokenAST(token)
{
}

void AdditionAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
