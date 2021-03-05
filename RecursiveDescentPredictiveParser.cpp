#include "RecursiveDescentPredictiveParser.h"

bool RecursiveDescentPredictiveParser::match(TokenType t)
{
	if (lookAhead.getTokenType() == t) {
		lookAhead = lexer.nextToken();
		return true;
	}
	else {
		lookAhead = lexer.nextToken();
		return false;
	}
}

void RecursiveDescentPredictiveParser::generateFirstSet()
{
	firstSet = {
		{NonTerminal::ADDOP, {TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR}},
		{NonTerminal::APARAMSTAIL, {TokenType::COMMA}},
	}
}

void RecursiveDescentPredictiveParser::generateFollowSet()
{
}


RecursiveDescentPredictiveParser::RecursiveDescentPredictiveParser(Lexer& lexer) : lexer(lexer)
{
	//parseGrammar(grammar);

	//generateFirstSet();
	//generateFollowSet();
}

bool RecursiveDescentPredictiveParser::parse()
{
	lookAhead = lexer.nextToken();

	return Start() && match(TokenType::END_OF_FILE);
}


// Grammar functions

bool RecursiveDescentPredictiveParser::Start()
{
	return false;
}