#pragma once
#include <string>

using std::string;

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
	ERROR,
	COMMENT,
	END_OF_FILE	
};

class Token {
private:
	TokenType tokenType;
	string lexeme;
	//datatype location; // location of lexeme in the code

public:
	Token();
	Token(TokenType token, string lexeme);
	inline TokenType getTokenType() const { return tokenType; };
};