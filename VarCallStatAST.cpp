#include "VarCallStatAST.h"
#include "Visitor.h"

VarCallStatAST::VarCallStatAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VarCallStatAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
