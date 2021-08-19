#pragma once
#include <string>
#include <ostream>
#include "EnumDeclarations.h"

using std::string;
using std::ostream;

class Token {
private:
	TokenType tokenType;
	string lexeme;
	int lineNumber;
	//datatype location; // location of lexeme in the code

public:
	static string tokenToString(TokenType t);
	Token();
	Token(TokenType token, string lexeme, int line);

	static string tokenToString(Token t);

	inline TokenType getTokenType() const { return tokenType; };
	inline void setTokenType(TokenType t) { tokenType = t; }
	inline string getLexeme() const { return lexeme; }
	inline int getLineNumber() const { return lineNumber; }

};

ostream& operator<<(ostream& os, Token& t);