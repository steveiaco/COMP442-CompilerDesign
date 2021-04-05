#include "TokenAST.h"
#include <sstream>

TokenAST::TokenAST(Token token) : token(token)
{
}

Token TokenAST::getToken()
{
	return token;
}

std::string TokenAST::getValue()
{
	return token.getLexeme();
}

string TokenAST::getData()
{
	return token.getLexeme();
}
