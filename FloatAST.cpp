#include "FloatAST.h"
#include <sstream>

FloatAST::FloatAST(Token token) : token(token)
{
	flt = token.getLexeme();
}

string FloatAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "float: " + flt + " (" + ss.str() + ")";
}
