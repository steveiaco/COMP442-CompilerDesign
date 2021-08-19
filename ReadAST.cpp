#include "ReadAST.h"
#include "Visitor.h"

ReadAST::ReadAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ReadAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
