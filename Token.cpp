#include "Token.h"

//TODO CHANGE THIS
Token::Token() : tokenType(ERROR)
{
}

Token::Token(TokenType token, string lexeme) : tokenType(token), lexeme(lexeme)
{
}
