#include "DivisionAST.h"
#include "Visitor.h"
DivisionAST::DivisionAST(Token token) : CompositeConceptTokenAST(token)
{
}

void DivisionAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
