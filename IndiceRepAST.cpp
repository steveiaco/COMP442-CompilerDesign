#include "IndiceRepAST.h"
#include "Visitor.h"

IndiceRepAST::IndiceRepAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void IndiceRepAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
