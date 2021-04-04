#include "ArrayDimensionAST.h"
#include "Visitor.h"

ArrayDimensionAST::ArrayDimensionAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ArrayDimensionAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
