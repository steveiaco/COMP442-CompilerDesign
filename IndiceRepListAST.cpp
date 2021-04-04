#include "IndiceRepListAST.h"
#include "Visitor.h"

IndiceRepListAST::IndiceRepListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void IndiceRepListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
