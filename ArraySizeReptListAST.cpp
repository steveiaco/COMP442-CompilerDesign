#include "ArraySizeReptListAST.h"
#include "Visitor.h"

ArraySizeReptListAST::ArraySizeReptListAST(CompositeConceptAST c) : CompositeConceptAST(c)
{
}

void ArraySizeReptListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
