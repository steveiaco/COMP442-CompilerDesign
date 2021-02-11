#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Token.h"
#include <vector>
#include <functional>
#include <boost/filesystem.hpp>

using namespace std;


int main(int argc, char* argv[]) 
{ 
	if (argc != 2) {
		std::cout << "Please include source file location surrounded by quotations";
		return 0;
	}

	boost::filesystem::path p(argv[1]);

	string filename = p.filename().string();
	string ext = p.extension().string();

	ifstream file(argv[1]);

	Lexer lexer(file);

	vector<Token> tokens;
	
	Token toAdd = lexer.nextToken();

	while (toAdd.getTokenType() != END_OF_FILE) {
		tokens.push_back(toAdd);
		toAdd = lexer.nextToken();
	}

	cout << endl;
	// Print out errors
	for (Token t : tokens) {
		switch (t.getTokenType()) {
		case INVALID_CHARACTER:
			cout << "Lexical error: Invalid character: \"" << t.getLexeme() << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_IDENTIFIER:
			cout << "Lexical error: Invalid identifier: \"" << t.getLexeme() << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_NUMBER:
			cout << "Lexical error: Invalid number: \"" << t.getLexeme() << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_COMMENT:
			cout << "Lexical error: End of file reached before end of comment: \"" << t.getLexeme() << "\": line " << t.getLineNumber() << "." << endl;
		case INVALID_STRING:
			cout << "Lexical error: End of file reached before end of string: \"" << t.getLexeme() << "\": line " << t.getLineNumber() << "." << endl;
		}
	}

	cout << endl;
	// Print out tokens
	int currentLine = -1;
	for (Token t : tokens) {
		if (t.getLineNumber() != currentLine) {
			currentLine = t.getLineNumber();
			cout << endl;
		}
		cout << t;
	}
}
