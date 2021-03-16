#include "VisibilityAST.h"
#include <sstream>

VisibilityAST::VisibilityAST(Token token) : token(token)
{
	vis = token.getLexeme();
}

string VisibilityAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "visiblity: " + vis + " (" + ss.str() + ")";
}
