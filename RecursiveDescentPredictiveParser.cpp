#include "RecursiveDescentPredictiveParser.h"
#include "ASTFactory.h"
#include <sstream>
#include <algorithm>
#include <sstream>
#include <iostream>

void RecursiveDescentPredictiveParser::applyDerivation(NonTerminal lhs, vector<Alphabet> rhs, string rule)
{

	Alphabet a = derivationStack.back(); derivationStack.pop_back();

	if (auto nonTerminal = std::get_if<NonTerminal>(&a)) {
		if (*nonTerminal != lhs) {
			std::cout << "NonTerminal encountered does not match stack\n";
		}
	}
	else if (auto terminal = std::get_if<TokenType>(&a)) {
		std::cout << "encountered TokenType instead of lhs NonTerminal\n";
	}

	for (auto it = rhs.rbegin(); it != rhs.rend(); ++it) {
		if (auto terminal = std::get_if<TokenType>(&(*it))) {
			if (*terminal == TokenType::EPSILON) {
				continue;
			}
		}
		derivationStack.push_back(*it);
	}

	derivationList.push_back(dumpDerivationStackToString(rule));
}

string RecursiveDescentPredictiveParser::dumpDerivationStackToString(string rule)
{
	std::stringstream ss;

	for (Alphabet pos : derivationStack) {
		if (auto nonTerminal = std::get_if<NonTerminal>(&pos)) {
			ss << EnumDeclarations::nonTerminalToString(*nonTerminal) << " ";
		}
		else if (auto terminal = std::get_if<TokenType>(&pos)) {
			ss << Token::tokenToString(*terminal) << " ";
		}
	}

	ss << " : applied '" << rule << "'";
	return ss.str();
}

void RecursiveDescentPredictiveParser::generateFirstSet()
{
	firstSet[NonTerminal::ADDOP] = { TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR };
	firstSet[NonTerminal::APARAMSTAIL] = { TokenType::COMMA, TokenType::EPSILON };
	firstSet[NonTerminal::ARITHEXPRTAIL] = { TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::EPSILON };
	firstSet[NonTerminal::ASSIGNOP] = { TokenType::ASSIGNMENT };
	firstSet[NonTerminal::CLASSDECLBODY] = { TokenType::PUBLIC, TokenType::PRIVATE, TokenType::FUNC, TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID, TokenType::EPSILON };
	firstSet[NonTerminal::EXPRTAIL] = { TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::EPSILON };
	firstSet[NonTerminal::ARITHEXPR] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	firstSet[NonTerminal::FPARAMSTAIL] = { TokenType::COMMA, TokenType::EPSILON };
	firstSet[NonTerminal::CLASSMETHOD] = { TokenType::DOUBLE_COLON, TokenType::EPSILON };
	firstSet[NonTerminal::FPARAMS] = { TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCDECLTAIL] = { TokenType::VOID, TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID };
	firstSet[NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL] = { TokenType::PERIOD, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL] = { TokenType::PERIOD, TokenType::ASSIGNMENT };
	firstSet[NonTerminal::FUNCORASSIGNSTATIDNEST] = { TokenType::LEFT_PARENTHESIS, TokenType::LEFT_SQUARE_BRACKET, TokenType::PERIOD, TokenType::ASSIGNMENT };
	firstSet[NonTerminal::ASSIGNSTATTAIL] = { TokenType::ASSIGNMENT };
	firstSet[NonTerminal::FUNCORVAR] = { TokenType::ID };
	firstSet[NonTerminal::FUNCORVARIDNESTTAIL] = { TokenType::PERIOD, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCORVARIDNEST] = { TokenType::LEFT_PARENTHESIS, TokenType::LEFT_SQUARE_BRACKET, TokenType::PERIOD, TokenType::EPSILON };
	firstSet[NonTerminal::APARAMS] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCSTATTAILIDNEST] = { TokenType::PERIOD, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCSTATTAIL] = { TokenType::PERIOD, TokenType::LEFT_PARENTHESIS, TokenType::LEFT_SQUARE_BRACKET };
	firstSet[NonTerminal::FUNCTION] = { TokenType::FUNC };
	firstSet[NonTerminal::FUNCHEAD] = { TokenType::FUNC };
	firstSet[NonTerminal::INHERIT] = { TokenType::INHERITS, TokenType::EPSILON };
	firstSet[NonTerminal::INTNUM] = { TokenType::INTEGER, TokenType::EPSILON };
	firstSet[NonTerminal::MEMBERDECL] = { TokenType::FUNC, TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID };
	firstSet[NonTerminal::FUNCDECL] = { TokenType::FUNC };
	firstSet[NonTerminal::METHODBODYVAR] = { TokenType::VAR, TokenType::EPSILON };
	firstSet[NonTerminal::NESTEDID] = { TokenType::COMMA, TokenType::EPSILON };
	firstSet[NonTerminal::CLASSDECL] = { TokenType::CLASS, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCDEF] = { TokenType::FUNC, TokenType::EPSILON };
	firstSet[NonTerminal::FUNCBODY] = { TokenType::LEFT_CURLY_BRACKET };
	firstSet[NonTerminal::RELOP] = { TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO };
	firstSet[NonTerminal::SIGN] = { TokenType::ADDITION, TokenType::SUBTRACTION };
	firstSet[NonTerminal::START] = { TokenType::MAIN, TokenType::CLASS, TokenType::FUNC };
	firstSet[NonTerminal::PROG] = { TokenType::MAIN, TokenType::CLASS, TokenType::FUNC };
	firstSet[NonTerminal::FUNCORASSIGNSTAT] = { TokenType::ID };
	firstSet[NonTerminal::STATBLOCK] = { TokenType::LEFT_CURLY_BRACKET, TokenType::IF, TokenType::WHILE, TokenType::READ, TokenType::WRITE, TokenType::RETURN, TokenType::BREAK, TokenType::CONTINUE, TokenType::ID, TokenType::EPSILON };
	firstSet[NonTerminal::EXPR] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	firstSet[NonTerminal::STATEMENT] = { TokenType::IF, TokenType::WHILE, TokenType::READ, TokenType::WRITE, TokenType::RETURN, TokenType::BREAK, TokenType::CONTINUE, TokenType::ID };
	firstSet[NonTerminal::STATEMENTLIST] = { TokenType::IF, TokenType::WHILE, TokenType::READ, TokenType::WRITE, TokenType::RETURN, TokenType::BREAK, TokenType::CONTINUE, TokenType::ID, TokenType::EPSILON };
	firstSet[NonTerminal::TERM] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	firstSet[NonTerminal::MULTOP] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND };
	firstSet[NonTerminal::FACTOR] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	firstSet[NonTerminal::TERMTAIL] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND, TokenType::EPSILON };
	firstSet[NonTerminal::TYPE] = { TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID };
	firstSet[NonTerminal::ARRAYSIZEREPT] = { TokenType::LEFT_SQUARE_BRACKET, TokenType::EPSILON };
	firstSet[NonTerminal::VARDECL] = { TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID };
	firstSet[NonTerminal::VARDECLREP] = { TokenType::INTEGER_ID, TokenType::FLOAT_ID, TokenType::STRING_ID, TokenType::ID, TokenType::EPSILON };
	firstSet[NonTerminal::VARIABLE] = { TokenType::ID };
	firstSet[NonTerminal::INDICEREP] = { TokenType::LEFT_SQUARE_BRACKET, TokenType::EPSILON };
	firstSet[NonTerminal::VARIABLEIDNESTTAIL] = { TokenType::PERIOD, TokenType::EPSILON };
	firstSet[NonTerminal::VARIABLEIDNEST] = { TokenType::LEFT_SQUARE_BRACKET, TokenType::PERIOD, TokenType::EPSILON };
	firstSet[NonTerminal::VISIBILITY] = { TokenType::PUBLIC, TokenType::PRIVATE, TokenType::EPSILON };
}

void RecursiveDescentPredictiveParser::generateFollowSet()
{
	followSet[NonTerminal::ADDOP] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	followSet[NonTerminal::APARAMSTAIL] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::ARITHEXPRTAIL] = { TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::ASSIGNOP] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	followSet[NonTerminal::CLASSDECLBODY] = { TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::EXPRTAIL] = { TokenType::SEMICOLON, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::ARITHEXPR] = { TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::FPARAMSTAIL] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::CLASSMETHOD] = { TokenType::LEFT_PARENTHESIS };
	followSet[NonTerminal::FPARAMS] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::FUNCDECLTAIL] = { TokenType::LEFT_CURLY_BRACKET, TokenType::SEMICOLON };
	followSet[NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL] = { TokenType::SEMICOLON };
	followSet[NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL] = { TokenType::SEMICOLON };
	followSet[NonTerminal::FUNCORASSIGNSTATIDNEST] = { TokenType::SEMICOLON };
	followSet[NonTerminal::ASSIGNSTATTAIL] = { TokenType::SEMICOLON };
	followSet[NonTerminal::FUNCORVAR] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND, TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::FUNCORVARIDNESTTAIL] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND, TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::FUNCORVARIDNEST] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND, TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::APARAMS] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::FUNCSTATTAILIDNEST] = { TokenType::SEMICOLON };
	followSet[NonTerminal::FUNCSTATTAIL] = { TokenType::SEMICOLON };
	followSet[NonTerminal::FUNCTION] = { TokenType::MAIN, TokenType::FUNC };
	followSet[NonTerminal::FUNCHEAD] = { TokenType::LEFT_CURLY_BRACKET };
	followSet[NonTerminal::INHERIT] = { TokenType::LEFT_CURLY_BRACKET };
	followSet[NonTerminal::INTNUM] = { TokenType::RIGHT_SQUARE_BRACKET };
	followSet[NonTerminal::MEMBERDECL] = { TokenType::PUBLIC, TokenType::PRIVATE, TokenType::FUNC, TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::ID, TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::FUNCDECL] = { TokenType::PUBLIC, TokenType::PRIVATE, TokenType::FUNC, TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::ID, TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::METHODBODYVAR] = { TokenType::IF, TokenType::WHILE, TokenType::READ, TokenType::WRITE, TokenType::RETURN, TokenType::BREAK, TokenType::CONTINUE, TokenType::ID, TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::NESTEDID] = { TokenType::LEFT_CURLY_BRACKET };
	followSet[NonTerminal::CLASSDECL] = { TokenType::FUNC, TokenType::MAIN };
	followSet[NonTerminal::FUNCDEF] = { TokenType::MAIN };
	followSet[NonTerminal::FUNCBODY] = { TokenType::MAIN, TokenType::FUNC };
	followSet[NonTerminal::RELOP] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	followSet[NonTerminal::SIGN] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	followSet[NonTerminal::START] = { };
	followSet[NonTerminal::PROG] = { };
	followSet[NonTerminal::FUNCORASSIGNSTAT] = { TokenType::SEMICOLON };
	followSet[NonTerminal::STATBLOCK] = { TokenType::ELSE, TokenType::SEMICOLON };
	followSet[NonTerminal::EXPR] = { TokenType::SEMICOLON, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::STATEMENT] = { TokenType::IF, TokenType::WHILE, TokenType::READ, TokenType::WRITE, TokenType::RETURN, TokenType::BREAK, TokenType::CONTINUE, TokenType::ID, TokenType::ELSE, TokenType::SEMICOLON, TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::STATEMENTLIST] = { TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::TERM] = { TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::MULTOP] = { TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::LEFT_PARENTHESIS, TokenType::NOT, TokenType::QUESTION_MARK, TokenType::ID, TokenType::ADDITION, TokenType::SUBTRACTION };
	followSet[NonTerminal::FACTOR] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND, TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::TERMTAIL] = { TokenType::SEMICOLON, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::TYPE] = { TokenType::LEFT_CURLY_BRACKET, TokenType::SEMICOLON, TokenType::ID };
	followSet[NonTerminal::ARRAYSIZEREPT] = { TokenType::RIGHT_PARENTHESIS, TokenType::COMMA, TokenType::SEMICOLON };
	followSet[NonTerminal::VARDECL] = { TokenType::PUBLIC, TokenType::PRIVATE, TokenType::FUNC, TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::ID, TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::VARDECLREP] = { TokenType::RIGHT_CURLY_BRACKET };
	followSet[NonTerminal::VARIABLE] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::INDICEREP] = { TokenType::MULTIPLICATION, TokenType::DIVISION, TokenType::AND, TokenType::SEMICOLON, TokenType::ASSIGNMENT, TokenType::PERIOD, TokenType::EQUAL_TO, TokenType::NOT_EQUAL_TO, TokenType::LESS_THAN, TokenType::GREATER_THAN, TokenType::LESS_THAN_EQUAL_TO, TokenType::GREATER_THAN_EQUAL_TO, TokenType::ADDITION, TokenType::SUBTRACTION, TokenType::OR, TokenType::COMMA, TokenType::COLON, TokenType::RIGHT_SQUARE_BRACKET, TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::VARIABLEIDNESTTAIL] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::VARIABLEIDNEST] = { TokenType::RIGHT_PARENTHESIS };
	followSet[NonTerminal::VISIBILITY] = { TokenType::FUNC, TokenType::INTEGER, TokenType::FLOAT, TokenType::STRING, TokenType::ID };

}

