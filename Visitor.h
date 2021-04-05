#pragma once
#include "CompositeConceptAST.h"
#include "IdAST.h"
#include "IntegerAST.h"
#include "FloatAST.h"
#include "StringAST.h"
#include "IntegerIdAST.h"
#include "FloatIdAST.h"
#include "StringIdAST.h"
#include "VoidAST.h"
#include "PublicAST.h"
#include "PrivateAST.h"
#include "BreakAST.h"
#include "ContinueAST.h"
#include "EqualToAST.h"
#include "NotEqualToAST.h"
#include "LessThanAST.h"
#include "GreaterThanASt.h"
#include "LessThanEqualToAST.h"
#include "GreaterThanEqualToAST.h"
#include "AdditionAST.h"
#include "SubtractionAST.h"
#include "MultiplicationAST.h"
#include "DivisionAST.h"
#include "AssignmentAST.h"
#include "OrAST.h"
#include "AndAST.h"
#include "NotAST.h"
#include "TernaryAST.h"
#include "PeriodAST.h"
#include "AParamsListAST.h"
#include "ArrayDimensionAST.h"
#include "ArraySizeReptListAST.h"
#include "AssignStatAST.h"
#include "ClassDeclBodyListAST.h"
#include "ClassListAST.h"
#include "FParamsListAST.h"
#include "FuncCallStatAST.h"
#include "FuncListAST.h"
#include "FuncOrVarListAST.h"
#include "IndiceRepListAST.h"
#include "InheritListAST.h"
#include "VarCallStatAST.h"
#include "VarDeclListAST.h"
#include "ArithExprAST.h"
#include "ClassDeclAST.h"
#include "ClassDeclBodyAST.h"
#include "ClassMethodAST.h"
#include "ExprASt.h"
#include "FParamsAST.h"
#include "FuncBodyAST.h"
#include "FuncDeclAST.h"
#include "FuncDefAST.h"
#include "FuncHeadAST.h"
#include "FuncStatAST.h"
#include "FunctionAST.h"
#include "IfAST.h"
#include "IndiceRepAST.h"
#include "InheritAST.h"
#include "ProgAST.h"
#include "ReadAST.h"
#include "ReturnAST.h"
#include "StartAST.h"
#include "StatementAST.h"
#include "StatementListAST.h"
#include "VarDeclAST.h"
#include "VariableAST.h"
#include "WhileAST.h"
#include "WriteAST.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Visitor
{
	std::vector<string> errorList;
	
public:
	virtual void visit(CompositeConceptAST* n) = 0;

	// Atomic Concepts
	virtual void visit(IdAST* n) = 0;
	virtual void visit(IntegerAST* n) = 0;
	virtual void visit(FloatAST* n) = 0;
	virtual void visit(StringAST* n) = 0;
	virtual void visit(IntegerIdAST* n) = 0;
	virtual void visit(FloatIdAST* n) = 0;
	virtual void visit(StringIdAST* n) = 0;
	virtual void visit(VoidAST* n) = 0;
	virtual void visit(PublicAST* n) = 0;
	virtual void visit(PrivateAST* n) = 0;
	virtual void visit(BreakAST* n) = 0;
	virtual void visit(ContinueAST* n) = 0;
	virtual void visit(EqualToAST* n) = 0;
	virtual void visit(NotEqualToAST* n) = 0;
	virtual void visit(LessThanAST* n) = 0;
	virtual void visit(GreaterThanAST* n) = 0;
	virtual void visit(LessThanEqualToAST* n) = 0;
	virtual void visit(GreaterThanEqualToAST* n) = 0;
	virtual void visit(AdditionAST* n) = 0;
	virtual void visit(SubtractionAST* n) = 0;
	virtual void visit(MultiplicationAST* n) = 0;
	virtual void visit(DivisionAST* n) = 0;
	virtual void visit(AssignmentAST* n) = 0;
	virtual void visit(OrAST* n) = 0;
	virtual void visit(AndAST* n) = 0;
	virtual void visit(NotAST* n) = 0;
	virtual void visit(TernaryAST* n) = 0;
	virtual void visit(PeriodAST* n) = 0;

	// Composite Concepts
	virtual void visit(AParamsListAST* n) = 0;
	virtual void visit(ArrayDimensionAST* n) = 0;
	virtual void visit(ArraySizeReptListAST* n) = 0;
	virtual void visit(AssignStatAST* n) = 0;
	virtual void visit(ClassDeclBodyListAST* n) = 0;
	virtual void visit(ClassListAST* n) = 0;
	virtual void visit(FParamsListAST* n) = 0;
	virtual void visit(FuncCallStatAST* n) = 0;
	virtual void visit(FuncListAST* n) = 0;
	virtual void visit(FuncOrVarListAST* n) = 0;
	virtual void visit(IndiceRepListAST* n) = 0;
	virtual void visit(InheritListAST* n) = 0;
	virtual void visit(VarCallStatAST* n) = 0;
	virtual void visit(VarDeclListAST* n) = 0;
	virtual void visit(ArithExprAST* n) = 0;
	virtual void visit(ClassDeclAST* n) = 0;
	virtual void visit(ClassDeclBodyAST* n) = 0;
	virtual void visit(ClassMethodAST* n) = 0;
	virtual void visit(ExprAST* n) = 0;
	virtual void visit(FParamsAST* n) = 0;
	virtual void visit(FuncBodyAST* n) = 0;
	virtual void visit(FuncDeclAST* n) = 0;
	virtual void visit(FuncDefAST* n) = 0;
	virtual void visit(FuncHeadAST* n) = 0;
	virtual void visit(FuncStatAST* n) = 0;
	virtual void visit(FunctionAST* n) = 0;
	virtual void visit(IfAST* n) = 0;
	virtual void visit(IndiceRepAST* n) = 0;
	virtual void visit(InheritAST* n) = 0;
	virtual void visit(ProgAST* n) = 0;
	virtual void visit(ReadAST* n) = 0;
	virtual void visit(ReturnAST* n) = 0;
	virtual void visit(StartAST* n) = 0;
	virtual void visit(StatementAST* n) = 0;
	virtual void visit(StatementListAST* n) = 0;
	virtual void visit(VarDeclAST* n) = 0;
	virtual void visit(VariableAST* n) = 0;
	virtual void visit(WhileAST* n) = 0;
	virtual void visit(WriteAST* n) = 0;
	void reportError(string error, int line);
	std::vector<string> getErrors() { return errorList; }
};

