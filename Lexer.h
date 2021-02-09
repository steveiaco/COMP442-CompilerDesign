#pragma once
#include "Token.h"
#include <fstream>
#include <regex>
#include <sstream>

using std::stringstream;

class Lexer {
private:
	
	// Input variables and functions
	std::ifstream& input;
	char lastChar;
	char getChar();


	// Atomic helper functions
	bool isAlphaNum(char c);
	bool isLetter(char c);
	bool isDigit(char c);
	bool isNonZero(char c);
	bool isCharacter(char c);


	bool isFraction(char c);

	// Main lexical elements
	
	// Helper functions

	// This function assumes we start at state S11 in our DFA
	// This means we assume that we have already read a ([0-9].)
	Token tryGetFloat(stringstream& s);
public:
	Lexer(std::ifstream &input);
	Token nextToken();
};