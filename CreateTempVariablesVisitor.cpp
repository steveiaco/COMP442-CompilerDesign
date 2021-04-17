#include "CreateTempVariablesVisitor.h"
#include "SymTabFactory.h"
string CreateTempVariablesVisitor::generateTemporaryVariableName()
{
	return 't' + std::to_string(tempVariableCounter++);
}

void CreateTempVariablesVisitor::visit(CompositeConceptAST* n)
{
}

void CreateTempVariablesVisitor::visit(IdAST* n)
{
}

void CreateTempVariablesVisitor::visit(IntegerAST* n)
{
}

void CreateTempVariablesVisitor::visit(FloatAST* n)
{
}

void CreateTempVariablesVisitor::visit(StringAST* n)
{
}

void CreateTempVariablesVisitor::visit(IntegerIdAST* n)
{
}

void CreateTempVariablesVisitor::visit(FloatIdAST* n)
{
}

void CreateTempVariablesVisitor::visit(StringIdAST* n)
{
}

void CreateTempVariablesVisitor::visit(VoidAST* n)
{
}

void CreateTempVariablesVisitor::visit(PublicAST* n)
{
}

void CreateTempVariablesVisitor::visit(PrivateAST* n)
{
}

void CreateTempVariablesVisitor::visit(BreakAST* n)
{
}

void CreateTempVariablesVisitor::visit(ContinueAST* n)
{
}

void CreateTempVariablesVisitor::visit(EqualToAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;
	
	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(NotEqualToAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(LessThanAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(GreaterThanAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(LessThanEqualToAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(GreaterThanEqualToAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(AdditionAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);
	
	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(SubtractionAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(MultiplicationAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(DivisionAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(AssignmentAST* n)
{
}

void CreateTempVariablesVisitor::visit(OrAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(AndAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(NotAST* n)
{
	// Generate a temp var name
	string tempVarName = generateTemporaryVariableName();

	// The operator's return intermediate variable
	n->setAssemData(tempVarName);

	// setup the entry info
	TemporaryEntry* tempVarEntry = SymTabFactory::makeSymTemporaryEntry();
	tempVarEntry->name = tempVarName;

	n->setType("integer");
	tempVarEntry->type = n->getType();

	// insert it into the table
	n->insertIntoNearestTable(tempVarEntry);
}

void CreateTempVariablesVisitor::visit(TernaryAST* n)
{
}

void CreateTempVariablesVisitor::visit(PeriodAST* n)
{
}

void CreateTempVariablesVisitor::visit(AParamsListAST* n)
{
}

void CreateTempVariablesVisitor::visit(ArrayDimensionAST* n)
{
}

void CreateTempVariablesVisitor::visit(ArraySizeReptListAST* n)
{
}

void CreateTempVariablesVisitor::visit(AssignStatAST* n)
{
}

void CreateTempVariablesVisitor::visit(ClassDeclBodyListAST* n)
{
}

void CreateTempVariablesVisitor::visit(ClassListAST* n)
{
}

void CreateTempVariablesVisitor::visit(FParamsListAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncCallStatAST* n)
{

}

void CreateTempVariablesVisitor::visit(FuncListAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncOrVarListAST* n)
{
}

void CreateTempVariablesVisitor::visit(IndiceRepListAST* n)
{
}

void CreateTempVariablesVisitor::visit(InheritListAST* n)
{
}

void CreateTempVariablesVisitor::visit(VarCallStatAST* n)
{
}

void CreateTempVariablesVisitor::visit(VarDeclListAST* n)
{
}

void CreateTempVariablesVisitor::visit(ArithExprAST* n)
{
}

void CreateTempVariablesVisitor::visit(ClassDeclAST* n)
{
}

void CreateTempVariablesVisitor::visit(ClassDeclBodyAST* n)
{
}

void CreateTempVariablesVisitor::visit(ClassMethodAST* n)
{
}

void CreateTempVariablesVisitor::visit(ExprAST* n)
{
}

void CreateTempVariablesVisitor::visit(FParamsAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncBodyAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncDeclAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncDefAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncHeadAST* n)
{
}

void CreateTempVariablesVisitor::visit(FuncStatAST* n)
{
}

void CreateTempVariablesVisitor::visit(FunctionAST* n)
{
}

void CreateTempVariablesVisitor::visit(IfAST* n)
{
}

void CreateTempVariablesVisitor::visit(IndiceRepAST* n)
{
}

void CreateTempVariablesVisitor::visit(InheritAST* n)
{
}

void CreateTempVariablesVisitor::visit(ProgAST* n)
{
}

void CreateTempVariablesVisitor::visit(ReadAST* n)
{
}

void CreateTempVariablesVisitor::visit(ReturnAST* n)
{
}

void CreateTempVariablesVisitor::visit(StartAST* n)
{
}

void CreateTempVariablesVisitor::visit(StatementAST* n)
{
}

void CreateTempVariablesVisitor::visit(StatementListAST* n)
{
}

void CreateTempVariablesVisitor::visit(VarDeclAST* n)
{
}

void CreateTempVariablesVisitor::visit(VariableAST* n)
{
}

void CreateTempVariablesVisitor::visit(WhileAST* n)
{
}

void CreateTempVariablesVisitor::visit(WriteAST* n)
{
}
