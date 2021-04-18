#include "ReturnAST.h"
#include "Visitor.h"

ReturnAST::ReturnAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ReturnAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
