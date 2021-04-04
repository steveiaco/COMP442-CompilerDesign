#include "PublicAST.h"
#include <sstream>
#include "Visitor.h"

PublicAST::PublicAST(Token token) : TokenAST(token)
{
}

void PublicAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string PublicAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}
