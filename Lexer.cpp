#include "Lexer.h"
#include <regex>
#include <iostream>
#include <string>



using std::regex_match;
using std::regex;
using std::string;


void Lexer::getChar()
{
	if (lastChar == '\n') {
		currentLine++;
	}
	
	input.get(lastChar);
	if (input.eof()) {
		lastChar = -1;
	}
}

void Lexer::getChar(stringstream& s) {
	if (lastChar != -1) {
		s << lastChar;
		getChar();
	}
}

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

Token Lexer::tryGetFloat(stringstream& s)
{
	// State S11 -> S4
	if (isDigit(lastChar)) {

		while (isDigit(lastChar)) {
			// State S4->S4
			while (isNonZero(lastChar)) {
				getChar(s);
			}

			// State S4 -> S12
			if (lastChar == '0') {

				// State S12 -> S12
				do {
					getChar(s);
				} while (lastChar == '0');

				// Represents an invalid state (digit.xxZero)
				if (!isNonZero(lastChar)) {
					return Token(INVALID_NUMBER, s.str(), currentLine);
				}

				// Exit represents S12 -> S4
			}
		}

		// S4 -> S5
		if (lastChar == 'e') {
			getChar(s);
			// S5 -> S6
			if (lastChar == '+' || lastChar == '-') {
				getChar(s);
			}

			// S5/S6 -> S8
			if (isNonZero(lastChar)) {
				do {
					getChar(s);
				} while (isDigit(lastChar));
			}
			// S5/S6 -> S7
			else if (lastChar == '0') {
				getChar(s);
				// TODO - DECIDE WHETHER TO ADD INVALID STATE WHERE THE SYMBOL FOLLOWING A VALID FLOAT IS NOT VALID (maybe look for operators, symbols, punctuation, instead of a non-digit)
			}
			// Represents invalid state (digit.xxxe)
			else {
				return Token(INVALID_NUMBER, s.str(), currentLine);
			}
		}
	}
	// Represents an invalid state (digit.non-digit)
	else {
		return Token(INVALID_NUMBER, s.str(), currentLine);
	}

	return Token(FLOAT, s.str(), currentLine);
}

Token Lexer::tryGetIdentifier(stringstream& s)
{
	// Read characters until we encounter a non-alphanum
	do {
		getChar(s);
	} while (isAlphaNum(lastChar));

	string lexeme = s.str();

	// Keywords
	if (lexeme == "break") { return Token(BREAK, lexeme, currentLine); }
	else if (lexeme == "class") { return Token(CLASS, lexeme, currentLine); }
	else if (lexeme == "continue") { return Token(CONTINUE, lexeme, currentLine); }
	else if (lexeme == "else") { return Token(ELSE, lexeme, currentLine); }
	else if (lexeme == "float") { return Token(FLOAT_ID, lexeme, currentLine); }
	else if (lexeme == "func") { return Token(FUNC, lexeme, currentLine); }
	else if (lexeme == "if") { return Token(IF, lexeme, currentLine); }
	else if (lexeme == "inherits") { return Token(INHERITS, lexeme, currentLine); }
	else if (lexeme == "integer") { return Token(INTEGER_ID, lexeme, currentLine); }
	else if (lexeme == "main") { return Token(MAIN, lexeme, currentLine); }
	else if (lexeme == "private") { return Token(PRIVATE, lexeme, currentLine); }
	else if (lexeme == "public") { return Token(PUBLIC, lexeme, currentLine); }
	else if (lexeme == "read") { return Token(READ, lexeme, currentLine); }
	else if (lexeme == "return") { return Token(RETURN, lexeme, currentLine); }
	else if (lexeme == "string") { return Token(STRING_ID, lexeme, currentLine); }
	else if (lexeme == "then") { return Token(THEN, lexeme, currentLine); }
	else if (lexeme == "var") { return Token(VAR, lexeme, currentLine); }
	else if (lexeme == "void") { return Token(VOID, lexeme, currentLine); }
	else if (lexeme == "while") { return Token(WHILE, lexeme, currentLine); }
	else if (lexeme == "write") { return Token(WRITE, lexeme, currentLine); }
	// ID
	else { return Token(ID, lexeme, currentLine); }
}

Lexer::Lexer(std::ifstream& input) : input(input)
{
	lastChar = ' ';
	currentLine = 1;
}

