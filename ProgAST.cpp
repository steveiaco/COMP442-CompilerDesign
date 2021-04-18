#include "ProgAST.h"
#include "Visitor.h"

ProgAST::ProgAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ProgAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
