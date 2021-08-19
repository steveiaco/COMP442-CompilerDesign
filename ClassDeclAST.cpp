#include "ClassDeclAST.h"
#include "Visitor.h"

ClassDeclAST::ClassDeclAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassDeclAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
