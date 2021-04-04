#include "ClassDeclBodyAST.h"
#include "Visitor.h"

ClassDeclBodyAST::ClassDeclBodyAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassDeclBodyAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
