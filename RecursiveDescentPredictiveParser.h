#pragma once
#include <fstream>
#include <unordered_map>
#include <set>
#include <variant>
#include <vector>
#include <queue>
#include <stack>
#include "AST.h"
#include "Token.h"
#include "Lexer.h"
#include "EnumDeclarations.h"

using std::ifstream;
using std::unordered_map;
using std::set;
using std::vector;
using std::stack;
using std::shared_ptr;

using Alphabet = std::variant<TokenType, NonTerminal>;

class RecursiveDescentPredictiveParser {

private:

	unordered_map<NonTerminal, set<TokenType>> firstSet;
	unordered_map<NonTerminal, set<TokenType>> followSet;
	vector<Token> tokens;

	Lexer& lexer;

	AST* ast;

	Token lookAhead;
	Token lastToken;

	vector<string> derivationList;
	vector<Alphabet> derivationStack;
	vector<string> syntaxErrors;

	stack<AST*> attributeStack;

	bool match(TokenType t);
	bool skipErrors(NonTerminal t);

	void generateFirstSet();
	void generateFollowSet();

	// Check if lookAhead is contained within FIRST(element)
	bool isElementOfFirst(vector<Alphabet> elements);

	// Check if lookAhead is contained within FOLLOW(element)
	bool isElementOfFollow(NonTerminal element);

	// Adds a step to the derivation list
	void applyDerivation(NonTerminal lhs, vector<Alphabet> rhs, string rule);
	string dumpDerivationStackToString(string rule);

	Token nextToken();

	// Non-terminal grammar functions
	bool AddOp(AST** addOp);
	bool AParams(AST** aParams);
	bool AParamsTail(AST** aParamsTail);
	bool ArithExpr(AST** arithExpr);
	bool ArithExprTail(AST** arithExprTail, AST* lhsTerm);
	bool ArraySizeRept(AST** arraySizeRept);
	bool AssignOp(AST** assignOp);
	bool AssignStatTail(AST** assignStatTail, AST* lhsAssignStat);
	bool ClassDecl(AST** classDeclS);
	bool ClassDeclBody(AST** classDeclBodyS);
	bool ClassMethod(AST** classMethodS);
	bool Expr(AST** exprS);
	bool ExprTail(AST** exprTail, AST* lhsArithExpr);
	bool Factor(AST** factor, AST* lhsFactor);
	bool FParams(AST** fParams);
	bool FParamsTail(AST** fParamsTail);
	bool FuncBody(AST** funcBodyS);
	bool FuncDecl(AST** funcDecl);
	bool FuncDeclTail(AST** funcDeclTail);
	bool FuncDef(AST** funcDefS);
	bool FuncHead(AST** funcHeadS);
	bool FuncOrAssignStat(AST** funcOrAssignStat);
	bool FuncOrAssignStatIDNest(AST** funcOrAssignStatIDNest, AST* lhsId);
	bool FuncOrAssignStatIDNestFuncTail(AST** funcOrAssignStatIdNestFuncTail, AST* lhsId);
	bool FuncOrAssignStatIDNestVarTail(AST** funcOrAssignStatIDNestVarTail, AST* lhsId);
	bool FuncOrVar(AST** funcOrVar);
	bool FuncOrVarIDNest(AST** funcOrVarIdNest, AST* id);
	bool FuncOrVarIDNestTail(AST** funcOrVarIdNestTail, AST* lhsId);
	bool FuncStatTail(AST** funcStatTail, AST* lhsId);
	bool FuncStatTailIDNest(AST** funcStatTailIdNest, AST* lhsId);
	bool Function(AST** functionS);
	bool IndiceRep(AST** indiceRep);
	bool Inherit(AST** inheritS);
	bool IntNum(AST** intNum);
	bool MemberDecl(AST** memberDeclS);
	bool MethodBodyVar(AST** methodBodyVar);
	bool MultOp(AST** multOp);
	bool NestedID(AST** nestedIdS);
	bool Prog(AST** progS);
	bool RelOp(AST** relOp);
	bool Sign(AST** sign);
	bool Start(AST** startS);
	bool StatBlock(AST** statBlock);
	bool Statement(AST** statementS);
	bool StatementList(AST** statementListS);
	bool Term(AST** term);
	bool TermTail(AST** termTail, AST* lhsFactor);
	bool Type(AST** type);
	bool VarDecl(AST** varDecl);
	bool VarDeclRep(AST** varDeclRep);
	bool Variable(AST** variable);
	bool VariableIDNest(AST** variableIdNest, AST* lhdId);
	bool VariableIDNestTail(AST** variableIdNestTail, AST* lhdId);
	bool Visibility(AST** visibilityS);


public:

	RecursiveDescentPredictiveParser(Lexer& lexer);

	bool parse();
	vector<Token>& getTokens();
	AST* getAST();
	vector<string> getSyntaxErrors();
	vector<string> getDerivation();
};