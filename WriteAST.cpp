#include "WriteAST.h"
#include "Visitor.h"

WriteAST::WriteAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void WriteAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
