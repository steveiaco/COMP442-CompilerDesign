#include "StatementAST.h"
#include "Visitor.h"

StatementAST::StatementAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void StatementAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
