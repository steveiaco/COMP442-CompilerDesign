#include "ClassDeclAST.h"
#include "Visitor.h"

ClassDeclAST::ClassDeclAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ClassDeclAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
