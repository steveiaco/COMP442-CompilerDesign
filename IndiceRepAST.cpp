#include "IndiceRepAST.h"
#include "Visitor.h"

IndiceRepAST::IndiceRepAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void IndiceRepAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
