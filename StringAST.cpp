#include "StringAST.h"
#include <sstream>
#include "Visitor.h"

StringAST::StringAST(Token token) : TokenAST(token)
{
}

string StringAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "string: " + getValue() + " (" + ss.str() + ")";
}

void StringAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	visitor->visit(this);
}