bool RecursiveDescentPredictiveParser::isElementOfFirst(vector<Alphabet> elements)
{
	// The number of non-terminals we have encountered
	int numNonTerminals = 0;
	// The number of epsilon transitions we use
	int numEpsilonTransisions = 0;
	for (Alphabet e : elements) {

		if (auto nonTerminal = std::get_if<NonTerminal>(&e)) {
			numNonTerminals++;
			// If the current production contains the current lookAhead token in its first set, then return true
			if (firstSet[*nonTerminal].find(lookAhead.getTokenType()) != firstSet[*nonTerminal].end()) {
				return true;
			}
			// If the current production is not nullable and it does not contain the current lookAhead token in its first set, then return false
			else if (firstSet[*nonTerminal].find(TokenType::EPSILON) == firstSet[*nonTerminal].end()) {
				return false;
			}
			// If the current production does not contain the current lookAhead token in its first set, but it is nullable, then move onto the next NonTerminal production (we use the epsilon transition)
			numEpsilonTransisions++;
		}
		// If we encounter a terminal symbol, then simply compare it with the lookahead
		else if (auto terminal = std::get_if<TokenType>(&e)) {
			if (lookAhead.getTokenType() == *terminal) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	// If all we used the epsilon transition for all non-terminals, this means the production can be completely nulled out, return true
	if (numNonTerminals == numEpsilonTransisions) {
		return true;
	}
	// If we didn't find the token in any of the NonTerminal productions, then we return false (the terminal case is handled above)
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::isElementOfFollow(NonTerminal element)
{
	return followSet[element].find(lookAhead.getTokenType()) != followSet[element].end();
}

bool RecursiveDescentPredictiveParser::match(TokenType t)
{
	if (lookAhead.getTokenType() == t) {

		if (t != TokenType::END_OF_FILE) {
			derivationStack.pop_back();
			derivationList.push_back(dumpDerivationStackToString(lookAhead.getLexeme()));
		}

		lastToken = lookAhead;
		lookAhead = nextToken();

		switch (lastToken.getTokenType()) {
			// Types
		case TokenType::INTEGER_ID:
		case TokenType::FLOAT_ID:
		case TokenType::STRING_ID:

			// Literals
		case TokenType::ID:
		case TokenType::FLOAT:
		case TokenType::INTEGER:
		case TokenType::STRING:
		case TokenType::PUBLIC:
		case TokenType::PRIVATE:
			// Relational Operators
		case TokenType::EQUAL_TO:
		case TokenType::NOT_EQUAL_TO:
		case TokenType::LESS_THAN:
		case TokenType::GREATER_THAN:
		case TokenType::LESS_THAN_EQUAL_TO:
		case TokenType::GREATER_THAN_EQUAL_TO:
			// Add Operators
		case TokenType::ADDITION:
		case TokenType::SUBTRACTION:
		case TokenType::OR:
			// Multiplication Operators
		case TokenType::MULTIPLICATION:
		case TokenType::DIVISION:
		case TokenType::AND:
			// Statement types
		case TokenType::BREAK:
		case TokenType::CONTINUE:
			// Assignment
		case TokenType::ASSIGNMENT:

		case TokenType::NOT:
		case TokenType::VOID:
		case TokenType::PERIOD:
			attributeStack.push(ASTFactory::makeNode(lastToken));
			break;
		}

		return true;
	}
	else {
		syntaxErrors.push_back("syntax error on line " + std::to_string(lookAhead.getLineNumber()) + ": got " + lookAhead.getLexeme() + ", expected " + Token::tokenToString(t));
		syntaxErrors.push_back("fatal error: sorry, i could not recover from the previous syntax error.");
		return false;
	}
}

bool RecursiveDescentPredictiveParser::skipErrors(NonTerminal t)
{
	set first = firstSet[t];
	set follow = followSet[t];

	bool epsilonIsInFirst = firstSet[t].find(TokenType::EPSILON) != firstSet[t].end();
	if ((first.find(lookAhead.getTokenType()) != first.end()) ||
		(epsilonIsInFirst && (follow.find(lookAhead.getTokenType()) != follow.end()))) {
		return true;
	}
	else {
		set firstAndFollow = firstSet[t];
		firstAndFollow.insert(followSet[t].begin(), followSet[t].end());

		std::stringstream listOfTokens;
		for (TokenType token : firstAndFollow) {
			listOfTokens << Token::tokenToString(token) + ", ";
		}

		syntaxErrors.push_back("syntax error on line " + std::to_string(lookAhead.getLineNumber()) + ": " + lookAhead.getLexeme() + " was unexpected. Expected: " + listOfTokens.str());

		// Error skipping
		while (firstAndFollow.find(lookAhead.getTokenType()) == firstAndFollow.end()) {
			lookAhead = nextToken();

			if (epsilonIsInFirst && (follow.find(lookAhead.getTokenType()) != follow.end())) {
				syntaxErrors.push_back("fatal error: sorry, i could not recover from the previous syntax error.");
				return false;
			}
			else if (lookAhead.getTokenType() == TokenType::END_OF_FILE) {
				syntaxErrors.push_back("fatal error: reached end of file without encountering expected token.");
				return false;
			}
		}
		return true;
	}
}

Token RecursiveDescentPredictiveParser::nextToken()
{
	Token t;
	do {
		t = lexer.nextToken();
		tokens.push_back(t);
	} while (t.getTokenType() == TokenType::COMMENT);
	return t;
}

AST* RecursiveDescentPredictiveParser::getAST()
{
	return ast;
}

vector<string> RecursiveDescentPredictiveParser::getSyntaxErrors()
{
	return syntaxErrors;
}

vector<string> RecursiveDescentPredictiveParser::getDerivation()
{
	return derivationList;
}

RecursiveDescentPredictiveParser::RecursiveDescentPredictiveParser(Lexer& lexer) : lexer(lexer)
{
	generateFirstSet();
	generateFollowSet();
}

bool RecursiveDescentPredictiveParser::parse()
{
	AST* startS = nullptr;

	lookAhead = nextToken();

	derivationStack.push_back(NonTerminal::START);
	derivationList.push_back("START");
	bool success = Start(&startS) && match(TokenType::END_OF_FILE);

	ast = startS;

	return success;
}

vector<Token>& RecursiveDescentPredictiveParser::getTokens()
{
	return tokens;
}


// Grammar functions

bool RecursiveDescentPredictiveParser::Start(AST** startS)
{
	if (!skipErrors(NonTerminal::START)) { return false; }
	// <START> ::= <Prog>
	if (isElementOfFirst({ NonTerminal::PROG })) {
		applyDerivation(NonTerminal::START, { NonTerminal::PROG }, "<START> ::= <Prog>");

		AST* progS = nullptr;
		if (Prog(&progS)) {
			*startS = ASTFactory::makeFamily(CompositeConcept::START, { progS });
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Prog(AST** progS)
{
	if (!skipErrors(NonTerminal::PROG)) { return false; }
	// <Prog> ::= <ClassDecl> <FuncDef> 'main' <FuncBody> 
	if (isElementOfFirst({ NonTerminal::CLASSDECL, NonTerminal::FUNCDEF, TokenType::MAIN, NonTerminal::FUNCBODY })) {
		applyDerivation(NonTerminal::PROG, { NonTerminal::CLASSDECL, NonTerminal::FUNCDEF, TokenType::MAIN, NonTerminal::FUNCBODY }, "<Prog> ::= <ClassDecl> <FuncDef> 'main' <FuncBody>");

		AST* classDeclS = nullptr;
		AST* funcDefS = nullptr;
		AST* funcBodyS = nullptr;
		if (ClassDecl(&classDeclS) && FuncDef(&funcDefS) && match(TokenType::MAIN) && FuncBody(&funcBodyS)) {
			AST* classList = ASTFactory::makeFamily(CompositeConcept::CLASSLIST, { classDeclS });
			AST* funcList = ASTFactory::makeFamily(CompositeConcept::FUNCLIST, { funcDefS });

			*progS = ASTFactory::makeFamily(CompositeConcept::PROG, { classList, funcList, funcBodyS });
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ClassDecl(AST** classDeclS)
{
	if (!skipErrors(NonTerminal::CLASSDECL)) { return false; }
	// <ClassDecl> ::= 'class' 'id' <Inherit> '{' <ClassDeclBody> '}' ';' <ClassDecl> 
	if (isElementOfFirst({ TokenType::CLASS, TokenType::ID, NonTerminal::INHERIT, TokenType::LEFT_CURLY_BRACKET, NonTerminal::CLASSDECLBODY, TokenType::RIGHT_CURLY_BRACKET, TokenType::SEMICOLON, NonTerminal::CLASSDECL })) {
		applyDerivation(NonTerminal::CLASSDECL, { TokenType::CLASS, TokenType::ID, NonTerminal::INHERIT, TokenType::LEFT_CURLY_BRACKET, NonTerminal::CLASSDECLBODY, TokenType::RIGHT_CURLY_BRACKET, TokenType::SEMICOLON, NonTerminal::CLASSDECL }, "<ClassDecl> ::= 'class' 'id' <Inherit> '{' <ClassDeclBody> '}' ';' <ClassDecl>");

		AST* inheritS = nullptr;
		AST* classDeclBodyS = nullptr;
		AST* classDeclSiblingS = nullptr;
		if (match(TokenType::CLASS) && match(TokenType::ID) && Inherit(&inheritS) && match(TokenType::LEFT_CURLY_BRACKET) && ClassDeclBody(&classDeclBodyS) && match(TokenType::RIGHT_CURLY_BRACKET) && match(TokenType::SEMICOLON) && ClassDecl(&classDeclSiblingS)) {

			AST* classId = attributeStack.top(); attributeStack.pop();
			AST* inheritList = ASTFactory::makeFamily(CompositeConcept::INHERITLIST, { inheritS });
			AST* classDeclBodyList = ASTFactory::makeFamily(CompositeConcept::CLASSDECLBODYLIST, { classDeclBodyS });
			*classDeclS = ASTFactory::makeFamily(CompositeConcept::CLASSDECL, { classId, inheritList, classDeclBodyList });
			if (classDeclSiblingS) {
				(*classDeclS)->makeSiblings(classDeclSiblingS);
			}
			return true;
		}
		else {
			return false;
		}
	}
	// <ClassDecl> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::CLASSDECL)) {
		applyDerivation(NonTerminal::CLASSDECL, { TokenType::EPSILON }, "<ClassDecl> -> EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncDef(AST** funcDefS)
{
	if (!skipErrors(NonTerminal::FUNCDEF)) { return false; }
	//<FuncDef> ::= <Function> <FuncDef> 
	if (isElementOfFirst({ NonTerminal::FUNCTION, NonTerminal::FUNCDEF })) {
		applyDerivation(NonTerminal::FUNCDEF, { NonTerminal::FUNCTION, NonTerminal::FUNCDEF }, "<FuncDef> ::= <Function> <FuncDef>");

		AST* functionS = nullptr;
		AST* funcDefSiblingS = nullptr;
		if (Function(&functionS) && FuncDef(&funcDefSiblingS)) {
			*funcDefS = ASTFactory::makeFamily(CompositeConcept::FUNCDEF, { functionS });
			if (funcDefSiblingS) {
				(*funcDefS)->makeSiblings(funcDefSiblingS);
			}
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncDef> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCDEF)) {
		applyDerivation(NonTerminal::FUNCDEF, { TokenType::EPSILON }, "<FuncDef> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncBody(AST** funcBodyS)
{
	if (!skipErrors(NonTerminal::FUNCBODY)) { return false; }
	// <FuncBody> ::= '{' <MethodBodyVar> <StatementList> '}' 
	if (isElementOfFirst({ TokenType::LEFT_CURLY_BRACKET, NonTerminal::METHODBODYVAR, NonTerminal::STATEMENTLIST, TokenType::RIGHT_CURLY_BRACKET })) {
		applyDerivation(NonTerminal::FUNCBODY, { TokenType::LEFT_CURLY_BRACKET, NonTerminal::METHODBODYVAR, NonTerminal::STATEMENTLIST, TokenType::RIGHT_CURLY_BRACKET }, "<FuncBody> ::= '{' <MethodBodyVar> <StatementList> '}'");

		AST* methodBodyVarS = nullptr;
		AST* statementList = nullptr;
		if (match(TokenType::LEFT_CURLY_BRACKET) && MethodBodyVar(&methodBodyVarS) && StatementList(&statementList) && match(TokenType::RIGHT_CURLY_BRACKET)) {
			AST* statementListParent = ASTFactory::makeFamily(CompositeConcept::STATEMENTLIST, { statementList });
			*funcBodyS = ASTFactory::makeFamily(CompositeConcept::FUNCBODY, { methodBodyVarS, statementListParent });
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Inherit(AST** inheritS)
{
	if (!skipErrors(NonTerminal::INHERIT)) { return false; }
	// <Inherit> ::= 'inherits' 'id' < NestedId >
	if (isElementOfFirst({ TokenType::INHERITS, TokenType::ID, NonTerminal::NESTEDID })) {
		applyDerivation(NonTerminal::INHERIT, { TokenType::INHERITS, TokenType::ID, NonTerminal::NESTEDID }, "<Inherit> ::= 'inherits' 'id' <NestedId>");
		AST* nestedId = nullptr;
		if (match(TokenType::INHERITS) && match(TokenType::ID) && NestedID(&nestedId)) {
			*inheritS = attributeStack.top(); attributeStack.pop();
			if (nestedId) {
				(*inheritS)->makeSiblings(nestedId);
			}
			return true;
		}
		else {
			return false;
		}
	}
	// <Inherit> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::INHERIT)) {
		applyDerivation(NonTerminal::INHERIT, { TokenType::EPSILON }, "<Inherit> ::= EPSILON");
		return true;
	}
	return false;
}

bool RecursiveDescentPredictiveParser::NestedID(AST** nestedIdS)
{
	if (!skipErrors(NonTerminal::NESTEDID)) { return false; }
	//<NestedId> ::= ',' 'id' < NestedId >
	if (isElementOfFirst({ TokenType::COMMA, TokenType::ID, NonTerminal::NESTEDID })) {
		applyDerivation(NonTerminal::NESTEDID, { TokenType::COMMA, TokenType::ID, NonTerminal::NESTEDID }, "<NestedId> ::= ',' 'id' <NestedId>");
		AST* nestedIdSibling = nullptr;
		if (match(TokenType::COMMA) && match(TokenType::ID) && NestedID(&nestedIdSibling)) {
			*nestedIdS = attributeStack.top(); attributeStack.pop();
			if (nestedIdSibling) {
				(*nestedIdS)->makeSiblings(nestedIdSibling);
			}
			return true;
		}
		else {
			return false;
		}
	}
	//<NestedId> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::NESTEDID)) {
		applyDerivation(NonTerminal::NESTEDID, { TokenType::EPSILON }, "<NestedId> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ClassDeclBody(AST** classDeclBodyS)
{
	if (!skipErrors(NonTerminal::CLASSDECLBODY)) { return false; }
	// <ClassDeclBody> ::= <Visibility> <MemberDecl> <ClassDeclBody> 
	if (isElementOfFirst({ NonTerminal::VISIBILITY, NonTerminal::MEMBERDECL, NonTerminal::CLASSDECLBODY })) {
		applyDerivation(NonTerminal::CLASSDECLBODY, { NonTerminal::VISIBILITY, NonTerminal::MEMBERDECL, NonTerminal::CLASSDECLBODY }, "<ClassDeclBody> ::= <Visibility> <MemberDecl> <ClassDeclBody>");
		AST* visibilityS = nullptr;
		AST* memberDeclS = nullptr;
		AST* classDeclBodySiblingS = nullptr;

		if (Visibility(&visibilityS) && MemberDecl(&memberDeclS) && ClassDeclBody(&classDeclBodySiblingS)) {
			*classDeclBodyS = ASTFactory::makeFamily(CompositeConcept::CLASSDECLBODY, { visibilityS, memberDeclS });
			if (classDeclBodySiblingS) {
				(*classDeclBodyS)->makeSiblings(classDeclBodySiblingS);
			}
			return true;
		}
		else {
			return false;
		}
	}
	// <ClassDeclBody> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::CLASSDECLBODY)) {
		applyDerivation(NonTerminal::CLASSDECLBODY, { TokenType::EPSILON }, "<ClassDeclBody> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FParams(AST** fParams)
{
	if (!skipErrors(NonTerminal::FPARAMS)) { return false; }
	//<FParams> ::= <Type> 'id' < ArraySizeRept > <FParamsTail>
	if (isElementOfFirst({ NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL })) {
		applyDerivation(NonTerminal::FPARAMS, { NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL }, "<FParams> ::= <Type> 'id' <ArraySizeRept> <FParamsTail>");

		AST* type = nullptr;
		AST* arraySizeRept = nullptr;
		AST* fParamsTail = nullptr;
		if (Type(&type) && match(TokenType::ID) && ArraySizeRept(&arraySizeRept) && FParamsTail(&fParamsTail)) {
			AST* fParamId = attributeStack.top(); attributeStack.pop();
			AST* arraySizeReptList = nullptr;
			if (arraySizeRept) {
				arraySizeReptList = ASTFactory::makeFamily(CompositeConcept::ARRAYSIZEREPTLIST, { arraySizeRept });
			}

			AST* fParamCurrent = ASTFactory::makeFamily(CompositeConcept::FPARAMS, { type, fParamId, arraySizeReptList });
			fParamCurrent->makeSiblings(fParamsTail);

			*fParams = ASTFactory::makeFamily(CompositeConcept::FPARAMSLIST, { fParamCurrent });
			return true;
		}
		else {
			return false;
		}
	}
	//<FParams> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::FPARAMS)) {
		applyDerivation(NonTerminal::FPARAMS, { TokenType::EPSILON }, "<FParams> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncDeclTail(AST** funcDeclTail)
{
	if (!skipErrors(NonTerminal::FUNCDECLTAIL)) { return false; }
	//<FuncDeclTail> ::= <Type> 
	if (isElementOfFirst({ NonTerminal::TYPE })) {
		applyDerivation(NonTerminal::FUNCDECLTAIL, { NonTerminal::TYPE }, "<FuncDeclTail> ::= <Type>");
		if (Type(funcDeclTail)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncDeclTail> ::= 'void' 
	else if (isElementOfFirst({ TokenType::VOID })) {
		applyDerivation(NonTerminal::FUNCDECLTAIL, { TokenType::VOID }, "<FuncDeclTail> ::= 'void'");
		if (match(TokenType::VOID)) {
			*funcDeclTail = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::MethodBodyVar(AST** methodBodyVar)
{
	if (!skipErrors(NonTerminal::METHODBODYVAR)) { return false; }
	//<MethodBodyVar> ::= 'var' '{' <VarDeclRep> '}'
	if (isElementOfFirst({ TokenType::VAR, TokenType::LEFT_CURLY_BRACKET, NonTerminal::VARDECLREP, TokenType::RIGHT_CURLY_BRACKET })) {
		applyDerivation(NonTerminal::METHODBODYVAR, { TokenType::VAR, TokenType::LEFT_CURLY_BRACKET, NonTerminal::VARDECLREP, TokenType::RIGHT_CURLY_BRACKET }, "<MethodBodyVar> ::= 'var' '{' <VarDeclRep> '}'");

		AST* varDeclRep = nullptr;
		if (match(TokenType::VAR) && match(TokenType::LEFT_CURLY_BRACKET) && VarDeclRep(&varDeclRep) && match(TokenType::RIGHT_CURLY_BRACKET)) {
			*methodBodyVar = ASTFactory::makeFamily(CompositeConcept::VARDECLLIST, { varDeclRep });
			return true;
		}
		else {
			return false;
		}
	}
	//<MethodBodyVar> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::METHODBODYVAR)) {
		applyDerivation(NonTerminal::METHODBODYVAR, { TokenType::EPSILON }, "<MethodBodyVar> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::StatementList(AST** statementListS)
{
	if (!skipErrors(NonTerminal::STATEMENTLIST)) { return false; }
	//<StatementList> ::= <Statement> <StatementList>
	if (isElementOfFirst({ NonTerminal::STATEMENT, NonTerminal::STATEMENTLIST })) {
		applyDerivation(NonTerminal::STATEMENTLIST, { NonTerminal::STATEMENT, NonTerminal::STATEMENTLIST }, "<StatementList> ::= <Statement> <StatementList>");

		AST* statement = nullptr;
		AST* statementListSibling = nullptr;
		if (Statement(&statement) && StatementList(&statementListSibling)) {
			statement->makeSiblings(statementListSibling);
			*statementListS = statement;
			return true;
		}
		else {
			return false;
		}
	}
	//<StatementList> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::STATEMENTLIST)) {
		applyDerivation(NonTerminal::STATEMENTLIST, { TokenType::EPSILON }, "<StatementList> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Visibility(AST** visibilityS)
{
	if (!skipErrors(NonTerminal::VISIBILITY)) { return false; }
	//<Visibility> :: = 'public'
	if (isElementOfFirst({ TokenType::PUBLIC })) {
		applyDerivation(NonTerminal::VISIBILITY, { TokenType::PUBLIC }, "<Visibility> ::= 'public'");
		if (match(TokenType::PUBLIC)) {
			*visibilityS = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Visibility> :: = 'private'
	else if (isElementOfFirst({ TokenType::PRIVATE })) {
		applyDerivation(NonTerminal::VISIBILITY, { TokenType::PRIVATE }, "<Visibility> ::= 'private'");
		if (match(TokenType::PRIVATE)) {
			*visibilityS = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Visibility> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::VISIBILITY)) {
		applyDerivation(NonTerminal::VISIBILITY, { TokenType::EPSILON }, "<Visibility> :: = EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::MemberDecl(AST** memberDeclS)
{
	if (!skipErrors(NonTerminal::MEMBERDECL)) { return false; }
	//<MemberDecl> ::= <FuncDecl>
	if (isElementOfFirst({ NonTerminal::FUNCDECL })) {
		applyDerivation(NonTerminal::MEMBERDECL, { NonTerminal::FUNCDECL }, "<MemberDecl> ::= <FuncDecl>");
		AST* funcDecl = nullptr;
		if (FuncDecl(&funcDecl)) {
			*memberDeclS = funcDecl;
			return true;
		}
		else {
			return false;
		}
	}
	//<MemberDecl> :: = <VarDecl>
	else if (isElementOfFirst({ NonTerminal::VARDECL })) {
		applyDerivation(NonTerminal::MEMBERDECL, { NonTerminal::VARDECL }, "<MemberDecl> ::= <VarDecl>");
		AST* varDecl = nullptr;
		if (VarDecl(&varDecl)) {
			*memberDeclS = varDecl;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Type(AST** type)
{
	if (!skipErrors(NonTerminal::TYPE)) { return false; }
	//<Type> :: = 'integer'
	if (isElementOfFirst({ TokenType::INTEGER_ID })) {
		applyDerivation(NonTerminal::TYPE, { TokenType::INTEGER_ID }, "<Type> ::= 'integer'");
		if (match(TokenType::INTEGER_ID)) {
			*type = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Type> :: = 'float'
	else if (isElementOfFirst({ TokenType::FLOAT_ID })) {
		applyDerivation(NonTerminal::TYPE, { TokenType::FLOAT_ID }, "<Type> ::= 'float'");
		if (match(TokenType::FLOAT_ID)) {
			*type = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Type> :: = 'string'
	else if (isElementOfFirst({ TokenType::STRING_ID })) {
		applyDerivation(NonTerminal::TYPE, { TokenType::STRING_ID }, "<Type> ::= 'string'");
		if (match(TokenType::STRING_ID)) {
			*type = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Type> :: = 'id'
	else if (isElementOfFirst({ TokenType::ID })) {
		applyDerivation(NonTerminal::TYPE, { TokenType::ID }, "<Type> ::= 'id'");
		if (match(TokenType::ID)) {
			*type = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ArraySizeRept(AST** arraySizeRept)
{
	if (!skipErrors(NonTerminal::ARRAYSIZEREPT)) { return false; }
	//<ArraySizeRept> :: = '[' < IntNum > ']' < ArraySizeRept >
	if (isElementOfFirst({ TokenType::LEFT_SQUARE_BRACKET, NonTerminal::INTNUM, TokenType::RIGHT_SQUARE_BRACKET, NonTerminal::ARRAYSIZEREPT })) {
		applyDerivation(NonTerminal::ARRAYSIZEREPT, { TokenType::LEFT_SQUARE_BRACKET, NonTerminal::INTNUM, TokenType::RIGHT_SQUARE_BRACKET, NonTerminal::ARRAYSIZEREPT }, "<ArraySizeRept> ::= '[' <IntNum> ']' <ArraySizeRept>");

		AST* intNum = nullptr;
		AST* arraySizeReptSibling = nullptr;;
		if (match(TokenType::LEFT_SQUARE_BRACKET) && IntNum(&intNum) && match(TokenType::RIGHT_SQUARE_BRACKET) && ArraySizeRept(&arraySizeReptSibling)) {
			AST* arrayDim = ASTFactory::makeFamily(CompositeConcept::ARRAYDIMENSION, { intNum });
			arrayDim->makeSiblings(arraySizeReptSibling);
			*arraySizeRept = arrayDim;
			return true;
		}
		else {
			return false;
		}
	}
	//<ArraySizeRept> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::ARRAYSIZEREPT)) {
		applyDerivation(NonTerminal::ARRAYSIZEREPT, { TokenType::EPSILON }, "<ArraySizeRept> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FParamsTail(AST** fParamsTail)
{
	if (!skipErrors(NonTerminal::FPARAMSTAIL)) { return false; }
	//<FParamsTail> :: = ',' < Type > 'id' < ArraySizeRept > <FParamsTail>
	if (isElementOfFirst({ TokenType::COMMA, NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL })) {
		applyDerivation(NonTerminal::FPARAMSTAIL, { TokenType::COMMA, NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL }, "<FParamsTail> :: = ',' < Type > 'id' < ArraySizeRept > <FParamsTail>");

		AST* type = nullptr;
		AST* arraySizeRept = nullptr;
		AST* fParamsTailSibling = nullptr;
		if (match(TokenType::COMMA) && Type(&type) && match(TokenType::ID) && ArraySizeRept(&arraySizeRept) && FParamsTail(&fParamsTailSibling)) {
			AST* fParamsId = attributeStack.top(); attributeStack.pop();
			AST* arraySizeReptList = nullptr;
			if (arraySizeRept) {
				arraySizeReptList = ASTFactory::makeFamily(CompositeConcept::ARRAYSIZEREPTLIST, { arraySizeRept });
			}
			*fParamsTail = ASTFactory::makeFamily(CompositeConcept::FPARAMS, { type, fParamsId, arraySizeReptList });
			(*fParamsTail)->makeSiblings(fParamsTailSibling);
			return true;
		}
		else {
			return false;
		}
	}
	//<FParamsTail> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::FPARAMSTAIL)) {
		applyDerivation(NonTerminal::FPARAMSTAIL, { TokenType::EPSILON }, "<FParamsTail> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::VarDeclRep(AST** varDeclRep)
{
	if (!skipErrors(NonTerminal::VARDECLREP)) { return false; }

	//<VarDeclRep> ::= <VarDecl> <VarDeclRep>
	if (isElementOfFirst({ NonTerminal::VARDECL, NonTerminal::VARDECLREP })) {
		applyDerivation(NonTerminal::VARDECLREP, { NonTerminal::VARDECL, NonTerminal::VARDECLREP }, "<VarDeclRep> ::= <VarDecl> <VarDeclRep>");
		AST* varDeclSibling = nullptr;
		if (VarDecl(varDeclRep) && VarDeclRep(&varDeclSibling)) {
			(*varDeclRep)->makeSiblings(varDeclSibling);
			return true;
		}
		else {
			return false;
		}
	}
	//<VarDeclRep> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::VARDECLREP)) {
		applyDerivation(NonTerminal::VARDECLREP, { TokenType::EPSILON }, "<VarDeclRep> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Statement(AST** statementS)
{
	if (!skipErrors(NonTerminal::STATEMENT)) { return false; }
	//<Statement> ::= <FuncOrAssignStat> ';'
	if (isElementOfFirst({ NonTerminal::FUNCORASSIGNSTAT, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { NonTerminal::FUNCORASSIGNSTAT, TokenType::SEMICOLON }, "<Statement> ::= <FuncOrAssignStat> ';'");

		AST* funcOrAssignStatS = nullptr;
		if (FuncOrAssignStat(&funcOrAssignStatS) && match(TokenType::SEMICOLON)) {
			*statementS = funcOrAssignStatS;
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'if' '(' < Expr > ')' 'then' < StatBlock > 'else' < StatBlock > ';'
	else if (isElementOfFirst({ TokenType::IF, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::THEN, NonTerminal::STATBLOCK, TokenType::ELSE, NonTerminal::STATBLOCK, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::IF, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::THEN, NonTerminal::STATBLOCK, TokenType::ELSE, NonTerminal::STATBLOCK, TokenType::SEMICOLON }, "<Statement> ::= 'if' '(' < Expr > ')' 'then' < StatBlock > 'else' < StatBlock > ';'");

		AST* ifExpr = nullptr;
		AST* thenBlock = nullptr;
		AST* elseBlock = nullptr;
		if (match(TokenType::IF) && match(TokenType::LEFT_PARENTHESIS) && Expr(&ifExpr) && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::THEN) && StatBlock(&thenBlock) && match(TokenType::ELSE) && StatBlock(&elseBlock) && match(TokenType::SEMICOLON)) {
			*statementS = ASTFactory::makeFamily(CompositeConcept::IF, { ifExpr, thenBlock, elseBlock });
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'while' '(' < Expr > ')' < StatBlock > ';'
	else if (isElementOfFirst({ TokenType::WHILE, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, NonTerminal::STATBLOCK, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::WHILE, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, NonTerminal::STATBLOCK, TokenType::SEMICOLON }, "<Statement> ::= 'while' '(' < Expr > ')' < StatBlock > ';'");

		AST* whileExpr = nullptr;
		AST* whileBlock = nullptr;
		if (match(TokenType::WHILE) && match(TokenType::LEFT_PARENTHESIS) && Expr(&whileExpr) && match(TokenType::RIGHT_PARENTHESIS) && StatBlock(&whileBlock) && match(TokenType::SEMICOLON)) {
			*statementS = ASTFactory::makeFamily(CompositeConcept::WHILE, { whileExpr, whileBlock });
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'read' '(' < Variable > ')' ';'
	else if (isElementOfFirst({ TokenType::READ, TokenType::LEFT_PARENTHESIS, NonTerminal::VARIABLE, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::READ, TokenType::LEFT_PARENTHESIS, NonTerminal::VARIABLE, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON }, "<Statement> ::= 'read' '(' < Variable > ')' ';'");

		AST* var = nullptr;
		if (match(TokenType::READ) && match(TokenType::LEFT_PARENTHESIS) && Variable(&var) && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::SEMICOLON)) {
			*statementS = ASTFactory::makeFamily(CompositeConcept::READ, { var });
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'write' '(' < Expr > ')' ';'
	else if (isElementOfFirst({ TokenType::WRITE, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::WRITE, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON }, "<Statement> ::= 'write' '(' < Expr > ')' ';'");

		AST* writeExpr = nullptr;
		if (match(TokenType::WRITE) && match(TokenType::LEFT_PARENTHESIS) && Expr(&writeExpr) && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::SEMICOLON)) {
			*statementS = ASTFactory::makeFamily(CompositeConcept::WRITE, { writeExpr });
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'return' '(' < Expr > ')' ';'
	else if (isElementOfFirst({ TokenType::RETURN, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::RETURN, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON }, "<Statement> ::= 'return' '(' < Expr > ')' ';'");

		AST* returnExpr = nullptr;
		if (match(TokenType::RETURN) && match(TokenType::LEFT_PARENTHESIS) && Expr(&returnExpr) && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::SEMICOLON)) {
			*statementS = ASTFactory::makeFamily(CompositeConcept::RETURN, { returnExpr });
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'break' ';'
	else if (isElementOfFirst({ TokenType::BREAK, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::BREAK, TokenType::SEMICOLON }, "<Statement> ::= 'break' ';'");

		if (match(TokenType::BREAK) && match(TokenType::SEMICOLON)) {
			*statementS = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'continue' ';'
	else if (isElementOfFirst({ TokenType::CONTINUE, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::STATEMENT, { TokenType::CONTINUE, TokenType::SEMICOLON }, "<Statement> ::= 'continue' ';'");
		if (match(TokenType::CONTINUE) && match(TokenType::SEMICOLON)) {
			*statementS = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncDecl(AST** funcDecl)
{
	if (!skipErrors(NonTerminal::FUNCDECL)) { return false; }
	//<FuncDecl> ::= 'func' 'id' '(' <FParams> ')' ':' <FuncDeclTail> ';'
	if (isElementOfFirst({ TokenType::FUNC, TokenType::ID, TokenType::LEFT_PARENTHESIS, NonTerminal::FPARAMS, TokenType::RIGHT_PARENTHESIS, TokenType::COLON, NonTerminal::FUNCDECLTAIL, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::FUNCDECL, { TokenType::FUNC, TokenType::ID, TokenType::LEFT_PARENTHESIS, NonTerminal::FPARAMS, TokenType::RIGHT_PARENTHESIS, TokenType::COLON, NonTerminal::FUNCDECLTAIL, TokenType::SEMICOLON }, "<FuncDecl> ::= 'func' 'id' '(' <FParams> ')' ':' <FuncDeclTail> ';'");

		AST* fParams = nullptr;
		AST* returnType = nullptr;
		if (match(TokenType::FUNC) && match(TokenType::ID) && match(TokenType::LEFT_PARENTHESIS) && FParams(&fParams) && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::COLON) && FuncDeclTail(&returnType) && match(TokenType::SEMICOLON)) {
			AST* funcId = attributeStack.top(); attributeStack.pop();
			*funcDecl = ASTFactory::makeFamily(CompositeConcept::FUNCDECL, { funcId, fParams, returnType });
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::VarDecl(AST** varDecl)
{
	if (!skipErrors(NonTerminal::VARDECL)) { return false; }
	//<VarDecl> ::= <Type> 'id' <ArraySizeRept> ';' 
	if (isElementOfFirst({ NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, TokenType::SEMICOLON })) {
		applyDerivation(NonTerminal::VARDECL, { NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, TokenType::SEMICOLON }, "<VarDecl> ::= <Type> 'id' <ArraySizeRept> ';'");

		AST* type = nullptr;
		AST* arraySizeRept = nullptr;
		if (Type(&type) && match(TokenType::ID) && ArraySizeRept(&arraySizeRept) && match(TokenType::SEMICOLON)) {
			AST* varId = attributeStack.top(); attributeStack.pop();
			AST* arraySizeReptList = nullptr;
			if (arraySizeRept) {
				arraySizeReptList = ASTFactory::makeFamily(CompositeConcept::ARRAYSIZEREPTLIST, { arraySizeRept });
			}
			*varDecl = ASTFactory::makeFamily(CompositeConcept::VARDECL, { type, varId, arraySizeReptList });
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::IntNum(AST** intNum)
{
	if (!skipErrors(NonTerminal::INTNUM)) { return false; }
	//<IntNum> ::= 'intnum'
	if (isElementOfFirst({ TokenType::INTEGER })) {
		applyDerivation(NonTerminal::INTNUM, { TokenType::INTEGER }, "<IntNum> ::= 'intnum'");
		if (match(TokenType::INTEGER)) {
			*intNum = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//< IntNum > ::= EPSILON
	else if (isElementOfFollow(NonTerminal::INTNUM)) {
		applyDerivation(NonTerminal::INTNUM, { TokenType::EPSILON }, "<IntNum> :: = EPSILON'");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStat(AST** funcOrAssignStat)
{
	if (!skipErrors(NonTerminal::FUNCORASSIGNSTAT)) { return false; }
	//<FuncOrAssignStat> ::= 'id' <FuncOrAssignStatIdnest> 
	if (isElementOfFirst({ TokenType::ID, NonTerminal::FUNCORASSIGNSTATIDNEST })) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTAT, { TokenType::ID, NonTerminal::FUNCORASSIGNSTATIDNEST }, "<FuncOrAssignStat> ::= 'id' <FuncOrAssignStatIdnest>");

		if (match(TokenType::ID) && FuncOrAssignStatIDNest(funcOrAssignStat, attributeStack.top())) {
			attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Expr(AST** exprS)
{
	if (!skipErrors(NonTerminal::EXPR)) { return false; }
	//<Expr> ::= <ArithExpr> <ExprTail> 
	if (isElementOfFirst({ NonTerminal::ARITHEXPR, NonTerminal::EXPRTAIL })) {
		applyDerivation(NonTerminal::EXPR, { NonTerminal::ARITHEXPR, NonTerminal::EXPRTAIL }, "<Expr> ::= <ArithExpr> <ExprTail>");

		AST* lhsArithExpr = nullptr;
		if (ArithExpr(&lhsArithExpr) && ExprTail(exprS, lhsArithExpr)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::StatBlock(AST** statBlock)
{
	if (!skipErrors(NonTerminal::STATBLOCK)) { return false; }
	//<StatBlock> ::= '{' <StatementList> '}' 
	if (isElementOfFirst({ TokenType::LEFT_CURLY_BRACKET, NonTerminal::STATEMENTLIST, TokenType::RIGHT_CURLY_BRACKET })) {
		applyDerivation(NonTerminal::STATBLOCK, { TokenType::LEFT_CURLY_BRACKET, NonTerminal::STATEMENTLIST, TokenType::RIGHT_CURLY_BRACKET }, "<StatBlock> ::= '{' <StatementList> '}'");
		AST* statementList = nullptr;
		if (match(TokenType::LEFT_CURLY_BRACKET) && StatementList(&statementList) && match(TokenType::RIGHT_CURLY_BRACKET)) {
			*statBlock = ASTFactory::makeFamily(CompositeConcept::STATEMENTLIST, { statementList });
			return true;
		}
		else {
			return false;
		}
	}
	//<StatBlock> :: = <Statement>
	else if (isElementOfFirst({ NonTerminal::STATEMENT })) {
		applyDerivation(NonTerminal::STATBLOCK, { NonTerminal::STATEMENT }, "<StatBlock> ::= <Statement>");
		AST* statement = nullptr;
		if (Statement(&statement)) {
			*statBlock = ASTFactory::makeFamily(CompositeConcept::STATEMENTLIST, { statement });
			return true;
		}
		else {
			return false;
		}
	}
	//<StatBlock> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::STATBLOCK)) {
		applyDerivation(NonTerminal::STATBLOCK, { TokenType::EPSILON }, "<StatBlock> :: = EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Variable(AST** variable)
{
	if (!skipErrors(NonTerminal::VARIABLE)) { return false; }
	//<Variable> ::= 'id' <VariableIdnest> 
	if (isElementOfFirst({ TokenType::ID, NonTerminal::VARIABLEIDNEST })) {
		applyDerivation(NonTerminal::VARIABLE, { TokenType::ID, NonTerminal::VARIABLEIDNEST }, "<Variable> ::= 'id' <VariableIdnest>");
		AST* variableIdNest = nullptr;
		if (match(TokenType::ID) && VariableIDNest(&variableIdNest, attributeStack.top())) {
			AST* varId = attributeStack.top(); attributeStack.pop();
			*variable = variableIdNest;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStatIDNest(AST** funcOrAssignStatIDNest, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCORASSIGNSTATIDNEST)) { return false; }
	//assignment
	//<FuncOrAssignStatIdnest> ::= <IndiceRep> <FuncOrAssignStatIdnestVarTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL })) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTATIDNEST, { NonTerminal::INDICEREP, NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL }, "<FuncOrAssignStatIdnest> ::= <IndiceRep> <FuncOrAssignStatIdnestVarTail>");
		AST* indiceRep = nullptr;
		if (IndiceRep(&indiceRep)) {
			if (indiceRep) {
				AST* varChildren = lhsId->makeSiblings(ASTFactory::makeFamily(CompositeConcept::INDICEREPLIST, { indiceRep }));
				lhsId = ASTFactory::makeFamily(CompositeConcept::VARCALLSTAT, { varChildren });
			}
			if (FuncOrAssignStatIDNestVarTail(funcOrAssignStatIDNest, lhsId)) {
				return true;
			}
		}
		else {
			return false;
		}
	}
	//function call
	//<FuncOrAssignStatIdnest> :: = '(' <AParams> ')' <FuncOrAssignStatIdnestFuncTail>
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL })) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTATIDNEST, { TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL }, "<FuncOrAssignStatIdnest> ::= '(' <AParams> ')' <FuncOrAssignStatIdnestFuncTail>");
		AST* aParams = nullptr;
		if (match(TokenType::LEFT_PARENTHESIS) && AParams(&aParams) && match(TokenType::RIGHT_PARENTHESIS)) {
			AST* funcCall = ASTFactory::makeFamily(CompositeConcept::FUNCCALLSTAT, { lhsId, aParams });
			if (FuncOrAssignStatIDNestFuncTail(funcOrAssignStatIDNest, funcCall)) {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ArithExpr(AST** arithExpr)
{
	if (!skipErrors(NonTerminal::ARITHEXPR)) { return false; }
	//<ArithExpr> ::= <Term> <ArithExprTail> 
	if (isElementOfFirst({ NonTerminal::TERM, NonTerminal::ARITHEXPRTAIL })) {
		applyDerivation(NonTerminal::ARITHEXPR, { NonTerminal::TERM, NonTerminal::ARITHEXPRTAIL }, "<ArithExpr> ::= <Term> <ArithExprTail>");

		AST* lhsTerm = nullptr;
		AST* arithExprTail = nullptr;
		if (Term(&lhsTerm) && ArithExprTail(arithExpr, lhsTerm)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ExprTail(AST** exprTail, AST* lhsArithExpr)
{
	if (!skipErrors(NonTerminal::EXPRTAIL)) { return false; }
	//<ExprTail> ::= <RelOp> <ArithExpr> 
	if (isElementOfFirst({ NonTerminal::RELOP, NonTerminal::ARITHEXPR })) {
		applyDerivation(NonTerminal::EXPRTAIL, { NonTerminal::RELOP, NonTerminal::ARITHEXPR }, "<ExprTail> ::= <RelOp> <ArithExpr>");

		AST* relOp = nullptr;
		AST* rhsArithExpr = nullptr;
		if (RelOp(&relOp) && ArithExpr(&rhsArithExpr)) {
			ASTFactory::makeFamily(relOp, { lhsArithExpr, rhsArithExpr });
			*exprTail = relOp;
			return true;
		}
		else {
			return false;
		}
	}
	//<ExprTail> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::EXPRTAIL)) {
		*exprTail = lhsArithExpr;
		applyDerivation(NonTerminal::EXPRTAIL, { TokenType::EPSILON }, "<ExprTail> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::VariableIDNest(AST** variableIdNest, AST* lhsId)
{
	if (!skipErrors(NonTerminal::VARIABLEIDNEST)) { return false; }
	//<VariableIdnest> ::= <IndiceRep> <VariableIdnestTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, NonTerminal::VARIABLEIDNESTTAIL })) {
		applyDerivation(NonTerminal::VARIABLEIDNEST, { NonTerminal::INDICEREP, NonTerminal::VARIABLEIDNESTTAIL }, "<VariableIdnest> ::= <IndiceRep> <VariableIdnestTail>");
		AST* indiceRep = nullptr;
		AST* variableIdNestTail = nullptr;
		if (IndiceRep(&indiceRep) && VariableIDNestTail(&variableIdNestTail, lhsId)) {
			if (indiceRep) {
				lhsId->makeSiblings(indiceRep);
			}
			*variableIdNest = variableIdNestTail;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::IndiceRep(AST** indiceRep)
{
	if (!skipErrors(NonTerminal::INDICEREP)) { return false; }
	//<IndiceRep> ::= '[' <Expr> ']' <IndiceRep> 
	if (isElementOfFirst({ TokenType::LEFT_SQUARE_BRACKET, NonTerminal::EXPR, TokenType::RIGHT_SQUARE_BRACKET, NonTerminal::INDICEREP })) {
		applyDerivation(NonTerminal::INDICEREP, { TokenType::LEFT_SQUARE_BRACKET, NonTerminal::EXPR, TokenType::RIGHT_SQUARE_BRACKET, NonTerminal::INDICEREP }, "<IndiceRep> ::= '[' <Expr> ']' <IndiceRep>");
		AST* expr = nullptr;
		AST* indiceRepSibling = nullptr;
		if (match(TokenType::LEFT_SQUARE_BRACKET) && Expr(&expr) && match(TokenType::RIGHT_SQUARE_BRACKET) && IndiceRep(&indiceRepSibling)) {
			expr->makeSiblings(indiceRepSibling);
			*indiceRep = expr;
			return true;
		}
		else {
			return false;
		}
	}
	//<IndiceRep> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::INDICEREP)) {
		applyDerivation(NonTerminal::INDICEREP, { TokenType::EPSILON }, "<IndiceRep> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStatIDNestVarTail(AST** funcOrAssignStatIDNestVarTail, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL)) { return false; }
	//function call
	//<FuncOrAssignStatIdnestVarTail> ::= '.' 'id' <FuncOrAssignStatIdnest> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCORASSIGNSTATIDNEST })) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL, { TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCORASSIGNSTATIDNEST }, "<FuncOrAssignStatIdnestVarTail> ::= '.' 'id' <FuncOrAssignStatIdnest>");
		AST* funcOrAssignStatIDNest = nullptr;

		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncOrAssignStatIDNest(&funcOrAssignStatIDNest, attributeStack.top())) {
			AST* varId = attributeStack.top(); attributeStack.pop();
			AST* dot = attributeStack.top(); attributeStack.pop();
			ASTFactory::makeFamily(dot, { lhsId, funcOrAssignStatIDNest });
			*funcOrAssignStatIDNestVarTail = dot;
			return true;
		}
		else {
			return false;
		}
	}
	//assignment
	//<FuncOrAssignStatIdnestVarTail> ::= <AssignStatTail> 
	else if (isElementOfFirst({ NonTerminal::ASSIGNSTATTAIL })) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL, { NonTerminal::ASSIGNSTATTAIL }, "<FuncOrAssignStatIdnestVarTail> ::= <AssignStatTail>");
		AST* assignStatTail = nullptr;
		if (AssignStatTail(&assignStatTail, lhsId)) {
			*funcOrAssignStatIDNestVarTail = assignStatTail;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AParams(AST** aParams)
{
	if (!skipErrors(NonTerminal::APARAMS)) { return false; }
	//<AParams> ::= <Expr> <AParamsTail> 
	if (isElementOfFirst({ NonTerminal::EXPR, NonTerminal::APARAMSTAIL })) {
		applyDerivation(NonTerminal::APARAMS, { NonTerminal::EXPR, NonTerminal::APARAMSTAIL }, "<AParams> ::= <Expr> <AParamsTail>");

		AST* expr = nullptr;
		AST* aParamsTail = nullptr;
		if (Expr(&expr) && AParamsTail(&aParamsTail)) {
			*aParams = ASTFactory::makeFamily(CompositeConcept::APARAMSLIST, { expr, aParamsTail });
			return true;
		}
		else {
			return false;
		}
	}
	//<AParams> ::= EPSILON 
	else if (isElementOfFollow({ NonTerminal::APARAMS })) {
		applyDerivation(NonTerminal::APARAMS, { TokenType::EPSILON }, "<AParams> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStatIDNestFuncTail(AST** funcOrAssignStatIdNestFuncTail, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL)) { return false; }
	//<FuncOrAssignStatIdnestFuncTail> ::= '.' 'id' <FuncStatTail> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL })) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL, { TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL }, "<FuncOrAssignStatIdnestFuncTail> ::= '.' 'id' <FuncStatTail>");
		AST* funcStatTail = nullptr;
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncStatTail(&funcStatTail, attributeStack.top())) {
			AST* rhsId = attributeStack.top(); attributeStack.pop();
			AST* dot = attributeStack.top(); attributeStack.pop();
			ASTFactory::makeFamily(dot, { lhsId, funcStatTail });
			*funcOrAssignStatIdNestFuncTail = dot;
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrAssignStatIdnestFuncTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL)) {
		applyDerivation(NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL, { TokenType::EPSILON }, "<FuncOrAssignStatIdnestFuncTail> ::= EPSILON");
		*funcOrAssignStatIdNestFuncTail = lhsId;
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Term(AST** term)
{
	if (!skipErrors(NonTerminal::TERM)) { return false; }
	//<Term> ::= <Factor> <TermTail> 
	if (isElementOfFirst({ NonTerminal::FACTOR, NonTerminal::TERMTAIL })) {
		applyDerivation(NonTerminal::TERM, { NonTerminal::FACTOR, NonTerminal::TERMTAIL }, "<Term> ::= <Factor> <TermTail>");

		AST* lhsFactor = nullptr;
		AST* termTail = nullptr;
		if (Factor(&lhsFactor, nullptr) && TermTail(&termTail, lhsFactor)) {
			*term = termTail;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ArithExprTail(AST** arithExprTail, AST* lhsTerm)
{
	if (!skipErrors(NonTerminal::ARITHEXPRTAIL)) { return false; }
	//<ArithExprTail> ::= <AddOp> <Term> <ArithExprTail> 
	if (isElementOfFirst({ NonTerminal::ADDOP, NonTerminal::TERM, NonTerminal::ARITHEXPRTAIL })) {
		applyDerivation(NonTerminal::ARITHEXPRTAIL, { NonTerminal::ADDOP, NonTerminal::TERM, NonTerminal::ARITHEXPRTAIL }, "<ArithExprTail> ::= <AddOp> <Term> <ArithExprTail>");

		AST* addOp = nullptr;
		AST* rhsTerm = nullptr;
		AST* rhsTermExpr = nullptr;
		if (AddOp(&addOp) && Term(&rhsTerm) && ArithExprTail(&rhsTermExpr, rhsTerm)) {
			ASTFactory::makeFamily(addOp, { lhsTerm, rhsTermExpr });
			*arithExprTail = addOp;
			return true;
		}
		else {
			return false;
		}
	}
	//<ArithExprTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::ARITHEXPRTAIL)) {
		*arithExprTail = lhsTerm;
		applyDerivation(NonTerminal::ARITHEXPRTAIL, { TokenType::EPSILON }, "<ArithExprTail> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::RelOp(AST** relOp)
{
	if (!skipErrors(NonTerminal::RELOP)) { return false; }
	//<RelOp> ::= 'eq' 
	if (isElementOfFirst({ TokenType::EQUAL_TO })) {
		applyDerivation(NonTerminal::RELOP, { TokenType::EQUAL_TO }, "<RelOp> ::= 'eq'");
		if (match(TokenType::EQUAL_TO)) {
			*relOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'neq' 
	else if (isElementOfFirst({ TokenType::NOT_EQUAL_TO })) {
		applyDerivation(NonTerminal::RELOP, { TokenType::NOT_EQUAL_TO }, "<RelOp> ::= 'neq'");
		if (match(TokenType::NOT_EQUAL_TO)) {
			*relOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'lt' 
	else if (isElementOfFirst({ TokenType::LESS_THAN })) {
		applyDerivation(NonTerminal::RELOP, { TokenType::LESS_THAN }, "<RelOp> ::= 'lt'");

		if (match(TokenType::LESS_THAN)) {
			*relOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'gt' 
	else if (isElementOfFirst({ TokenType::GREATER_THAN })) {
		applyDerivation(NonTerminal::RELOP, { TokenType::GREATER_THAN }, "<RelOp> ::= 'gt'");

		if (match(TokenType::GREATER_THAN)) {
			*relOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'leq' 
	else if (isElementOfFirst({ TokenType::LESS_THAN_EQUAL_TO })) {
		applyDerivation(NonTerminal::RELOP, { TokenType::LESS_THAN_EQUAL_TO }, "<RelOp> ::= 'leq'");

		if (match(TokenType::LESS_THAN_EQUAL_TO)) {
			*relOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'geq' 
	else if (isElementOfFirst({ TokenType::GREATER_THAN_EQUAL_TO })) {
		applyDerivation(NonTerminal::RELOP, { TokenType::GREATER_THAN_EQUAL_TO }, "<RelOp> ::= 'geq'");

		if (match(TokenType::GREATER_THAN_EQUAL_TO)) {
			*relOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::VariableIDNestTail(AST** variableIdNestTail, AST* lhsId)
{
	if (!skipErrors(NonTerminal::VARIABLEIDNESTTAIL)) { return false; }
	//<VariableIdnestTail> ::= '.' 'id' <VariableIdnest> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::VARIABLEIDNEST })) {
		applyDerivation(NonTerminal::VARIABLEIDNESTTAIL, { TokenType::PERIOD, TokenType::ID, NonTerminal::VARIABLEIDNEST }, "<VariableIdnestTail> ::= '.' 'id' <VariableIdnest>");
		AST* variableIdNest = nullptr;
		if (match(TokenType::PERIOD) && match(TokenType::ID) && VariableIDNest(&variableIdNest, attributeStack.top())) {
			AST* rhsId = attributeStack.top(); attributeStack.pop();
			AST* dot = attributeStack.top(); attributeStack.pop();
			ASTFactory::makeFamily(dot, { lhsId, variableIdNest });
			*variableIdNestTail = dot;
			return true;
		}
		else {
			return false;
		}
	}
	//<VariableIdnestTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::VARIABLEIDNESTTAIL)) {
		applyDerivation(NonTerminal::VARIABLEIDNESTTAIL, { TokenType::EPSILON }, "<VariableIdnestTail> ::= EPSILON");
		*variableIdNestTail = lhsId;
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AssignStatTail(AST** assignStatTail, AST* lhsAssignStat)
{
	if (!skipErrors(NonTerminal::ASSIGNSTATTAIL)) { return false; }
	//<AssignStatTail> ::= <AssignOp> <Expr> 
	if (isElementOfFirst({ NonTerminal::ASSIGNOP, NonTerminal::EXPR })) {
		applyDerivation(NonTerminal::ASSIGNSTATTAIL, { NonTerminal::ASSIGNOP, NonTerminal::EXPR }, "<AssignStatTail> ::= <AssignOp> <Expr>");

		AST* assignOp = nullptr;
		AST* rhsExpr = nullptr;
		if (AssignOp(&assignOp) && Expr(&rhsExpr)) {
			ASTFactory::makeFamily(assignOp, { lhsAssignStat, rhsExpr });
			*assignStatTail = assignOp;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AParamsTail(AST** aParamsTail)
{
	if (!skipErrors(NonTerminal::APARAMSTAIL)) { return false; }
	//<AParamsTail> ::= ',' <Expr> <AParamsTail> 
	if (isElementOfFirst({ TokenType::COMMA, NonTerminal::EXPR, NonTerminal::APARAMSTAIL })) {
		applyDerivation(NonTerminal::APARAMSTAIL, { TokenType::COMMA, NonTerminal::EXPR, NonTerminal::APARAMSTAIL }, "<AParamsTail> ::= ',' <Expr> <AParamsTail>");

		AST* expr = nullptr;
		AST* aParamsTailSibling = nullptr;
		if (match(TokenType::COMMA) && Expr(&expr) && AParamsTail(&aParamsTailSibling)) {
			expr->makeSiblings(aParamsTailSibling);
			*aParamsTail = expr;
			return true;
		}
		else {
			return false;
		}
	}
	//<AParamsTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::APARAMSTAIL)) {
		applyDerivation(NonTerminal::APARAMSTAIL, { TokenType::EPSILON }, "<AParamsTail> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncStatTail(AST** funcStatTail, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCSTATTAIL)) { return false; }
	//<FuncStatTail> ::= <IndiceRep> '.' 'id' <FuncStatTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL })) {
		applyDerivation(NonTerminal::FUNCSTATTAIL, { NonTerminal::INDICEREP, TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL }, "<FuncStatTail> ::= <IndiceRep> '.' 'id' <FuncStatTail>");
		AST* indiceRep = nullptr;
		AST* funcStatTailSibling = nullptr;
		if (IndiceRep(&indiceRep) && match(TokenType::PERIOD) && match(TokenType::ID) && FuncStatTail(&funcStatTailSibling, attributeStack.top())) {
			AST* dot = attributeStack.top(); attributeStack.pop();
			AST* rhsId = attributeStack.top(); attributeStack.pop();
			if (indiceRep) {
				lhsId->makeSiblings(indiceRep);
			}
			ASTFactory::makeFamily(dot, { lhsId, funcStatTailSibling });
			*funcStatTail = dot;
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncStatTail> ::= '(' <AParams> ')' <FuncStatTailIdnest> 
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCSTATTAILIDNEST })) {
		applyDerivation(NonTerminal::FUNCSTATTAIL, { TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCSTATTAILIDNEST }, "<FuncStatTail> ::= '(' <AParams> ')' <FuncStatTailIdnest>");
		AST* aParams = nullptr;
		AST* funcStatTailIdNest = nullptr;
		if (match(TokenType::LEFT_PARENTHESIS) && AParams(&aParams) && match(TokenType::RIGHT_PARENTHESIS) && FuncStatTailIDNest(&funcStatTailIdNest, lhsId)) {
			lhsId->makeSiblings(aParams);
			*funcStatTail = funcStatTailIdNest;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Factor(AST** factor, AST* lhsFactor)
{
	if (!skipErrors(NonTerminal::FACTOR)) { return false; }
	//<Factor> ::= 'intnum' 
	if (isElementOfFirst({ TokenType::INTEGER })) {
		applyDerivation(NonTerminal::FACTOR, { TokenType::INTEGER }, "<Factor> ::= 'intnum'");
		if (match(TokenType::INTEGER)) {
			*factor = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'floatnum' 
	else if (isElementOfFirst({ TokenType::FLOAT })) {
		applyDerivation(NonTerminal::FACTOR, { TokenType::FLOAT }, "<Factor> ::= 'floatnum'");
		if (match(TokenType::FLOAT)) {
			*factor = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'stringlit' 
	else if (isElementOfFirst({ TokenType::STRING })) {
		applyDerivation(NonTerminal::FACTOR, { TokenType::STRING }, "<Factor> ::= 'stringlit'");
		if (match(TokenType::STRING)) {
			*factor = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= '(' <Expr> ')' 
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS })) {
		applyDerivation(NonTerminal::FACTOR, { TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS }, "<Factor> ::= '(' <Expr> ')'");
		AST* expr = nullptr;
		if (match(TokenType::LEFT_PARENTHESIS) && Expr(&expr) && match(TokenType::RIGHT_PARENTHESIS)) {
			*factor = expr;
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'not' <Factor> 
	else if (isElementOfFirst({ TokenType::NOT, NonTerminal::FACTOR })) {
		applyDerivation(NonTerminal::FACTOR, { TokenType::NOT, NonTerminal::FACTOR }, "<Factor> ::= 'not' <Factor>");
		AST* factorS = nullptr;
		if (match(TokenType::NOT) && Factor(&factorS, nullptr)) {
			AST* notOp = attributeStack.top(); attributeStack.pop();
			notOp->adoptChildren(factorS);
			*factor = notOp;
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'qm' '[' <Expr> ':' <Expr> ':' <Expr> ']' 
	else if (isElementOfFirst({ TokenType::QUESTION_MARK, TokenType::LEFT_SQUARE_BRACKET, NonTerminal::EXPR, TokenType::COLON,  NonTerminal::EXPR, TokenType::COLON, NonTerminal::EXPR, TokenType::RIGHT_SQUARE_BRACKET })) {
		applyDerivation(NonTerminal::FACTOR, { TokenType::QUESTION_MARK, TokenType::LEFT_SQUARE_BRACKET, NonTerminal::EXPR, TokenType::COLON,  NonTerminal::EXPR, TokenType::COLON, NonTerminal::EXPR, TokenType::RIGHT_SQUARE_BRACKET }, "<Factor> ::= 'qm' '[' <Expr> ':' <Expr> ':' <Expr> ']'");
		AST* truthExpr = nullptr;
		AST* branch1Expr = nullptr;
		AST* branch2Expr = nullptr;
		if (match(TokenType::QUESTION_MARK) && match(TokenType::LEFT_SQUARE_BRACKET) && Expr(&truthExpr) && match(TokenType::COLON) && Expr(&branch1Expr) && match(TokenType::COLON) && Expr(&branch2Expr) && match(TokenType::RIGHT_SQUARE_BRACKET)) {
			AST* ternary = ASTFactory::makeFamily(CompositeConcept::TERNARY, { truthExpr, branch1Expr, branch2Expr });
			*factor = ternary;
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= <Sign> <Factor> 
	else if (isElementOfFirst({ NonTerminal::SIGN, NonTerminal::FACTOR })) {
		applyDerivation(NonTerminal::FACTOR, { NonTerminal::SIGN, NonTerminal::FACTOR }, "<Factor> ::= <Sign> <Factor>");
		AST* sign = nullptr;
		AST* rhsFactorSibling = nullptr;
		if (Sign(&sign) && Factor(&rhsFactorSibling, lhsFactor)) {
			ASTFactory::makeFamily(sign, { lhsFactor, rhsFactorSibling });
			*factor = sign;
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= <FuncOrVar> 
	else if (isElementOfFirst({ NonTerminal::FUNCORVAR })) {
		applyDerivation(NonTerminal::FACTOR, { NonTerminal::FUNCORVAR }, "<Factor> ::= <FuncOrVar>");
		AST* funcOrVar = nullptr;
		if (FuncOrVar(&funcOrVar)) {
			*factor = funcOrVar;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::TermTail(AST** termTail, AST* lhsFactor)
{
	if (!skipErrors(NonTerminal::TERMTAIL)) { return false; }
	//<TermTail> ::= <MultOp> <Factor> <TermTail> 
	if (isElementOfFirst({ NonTerminal::MULTOP, NonTerminal::FACTOR, NonTerminal::TERMTAIL })) {
		applyDerivation(NonTerminal::TERMTAIL, { NonTerminal::MULTOP, NonTerminal::FACTOR, NonTerminal::TERMTAIL }, "<TermTail> ::= <MultOp> <Factor> <TermTail>");

		AST* multOp = nullptr;
		AST* rhsFactor = nullptr;
		AST* termTailChild = nullptr;

		if (MultOp(&multOp) && Factor(&rhsFactor, nullptr) && TermTail(&termTailChild, rhsFactor)) {
			ASTFactory::makeFamily(multOp, { lhsFactor, termTailChild });
			*termTail = multOp;
			return true;
		}
		else {
			return false;
		}
	}
	//<TermTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::TERMTAIL)) {
		*termTail = lhsFactor;
		applyDerivation(NonTerminal::TERMTAIL, { TokenType::EPSILON }, "<TermTail> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AddOp(AST** addOp)
{
	if (!skipErrors(NonTerminal::ADDOP)) { return false; }
	//<AddOp> ::= '+' 
	if (isElementOfFirst({ TokenType::ADDITION })) {
		applyDerivation(NonTerminal::ADDOP, { TokenType::ADDITION }, "<AddOp> ::= '+'");
		if (match(TokenType::ADDITION)) {
			*addOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<AddOp> ::= '-' 
	else if (isElementOfFirst({ TokenType::SUBTRACTION })) {
		applyDerivation(NonTerminal::ADDOP, { TokenType::SUBTRACTION }, "<AddOp> ::= '-'");
		if (match(TokenType::SUBTRACTION)) {
			*addOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<AddOp> ::= 'or' 
	else if (isElementOfFirst({ TokenType::OR })) {
		applyDerivation(NonTerminal::ADDOP, { TokenType::OR }, "<AddOp> ::= 'or'");
		if (match(TokenType::OR)) {
			*addOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AssignOp(AST** assignOp)
{
	if (!skipErrors(NonTerminal::ASSIGNOP)) { return false; }
	//<AssignOp> ::= 'assign'
	if (isElementOfFirst({ TokenType::ASSIGNMENT })) {
		applyDerivation(NonTerminal::ASSIGNOP, { TokenType::ASSIGNMENT }, "<AssignOp> ::= 'assign'");
		if (match(TokenType::ASSIGNMENT)) {
			*assignOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncStatTailIDNest(AST** funcStatTailIdNest, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCSTATTAILIDNEST)) { return false; }
	//<FuncStatTailIdnest> ::= '.' 'id' <FuncStatTail> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL })) {
		applyDerivation(NonTerminal::FUNCSTATTAILIDNEST, { TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL }, "<FuncStatTailIdnest> ::= '.' 'id' <FuncStatTail>");
		AST* funcStatTail = nullptr;
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncStatTail(&funcStatTail, attributeStack.top())) {
			AST* statId = attributeStack.top(); attributeStack.pop();
			AST* dot = attributeStack.top(); attributeStack.pop();
			ASTFactory::makeFamily(dot, { lhsId, funcStatTail });
			*funcStatTailIdNest = dot;
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncStatTailIdnest> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCSTATTAILIDNEST)) {
		applyDerivation(NonTerminal::FUNCSTATTAILIDNEST, { TokenType::EPSILON }, "<FuncStatTailIdnest> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
	return false;
}

bool RecursiveDescentPredictiveParser::FuncOrVar(AST** funcOrVar)
{
	if (!skipErrors(NonTerminal::FUNCORVAR)) { return false; }
	//<FuncOrVar> ::= 'id' <FuncOrVarIdnest> 
	if (isElementOfFirst({ TokenType::ID, NonTerminal::FUNCORVARIDNEST })) {
		applyDerivation(NonTerminal::FUNCORVAR, { TokenType::ID, NonTerminal::FUNCORVARIDNEST }, "<FuncOrVar> ::= 'id' <FuncOrVarIdnest>");
		AST* funcOrVarIdNest = nullptr;
		if (match(TokenType::ID) && FuncOrVarIDNest(&funcOrVarIdNest, attributeStack.top())) {
			AST* id = attributeStack.top(); attributeStack.pop();
			*funcOrVar = funcOrVarIdNest;
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool RecursiveDescentPredictiveParser::Sign(AST** sign)
{
	if (!skipErrors(NonTerminal::SIGN)) { return false; }
	//<Sign> ::= '+' 
	if (isElementOfFirst({ TokenType::ADDITION })) {
		applyDerivation(NonTerminal::SIGN, { TokenType::ADDITION }, "<Sign> :: = '+'");
		if (match(TokenType::ADDITION)) {
			*sign = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<Sign> ::= '-' 
	else if (isElementOfFirst({ TokenType::SUBTRACTION })) {
		applyDerivation(NonTerminal::SIGN, { TokenType::SUBTRACTION }, "<Sign> :: = '-'");
		if (match(TokenType::SUBTRACTION)) {
			*sign = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::MultOp(AST** multOp)
{
	if (!skipErrors(NonTerminal::MULTOP)) { return false; }
	//<MultOp> ::= '*' 
	if (isElementOfFirst({ TokenType::MULTIPLICATION })) {
		applyDerivation(NonTerminal::MULTOP, { TokenType::MULTIPLICATION }, "<MultOp> ::= '*'");
		if (match(TokenType::MULTIPLICATION)) {
			*multOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<MultOp> ::= '/' 
	else if (isElementOfFirst({ TokenType::DIVISION })) {
		applyDerivation(NonTerminal::MULTOP, { TokenType::DIVISION }, "<MultOp> ::= '/'");
		if (match(TokenType::DIVISION)) {
			*multOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<MultOp> ::= 'and'
	else if (isElementOfFirst({ TokenType::AND })) {
		applyDerivation(NonTerminal::MULTOP, { TokenType::AND }, "<MultOp> ::= 'and'");
		if (match(TokenType::AND)) {
			*multOp = attributeStack.top(); attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrVarIDNest(AST** funcOrVarIdNest, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCORVARIDNEST)) { return false; }
	// function
	//<FuncOrVarIdnest> ::= '(' <AParams> ')' <FuncOrVarIdnestTail> 
	if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCORVARIDNESTTAIL })) {
		applyDerivation(NonTerminal::FUNCORVARIDNEST, { TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCORVARIDNESTTAIL }, "<FuncOrVarIdnest> ::= '(' <AParams> ')' <FuncOrVarIdnestTail>");
		AST* aParams = nullptr;
		AST* funcOrVarIdNestTail = nullptr;
		if (match(TokenType::LEFT_PARENTHESIS) && AParams(&aParams) && match(TokenType::RIGHT_PARENTHESIS)) {
			AST* funcCall = ASTFactory::makeFamily(CompositeConcept::FUNCCALLSTAT, { lhsId, aParams });

			if (FuncOrVarIDNestTail(&funcOrVarIdNestTail, funcCall)) {
				*funcOrVarIdNest = funcOrVarIdNestTail;
				return true;
			}
		}
		else {
			return false;
		}
	}
	// variable
	//<FuncOrVarIdnest> ::= <IndiceRep> <FuncOrVarIdnestTail> 
	else if (isElementOfFirst({ NonTerminal::INDICEREP, NonTerminal::FUNCORVARIDNESTTAIL })) {
		applyDerivation(NonTerminal::FUNCORVARIDNEST, { NonTerminal::INDICEREP, NonTerminal::FUNCORVARIDNESTTAIL }, "<FuncOrVarIdnest> ::= <IndiceRep> <FuncOrVarIdnestTail>");
		AST* indiceRep = nullptr;
		AST* funcOrVarIdNestTail = nullptr;
		if (IndiceRep(&indiceRep)) {
			AST* indiceList = nullptr;
			if (indiceRep) {
				indiceList = ASTFactory::makeFamily(CompositeConcept::INDICEREPLIST, { indiceRep });
			}
			AST* varStat = ASTFactory::makeFamily(CompositeConcept::VARCALLSTAT, { lhsId, indiceList });
			if (FuncOrVarIDNestTail(&funcOrVarIdNestTail, varStat)) {
				*funcOrVarIdNest = funcOrVarIdNestTail;
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrVarIDNestTail(AST** funcOrVarIdNestTail, AST* lhsId)
{
	if (!skipErrors(NonTerminal::FUNCORVARIDNESTTAIL)) { return false; }
	//<FuncOrVarIdnestTail> ::= '.' 'id' <FuncOrVarIdnest> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCORVARIDNEST })) {
		applyDerivation(NonTerminal::FUNCORVARIDNESTTAIL, { TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCORVARIDNEST }, "<FuncOrVarIdnestTail> ::= '.' 'id' <FuncOrVarIdnest>");
		AST* funcOrVarIDNest = nullptr;
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncOrVarIDNest(&funcOrVarIDNest, attributeStack.top())) {
			AST* rhsId = attributeStack.top(); attributeStack.pop();
			AST* dot = attributeStack.top(); attributeStack.pop();
			ASTFactory::makeFamily(dot, { lhsId, funcOrVarIDNest });
			*funcOrVarIdNestTail = dot;
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrVarIdnestTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::FUNCORVARIDNESTTAIL)) {
		applyDerivation(NonTerminal::FUNCORVARIDNESTTAIL, { TokenType::EPSILON }, "<FuncOrVarIdnestTail> ::= EPSILON");
		*funcOrVarIdNestTail = lhsId;
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Function(AST** functionS)
{
	if (!skipErrors(NonTerminal::FUNCTION)) { return false; }
	//<Function> ::= <FuncHead> <FuncBody> 
	if (isElementOfFirst({ NonTerminal::FUNCHEAD, NonTerminal::FUNCBODY })) {
		applyDerivation(NonTerminal::FUNCTION, { NonTerminal::FUNCHEAD, NonTerminal::FUNCBODY }, "<FuncHead> ::= 'func' 'id' <ClassMethod> '(' <FParams> ')' ':' <FuncDeclTail> ");

		AST* funcHeadS = nullptr;
		AST* funcBodyS = nullptr;
		if (FuncHead(&funcHeadS) && FuncBody(&funcBodyS)) {
			funcHeadS->makeSiblings(funcBodyS);
			*functionS = funcHeadS;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncHead(AST** funcHeadS)
{
	if (!skipErrors(NonTerminal::FUNCHEAD)) { return false; }
	//<FuncHead> ::= 'func' 'id' <ClassMethod> '(' <FParams> ')' ':' <FuncDeclTail> 
	if (isElementOfFirst({ TokenType::FUNC, TokenType::ID, NonTerminal::CLASSMETHOD, TokenType::LEFT_PARENTHESIS, NonTerminal::FPARAMS, TokenType::RIGHT_PARENTHESIS, TokenType::COLON, NonTerminal::FUNCDECLTAIL })) {
		applyDerivation(NonTerminal::FUNCHEAD, { TokenType::FUNC, TokenType::ID, NonTerminal::CLASSMETHOD, TokenType::LEFT_PARENTHESIS, NonTerminal::FPARAMS, TokenType::RIGHT_PARENTHESIS, TokenType::COLON, NonTerminal::FUNCDECLTAIL }, "<FuncHead> ::= 'func' 'id' <ClassMethod> '(' <FParams> ')' ':' <FuncDeclTail> ");

		AST* classMethodS = nullptr;
		AST* fParamsS = nullptr;
		AST* funcDeclTailS = nullptr;
		if (match(TokenType::FUNC) && match(TokenType::ID) && ClassMethod(&classMethodS) && match(TokenType::LEFT_PARENTHESIS) && FParams(&fParamsS) && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::COLON) && FuncDeclTail(&funcDeclTailS)) {
			AST* functionId = attributeStack.top(); attributeStack.pop();
			*funcHeadS = ASTFactory::makeFamily(CompositeConcept::FUNCHEAD, { functionId, classMethodS, fParamsS, funcDeclTailS });
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ClassMethod(AST** classMethodS)
{
	if (!skipErrors(NonTerminal::CLASSMETHOD)) { return false; }
	//<ClassMethod> ::= 'sr' 'id' 
	if (isElementOfFirst({ TokenType::DOUBLE_COLON, TokenType::ID })) {
		applyDerivation(NonTerminal::CLASSMETHOD, { TokenType::DOUBLE_COLON, TokenType::ID }, "<ClassMethod> ::= 'sr' 'id'");

		if (match(TokenType::DOUBLE_COLON) && match(TokenType::ID)) {
			*classMethodS = ASTFactory::makeFamily(CompositeConcept::CLASSMETHOD, { attributeStack.top() });
			attributeStack.pop();
			return true;
		}
		else {
			return false;
		}
	}
	//<ClassMethod> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::CLASSMETHOD)) {
		applyDerivation(NonTerminal::CLASSMETHOD, { TokenType::EPSILON }, "<ClassMethod> ::= EPSILON");
		return true;
	}
	else {
		return false;
	}
}