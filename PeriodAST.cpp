#include "PeriodAST.h"
#include "Visitor.h"

PeriodAST::PeriodAST(Token t) : CompositeConceptTokenAST(t)
{
}

void PeriodAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
