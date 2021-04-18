#include "ClassListAST.h"
#include "Visitor.h"

ClassListAST::ClassListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
