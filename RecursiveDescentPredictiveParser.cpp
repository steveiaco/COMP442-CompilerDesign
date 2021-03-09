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
			else {
				return false;
			}
		}
	}
	// If we didn't find the token in any of the NonTerminal productions
	return false;
}

bool RecursiveDescentPredictiveParser::isElementOfFollow(NonTerminal element)
{
	return followSet[element].find(lookAhead.getTokenType()) != followSet[element].end();
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
	Token t;
	do {
		t = lexer.nextToken();
		tokens.push_back(t);
	} while (t.getTokenType() == TokenType::COMMENT);
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
		else {
			return false;
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
		else {
			return false;
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
	//<FuncDef> ::= <Function> <FuncDef> 
	if (isElementOfFirst({ NonTerminal::FUNCTION, NonTerminal::FUNCDEF })) {
		if (Function() && FuncDef()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncDef> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCDEF)) {
		return true;
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
		else {
			return false;
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
	//<FuncDeclTail> ::= <Type> 
	if (isElementOfFirst({ NonTerminal::TYPE })) {
		if (Type()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncDeclTail> ::= 'void' 
	else if (isElementOfFirst({ TokenType::VOID })) {
		if (match(TokenType::VOID)) {
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
		else {
			return false;
		}
	}
	//<MemberDecl> :: = <VarDecl>
	else if (isElementOfFirst({ NonTerminal::VARDECL })) {
		if (VarDecl()) {
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

bool RecursiveDescentPredictiveParser::Type()
{
	//<Type> :: = 'integer'
	if (isElementOfFirst({ TokenType::INTEGER_ID })) {
		if (match(TokenType::INTEGER_ID)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Type> :: = 'float'
	else if (isElementOfFirst({ TokenType::FLOAT_ID })) {
		if (match(TokenType::FLOAT_ID)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Type> :: = 'string'
	else if (isElementOfFirst({ TokenType::STRING_ID })) {
		if (match(TokenType::STRING_ID)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Type> :: = 'id'
	else if (isElementOfFirst({ TokenType::ID })) {
		if (match(TokenType::ID)) {
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
	else if (isElementOfFollow(NonTerminal::ARRAYSIZEREPT)) {
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

bool RecursiveDescentPredictiveParser::VarDeclRep()
{
	//<VarDeclRep> ::= <VarDecl> <VarDeclRep>
	if (isElementOfFirst({ NonTerminal::VARDECL, NonTerminal::VARDECLREP })) {
		if (VarDecl() && VarDeclRep()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<VarDeclRep> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::VARDECLREP)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Statement()
{
	//<Statement> ::= < FuncOrAssignStat> ';'
	if (isElementOfFirst({ NonTerminal::FUNCORASSIGNSTAT, TokenType::SEMICOLON })) {
		if (FuncOrAssignStat() && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'if' '(' < Expr > ')' 'then' < StatBlock > 'else' < StatBlock > ';'
	else if (isElementOfFirst({ TokenType::IF, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::THEN, NonTerminal::STATBLOCK, TokenType::ELSE, NonTerminal::STATBLOCK, TokenType::SEMICOLON })) {
		if (match(TokenType::IF) && match(TokenType::LEFT_PARENTHESIS) && Expr() && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::THEN) && StatBlock() && match(TokenType::ELSE) && StatBlock() && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'while' '(' < Expr > ')' < StatBlock > ';'
	else if (isElementOfFirst({ TokenType::WHILE, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, NonTerminal::STATBLOCK, TokenType::SEMICOLON })) {
		if (match(TokenType::WHILE) && match(TokenType::LEFT_PARENTHESIS) && Expr() && match(TokenType::RIGHT_PARENTHESIS) && StatBlock() && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'read' '(' < Variable > ')' ';'
	else if (isElementOfFirst({ TokenType::READ, TokenType::LEFT_PARENTHESIS, NonTerminal::VARIABLE, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON })) {
		if (match(TokenType::READ) && match(TokenType::LEFT_PARENTHESIS) && Variable() && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'write' '(' < Expr > ')' ';'
	else if (isElementOfFirst({ TokenType::WRITE, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON })) {
		if (match(TokenType::WRITE) && match(TokenType::LEFT_PARENTHESIS) && Expr() && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'return' '(' < Expr > ')' ';'
	else if (isElementOfFirst({ TokenType::RETURN, TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS, TokenType::SEMICOLON })) {
		if (match(TokenType::RETURN) && match(TokenType::LEFT_PARENTHESIS) && Expr() && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'break' ';'
	else if (isElementOfFirst({ TokenType::BREAK, TokenType::SEMICOLON })) {
		if (match(TokenType::BREAK) && match(TokenType::SEMICOLON)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Statement> ::= 'continue' ';'
	else if (isElementOfFirst({ TokenType::CONTINUE, TokenType::SEMICOLON })) {
		if (match(TokenType::CONTINUE) && match(TokenType::SEMICOLON)) {
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

bool RecursiveDescentPredictiveParser::FuncDecl()
{
	//<FuncDecl> ::= 'func' 'id' '(' <FParams> ')' ':' <FuncDeclTail> ';'
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

bool RecursiveDescentPredictiveParser::VarDecl()
{
	//<VarDecl> ::= <Type> 'id' <ArraySizeRept> ';' 
	if (isElementOfFirst({ NonTerminal::TYPE, TokenType::ID, NonTerminal::ARRAYSIZEREPT, TokenType::SEMICOLON })) {
		if (Type() && match(TokenType::ID) && ArraySizeRept() && match(TokenType::SEMICOLON)) {
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

bool RecursiveDescentPredictiveParser::IntNum()
{
	//<IntNum> :: = 'intnum'
	if (isElementOfFirst({ TokenType::INTEGER })) {
		if (match(TokenType::INTEGER)) {
			return true;
		}
		else {
			return false;
		}
	}
	//< IntNum > :: = EPSILON
	else if (isElementOfFollow(NonTerminal::INTNUM)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStat()
{
	//<FuncOrAssignStat> ::= 'id' <FuncOrAssignStatIdnest> 
	if (isElementOfFirst({ TokenType::ID, NonTerminal::FUNCORASSIGNSTATIDNEST })) {
		if (match(TokenType::ID) && FuncOrAssignStatIDNest()) {
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

bool RecursiveDescentPredictiveParser::Expr()
{
	//<Expr> ::= <ArithExpr> <ExprTail> 
	if (isElementOfFirst({ NonTerminal::ARITHEXPR, NonTerminal::EXPRTAIL })) {
		if (ArithExpr() && ExprTail()) {
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

bool RecursiveDescentPredictiveParser::StatBlock()
{
	//<StatBlock> ::= '{' <StatementList> '}' 
	if (isElementOfFirst({ TokenType::LEFT_CURLY_BRACKET, NonTerminal::STATEMENTLIST, TokenType::RIGHT_CURLY_BRACKET })) {
		if (match(TokenType::LEFT_CURLY_BRACKET) && StatementList() && match(TokenType::RIGHT_CURLY_BRACKET)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<StatBlock> :: = <Statement>
	else if (isElementOfFirst({ NonTerminal::STATEMENT })) {
		if (Statement()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<StatBlock> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::STATBLOCK)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Variable()
{
	//<Variable> ::= 'id' <VariableIdnest> 
	if (isElementOfFirst({ TokenType::ID, NonTerminal::VARIABLEIDNEST })) {
		if (match(TokenType::ID) && VariableIDNest()) {
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

bool RecursiveDescentPredictiveParser::FuncOrAssignStatIDNest()
{
	//<FuncOrAssignStatIdnest> ::= <IndiceRep> <FuncOrAssignStatIdnestVarTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, NonTerminal::FUNCORASSIGNSTATIDNESTVARTAIL })) {
		if (IndiceRep() && FuncOrAssignStatIDNestVarTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrAssignStatIdnest> :: = '(' < AParams > ')' < FuncOrAssignStatIdnestFuncTail >
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL })) {
		if (match(TokenType::LEFT_PARENTHESIS) && AParams() && match(TokenType::RIGHT_PARENTHESIS) && FuncOrAssignStatIDNestFuncTail()) {
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

bool RecursiveDescentPredictiveParser::ArithExpr()
{
	//<ArithExpr> ::= <Term> <ArithExprTail> 
	if (isElementOfFirst({ NonTerminal::TERM, NonTerminal::ARITHEXPRTAIL })) {
		if (Term() && ArithExprTail()) {
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

bool RecursiveDescentPredictiveParser::ExprTail()
{
	//<ExprTail> ::= <RelOp> <ArithExpr> 
	if (isElementOfFirst({ NonTerminal::RELOP, NonTerminal::ARITHEXPR })) {
		if (RelOp() && ArithExpr()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<ExprTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::EXPRTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::VariableIDNest()
{
	//<VariableIdnest> ::= <IndiceRep> <VariableIdnestTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, NonTerminal::VARIABLEIDNESTTAIL })) {
		if (IndiceRep() && VariableIDNestTail()) {
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

bool RecursiveDescentPredictiveParser::IndiceRep()
{
	//<IndiceRep> ::= '[' <Expr> ']' <IndiceRep> 
	if (isElementOfFirst({ TokenType::LEFT_SQUARE_BRACKET, NonTerminal::EXPR, TokenType::RIGHT_SQUARE_BRACKET, NonTerminal::INDICEREP })) {
		if (match(TokenType::LEFT_SQUARE_BRACKET) && Expr() && match(TokenType::RIGHT_SQUARE_BRACKET) && IndiceRep()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<IndiceRep> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::INDICEREP)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStatIDNestVarTail()
{
	//<FuncOrAssignStatIdnestVarTail> ::= '.' 'id' <FuncOrAssignStatIdnest> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCORASSIGNSTATIDNEST })) {
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncOrAssignStatIDNest()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrAssignStatIdnestVarTail> ::= <AssignStatTail> 
	else if (isElementOfFirst({ NonTerminal::ASSIGNSTATTAIL })) {
		if (AssignStatTail()) {
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

bool RecursiveDescentPredictiveParser::AParams()
{
	//<AParams> ::= <Expr> <AParamsTail> 
	if (isElementOfFirst({ NonTerminal::EXPR, NonTerminal::APARAMSTAIL })) {
		if (Expr() && AParamsTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<AParams> ::= EPSILON 
	else if (isElementOfFollow({ NonTerminal::APARAMS })) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncOrAssignStatIDNestFuncTail()
{
	//<FuncOrAssignStatIdnestFuncTail> ::= '.' 'id' <FuncStatTail> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL })) {
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncStatTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrAssignStatIdnestFuncTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCORASSIGNSTATIDNESTFUNCTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Term()
{
	//<Term> ::= <Factor> <TermTail> 
	if (isElementOfFirst({ NonTerminal::FACTOR, NonTerminal::TERMTAIL })) {
		if (Factor() && TermTail()) {
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

bool RecursiveDescentPredictiveParser::ArithExprTail()
{
	//<ArithExprTail> ::= <AddOp> <Term> <ArithExprTail> 
	if (isElementOfFirst({NonTerminal::ADDOP, NonTerminal::TERM, NonTerminal::ARITHEXPRTAIL})) {
		if (AddOp() && Term() && ArithExprTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<ArithExprTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::ARITHEXPRTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::RelOp()
{
	//<RelOp> ::= 'eq' 
	if (isElementOfFirst({ TokenType::EQUAL_TO })) {
		if (match(TokenType::EQUAL_TO)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'neq' 
	else if (isElementOfFirst({ TokenType::NOT_EQUAL_TO })) {
		if (match(TokenType::NOT_EQUAL_TO)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'lt' 
	else if (isElementOfFirst({ TokenType::LESS_THAN })) {
		if (match(TokenType::LESS_THAN)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'gt' 
	else if (isElementOfFirst({ TokenType::GREATER_THAN })) {
		if (match(TokenType::GREATER_THAN)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'leq' 
	else if (isElementOfFirst({ TokenType::LESS_THAN_EQUAL_TO })) {
		if (match(TokenType::LESS_THAN_EQUAL_TO)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<RelOp> ::= 'geq' 
	else if (isElementOfFirst({ TokenType::GREATER_THAN_EQUAL_TO })) {
		if (match(TokenType::GREATER_THAN_EQUAL_TO)) {
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

bool RecursiveDescentPredictiveParser::VariableIDNestTail()
{
	//<VariableIdnestTail> ::= '.' 'id' <VariableIdnest> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::VARIABLEIDNEST })) {
		if (match(TokenType::PERIOD) && match(TokenType::ID) && VariableIDNest()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<VariableIdnestTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::VARIABLEIDNESTTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AssignStatTail()
{
	//<AssignStatTail> ::= <AssignOp> <Expr> 
	if (isElementOfFirst({ NonTerminal::ASSIGNOP, NonTerminal::EXPR })) {
		if (AssignOp() && Expr()) {
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

bool RecursiveDescentPredictiveParser::AParamsTail()
{
	//<AParamsTail> ::= ',' <Expr> <AParamsTail> 
	if (isElementOfFirst({ TokenType::COMMA, NonTerminal::EXPR, NonTerminal::APARAMSTAIL })) {
		if (match(TokenType::COMMA) && Expr() && AParamsTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<AParamsTail> :: = EPSILON
	else if (isElementOfFollow(NonTerminal::APARAMSTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::FuncStatTail()
{
	//<FuncStatTail> ::= <IndiceRep> '.' 'id' <FuncStatTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL })) {
		if (IndiceRep() && match(TokenType::PERIOD) && match(TokenType::ID) && FuncStatTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncStatTail> ::= '(' <AParams> ')' <FuncStatTailIdnest> 
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCSTATTAILIDNEST })) {
		if (match(TokenType::LEFT_PARENTHESIS) && AParams() && match(TokenType::RIGHT_PARENTHESIS) && FuncStatTailIDNest()) {
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

bool RecursiveDescentPredictiveParser::Factor()
{
	//<Factor> ::= <FuncOrVar> 
	if (isElementOfFirst({ NonTerminal::FUNCORVAR })) {
		if (FuncOrVar()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'intnum' 
	else if (isElementOfFirst({ TokenType::INTEGER })) {
		if (match(TokenType::INTEGER)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'floatnum' 
	else if (isElementOfFirst({ TokenType::FLOAT })) {
		if (match(TokenType::FLOAT)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'stringlit' 
	else if (isElementOfFirst({ TokenType::STRING })) {
		if (match(TokenType::STRING)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= '(' <Expr> ')' 
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::EXPR, TokenType::RIGHT_PARENTHESIS })) {
		if (match(TokenType::LEFT_PARENTHESIS) && Expr() && match(TokenType::RIGHT_PARENTHESIS)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'not' <Factor> 
	else if (isElementOfFirst({ TokenType::NOT, NonTerminal::FACTOR })) {
		if (match(TokenType::NOT) && Factor()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= <Sign> <Factor> 
	else if (isElementOfFirst({ NonTerminal::SIGN, NonTerminal::FACTOR })) {
		if (Sign() && Factor()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Factor> ::= 'qm' '[' <Expr> ':' <Expr> ':' <Expr> ']' 
	else if (isElementOfFirst({ TokenType::QUESTION_MARK, TokenType::LEFT_SQUARE_BRACKET, NonTerminal::EXPR, TokenType::COLON,  NonTerminal::EXPR, TokenType::COLON, NonTerminal::EXPR, TokenType::RIGHT_SQUARE_BRACKET })) {
		if (match(TokenType::QUESTION_MARK) && match(TokenType::LEFT_SQUARE_BRACKET) && Expr() && match(TokenType::COLON) && Expr() && match(TokenType::COLON) && Expr() && match(TokenType::RIGHT_SQUARE_BRACKET)) {
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

bool RecursiveDescentPredictiveParser::TermTail()
{
	//<TermTail> ::= <MultOp> <Factor> <TermTail> 
	if (isElementOfFirst({ NonTerminal::MULTOP, NonTerminal::FACTOR, NonTerminal::TERMTAIL })) {
		if (MultOp() && Factor() && TermTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<TermTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::TERMTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::AddOp()
{
	//<AddOp> ::= '+' 
	if (isElementOfFirst({ TokenType::ADDITION })) {
		if (match(TokenType::ADDITION)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<AddOp> ::= '-' 
	else if (isElementOfFirst({ TokenType::SUBTRACTION })) {
		if (match(TokenType::SUBTRACTION)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<AddOp> ::= 'or' 
	else if (isElementOfFirst({ TokenType::OR })) {
		if (match(TokenType::OR)) {
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

bool RecursiveDescentPredictiveParser::AssignOp()
{
	//<AssignOp> ::= 'assign'
	if (isElementOfFirst({ TokenType::ASSIGNMENT })) {
		if (match(TokenType::ASSIGNMENT)) {
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

bool RecursiveDescentPredictiveParser::FuncStatTailIDNest()
{
	//<FuncStatTailIdnest> ::= '.' 'id' <FuncStatTail> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCSTATTAIL })) {
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncStatTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncStatTailIdnest> ::= EPSILON
	else if (isElementOfFollow(NonTerminal::FUNCSTATTAILIDNEST)) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

bool RecursiveDescentPredictiveParser::FuncOrVar()
{
	//<FuncOrVar> ::= 'id' <FuncOrVarIdnest> 
	if (isElementOfFirst({ TokenType::ID, NonTerminal::FUNCORVARIDNEST })) {
		if (match(TokenType::ID) && FuncOrVarIDNest()) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool RecursiveDescentPredictiveParser::Sign()
{
	//<Sign> ::= '+' 
	if (isElementOfFirst({ TokenType::ADDITION })) {
		if (match(TokenType::ADDITION)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<Sign> ::= '-' 
	else if (isElementOfFirst({ TokenType::SUBTRACTION })) {
		if (match(TokenType::SUBTRACTION)) {
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

bool RecursiveDescentPredictiveParser::MultOp()
{
	//<MultOp> ::= '*' 
	if (isElementOfFirst({ TokenType::MULTIPLICATION })) {
		if (match(TokenType::MULTIPLICATION)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<MultOp> ::= '/' 
	else if (isElementOfFirst({ TokenType::DIVISION})) {
		if (match(TokenType::DIVISION)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<MultOp> ::= 'and'
	else if (isElementOfFirst({ TokenType::AND })) {
		if (match(TokenType::AND)) {
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

bool RecursiveDescentPredictiveParser::FuncOrVarIDNest()
{
	//<FuncOrVarIdnest> ::= <IndiceRep> <FuncOrVarIdnestTail> 
	if (isElementOfFirst({ NonTerminal::INDICEREP, NonTerminal::FUNCORVARIDNESTTAIL })) {
		if (IndiceRep() && FuncOrVarIDNestTail()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrVarIdnest> ::= '(' <AParams> ')' <FuncOrVarIdnestTail> 
	else if (isElementOfFirst({ TokenType::LEFT_PARENTHESIS, NonTerminal::APARAMS, TokenType::RIGHT_PARENTHESIS, NonTerminal::FUNCORVARIDNESTTAIL })) {
		if (match(TokenType::LEFT_PARENTHESIS) && AParams() && match(TokenType::RIGHT_PARENTHESIS) && FuncOrVarIDNestTail()) {
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

bool RecursiveDescentPredictiveParser::FuncOrVarIDNestTail()
{
	//<FuncOrVarIdnestTail> ::= '.' 'id' <FuncOrVarIdnest> 
	if (isElementOfFirst({ TokenType::PERIOD, TokenType::ID, NonTerminal::FUNCORVARIDNEST })) {
		if (match(TokenType::PERIOD) && match(TokenType::ID) && FuncOrVarIDNest()) {
			return true;
		}
		else {
			return false;
		}
	}
	//<FuncOrVarIdnestTail> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::FUNCORVARIDNESTTAIL)) {
		return true;
	}
	else {
		return false;
	}
}

bool RecursiveDescentPredictiveParser::Function()
{
	//<Function> ::= <FuncHead> <FuncBody> 
	if (isElementOfFirst({ NonTerminal::FUNCHEAD, NonTerminal::FUNCBODY })) {
		if (FuncHead() && FuncBody()) {
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

bool RecursiveDescentPredictiveParser::FuncHead()
{
	//<FuncHead> ::= 'func' 'id' <ClassMethod> '(' <FParams> ')' ':' <FuncDeclTail> 
	if (isElementOfFirst({ TokenType::FUNC, TokenType::ID, NonTerminal::CLASSMETHOD, TokenType::LEFT_PARENTHESIS, NonTerminal::FPARAMS, TokenType::RIGHT_PARENTHESIS, TokenType::COLON, NonTerminal::FUNCDECLTAIL })) {
		if (match(TokenType::FUNC) && match(TokenType::ID) && ClassMethod() && match(TokenType::LEFT_PARENTHESIS) && FParams() && match(TokenType::RIGHT_PARENTHESIS) && match(TokenType::COLON) && FuncDeclTail()) {
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

bool RecursiveDescentPredictiveParser::ClassMethod()
{
	//<ClassMethod> ::= 'sr' 'id' 
	if (isElementOfFirst({ TokenType::DOUBLE_COLON, TokenType::ID })) {
		if (match(TokenType::DOUBLE_COLON) && match(TokenType::ID)) {
			return true;
		}
		else {
			return false;
		}
	}
	//<ClassMethod> ::= EPSILON 
	else if (isElementOfFollow(NonTerminal::CLASSMETHOD)) {
		return true;
	}
	else {
		return false;
	}
}