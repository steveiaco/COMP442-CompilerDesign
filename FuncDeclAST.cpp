#include "FuncDeclAST.h"
#include "Visitor.h"

FuncDeclAST::FuncDeclAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void FuncDeclAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
