#include "VarDeclListAST.h"
#include "Visitor.h"

VarDeclListAST::VarDeclListAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void VarDeclListAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
