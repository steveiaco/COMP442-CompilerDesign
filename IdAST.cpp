#include "IdAST.h"
#include <sstream>


IdAST::IdAST(Token token) : token(token)
{
	id = token.getLexeme();
}

string IdAST::toString()
{
	std::stringstream ss;
	ss << (void const*)this;
	return "ID: " + id + " (" + ss.str() + ")";
}

void IdAST::setId(string id)
{
	this->id = id;
}

string IdAST::getId()
{
	return id;
}
