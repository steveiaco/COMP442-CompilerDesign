#include "VoidAST.h"
#include <sstream>
VoidAST::VoidAST(Token token) : TokenAST(token)
{
}

void VoidAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string VoidAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}