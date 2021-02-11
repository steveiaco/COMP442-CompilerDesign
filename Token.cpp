#include "Token.h"
#include <regex>

string Token::tokenToString(TokenType t) {
	switch (t) {
	case ID: 
		return "ID";
		break;
	case INTEGER: 
		return "INTEGER";
		break;
	case FLOAT: 
		return "FLOAT";
		break;
	case STRING: 
		return "STRING";
		break;
	case INTEGER_ID: 
		return "INTEGER_ID";
		break;
	case FLOAT_ID: 
		return "FLOAT_ID";
		break;
	case STRING_ID: 
		return "STRING_ID";
		break;
	case IF: 
		return "IF";
		break;
	case THEN: 
		return "THEN";
		break;
	case ELSE: 
		return "ELSE";
		break;
	case VOID: 
		return "VOID";
		break;
	case PUBLIC: 
		return "PUBLIC";
		break;
	case PRIVATE: 
		return "PRIVATE";
		break;
	case FUNC: 
		return "FUNC";
		break;
	case VAR: 
		return "VAR";
		break;
	case CLASS: 
		return "CLASS";
		break;
	case WHILE: 
		return "WHILE";
		break;
	case READ: 
		return "READ";
		break;
	case WRITE: 
		return "WRITE";
		break;
	case RETURN: 
		return "RETURN";
		break;
	case MAIN: 
		return "MAIN";
		break;
	case INHERITS: 
		return "INHERITS";
		break;
	case BREAK: 
		return "BREAK";
		break;
	case CONTINUE: 
		return "CONTINUE";
		break;
	case LEFT_SQUARE_BRACKET: 
		return "LEFT_SQUARE_BRACKET";
		break;
	case RIGHT_SQUARE_BRACKET: 
		return "RIGHT_SQUARE_BRACKET";
		break;
	case LEFT_CURLY_BRACKET: 
		return "LEFT_CURLY_BRACKET";
		break;
	case RIGHT_CURLY_BRACKET: 
		return "RIGHT_CURLY_BRACKET";
		break;
	case LEFT_PARENTHESIS: 
		return "LEFT_PARENTHESIS";
		break;
	case RIGHT_PARENTHESIS: 
		return "RIGHT_PARENTHESIS";
		break;
	case SEMICOLON: 
		return "SEMICOLON";
		break;
	case COMMA: 
		return "COMMA";
		break;
	case PERIOD: 
		return "PERIOD";
		break;
	case COLON: 
		return "COLON";
		break;
	case DOUBLE_COLON: 
		return "DOUBLE_COLON";
		break;
	case QUOTE: 
		return "QUOTE";
		break;
	case EQUAL_TO: 
		return "EQUAL_TO";
		break;
	case NOT_EQUAL_TO: 
		return "NOT_EQUAL_TO";
		break;
	case LESS_THAN: 
		return "LESS_THAN";
		break;
	case GREATER_THAN: 
		return "GREATER_THAN";
		break;
	case LESS_THAN_EQUAL_TO: 
		return "LESS_THAN_EQUAL_TO";
		break;
	case GREATER_THAN_EQUAL_TO: 
		return "GREATER_THAN_EQUAL_TO";
		break;
	case ADDITION: 
		return "ADDITION";
		break;
	case SUBTRACTION: 
		return "SUBTRACTION";
		break;
	case MULTIPLICATION: 
		return "MULTIPLICATION";
		break;
	case DIVISION: 
		return "DIVISION";
		break;
	case ASSIGNMENT: 
		return "ASSIGNMENT";
		break;
	case OR: 
		return "OR";
		break;
	case AND: 
		return "AND";
		break;
	case NOT: 
		return "NOT";
		break;
	case QUESTION_MARK: 
		return "QUESTION_MARK";
		break;
	case INVALID_CHARACTER: 
		return "INVALID_CHARACTER";
		break;
	case INVALID_NUMBER: 
		return "INVALID_NUMBER";
		break;
	case INVALID_IDENTIFIER: 
		return "INVALID_IDENTIFIER";
		break;
	case INVALID_COMMENT:
		return "INVALID_COMMENT";
		break;
	case INVALID_STRING:
		return "INVALID_STRING";
		break;
	case UNDEFINED: 
		return "UNDEFINED";
		break;
	case COMMENT: 
		return "COMMENT";
		break;
	case END_OF_FILE: 
		return "END_OF_FILE";
		break;
	default:
		return "ERROR";
		break;
	}
}

Token::Token() : tokenType(UNDEFINED), lexeme("uninitialized"), lineNumber(-1)
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
