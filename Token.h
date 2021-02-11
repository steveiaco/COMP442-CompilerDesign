#pragma once
#include <string>
#include <ostream>

using std::string;
using std::ostream;

enum TokenType {
	ID,
	// Types
	INTEGER,
	FLOAT,
	STRING,
	// Keywords
	INTEGER_ID,
	FLOAT_ID,
	STRING_ID,
	IF,
	THEN,
	ELSE,
	VOID,
	PUBLIC,
	PRIVATE,
	FUNC,
	VAR,
	CLASS,
	WHILE,
	READ,
	WRITE,
	RETURN,
	MAIN,
	INHERITS,
	BREAK,
	CONTINUE,
	// Separators
	LEFT_SQUARE_BRACKET,
	RIGHT_SQUARE_BRACKET,
	LEFT_CURLY_BRACKET,
	RIGHT_CURLY_BRACKET,
	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,
	SEMICOLON,
	COMMA,
	PERIOD,
	COLON,
	DOUBLE_COLON,
	QUOTE,
	// Operators
	EQUAL_TO,	// ==
	NOT_EQUAL_TO,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_EQUAL_TO,
	GREATER_THAN_EQUAL_TO,
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	ASSIGNMENT, // =
	OR,
	AND,
	NOT, //!
	QUESTION_MARK, //? TO BE RENAMED
	// Other
	INVALID_CHARACTER,
	INVALID_NUMBER,
	INVALID_IDENTIFIER,
	INVALID_COMMENT,
	INVALID_STRING,
	UNDEFINED,
	COMMENT,
	END_OF_FILE	
};

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