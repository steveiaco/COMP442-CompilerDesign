#include "Lexer.h"
#include <iostream>
#include <string>


using std::regex_match;
using std::regex;
using std::string;


bool Lexer::isAlphaNum(char c)
{
	return isLetter(c) || isDigit(c) || c == '_';
}

bool Lexer::isLetter(char c)
{
	return regex_match(string(1, c), regex("[a-zA-Z]"));
}

bool Lexer::isDigit(char c)
{
	return regex_match(string(1, c), regex("[0-9]"));
}

bool Lexer::isNonZero(char c)
{
	return regex_match(string(1, c), regex("[1-9]"));
}

bool Lexer::isCharacter(char c)
{
	return isAlphaNum(c) || c == ' ';
}

bool Lexer::isWhitespace(char c)
{
	return regex_match(string(1, c), regex("[\\s\\n]"));
}

bool Lexer::isFraction(char c)
{
	return false;
}

Token Lexer::generateError(stringstream& s)
{
	return Token(ERROR, s.str());
}

Token Lexer::tryGetFloat(stringstream& s)
{
	// State S11 -> S4
	if (isDigit(lastChar)) {

		while (isDigit(lastChar)) {
			// State S4->S4
			while (isNonZero(lastChar)) {
				s.put(lastChar);
				input.get(lastChar);
			}

			// State S4 -> S12
			if (lastChar == '0') {

				// State S12 -> S12
				do {
					s.put(lastChar);
					input.get(lastChar);
				} while (lastChar == '0');

				// Represents an invalid state (digit.xxZero)
				if (!isNonZero(lastChar)) {
					return Token(ERROR, s.str());
				}

				// Exit represents S12 -> S4
			}
		}

		// S4 -> S5
		if (lastChar == 'e') {
			s.put(lastChar);
			input.get(lastChar);

			// S5 -> S6
			if (lastChar == '+' || lastChar == '-') {
				s.put(lastChar);
				input.get(lastChar);
			}

			// S5/S6 -> S8
			if (isNonZero(lastChar)) {
				do {
					s.put(lastChar);
					input.get(lastChar);
				} while (isDigit(lastChar));
				// TODO - DECIDE WHETHER TO ADD INVALID STATE WHERE THE SYMBOL FOLLOWING A VALID FLOAT IS NOT VALID (maybe look for operators, symbols, punctuation, instead of a non-digit)
			}
			// S5/S6 -> S7
			else if (lastChar == '0') {
				s.put(lastChar);
				input.get(lastChar);
				// TODO - DECIDE WHETHER TO ADD INVALID STATE WHERE THE SYMBOL FOLLOWING A VALID FLOAT IS NOT VALID (maybe look for operators, symbols, punctuation, instead of a non-digit)
			}
			// Represents invalid state (digit.xxxe)
			else {
				return generateError(s);
			}
		}
	}
	// Represents an invalid state (digit.non-digit)
	else {
		return generateError(s);
	}

	return Token(FLOAT, s.str());
}

Lexer::Lexer(std::ifstream& input) : input(input)
{
	lastChar = ' ';
}

