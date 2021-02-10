#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Token.h"
#include <vector>

using namespace std;


int main(int argc, char* argv[]) 
{ 
	if (argc != 2) {
		std::cout << "Please include source file location surrounded by quotations";
		return 0;
	}

	std::cout << argv[1];

	ifstream file(argv[1]);

	Lexer lexer(file);

	vector<Token> tokens;
	
	Token toAdd = lexer.nextToken();

	while (toAdd.getTokenType() != END_OF_FILE) {
		tokens.push_back(toAdd);
		toAdd = lexer.nextToken();
	}
}