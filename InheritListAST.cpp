#include "InheritListAST.h"
#include "Visitor.h"

InheritListAST::InheritListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void InheritListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
