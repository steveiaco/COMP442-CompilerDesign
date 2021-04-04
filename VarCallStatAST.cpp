#include "VarCallStatAST.h"
#include "Visitor.h"

VarCallStatAST::VarCallStatAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VarCallStatAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
