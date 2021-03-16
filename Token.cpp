#include "Token.h"
#include <regex>

string Token::tokenToString(TokenType t) {
	switch (t) {
	case TokenType::ID: 
		return "ID";
		break;
	case TokenType::INTEGER: 
		return "INTEGER";
		break;
	case TokenType::FLOAT: 
		return "FLOAT";
		break;
	case TokenType::STRING: 
		return "STRING";
		break;
	case TokenType::INTEGER_ID: 
		return "INTEGER_ID";
		break;
	case TokenType::FLOAT_ID: 
		return "FLOAT_ID";
		break;
	case TokenType::STRING_ID: 
		return "STRING_ID";
		break;
	case TokenType::IF: 
		return "IF";
		break;
	case TokenType::THEN: 
		return "THEN";
		break;
	case TokenType::ELSE: 
		return "ELSE";
		break;
	case TokenType::VOID: 
		return "VOID";
		break;
	case TokenType::PUBLIC: 
		return "PUBLIC";
		break;
	case TokenType::PRIVATE: 
		return "PRIVATE";
		break;
	case TokenType::FUNC: 
		return "FUNC";
		break;
	case TokenType::VAR: 
		return "VAR";
		break;
	case TokenType::CLASS: 
		return "CLASS";
		break;
	case TokenType::WHILE: 
		return "WHILE";
		break;
	case TokenType::READ: 
		return "READ";
		break;
	case TokenType::WRITE: 
		return "WRITE";
		break;
	case TokenType::RETURN: 
		return "RETURN";
		break;
	case TokenType::MAIN: 
		return "MAIN";
		break;
	case TokenType::INHERITS: 
		return "INHERITS";
		break;
	case TokenType::BREAK: 
		return "BREAK";
		break;
	case TokenType::CONTINUE: 
		return "CONTINUE";
		break;
	case TokenType::LEFT_SQUARE_BRACKET: 
		return "LEFT_SQUARE_BRACKET";
		break;
	case TokenType::RIGHT_SQUARE_BRACKET: 
		return "RIGHT_SQUARE_BRACKET";
		break;
	case TokenType::LEFT_CURLY_BRACKET: 
		return "LEFT_CURLY_BRACKET";
		break;
	case TokenType::RIGHT_CURLY_BRACKET: 
		return "RIGHT_CURLY_BRACKET";
		break;
	case TokenType::LEFT_PARENTHESIS: 
		return "LEFT_PARENTHESIS";
		break;
	case TokenType::RIGHT_PARENTHESIS: 
		return "RIGHT_PARENTHESIS";
		break;
	case TokenType::SEMICOLON: 
		return "SEMICOLON";
		break;
	case TokenType::COMMA: 
		return "COMMA";
		break;
	case TokenType::PERIOD: 
		return "PERIOD";
		break;
	case TokenType::COLON: 
		return "COLON";
		break;
	case TokenType::DOUBLE_COLON: 
		return "DOUBLE_COLON";
		break;
	case TokenType::QUOTE: 
		return "QUOTE";
		break;
	case TokenType::EQUAL_TO: 
		return "EQUAL_TO";
		break;
	case TokenType::NOT_EQUAL_TO: 
		return "NOT_EQUAL_TO";
		break;
	case TokenType::LESS_THAN: 
		return "LESS_THAN";
		break;
	case TokenType::GREATER_THAN: 
		return "GREATER_THAN";
		break;
	case TokenType::LESS_THAN_EQUAL_TO: 
		return "LESS_THAN_EQUAL_TO";
		break;
	case TokenType::GREATER_THAN_EQUAL_TO: 
		return "GREATER_THAN_EQUAL_TO";
		break;
	case TokenType::ADDITION: 
		return "ADDITION";
		break;
	case TokenType::SUBTRACTION: 
		return "SUBTRACTION";
		break;
	case TokenType::MULTIPLICATION: 
		return "MULTIPLICATION";
		break;
	case TokenType::DIVISION: 
		return "DIVISION";
		break;
	case TokenType::ASSIGNMENT: 
		return "ASSIGNMENT";
		break;
	case TokenType::OR: 
		return "OR";
		break;
	case TokenType::AND: 
		return "AND";
		break;
	case TokenType::NOT: 
		return "NOT";
		break;
	case TokenType::QUESTION_MARK: 
		return "QUESTION_MARK";
		break;
	case TokenType::INVALID_CHARACTER: 
		return "INVALID_CHARACTER";
		break;
	case TokenType::INVALID_NUMBER: 
		return "INVALID_NUMBER";
		break;
	case TokenType::INVALID_IDENTIFIER: 
		return "INVALID_IDENTIFIER";
		break;
	case TokenType::INVALID_COMMENT:
		return "INVALID_COMMENT";
		break;
	case TokenType::INVALID_STRING:
		return "INVALID_STRING";
		break;
	case TokenType::UNDEFINED: 
		return "UNDEFINED";
		break;
	case TokenType::COMMENT: 
		return "COMMENT";
		break;
	case TokenType::END_OF_FILE: 
		return "END_OF_FILE";
		break;
	case TokenType::EPSILON:
		return "EPSILON";
		break;
	default:
		return "-TOKEN STRING MISSING-";
		break;
	}
}

Token::Token() : tokenType(TokenType::UNDEFINED), lexeme("uninitialized"), lineNumber(-1)
{
}

Token::Token(TokenType token, string lexeme, int line) : tokenType(token), lexeme(lexeme), lineNumber(line)
{
}

ostream& operator<<(ostream& os, Token& t)
{
	string l = std::regex_replace(t.getLexeme(), std::regex("\n"), "\\n");
	return os << '[' << Token::tokenToString(t.getTokenType()) << ", " << l << ", " << t.getLineNumber() << "] ";
}
