#include "RecursiveDescentPredictiveParser.h"

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
	for (Alphabet e : elements) {
		
		if (auto nonTerminal = std::get_if<NonTerminal>(&e)) {
			// If the current production contains the current lookAhead token in its first set, then return true
			if (firstSet[*nonTerminal].find(lookAhead.getTokenType()) != firstSet[*nonTerminal].end()) {
				return true;
			}
			// If the current production is not nullable and it does not contain the current lookAhead token in its first set, then return false
			else if (firstSet[*nonTerminal].find(TokenType::EPSILON) == firstSet[*nonTerminal].end()) {
				return false;
			}
		// If the current production does not contain the current lookAhead token in its first set, but it is nullable, then move onto the next NonTerminal production
		}
		// If we encounter a terminal symbol, then simply compare it with the lookahead
		else if (auto terminal = std::get_if<TokenType>(&e)) {
			if (lookAhead.getTokenType() == *terminal) {
				return true;
			}
		}
	}
	// If we didn't find the token in any of the NonTerminal productions
	return false;
}

bool RecursiveDescentPredictiveParser::isElementOfFollow(NonTerminal element)
{
	return followSet[element].find(lookAhead.getTokenType()) != firstSet[element].end();
}

bool RecursiveDescentPredictiveParser::match(TokenType t)
{
	if (lookAhead.getTokenType() == t) {
		lookAhead = nextToken();
		return true;
	}
	else {
		lookAhead = nextToken();
		return false;
	}
}


Token RecursiveDescentPredictiveParser::nextToken()
{
	Token t = lexer.nextToken();
	tokens.push_back(t);
	return t;
}


RecursiveDescentPredictiveParser::RecursiveDescentPredictiveParser(Lexer& lexer) : lexer(lexer)
{
	generateFirstSet();
	generateFollowSet();
}

bool RecursiveDescentPredictiveParser::parse()
{
	lookAhead = nextToken();

	return Start() && match(TokenType::END_OF_FILE);
}

vector<Token>& RecursiveDescentPredictiveParser::getTokens()
{
	return tokens;
}


// Grammar functions

