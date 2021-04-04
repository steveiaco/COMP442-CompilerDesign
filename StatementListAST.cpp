#include "StatementListAST.h"
#include "Visitor.h"

StatementListAST::StatementListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void StatementListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
