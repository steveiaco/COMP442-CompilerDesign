#include "TernaryAST.h"
#include "Visitor.h"
TernaryAST::TernaryAST(Token token) : CompositeConceptTokenAST(token)
{
}

void TernaryAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
