#include "Token.h"

Token::Token() : tokenType(ERROR), lexeme("uninitialized")
{
}

Token::Token(TokenType token, string lexeme) : tokenType(token), lexeme(lexeme)
{
}

