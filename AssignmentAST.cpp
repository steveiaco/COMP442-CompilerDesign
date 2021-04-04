#include "AssignmentAST.h"
#include "Visitor.h"
AssignmentAST::AssignmentAST(Token token) : CompositeConceptTokenAST(token)
{
}

void AssignmentAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
