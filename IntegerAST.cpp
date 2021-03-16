#include "IntegerAST.h"
#include <sstream>

IntegerAST::IntegerAST(Token token) : token(token)
{
	value = token.getLexeme();
}

string IntegerAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "integer: " + value + " (" + ss.str() + ")";
}

void IntegerAST::setValue(string value)
{
	this->value = value;
}

string IntegerAST::getValue()
{
	return value;
}
