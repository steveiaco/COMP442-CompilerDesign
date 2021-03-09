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
	bool AddOp();
	bool AParams();
	bool AParamsTail();
	bool ArithExpr();
	bool ArithExprTail();
	bool ArraySizeRept();
	bool AssignOp();
	bool AssignStatTail();
	bool ClassDecl();
	bool ClassDeclBody();
	bool ClassMethod();
	bool Expr();
	bool ExprTail();
	bool Factor();
	bool FParams();
	bool FParamsTail();
	bool FuncBody();
	bool FuncDecl();
	bool FuncDeclTail();
	bool FuncDef();
	bool FuncHead();
	bool FuncOrAssignStat();
	bool FuncOrAssignStatIDNest();
	bool FuncOrAssignStatIDNestFuncTail();
	bool FuncOrAssignStatIDNestVarTail();
	bool FuncOrVar();
	bool FuncOrVarIDNest();
	bool FuncOrVarIDNestTail();
	bool FuncStatTail();
	bool FuncStatTailIDNest();
	bool Function();
	bool IndiceRep();
	bool Inherit();
	bool IntNum();
	bool MemberDecl();
	bool MethodBodyVar();
	bool MultOp();
	bool NestedID();
	bool Prog();
	bool RelOp();
	bool Sign();
	bool Start();
	bool StatBlock();
	bool Statement();
	bool StatementList();
	bool Term();
	bool TermTail();
	bool Type();
	bool VarDecl();
	bool VarDeclRep();
	bool Variable();
	bool VariableIDNest();
	bool VariableIDNestTail();
	bool Visibility();


public:

	RecursiveDescentPredictiveParser(Lexer& lexer);

	bool parse();
	vector<Token>& getTokens();
};