#include "StartAST.h"
#include "Visitor.h"

StartAST::StartAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void StartAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
