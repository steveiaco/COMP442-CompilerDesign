#include "Lexer.h"
#include <iostream>
#include <string>


using std::regex_match;
using std::regex;


bool Lexer::isAlphaNum(char c)
{
	return isLetter(c) || isDigit(c) || c == '_';
}

bool Lexer::isLetter(char c)
{
	return regex_match(&c, regex("[a-zA-Z]"));
}

bool Lexer::isDigit(char c)
{
	return regex_match(&c, regex("[0-9]"));
}

bool Lexer::isNonZero(char c)
{
	return regex_match(&c, regex("[1-9]"));
}

bool Lexer::isCharacter(char c)
{
	return isAlphaNum(c) || c == ' ';
}

bool Lexer::isFloatTerminator(char c)
{
	return false;
}

bool Lexer::isFraction(char c)
{
	return false;
}

Token Lexer::tryGetFloat(stringstream& s)
{
	input.get(lastChar);

	
	// State S11 -> S4
	if (isDigit(lastChar)) {


		// State S4->S4
		if (isNonZero(lastChar)) {
			s.put(lastChar);
			input.get(lastChar);
		}

		// State S4 -> S12
		else if (lastChar == '0') {

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

		// S4 -> S5
		else if (lastChar == 'e') {
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
				return Token(FLOAT, s.str());
			}
			// S5/S6 -> S7
			else if (lastChar == '0') {
				s.put(lastChar);
				input.get(lastChar);

				// TODO - DECIDE WHETHER TO ADD INVALID STATE WHERE THE SYMBOL FOLLOWING A VALID FLOAT IS NOT VALID (maybe look for operators, symbols, punctuation, instead of a non-digit)
				return Token(FLOAT, s.str());
			}
			// Represents invalid state (digit.xxxe)
			else {
				return Token(ERROR, s.str());
			}
		}

	}
	// Represents an invalid state (digit.non-digit)
	else {
		//TODO BE CONSISTENT WITH THIS HANDLING OF ERRONEOUS CHARACTER BEING READ, SHOULD WE INCLUDE IT INTO THE CURRENT LEXEME OR LEAVE IT TO BE READ BY THE NEXT TOKEN CALL?
		s.put(lastChar);
		input.get(lastChar);
		return Token(ERROR, s.str());
	}
}

Lexer::Lexer(std::ifstream& input) : input(input)
{
	lastChar = ' ';
}

Token Lexer::nextToken()
{
	// fastforward the file-read position if we are at a whitespace
	while (lastChar == ' ') {
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
		if (lexeme == "break")			{	return Token(BREAK, lexeme); }
		else if (lexeme == "class")		{	return Token(CLASS, lexeme );	}
		else if (lexeme == "continue")	{	return Token(CONTINUE, lexeme);	}
		else if (lexeme == "else")		{	return Token(ELSE, lexeme);	}
		else if (lexeme == "func")		{	return Token(FUNC, lexeme);	}
		else if (lexeme == "if")		{	return Token(IF, lexeme);	}
		else if (lexeme == "inherits")	{	return Token(INHERITS, lexeme);	}
		else if (lexeme == "main")		{	return Token(MAIN, lexeme);		}
		else if (lexeme == "private")	{	return Token(PRIVATE, lexeme);	}
		else if (lexeme == "public")	{	return Token(PUBLIC, lexeme);	}
		else if (lexeme == "read")		{	return Token(READ, lexeme);		}
		else if (lexeme == "return")	{	return Token(RETURN, lexeme);	}
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
			stringstream stringStream;

			// S2 -> S2
			do {
				stringStream.putback(lastChar);
				input.get(lastChar);
			} while (isDigit(lastChar));

			// S2 -> S11
			if (lastChar == '.') {
				return tryGetFloat(stringStream);
			}
			// S2 -> INT
			else {
				return Token(INTEGER, stringStream.str());
			}
		}
		// START -> S3
		else {
			stringstream stringStream;

			// contains a single 0
			stringStream.putback(lastChar);
			input.get(lastChar);

			// S3 -> S11
			if (lastChar == '.') {
				return tryGetFloat(stringStream);
			}
			// S3 -> INT
			else {
				return Token(INTEGER, stringStream.str());
			}
		}
	} 
	// State S9
	else if (lastChar == '"') {
		stringstream stringStream;

		// S9 -> S9
		do {
			stringStream.putback(lastChar);
			input.get(lastChar);
		} while (lastChar != '"');

		return Token(COMMENT, stringStream.str());
	}

}
