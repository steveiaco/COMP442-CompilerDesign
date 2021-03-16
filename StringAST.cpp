#include "StringAST.h"
#include <sstream>

StringAST::StringAST(Token token) : token(token)
{
	str = token.getLexeme();
}

string StringAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "string: " + str + " (" + ss.str() + ")";
}
