#include "ClassDeclBodyListAST.h"
#include "Visitor.h"

ClassDeclBodyListAST::ClassDeclBodyListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassDeclBodyListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
