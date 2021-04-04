#include "VarDeclListAST.h"
#include "Visitor.h"

VarDeclListAST::VarDeclListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VarDeclListAST::accept(Visitor* visitor)
{
	CompositeConceptAST::accept(visitor);
	visitor->visit(this);
}
