#include "EqualToAST.h"
#include <sstream>
#include "Visitor.h"
EqualToAST::EqualToAST(Token token) : CompositeConceptTokenAST(token)
{
}

void EqualToAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	CompositeConceptTokenAST::accept(visitor, handleDepthSearch);
	visitor->visit(this);
}
