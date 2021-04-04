#include "SubtractionAST.h"
#include "Visitor.h"
SubtractionAST::SubtractionAST(Token token) : CompositeConceptTokenAST(token)
{
}

void SubtractionAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
