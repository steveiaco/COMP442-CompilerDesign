#include "EqualToAST.h"
#include <sstream>
#include "Visitor.h"
EqualToAST::EqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void EqualToAST::accept(Visitor* visitor)
{
	CompositeConceptTokenAST::accept(visitor);
	visitor->visit(this);
}
