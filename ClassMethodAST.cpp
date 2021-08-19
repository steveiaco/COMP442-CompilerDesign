#include "ClassMethodAST.h"
#include "Visitor.h"

ClassMethodAST::ClassMethodAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassMethodAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
