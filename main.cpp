#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"
#include "RecursiveDescentPredictiveParser.h"
#include "Token.h"
#include <vector>
#include <functional>
#include <boost/filesystem.hpp>
#include <regex>
#include "AST.h"
#include "SymTabCreationVisitor.h"

using namespace std;

void writeOutlexErrorFile(vector<Token> tokens, string path) {
	ofstream file(path);

	if (file.fail()) { return; }

	// Print out errors
	for (Token t : tokens) {
		string l = std::regex_replace(t.getLexeme(), std::regex("\n"), "\\n");
		
		switch (t.getTokenType()) {
		case TokenType::INVALID_CHARACTER:
			file << "Lexical error: Invalid character: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case TokenType::INVALID_IDENTIFIER:
			file << "Lexical error: Invalid identifier: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case TokenType::INVALID_NUMBER:
			file << "Lexical error: Invalid number: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case TokenType::INVALID_COMMENT:
			file << "Lexical error: End of file reached before end of comment: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		case TokenType::INVALID_STRING:
			file << "Lexical error: End of file reached before end of string: \"" << l << "\": line " << t.getLineNumber() << "." << endl;
			break;
		}
	}

	file.close();
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

	file.close();
}

void writeASTDotFile(AST* tree, string path) {

	
	ofstream file(path);

	if (file.fail() || !tree) { return; }
	
	string dot = tree->toDotString();

	file << "digraph finite_state_machine{\n";
	file << tree->toDotString();
	file << "}\n";

	file.close();
}

void writeASTSymbolTableFile(AST* tree, string path) {
	AST* progNode = tree->getChild(0);

	ofstream file(path);

	if (file.fail() || !tree) { return; }
	
	string dot = tree->toDotString();

	file << "strict digraph structs {\n";
	file << "\tnode [shape=plaintext]";
	file << progNode->getSymTab()->toDotString();
	file << "}\n";

	file.close();
}


void writeOutStringVector(vector<string> strings, string path) {
	ofstream file(path);

	if (file.fail()) { return; }

	for (string e : strings) {
		file << e << std::endl;
	}

	file.close();
}

int main(int argc, char* argv[]) 
{ 
	if (argc != 2) {
		std::cout << "Error: Please include one parameter.";
		return 0;
	}

	boost::filesystem::path p(argv[1]);

	if (!p.has_filename()) {
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
	string outASTPath = p.parent_path().string() + "\\" + filename + ".outast";
	string outSyntaxErrorsPath = p.parent_path().string() + "\\" + filename + ".outsyntaxerrors";
	string outSyntaxDerivationPath = p.parent_path().string() + "\\" + filename + ".outderivation";
	string outSymbolTablePath = p.parent_path().string() + "\\" + filename + ".outsymboltables";
	string outSemanticErrorsPath = p.parent_path().string() + "\\" + filename + ".outsemanticerrors";

	ifstream file(argv[1]);

	Lexer lexer(file);
	RecursiveDescentPredictiveParser parser(lexer);

	bool parseSuccessful =  parser.parse();
	cout << parseSuccessful;

	vector<Token>& tokens = parser.getTokens();

	SymTabCreationVisitor* symTabCreationVisitor = &SymTabCreationVisitor();

	if (parseSuccessful) {
		parser.getAST()->accept(symTabCreationVisitor);
	}

	writeOutlexErrorFile(tokens, outlexErrorsPath);
	writeOutlexTokensFile(tokens, outlexTokensPath);
	writeASTDotFile(parser.getAST(), outASTPath);
	writeASTSymbolTableFile(parser.getAST(), outSymbolTablePath);
	writeOutStringVector(parser.getSyntaxErrors(), outSyntaxErrorsPath);
	writeOutStringVector(parser.getDerivation(), outSyntaxDerivationPath);
	writeOutStringVector(symTabCreationVisitor->getErrors(), outSemanticErrorsPath);
}
