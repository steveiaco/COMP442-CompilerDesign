#include "IntegerAST.h"
#include <sstream>
#include "Visitor.h"

IntegerAST::IntegerAST(Token token) : TokenAST(token)
{
}

string IntegerAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "integer: " + getValue() + " (" + ss.str() + ")";
}

void IntegerAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	visitor->visit(this);
}
