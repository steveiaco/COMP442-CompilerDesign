#include "Token.h"

Token::Token() : tokenType(ERROR), lexeme("uninitialized"), lineNumber(-1)
{
}

Token::Token(TokenType token, string lexeme, int line) : tokenType(token), lexeme(lexeme), lineNumber(line)
{
}

