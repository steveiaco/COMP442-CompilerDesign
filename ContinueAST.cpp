#include "ContinueAST.h"
#include <sstream>
#include "Visitor.h"

ContinueAST::ContinueAST(Token token) : TokenAST(token)
{
}

void ContinueAST::accept(Visitor* visitor, bool handleDepthSearch)
{
	visitor->visit(this);
}

string ContinueAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return getValue() + " (" + ss.str() + ")";
}
