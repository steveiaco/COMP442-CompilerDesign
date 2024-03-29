#pragma once
#include <string>

enum class NonTerminal {
	ADDOP,
	APARAMSTAIL,
	ARITHEXPRTAIL,
	ASSIGNOP,
	CLASSDECLBODY,
	EXPRTAIL,
	ARITHEXPR,
	FPARAMSTAIL,
	CLASSMETHOD,
	FPARAMS,
	FUNCDECLTAIL,
	FUNCORASSIGNSTATIDNESTFUNCTAIL,
	FUNCORASSIGNSTATIDNESTVARTAIL,
	FUNCORASSIGNSTATIDNEST,
	ASSIGNSTATTAIL,
	FUNCORVAR,
	FUNCORVARIDNESTTAIL,
	FUNCORVARIDNEST,
	APARAMS,
	FUNCSTATTAILIDNEST,
	FUNCSTATTAIL,
	FUNCTION,
	FUNCHEAD,
	INHERIT,
	INTNUM,
	MEMBERDECL,
	FUNCDECL,
	METHODBODYVAR,
	NESTEDID,
	CLASSDECL,
	FUNCDEF,
	FUNCBODY,
	RELOP,
	SIGN,
	START,
	PROG,
	FUNCORASSIGNSTAT,
	STATBLOCK,
	EXPR,
	STATEMENT,
	STATEMENTLIST,
	TERM,
	MULTOP,
	FACTOR,
	TERMTAIL,
	TYPE,
	ARRAYSIZEREPT,
	VARDECL,
	VARDECLREP,
	VARIABLE,
	INDICEREP,
	VARIABLEIDNESTTAIL,
	VARIABLEIDNEST,
	VISIBILITY,
};

enum class CompositeConcept {
	// Not part of the grammar
	APARAMSLIST,
	ARRAYDIMENSION,
	ARRAYSIZEREPTLIST,
	ASSIGNSTAT,
	CLASSDECLBODYLIST,
	CLASSLIST,
	FPARAMSLIST,
	FUNCCALLSTAT,
	FUNCLIST,
	FUNCORVARLIST,
	INDICEREPLIST,
	INHERITLIST,
	TERNARY,
	VARCALLSTAT,
	VARDECLLIST,


	// Part of the grammar
	ARITHEXPR,
	CLASSDECL,
	CLASSDECLBODY,
	CLASSMETHOD,
	EXPR,
	FPARAMS,
	FUNCBODY,
	FUNCDECL,
	FUNCDEF,
	FUNCHEAD,
	FUNCSTAT,
	FUNCTION,
	IF,
	INDICEREP,
	INHERIT,
	PROG,
	READ,
	RETURN,
	START,
	STATEMENT,
	STATEMENTLIST,
	VARDECL,
	VARIABLE,
	WHILE,
	WRITE,
};

enum class AtomicConcept {
	ID,
	FLOAT,
	INTEGER,
	STRING,
	VISIBILITY
};

enum class TokenType {
	ID,
	// Types
	INTEGER,
	FLOAT,
	STRING,
	// Keywords
	INTEGER_ID, //keyword int
	FLOAT_ID,	//keyword float
	STRING_ID,	//keyword string
	IF,
	THEN,
	ELSE,
	VOID,
	PUBLIC,
	PRIVATE,
	FUNC,
	VAR,
	CLASS,
	WHILE,
	READ,
	WRITE,
	RETURN,
	MAIN,
	INHERITS,
	BREAK,
	CONTINUE,
	// Separators
	LEFT_SQUARE_BRACKET,
	RIGHT_SQUARE_BRACKET,
	LEFT_CURLY_BRACKET,
	RIGHT_CURLY_BRACKET,
	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,
	SEMICOLON,
	COMMA,
	PERIOD,
	COLON,
	DOUBLE_COLON,
	QUOTE,
	// Operators
	EQUAL_TO,	// ==
	NOT_EQUAL_TO,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_EQUAL_TO,
	GREATER_THAN_EQUAL_TO,
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	ASSIGNMENT, // =
	OR,
	AND,
	NOT, //!
	QUESTION_MARK, //? TO BE RENAMED
	// Other
	INVALID_CHARACTER,
	INVALID_NUMBER,
	INVALID_IDENTIFIER,
	INVALID_COMMENT,
	INVALID_STRING,
	UNDEFINED,
	COMMENT,
	END_OF_FILE,
	// Used for parser
	EPSILON
};

enum class SymTableEntryKind {
	CLASS,
	FUNCTION,
	PARAMETER,
	VARIABLE
};

class EnumDeclarations {
public:
	static std::string nonTerminalToString(NonTerminal t);
	static std::string compositeConceptToString(CompositeConcept c);
};