#include "ArithExprAST.h"
#include "Visitor.h"

ArithExprAST::ArithExprAST(CompositeConcept c) : CompositeConceptAST(c)
{
}

void ArithExprAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
