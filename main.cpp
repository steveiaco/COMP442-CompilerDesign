#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Token.h"
#include <vector>
#include <functional>
#include <boost/filesystem.hpp>
#include <regex>

using namespace std;

void writeOutlexErrorFile(vector<Token> tokens, string path) {
	ofstream file(path);

	if (file.fail()) { return; }

	// Print out errors
	for (Token t : tokens) {
		string l = std::regex_replace(t.getLexeme(), std::regex("\n"), "\\n");
		
		switch (t.getTokenType()) {
		case INVALID_CHARACTER:
			file << "Lexical error: Invalid character: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_IDENTIFIER:
			file << "Lexical error: Invalid identifier: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_NUMBER:
			file << "Lexical error: Invalid number: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_COMMENT:
			file << "Lexical error: End of file reached before end of comment: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case INVALID_STRING:
			file << "Lexical error: End of file reached before end of string: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		}
	}
}

void writeOutlexTokensFile(vector<Token> tokens, string path) {
	ofstream file(path);

	if (file.fail()) { return; }

	// Print out tokens
	int currentLine = 1;
	for (Token t : tokens) {
		if (t.getLineNumber() != currentLine) {
			currentLine = t.getLineNumber();
			file << endl;
		}
		file << t;
	}
}

int main(int argc, char* argv[]) 
{ 
	boost::filesystem::path p(argv[1]);

	if (argc != 2 || !p.has_filename()) {
		std::cout << "Error: Please include source file location.";
		return 0;
	}

	string filename = p.stem().string();
	string ext = p.extension().string();

	if (ext != ".src") {
		cout << "Error: Invalid file extension, this application only support .src source files.";
		return 0;
	}

	string outlexErrorsPath = p.parent_path().string() + "\\" + filename + ".outlexerrors";
	string outlexTokensPath = p.parent_path().string() + "\\" + filename + ".outlextokens";

	ifstream file(argv[1]);

	Lexer lexer(file);

	vector<Token> tokens;

	Token toAdd = lexer.nextToken();
	while (toAdd.getTokenType() != END_OF_FILE) {
		tokens.push_back(toAdd);
		toAdd = lexer.nextToken();
	}

	writeOutlexErrorFile(tokens, outlexErrorsPath);
	writeOutlexTokensFile(tokens, outlexTokensPath);
}
