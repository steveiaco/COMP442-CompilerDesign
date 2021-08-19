#include "ArrayDimensionAST.h"
#include "Visitor.h"

ArrayDimensionAST::ArrayDimensionAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ArrayDimensionAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
