#include "VarDeclAST.h"
#include "Visitor.h"

VarDeclAST::VarDeclAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VarDeclAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
