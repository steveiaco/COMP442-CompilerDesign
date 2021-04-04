#include "StatementAST.h"
#include "Visitor.h"

StatementAST::StatementAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void StatementAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
