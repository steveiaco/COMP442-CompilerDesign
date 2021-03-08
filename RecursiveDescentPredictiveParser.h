#pragma once
#include <fstream>
#include <unordered_map>
#include <set>
#include <vector>
#include "../COMP442/Token.h"
#include "../COMP442/Lexer.h"
#include <variant>


using std::ifstream;
using std::unordered_map;
using std::set;
using std::vector;

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

using Alphabet = std::variant<TokenType, NonTerminal>;

class RecursiveDescentPredictiveParser {

private:

	unordered_map<NonTerminal, set<TokenType>> firstSet;
	unordered_map<NonTerminal, set<TokenType>> followSet;
	vector<Token> tokens;

	Lexer& lexer;

	Token lookAhead;

	
	bool match(TokenType t);

	void generateFirstSet();
	void generateFollowSet();

	// Check if lookAhead is contained within FIRST(element)
	bool isElementOfFirst(vector<Alphabet> elements);

	// Check if lookAhead is contained within FOLLOW(element)
	bool isElementOfFollow(NonTerminal element);

	Token nextToken();

	// Non-terminal grammar functions
	bool Start();
	bool Prog();
	bool ClassDecl();
	bool FuncDef();
	bool FuncBody();
	bool Inherit();
	bool ClassDeclBody();
	bool FParams();
	bool FuncDeclTail();
	bool MethodBodyVar();
	bool StatementList();
	bool NestedID();
	bool Visibility();
	bool MemberDecl();
	bool Type();
	bool ArraySizeRept();
	bool FParamsTail();
	bool VarDeclRep();
	bool Statement();
	bool FuncDecl();
	bool VarDecl();
	bool IntNum();

public:

	RecursiveDescentPredictiveParser(Lexer& lexer);

	bool parse();
	vector<Token>& getTokens();
};