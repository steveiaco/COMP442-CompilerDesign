#include "WhileAST.h"
#include "Visitor.h"

WhileAST::WhileAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void WhileAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
