#include "AssignmentAST.h"
#include "Visitor.h"
AssignmentAST::AssignmentAST(Token token) : CompositeConceptTokenAST(token)
{
}

void AssignmentAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