bool RecursiveDescentPredictiveParser::Start()
{
	// <START> :: = <Prog>
	if (isElementOfFirst({ NonTerminal::PROG })) {
		if (Prog()) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Prog()
{
	// <Prog> ::= <ClassDecl> <FuncDef> 'main' <FuncBody> 
	if (isElementOfFirst({ NonTerminal::CLASSDECL, NonTerminal::FUNCDEF, TokenType::MAIN, NonTerminal::FUNCBODY })) {
		if (ClassDecl() && FuncDef() && match(TokenType::MAIN) && FuncBody()) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ClassDecl()
{
	// <ClassDecl> ::= 'class' 'id' <Inherit> '{' <ClassDeclBody> '}' ';' <ClassDecl> 
	if (isElementOfFirst({ TokenType::CLASS, TokenType::ID, NonTerminal::INHERIT, TokenType::LEFT_CURLY_BRACKET, NonTerminal::CLASSDECLBODY, TokenType::RIGHT_CURLY_BRACKET, TokenType::SEMICOLON, NonTerminal::CLASSDECL })) {
		if (match(TokenType::CLASS) && match(TokenType::ID) && Inherit() && match(TokenType::LEFT_CURLY_BRACKET) && ClassDeclBody() && match(TokenType::RIGHT_CURLY_BRACKET) && match(TokenType::SEMICOLON) && ClassDecl()) {
			return true;
		}
		else {
			return false;
		}
	}
	// <ClassDecl> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::CLASSDECL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncDef()
{
	// <FuncDecl> ::= 'func' 'id' '(' <FParams> ')' ':' <FuncDeclTail> ';' 
	if (isElementOfFirst({ TokenType::FUNC, TokenType::ID, TokenType::LEFT_PARENTHESIS, NonTerminal::FPARAMS, TokenType::RIGHT_PARENTHESIS, TokenType::COLON, NonTerminal::FUNCDECLTAIL, TokenType::SEMICOLON })) {
		if (match(TokenType::FUNC) && match(TokenType::ID) && match(TokenType::LEFT_PARENTHESIS) && FParams() && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::COLON) && FuncDeclTail() && match(TokenType::SEMICOLON)) {
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

bool RecursiveDescentPredictiveParser::FuncBody()
{
	// <FuncBody> ::= '{' <MethodBodyVar> <StatementList> '}' 
	if (isElementOfFirst({ TokenType::LEFT_CURLY_BRACKET, NonTerminal::METHODBODYVAR, NonTerminal::STATEMENTLIST, TokenType::RIGHT_CURLY_BRACKET })) {
		if (match(TokenType::LEFT_CURLY_BRACKET) && MethodBodyVar() && StatementList() && match(TokenType::RIGHT_CURLY_BRACKET)) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Inherit()
{
	// <Inherit> :: = 'inherits' 'id' < NestedId >
	if (isElementOfFirst({TokenType::INHERITS, TokenType::ID, NonTerminal::NESTEDID})) {
		if (match(TokenType::INHERITS) && match(TokenType::ID) && NestedID()) {
			return true;
		}
		else {
			return false;
		}
	}
	// <Inherit> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::INHERIT)) {
		return true;
	}
	return false;
}

bool RecursiveDescentPredictiveParser::ClassDeclBody()
{
	// <ClassDeclBody> ::= <Visibility> <MemberDecl> <ClassDeclBody> 
	if (isElementOfFirst({ NonTerminal::VISIBILITY, NonTerminal::MEMBERDECL, NonTerminal::CLASSDECLBODY })) {
		if (Visibility() && MemberDecl() && ClassDeclBody()) {
			return true;
		}
		else {
			return false;
		}
	}
	// <ClassDeclBody> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::CLASSDECLBODY)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FParams()
{
	//<FParams> ::= <Type> 'id' < ArraySizeRept > <FParamsTail>
	if (isElementOfFirst({ NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL })) {
		if (Type() && match(TokenType::ID) && ArraySizeRept() && FParamsTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FParams> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FPARAMS)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncDeclTail()
{
	//<FParamsTail> :: = ',' < Type > 'id' < ArraySizeRept > <FParamsTail>
	if (isElementOfFirst({TokenType::COMMA, NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL})) {
		if (match(TokenType::COMMA) && Type() && match(TokenType::ID) && ArraySizeRept() && FParamsTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FParamsTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCDECLTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::MethodBodyVar()
{
	//<MethodBodyVar> :: = 'var' '{' <VarDeclRep> '}'
	if (isElementOfFirst({TokenType::VAR, TokenType::LEFT_CURLY_BRACKET, NonTerminal::VARDECLREP, TokenType::RIGHT_CURLY_BRACKET})) {
		if (match(TokenType::VAR) && match(TokenType::LEFT_CURLY_BRACKET) && VarDeclRep() && match(TokenType::RIGHT_CURLY_BRACKET)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<MethodBodyVar> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::METHODBODYVAR)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::StatementList()
{
	//<StatementList> ::= <Statement> <StatementList>
	if (isElementOfFirst({ NonTerminal::STATEMENT, NonTerminal::STATEMENTLIST })) {
		if (Statement() && StatementList()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<StatementList> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::STATEMENTLIST)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::NestedID()
{
	//<NestedId> :: = ',' 'id' < NestedId >
	if (isElementOfFirst({ TokenType::COMMA, TokenType::ID, NonTerminal::NESTEDID })) {
		if (match(TokenType::COMMA) && match(TokenType::ID) && NestedID()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<NestedId> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::NESTEDID)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Visibility()
{
	//<Visibility> :: = 'public'
	if (isElementOfFirst({ TokenType::PUBLIC })) {
		if (match(TokenType::PUBLIC)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Visibility> :: = 'private'
	else if (isElementOfFirst({ TokenType::PRIVATE })) {
		if (match(TokenType::PRIVATE)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Visibility> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::VISIBILITY)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::MemberDecl()
{
	//<MemberDecl> :: = <FuncDecl>
	if (isElementOfFirst({NonTerminal::FUNCDECL})) {
		if (FuncDecl()) {
			return true;
		}
	}
	//<MemberDecl> :: = <VarDecl>
	else if (isElementOfFirst({ NonTerminal::VARDECL })) {
		if (VarDecl()) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Type()
{
	//<Type> :: = 'integer'
	if (isElementOfFirst({ TokenType::INTEGER_ID })) {
		if (match(TokenType::INTEGER_ID)) {
			return true;
		}
	}
	//<Type> :: = 'float'
	else if (isElementOfFirst({ TokenType::FLOAT_ID })) {
		if (match(TokenType::FLOAT_ID)) {
			return true;
		}
	}
	//<Type> :: = 'string'
	else if (isElementOfFirst({ TokenType::STRING_ID })) {
		if (match(TokenType::STRING_ID)) {
			return true;
		}
	}
	//<Type> :: = 'id'
	else if (isElementOfFirst({ TokenType::ID })) {
		if (match(TokenType::ID)) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::ArraySizeRept()
{
	//<ArraySizeRept> :: = '[' < IntNum > ']' < ArraySizeRept >
	if (isElementOfFirst({ TokenType::LEFT_SQUARE_BRACKET, NonTerminal::INTNUM, TokenType::RIGHT_SQUARE_BRACKET, NonTerminal::ARRAYSIZEREPT })) {
		if (match(TokenType::LEFT_SQUARE_BRACKET) && IntNum() && match(TokenType::RIGHT_SQUARE_BRACKET) && ArraySizeRept()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<ArraySizeRept> ::= EPSILON
	if (isElementOfFollow(NonTerminal::ARRAYSIZEREPT)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FParamsTail()
{
	//<FParamsTail> :: = ',' < Type > 'id' < ArraySizeRept > <FParamsTail>
	if (isElementOfFirst({ TokenType::COMMA, NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, NonTerminal::FPARAMSTAIL })) {
		if (match(TokenType::COMMA) && Type() && match(TokenType::ID) && ArraySizeRept() && FParamsTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FParamsTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FPARAMSTAIL)) {
		return true;
	}
	else {
		return false;
	}
}