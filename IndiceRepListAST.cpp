#include "IndiceRepListAST.h"
#include "Visitor.h"

IndiceRepListAST::IndiceRepListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void IndiceRepListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
