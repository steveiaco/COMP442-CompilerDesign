#include "PrivateAST.h"
#include <sstream>

PrivateAST::PrivateAST(Token token) : TokenAST(token)
{
}

void PrivateAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string PrivateAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}