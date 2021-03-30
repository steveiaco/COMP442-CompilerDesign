#include "ContinueAST.h"
#include <sstream>

ContinueAST::ContinueAST(Token token) : TokenAST(token)
{
}

void ContinueAST::accept(Visitor* visitor)
{
	visitor->visit(this);
}

string ContinueAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}
