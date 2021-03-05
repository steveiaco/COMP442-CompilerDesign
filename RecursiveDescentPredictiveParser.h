#pragma once
#include <fstream>
#include <unordered_map>
#include <set>
#include "../COMP442/Token.h"
#include "../COMP442/Lexer.h"


using std::ifstream;
using std::unordered_map;
using std::set;

enum NonTerminal {
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

class RecursiveDescentPredictiveParser {

private:

	unordered_map<TokenType, set<TokenType>> firstSet;
	unordered_map<TokenType, set<TokenType>> followSet;

	Lexer& lexer;

	Token& lookAhead;

	
	bool match(TokenType t);

	void generateFirstSet();
	void generateFollowSet();

	// Non-terminal grammar functions
	bool Start();
	bool Prog();
	bool ClassDecl();
	bool FuncDef();
	bool FuncBody();

public:

	RecursiveDescentPredictiveParser(Lexer& lexer);

	bool parse();
};