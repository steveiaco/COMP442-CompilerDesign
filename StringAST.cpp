#include "StringAST.h"
#include <sstream>

StringAST::StringAST(Token token) : TokenAST(token)
{
}

string StringAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "string: " + getValue() + " (" + ss.str() + ")";
}

void StringAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}
