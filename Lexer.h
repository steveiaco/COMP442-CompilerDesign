#pragma once
#include "Token.h"
#include <fstream>
#include <sstream>

using std::stringstream;
using std::ifstream;

class Lexer {
private:
	
	// Input variables and functions
	std::ifstream& input;
	char lastChar;
	int currentLine;
	void getChar();
	void getChar(stringstream& s);


	// Atomic helper functions
	bool isAlphaNum(char c);
	bool isLetter(char c);
	bool isDigit(char c);
	bool isNonZero(char c);
	bool isCharacter(char c);
	bool isWhitespace(char c);
	bool isFraction(char c);
	
	// Helper functions

	// This function assumes we start at state S11 in our DFA
	// This means we assume that we have already read a ([0-9].)
	Token tryGetFloat(stringstream& s);
	Token tryGetIdentifier(stringstream& s);
public:
	Lexer(ifstream &input);
	Token nextToken();
};