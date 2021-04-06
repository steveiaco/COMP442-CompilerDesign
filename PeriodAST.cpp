#include "PeriodAST.h"
#include "Visitor.h"

PeriodAST::PeriodAST(Token t) : CompositeConceptTokenAST(t)
{
}

void PeriodAST::accept(Visitor* visitor)
{
	// don't go deeper, we only want to access the top level "."
	visitor->visit(this);
}
