#include "StatementListAST.h"
#include "Visitor.h"

StatementListAST::StatementListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void StatementListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
