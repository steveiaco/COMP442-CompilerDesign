#include "AssignStatAST.h"
#include "Visitor.h"

AssignStatAST::AssignStatAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void AssignStatAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
