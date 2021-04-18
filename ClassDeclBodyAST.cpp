#include "ClassDeclBodyAST.h"
#include "Visitor.h"

ClassDeclBodyAST::ClassDeclBodyAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassDeclBodyAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
