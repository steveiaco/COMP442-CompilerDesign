#include "ClassDeclBodyListAST.h"
#include "Visitor.h"

ClassDeclBodyListAST::ClassDeclBodyListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassDeclBodyListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