Token Lexer::nextToken()
{
	// fastforward the file-read position if we are at a whitespace
	while (isWhitespace(lastChar)) {
		input.get(lastChar);
	}

	// State S1
	if (isLetter(lastChar)) {
		stringstream stringStream;

		// Read characters until we encounter a non-alphanum
		do {
			stringStream.put(lastChar);
			input.get(lastChar);
		} while (isAlphaNum(lastChar));

		string lexeme = stringStream.str();
		
		// Keywords
		if (lexeme == "break")			{	return Token(BREAK, lexeme);	}
		else if (lexeme == "class")		{	return Token(CLASS, lexeme );	}
		else if (lexeme == "continue")	{	return Token(CONTINUE, lexeme);	}
		else if (lexeme == "else")		{	return Token(ELSE, lexeme);		}
		else if (lexeme == "float")		{	return Token(FLOAT_ID, lexeme);	}
		else if (lexeme == "func")		{	return Token(FUNC, lexeme);		}
		else if (lexeme == "if")		{	return Token(IF, lexeme);		}
		else if (lexeme == "inherits")	{	return Token(INHERITS, lexeme);	}
		else if (lexeme == "integer")	{	return Token(INTEGER_ID, lexeme);	}
		else if (lexeme == "main")		{	return Token(MAIN, lexeme);		}
		else if (lexeme == "private")	{	return Token(PRIVATE, lexeme);	}
		else if (lexeme == "public")	{	return Token(PUBLIC, lexeme);	}
		else if (lexeme == "read")		{	return Token(READ, lexeme);		}
		else if (lexeme == "return")	{	return Token(RETURN, lexeme);	}
		else if (lexeme == "string")	{	return Token(STRING_ID, lexeme);}
		else if (lexeme == "then")		{	return Token(THEN, lexeme);		}
		else if (lexeme == "var")		{	return Token(VAR, lexeme);		}
		else if (lexeme == "void")		{	return Token(VOID, lexeme);		}
		else if (lexeme == "while")		{	return Token(WHILE, lexeme);	}
		else if (lexeme == "write")		{	return Token(WRITE, lexeme);	}
		// ID
		else { return Token(ID, lexeme); }
	}
	// States S2/S3
	else if (isDigit(lastChar)) {
		// START -> S2
		if (isNonZero(lastChar)) {
			stringstream s;

			// S2 -> S2
			do {
				s << lastChar;
				input.get(lastChar);
			} while (isDigit(lastChar));

			// S2 -> S11
			if (lastChar == '.') {
				s << lastChar;
				input.get(lastChar);
				return tryGetFloat(s);
			}
			// S2 -> INT
			else {
				return Token(INTEGER, s.str());
			}
		}
		// START -> S3
		else {
			stringstream s;

			// contains a single 0
			s << lastChar;
			input.get(lastChar);

			// S3 -> S11
			if (lastChar == '.') {
				s << lastChar;
				input.get(lastChar);
				return tryGetFloat(s);
			}
			// S3 -> INT
			else {
				return Token(INTEGER, s.str());
			}
		}
	} 
	else {

		TokenType t;
		stringstream s;

		// First, handle the simple cases
		if (lastChar == '+') { t = ADDITION;	s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '-') { t = SUBTRACTION;	s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '*') { t = MULTIPLICATION; s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '|') { t = OR;				s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '&') { t = AND;			s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '!') { t = NOT;			s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '?') { t = QUESTION_MARK;			s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '(') {	t = LEFT_PARENTHESIS;		s.put(lastChar); input.get(lastChar); }
		else if (lastChar == ')') { t = RIGHT_PARENTHESIS;		s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '{') { t = LEFT_CURLY_BRACKET;		s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '}') { t = RIGHT_CURLY_BRACKET;	s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '[') { t = LEFT_SQUARE_BRACKET;	s.put(lastChar); input.get(lastChar); }
		else if (lastChar == ']') { t = RIGHT_SQUARE_BRACKET;	s.put(lastChar); input.get(lastChar); }
		else if (lastChar == ';') { t = SEMICOLON;				s.put(lastChar); input.get(lastChar); }
		else if (lastChar == ',') { t = COMMA;					s.put(lastChar); input.get(lastChar); }
		else if (lastChar == '.') { t = PERIOD;					s.put(lastChar); input.get(lastChar); }

		// Next, handle the edge cases

		// START -> S9
		else if (lastChar == '"') {

			t = STRING;

			// S9 -> S9
			do {
				s << lastChar;
				input.get(lastChar);
			} while (lastChar != '"');

			// Append the "
			s.put(lastChar);
			input.get(lastChar);
		}
		
		// START -> S23
		else if (lastChar == '/') { 

			s << lastChar;
			input.get(lastChar); 

			// S23 -> S118 - Line comment
			if (lastChar == '/') {
				t = COMMENT;
				do {
					s << lastChar;
					input.get(lastChar);
				} while (lastChar != '\n');
			}
			// S23 -> S116 - Block comment
			else if (lastChar == '*') {
				t = COMMENT;

			}
			else {
				t = DIVISION;
				s.put(lastChar); 
			}
		}

		// START -> S13
		else if (lastChar == '=') {
			
			input.get(lastChar);

			// S13 -> S14
			if (lastChar == '=') {
				input.get(lastChar);
				t = EQUAL_TO;
				s << "==";
			}
			else {
				t = ASSIGNMENT;
				s << '=';
			}
		}
		
		// START -> S15
		else if (lastChar == '<') {

			input.get(lastChar);

			// S15 -> S16
			if (lastChar == '=') {
				input.get(lastChar);
				t = LESS_THAN_EQUAL_TO;
				s << "<=";
			}
			// S15 -> S17
			else if (lastChar == '>') {
				input.get(lastChar);
				t = NOT_EQUAL_TO;
				s << "<>";
			}
			else {
				t = LESS_THAN;
				s << '<';
			}
		}

		// START -> S18
		else if (lastChar == '>') {
			input.get(lastChar);

			// S18 -> S19
			if (lastChar == '=') {
				input.get(lastChar);
				t = GREATER_THAN_EQUAL_TO;
				s << ">=";
			}
			else {
				t = GREATER_THAN;
				s << '>';
			}
		}

		// START -> S37
		else if (lastChar == ':') {
			input.get(lastChar);

			// S37 -> S38
			if (lastChar == ':') {
				input.get(lastChar);
				t = DOUBLE_COLON;
				s << "::";
			}
			else {
				t = COLON;
				s << ':';
			}
		}

		// Invalid alphabet
		else {
			t = ERROR;
			s << lastChar;
			input.get(lastChar);
		}

		return Token(t, s.str());
	}

}
