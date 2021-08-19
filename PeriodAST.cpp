#include "PeriodAST.h"
#include "Visitor.h"

PeriodAST::PeriodAST(Token t) : CompositeConceptTokenAST(t)
{
}

void PeriodAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
