#include "VarDeclAST.h"
#include "Visitor.h"

VarDeclAST::VarDeclAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VarDeclAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
