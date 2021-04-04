#include "WriteAST.h"
#include "Visitor.h"

WriteAST::WriteAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void WriteAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