Token Lexer::nextToken()
{
	// fastforward the file-read position if we are at a whitespace
	while (isWhitespace(lastChar)) {
		getChar();
	}

	// State S1
	if (isLetter(lastChar)) {
		stringstream s;

		return tryGetIdentifier(s);
	}
	// States S2/S3
	else if (isDigit(lastChar)) {
		// START -> S2
		if (isNonZero(lastChar)) {
			stringstream s;

			// S2 -> S2
			do {
				getChar(s);
			} while (isDigit(lastChar));

			// S2 -> S11
			if (lastChar == '.') {
				getChar(s);
				return tryGetFloat(s);
			}
			// S2 -> INT
			else {
				return Token(INTEGER, s.str(), currentLine);
			}
		}
		// START -> S3
		else {
			stringstream s;

			// contains a single 0
			getChar(s);

			// S3 -> S11
			if (lastChar == '.') {
				getChar(s);
				return tryGetFloat(s);
			}
			// S3 -> INT
			else {
				return Token(INTEGER, s.str(), currentLine);
			}
		}
	} 
	else {

		TokenType t;
		stringstream s;
		int l = currentLine;

		// First, handle the simple cases
		if (lastChar == '+') { t = ADDITION;	getChar(s); }
		else if (lastChar == '-') { t = SUBTRACTION;	getChar(s); }
		else if (lastChar == '*') { t = MULTIPLICATION; getChar(s); }
		else if (lastChar == '|') { t = OR;				getChar(s); }
		else if (lastChar == '&') { t = AND;			getChar(s); }
		else if (lastChar == '!') { t = NOT;			getChar(s); }
		else if (lastChar == '?') { t = QUESTION_MARK;			getChar(s); }
		else if (lastChar == '(') {	t = LEFT_PARENTHESIS;		getChar(s); }
		else if (lastChar == ')') { t = RIGHT_PARENTHESIS;		getChar(s); }
		else if (lastChar == '{') { t = LEFT_CURLY_BRACKET;		getChar(s); }
		else if (lastChar == '}') { t = RIGHT_CURLY_BRACKET;	getChar(s); }
		else if (lastChar == '[') { t = LEFT_SQUARE_BRACKET;	getChar(s); }
		else if (lastChar == ']') { t = RIGHT_SQUARE_BRACKET;	getChar(s); }
		else if (lastChar == ';') { t = SEMICOLON;				getChar(s); }
		else if (lastChar == ',') { t = COMMA;					getChar(s); }
		else if (lastChar == '.') { t = PERIOD;					getChar(s); }

		// Next, handle the edge cases

		// START -> S9
		else if (lastChar == '"') {

			t = STRING;

			//Skip "
			getChar();

			// S9 -> S9
			while (lastChar != '"' && lastChar != -1) {
				getChar(s);
			}
			
			if (lastChar == -1) {
				t = INVALID_STRING;
			}
			
			//Skip "
			getChar();
		}
		
		// START -> S23
		else if (lastChar == '/') { 

			getChar(s);

			// S23 -> S118 - Line comment
			if (lastChar == '/') {
				t = COMMENT;
				do {
					getChar(s);
				} while (lastChar != '\n' && lastChar != -1);
			}
			// S23 -> S116 - Block comment
			else if (lastChar == '*') {
				t = COMMENT;

				getChar(s);

				int detectedCommentBlocks = 1;

				for (int i = 0; i < detectedCommentBlocks; i++) {
					do {
						// S116 -> S116
						while (lastChar != '*' && lastChar != -1) {

							// Nested block detection
							if (lastChar == '/') {
								getChar(s);
								if (lastChar == '*') {
									detectedCommentBlocks++;
								}
							}
							getChar(s);
						} // Exiting this while loop signifies S116 -> S117

						// S117 -> S117
						while (lastChar == '*') {
							getChar(s);
						}

						// We've reached EOF and must 
						if (lastChar == -1) {
							t = INVALID_COMMENT;
						}
					} while (lastChar != '/' && lastChar != -1);
					// If the while evaluates to true, represents S117 -> S116
					// If the while evaluates to false, represents S117 -> CMT
				}
				getChar(s);
			}
			else {
				t = DIVISION;
				s.put(lastChar); 
			}
		}

		// START -> S13
		else if (lastChar == '=') {
			
			getChar();

			// S13 -> S14
			if (lastChar == '=') {
				getChar();
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

			getChar();

			// S15 -> S16
			if (lastChar == '=') {
				getChar();
				t = LESS_THAN_EQUAL_TO;
				s << "<=";
			}
			// S15 -> S17
			else if (lastChar == '>') {
				getChar();
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
			getChar();

			// S18 -> S19
			if (lastChar == '=') {
				getChar();
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
			getChar();

			// S37 -> S38
			if (lastChar == ':') {
				getChar();
				t = DOUBLE_COLON;
				s << "::";
			}
			else {
				t = COLON;
				s << ':';
			}
		}

		// Identifier that starts with a _
		else if (lastChar == '_') {
			t = INVALID_CHARACTER;
			getChar(s);
		}

		// End of file
		else if (lastChar == -1) {
			t = END_OF_FILE;
		}

		// Invalid alphabet
		else {
			t = INVALID_CHARACTER;
			getChar(s);
		}

		return Token(t, s.str(), l);
	}

}


