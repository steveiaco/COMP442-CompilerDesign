#include "IntegerIdAST.h"
#include <sstream>

IntegerIdAST::IntegerIdAST(Token t) : TokenAST(t)
{
}

string IntegerIdAST::toString()
{
	std::stringstream ss;
	ss << "integer";
	ss << (void const*)this;
	return ss.str();
}

void IntegerIdAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}
