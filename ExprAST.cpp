#include "ExprAST.h"
#include "Visitor.h"

ExprAST::ExprAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ExprAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
