#include "IfAST.h"
#include "Visitor.h"

IfAST::IfAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void IfAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
