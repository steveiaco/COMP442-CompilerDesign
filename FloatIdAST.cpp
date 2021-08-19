#include "FloatIdAST.h"
#include <sstream>
FloatIdAST::FloatIdAST(Token token) : TokenAST(token)
{
}

void FloatIdAST::accept(Visitor* visitor, bool handleDepthSearch)
{
}

string FloatIdAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "float: " + getToken().getLexeme() + " (" + ss.str() + ")";
}
