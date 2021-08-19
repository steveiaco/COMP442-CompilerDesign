#pragma once
#include "Visitor.h"
class TypeCheckingVisitor :
	public Visitor
{
public:
	TypeCheckingVisitor();
	// Inherited via Visitor
	virtual void visit(CompositeConceptAST* n) override;
	virtual void visit(IdAST* n) override;
	virtual void visit(IntegerAST* n) override;
	virtual void visit(FloatAST* n) override;
	virtual void visit(StringAST* n) override;
	virtual void visit(IntegerIdAST* n) override;
	virtual void visit(FloatIdAST* n) override;
	virtual void visit(StringIdAST* n) override;
	virtual void visit(VoidAST* n) override;
	virtual void visit(PublicAST* n) override;
	virtual void visit(PrivateAST* n) override;
	virtual void visit(BreakAST* n) override;
	virtual void visit(ContinueAST* n) override;
	virtual void visit(EqualToAST* n) override;
	virtual void visit(NotEqualToAST* n) override;
	virtual void visit(LessThanAST* n) override;
	virtual void visit(GreaterThanAST* n) override;
	virtual void visit(LessThanEqualToAST* n) override;
	virtual void visit(GreaterThanEqualToAST* n) override;
	virtual void visit(AdditionAST* n) override;
	virtual void visit(SubtractionAST* n) override;
	virtual void visit(MultiplicationAST* n) override;
	virtual void visit(DivisionAST* n) override;
	virtual void visit(AssignmentAST* n) override;
	virtual void visit(OrAST* n) override;
	virtual void visit(AndAST* n) override;
	virtual void visit(NotAST* n) override;
	virtual void visit(TernaryAST* n) override;
	virtual void visit(PeriodAST* n) override;
	virtual void visit(AParamsListAST* n) override;
	virtual void visit(ArrayDimensionAST* n) override;
	virtual void visit(ArraySizeReptListAST* n) override;
	virtual void visit(AssignStatAST* n) override;
	virtual void visit(ClassDeclBodyListAST* n) override;
	virtual void visit(ClassListAST* n) override;
	virtual void visit(FParamsListAST* n) override;
	virtual void visit(FuncCallStatAST* n) override;
	virtual void visit(FuncListAST* n) override;
	virtual void visit(FuncOrVarListAST* n) override;
	virtual void visit(IndiceRepListAST* n) override;
	virtual void visit(InheritListAST* n) override;
	virtual void visit(VarCallStatAST* n) override;
	virtual void visit(VarDeclListAST* n) override;
	virtual void visit(ArithExprAST* n) override;
	virtual void visit(ClassDeclAST* n) override;
	virtual void visit(ClassDeclBodyAST* n) override;
	virtual void visit(ClassMethodAST* n) override;
	virtual void visit(ExprAST* n) override;
	virtual void visit(FParamsAST* n) override;
	virtual void visit(FuncBodyAST* n) override;
	virtual void visit(FuncDeclAST* n) override;
	virtual void visit(FuncDefAST* n) override;
	virtual void visit(FuncHeadAST* n) override;
	virtual void visit(FuncStatAST* n) override;
	virtual void visit(FunctionAST* n) override;
	virtual void visit(IfAST* n) override;
	virtual void visit(IndiceRepAST* n) override;
	virtual void visit(InheritAST* n) override;
	virtual void visit(ProgAST* n) override;
	virtual void visit(ReadAST* n) override;
	virtual void visit(ReturnAST* n) override;
	virtual void visit(StartAST* n) override;
	virtual void visit(StatementAST* n) override;
	virtual void visit(StatementListAST* n) override;
	virtual void visit(VarDeclAST* n) override;
	virtual void visit(VariableAST* n) override;
	virtual void visit(WhileAST* n) override;
	virtual void visit(WriteAST* n) override;
};

