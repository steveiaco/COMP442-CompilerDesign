#include "InheritAST.h"
#include "Visitor.h"

InheritAST::InheritAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void InheritAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
