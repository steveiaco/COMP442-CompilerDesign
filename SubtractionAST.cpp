#include "SubtractionAST.h"
#include "Visitor.h"
SubtractionAST::SubtractionAST(Token token) : CompositeConceptTokenAST(token)
{
}

void SubtractionAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
