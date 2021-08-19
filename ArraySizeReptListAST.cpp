#include "ArraySizeReptListAST.h"
#include "Visitor.h"

ArraySizeReptListAST::ArraySizeReptListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ArraySizeReptListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
