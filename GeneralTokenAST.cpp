#include "GeneralTokenAST.h"
#include <sstream>

GeneralTokenAST::GeneralTokenAST(Token token) : token(token)
{
	id = token.getLexeme();
}

string GeneralTokenAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return id + " (" + ss.str() + ")";
}
