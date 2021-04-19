#include "GenerateMoonAssemblyVisitor.h"
#include "SymTabFactory.h"
#include <iostream>

int GenerateMoonAssemblyVisitor::getStackOffset(SymTab* table)
{
	return table->computeInternalOffset() + 4;
}

string GenerateMoonAssemblyVisitor::getRegister()
{
	string toReturn = registers.top();
	registers.pop();
	return toReturn;
}

string GenerateMoonAssemblyVisitor::loadVariable(AST* valueNode, SymTab* table)
{
	string reg = getRegister();

	// If right child is VarCallStat
	if (VarCallStatAST* varCallStatNode = dynamic_cast<VarCallStatAST*>(valueNode))
	{
		SymTabEntry* variable = table->findVarOrParamRecord(varCallStatNode->getData());

		codeOperations.push_back("\tlw " + reg + "," + std::to_string(variable->getOffset()) + "(" + stackFramePointerRegister + ")");
	}

	// If the right child is a FuncCallStat
	if (FuncCallStatAST* funcCallStatNode = dynamic_cast<FuncCallStatAST*>(valueNode))
	{
		// Get variable (or parameter) symbolic record
		TemporaryEntry* tempAssignmentRHS = table->findTemporaryRecord(funcCallStatNode->getAssemData());

		// Load the variable's contents into a register
		codeOperations.push_back("\tlw " + reg + "," + std::to_string(tempAssignmentRHS->getOffset()) + "(" + stackFramePointerRegister + ")");
	}

	// If the right child is an expression (operator)
	else if (CompositeConceptTokenAST* operatorType = dynamic_cast<CompositeConceptTokenAST*>(valueNode))
	{
		SymTabEntry* tempVar = table->findTemporaryRecord(operatorType->getAssemData());

		codeOperations.push_back("\tlw " + reg + "," + std::to_string(tempVar->getOffset()) + "(" + stackFramePointerRegister + ")");
	}

	// If right child is immediate type (integer, float, string)
	else if (TokenAST* immType = dynamic_cast<TokenAST*>(valueNode))
	{
		codeOperations.push_back("\taddi " + reg + "," + zeroRegister + "," + immType->getAssemData());
	}

	return reg;
}

void GenerateMoonAssemblyVisitor::visitChildren(AST* parent)
{
	AST* child = parent->leftMostChild;
	while (child != nullptr) {
		child->accept(this, false);
		child = child->rightSibling;
	}
}

GenerateMoonAssemblyVisitor::GenerateMoonAssemblyVisitor()
{
	// Setup registers
	zeroRegister = "r0";
	stackFramePointerRegister = "r14";
	returnAddressRegister = "r15";

	registers.push("r1");
	registers.push("r2");
	registers.push("r3");
	registers.push("r4");
	registers.push("r5");
	registers.push("r6");
	registers.push("r7");
	registers.push("r8");
	registers.push("r9");
	registers.push("r10");
	registers.push("r11");
	registers.push("r12");
	// Removed over concerns with lib.m conflicts
	//registers.push("r13");
}

std::vector<string> GenerateMoonAssemblyVisitor::getCode()
{
	std::vector<string> construct;

	for (std::deque<string> func : functions) {
		while (func.size() != 0) {
			construct.push_back(func.front());
			func.pop_front();
		}
	}

	construct.insert(construct.end(), reserveOperations.begin(), reserveOperations.end());
	return construct;
}

void GenerateMoonAssemblyVisitor::visit(CompositeConceptAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(IdAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(IntegerAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(FloatAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(StringAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(IntegerIdAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(FloatIdAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(StringIdAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(VoidAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(PublicAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(PrivateAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(BreakAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(ContinueAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(EqualToAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% equal to compare");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tceq " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(NotEqualToAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% not equal compare");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tcne " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(LessThanAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% less than compare");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tclt " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(GreaterThanAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% greater than compare");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tcgt " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(LessThanEqualToAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% less than or equal to compare");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tcle " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(GreaterThanEqualToAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% greater than or equal to compare");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tcge " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(AdditionAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% addition operation");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tadd " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(SubtractionAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% subtraction operation");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tsub " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(MultiplicationAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% multiplication operation");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tmul " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(DivisionAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% division operation");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Perform operation on left and right operand, and save to temporary variable
		codeOperations.push_back("\tdiv " + resultReg + "," + registersUsed[0] + "," + registersUsed[1]);


		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(AssignmentAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% assignment operation");

	AST* leftChild = n->getChild(0);
	AST* rightChild = n->getChild(1);

	SymTab* table = n->getNearestSymbolTable();

	// Search variable and parameter in symtab
	SymTabEntry* varAssignmentLHS = nullptr;
	int arrayOffsetLHS = 0;
	VariableEntry* varEntry = table->findVariableRecord(leftChild->getData());
	ParameterEntry* paramEntry = table->findParameterRecord(leftChild->getData());

	string type;
	// The dimensions of the array we are assigning to
	std::vector<int> arraySize;
	if (varEntry != nullptr) {
		varAssignmentLHS = varEntry;
		type = varEntry->type;
		arraySize = varEntry->arrayIndices;
	}
	else if (paramEntry != nullptr) {
		varAssignmentLHS = paramEntry;
		type = paramEntry->type;
		arraySize = paramEntry->arrayIndices;
	}

	if (arraySize.size() > 0) {
		if (type == "integer") {

		}
		else if (type == "float") {

		}
		// it's a class type
		else {

		}

	}

	// If right child is VarCallStat
	if (VarCallStatAST* varCallStatNode = dynamic_cast<VarCallStatAST*>(rightChild))
	{
		// Get variable (or parameter) symbolic record
		SymTabEntry* varAssignmentRHS = table->findVariableRecord(varCallStatNode->getData());
		if (varAssignmentRHS == nullptr) {
			varAssignmentRHS = table->findParameterRecord(varCallStatNode->getData());
		}

		// Get a register
		string reg = registers.top(); registers.pop();

		// Load the variable's contents into a register
		codeOperations.push_back("\tlw " + reg + "," + std::to_string(varAssignmentRHS->getOffset()) + "(" + stackFramePointerRegister + ")");

		// Write the register contents to the variables stack offset
		codeOperations.push_back("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);


		// Put the register back as we're done with it
		registers.push(reg);
	}
	// If the right child is a FuncCallStat
	if (FuncCallStatAST* funcCallStatNode = dynamic_cast<FuncCallStatAST*>(rightChild))
	{
		// Get variable (or parameter) symbolic record
		TemporaryEntry* tempAssignmentRHS = table->findTemporaryRecord(funcCallStatNode->getAssemData());

		// Get a register
		string reg = registers.top(); registers.pop();

		// Load the variable's contents into a register
		codeOperations.push_back("\tlw " + reg + "," + std::to_string(tempAssignmentRHS->getOffset()) + "(" + stackFramePointerRegister + ")");

		// Write the register contents to the variables stack offset
		codeOperations.push_back("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);

		// Put the register back as we're done with it
		registers.push(reg);
	}
	// If the right child is an expression (operator)
	else if (CompositeConceptTokenAST* operatorType = dynamic_cast<CompositeConceptTokenAST*>(rightChild))
	{
		// Get variable (or parameter) symbolic record
		SymTabEntry* varAssignmentRHS = table->findTemporaryRecord(operatorType->getAssemData());

		// Get a register
		string reg = registers.top(); registers.pop();

		// Load the variable's contents into a register
		codeOperations.push_back("\tlw " + reg + "," + std::to_string(varAssignmentRHS->getOffset()) + "(" + stackFramePointerRegister + ")");

		// Write the register contents to the variables stack offset
		codeOperations.push_back("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);

		// Put the register back as we're done with it
		registers.push(reg);
	}
	// If right child is immediate type (integer, float, string)
	else if (TokenAST* immType = dynamic_cast<TokenAST*>(rightChild))
	{
		// Get a register
		string reg = registers.top(); registers.pop();

		// Clear the contents of the register
		codeOperations.push_back("\tsub " + reg + "," + reg + "," + reg);

		// Add the immediate value to the register
		codeOperations.push_back("\taddi " + reg + "," + reg + "," + immType->getData());

		// Write the register contents to the variable's stack offset
		codeOperations.push_back("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);

		// Put the register back as we're done with it
		registers.push(reg);
	}
	// TODO support array assignment
}

void GenerateMoonAssemblyVisitor::visit(OrAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% or operation");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Generate branch labels
		string nonZeroLabel = lg.generateNonZeroLabel();
		string endOrLabel = lg.generateEndOrLabel();

		// Create branch operations
		codeOperations.push_back("\tbnz " + registersUsed[0] + "," + nonZeroLabel);
		codeOperations.push_back("\tbnz " + registersUsed[1] + "," + nonZeroLabel);

		// Condition where both operands are zero
		codeOperations.push_back("\taddi " + resultReg + "," + zeroRegister + ",0");
		codeOperations.push_back("\tj " + endOrLabel);

		// Condition where at least one operand is non-zero
		codeOperations.push_back(nonZeroLabel + "\taddi " + resultReg + "," + zeroRegister + ",1");

		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back(endOrLabel + "\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(AndAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% and operation");

	SymTab* table = n->getNearestSymbolTable();

	std::vector<string> registersUsed;

	// Load left and right operands into registers
	registersUsed.push_back(loadVariable(n->getChild(0), table));
	registersUsed.push_back(loadVariable(n->getChild(1), table));

	if (registersUsed.size() == 2) {

		string resultReg = getRegister();
		registersUsed.push_back(resultReg);

		// Generate branch labels
		string zeroLabel = lg.generateZeroLabel();
		string endAndLabel = lg.generateEndAndLabel();

		// Create branch operations
		codeOperations.push_back("\tbz " + registersUsed[0] + "," + zeroLabel);
		codeOperations.push_back("\tbz " + registersUsed[1] + "," + zeroLabel);

		// Condition where both operands are non-zero
		codeOperations.push_back("\taddi " + resultReg + "," + zeroRegister + ",1");
		codeOperations.push_back("\tj " + endAndLabel);

		// Condition where at least one operand is zero
		codeOperations.push_back(zeroLabel + "\taddi " + resultReg + "," + zeroRegister + ",0");

		// Save result to temporary variable
		TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());
		codeOperations.push_back(endAndLabel + "\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + resultReg);
	}

	// Release registers
	for (vector<string>::reverse_iterator reg = registersUsed.rbegin(); reg != registersUsed.rend(); ++reg) {
		registers.push(*reg);
	}
}

void GenerateMoonAssemblyVisitor::visit(NotAST* n)
{
	visitChildren(n);

	codeOperations.push_back("% and operation");

	SymTab* table = n->getNearestSymbolTable();

	// Load operand into a register
	string operandRegister = loadVariable(n->getChild(0), table);

	// Generate branch labels
	string zeroLabel = lg.generateZeroLabel();
	string endNotLabel = lg.generateEndNotLabel();

	// Get TemporaryEntry where we save our result to
	TemporaryEntry* tempRecord = table->findTemporaryRecord(n->getAssemData());

	// Create branch operations
	codeOperations.push_back("\tbnz " + operandRegister + "," + zeroLabel);

	// Condition where the operand is zero
	codeOperations.push_back("\taddi " + operandRegister + "," + zeroRegister + ",1");
	// Save result to temporary variable
	codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + operandRegister);
	// Jump to the end of the operation
	codeOperations.push_back("\tj " + endNotLabel);

	// Condition where is non-zero
	codeOperations.push_back(zeroLabel + "\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + ")," + zeroRegister);

	// Release registers
	registers.push(operandRegister);
}

void GenerateMoonAssemblyVisitor::visit(TernaryAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(PeriodAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(AParamsListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ArrayDimensionAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ArraySizeReptListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(AssignStatAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ClassDeclBodyListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ClassListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FParamsListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FuncCallStatAST* n)
{
	visitChildren(n);

	// if the parent node is of type PeriodAST then we must skip this funccall as the parent will take care of the operation
	if (PeriodAST* period = dynamic_cast<PeriodAST*>(n->parent)) {
		return;
	}

	// TODO handle the case where we are within a class scope

	// Handle free function call
	AST* functionNameNode = n->getChild(0);
	SymTab* table = n->getNearestSymbolTable();
	int tableOffset = table->computeInternalOffset();

	if (functionNameNode != nullptr && table != nullptr) {

		FunctionEntry* functionEntry = nullptr;

		// grab function name 
		std::vector<FunctionEntry*> entries = n->searchFunctionScope(functionNameNode->getData());
		if (entries.size() != 0) {
			functionEntry = entries[0];
		}
		// comment
		codeOperations.push_back("% function call to " + functionNameNode->getData());

		int calledFunctionOffset = functionEntry->link->computeInternalOffset();
		// handle parameter copying
		if (AST* aParamListNode = n->getChild(1)) {
			std::vector<AST*> paramsPassed = aParamListNode->getChildren();


			string paramOffsetReg = getRegister();

			for (int i = 0; i < paramsPassed.size(); i++) {
				codeOperations.push_back("\t% copy param");
				string paramPassedReg = loadVariable(paramsPassed[i], table);
				// i+1 due to jump register state being stored above the current frame
				codeOperations.push_back("\tsw " + std::to_string((tableOffset - 4) - 4*i) + "(" + stackFramePointerRegister + ")," + paramPassedReg);
				registers.push(paramPassedReg);
			}

			registers.push(paramOffsetReg);
		}

		// save jump register state
		codeOperations.push_back("\tsw " + std::to_string(tableOffset) + "(" + stackFramePointerRegister + ")," + returnAddressRegister);

		// increment stack frame
		codeOperations.push_back("\taddi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(tableOffset - 4));

		// jump instruction
		codeOperations.push_back("\tjl " + returnAddressRegister + "," + functionEntry->name);

		// decrement stack frame
		codeOperations.push_back("\tsubi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(tableOffset - 4));

		// restore jump register state
		codeOperations.push_back("\tlw " + returnAddressRegister + "," + std::to_string(tableOffset) + "(" + stackFramePointerRegister + ")");

		// if we have a return type, grab return value from stack (which is located at the (stackFramePointerRegister + (tableOffset - 4) + calledFunctionOffset) and store it in the FunCallStat temp variable 
		if (n->getType() != "void") {
			codeOperations.push_back("% copy return value");
			string returnReg = getRegister();
			// load the return value into a register
			codeOperations.push_back("\tlw " + returnReg + "," + std::to_string(tableOffset - 4 + calledFunctionOffset) + "(" + stackFramePointerRegister + ")");

			// save the register value into the calling function's temporary variable
			TemporaryEntry* tempReturnVar = table->findTemporaryRecord(n->getAssemData());
			codeOperations.push_back("\tsw " + std::to_string(tempReturnVar->getOffset()) + "(" + stackFramePointerRegister + ")," + returnReg);
		}

	}
}

void GenerateMoonAssemblyVisitor::visit(FuncListAST* n)
{
	visitChildren(n);

	// This node is visited right before we start visiting the main subtree
	// Prepare a new deque for the main function
	if (ProgAST* progParent = dynamic_cast<ProgAST*>(n->parent)) {
		if (codeOperations.size() != 0) {
			functions.push_back(codeOperations);
			codeOperations = std::deque<string>();
		}
	}
}

void GenerateMoonAssemblyVisitor::visit(FuncOrVarListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(IndiceRepListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(InheritListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(VarCallStatAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(VarDeclListAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ArithExprAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ClassDeclAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ClassDeclBodyAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ClassMethodAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ExprAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FParamsAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FuncBodyAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FuncDeclAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FuncDefAST* n)
{
	visitChildren(n);

	if (FunctionEntry* fEntry = dynamic_cast<FunctionEntry*>(n->getSymRec())) {
		codeOperations.push_front(fEntry->name);

		// Write return jump operation
		codeOperations.push_back("\tjr " + returnAddressRegister);

		functions.push_back(codeOperations);
		codeOperations = std::deque<string>();
	}
}

void GenerateMoonAssemblyVisitor::visit(FuncHeadAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FuncStatAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(FunctionAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(IfAST* n)
{
	n->getChild(0)->accept(this, false);

	SymTab* table = n->getNearestSymbolTable();
	string boolExpr = loadVariable(n->getChild(0), table);

	// If an else statement list exist
	if (n->getChild(2)) {
		codeOperations.push_back("% ifelse statement");

		
		string elseLabel = lg.generateElseLabel();
		string endIfLabel = lg.generateEndIfLabel();

		// If the expression evaluates to false, then jump to the else address
		codeOperations.push_back("\tbz " + boolExpr + "," + elseLabel);

		// Code for when the if statement resolves to true
		n->getChild(1)->accept(this, false);
		codeOperations.push_back("\tj " + endIfLabel);


		// Code for when the if statement resolves to false
		codeOperations.push_back(elseLabel + "\tnop");
		n->getChild(2)->accept(this, false);

		// End of if statement
		codeOperations.push_back(endIfLabel + "\tnop");
	}
	// if an else statement list does not exist
	else {
		codeOperations.push_back("% if statement");

		string endIfLabel = lg.generateEndIfLabel();

		// If the expression evaluates to false, then jump to the else address
		codeOperations.push_back("\tbz " + boolExpr + "," + endIfLabel);

		// Code for when the if statement resolves to true
		n->getChild(1)->accept(this, false);

		// End of if statement
		codeOperations.push_back(endIfLabel + "\tnop");
	}

	registers.push(boolExpr);

}

void GenerateMoonAssemblyVisitor::visit(IndiceRepAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(InheritAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(ProgAST* n)
{
	visitChildren(n);

	if (SymTab* table = n->getSymTab()) {
		// Setup program entry
		codeOperations.push_front("MAIN");
		codeOperations.push_front("\tsubi " + stackFramePointerRegister + "," + stackFramePointerRegister + ",4");
		codeOperations.push_front("\tsub " + zeroRegister + "," + zeroRegister + "," + zeroRegister);
		codeOperations.push_front("\taddi " + stackFramePointerRegister + "," + zeroRegister + ",topaddr");
		codeOperations.push_front("\tentry");
		// Add the hlt instruction to the end of main
		reserveOperations.push_back("\t% buffer space used for console output");
		reserveOperations.push_back("buf\tres 20");
		codeOperations.push_back("\thlt");

		functions.push_back(codeOperations);
	}
}

void GenerateMoonAssemblyVisitor::visit(ReadAST* n)
{
	SymTab* table = n->getNearestSymbolTable();

	codeOperations.push_back("% read integer from user");

	string bufferRegister = getRegister();

	string getStrLabel = lg.generateGetStrLabel();
	string endGetLabel = lg.generateEndGetLabel();

	// Link buffer to stack
	codeOperations.push_back("\taddi " + bufferRegister + "," + zeroRegister + ",buf");
	codeOperations.push_back("\tsw -8(" + stackFramePointerRegister + ")," + bufferRegister);

	// save jump register state
	codeOperations.push_back("\tsw " + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")," + returnAddressRegister);

	// print input statement to user
	string charRegister = getRegister();
	codeOperations.push_back("\taddi " + charRegister + "," + zeroRegister + ",10");
	codeOperations.push_back("\tputc " + charRegister);
	codeOperations.push_back("\taddi " + charRegister + "," + zeroRegister + ",63");
	codeOperations.push_back("\tputc " + charRegister);
	codeOperations.push_back("\taddi " + charRegister + "," + zeroRegister + ",58");
	codeOperations.push_back("\tputc " + charRegister);


	// Read string from console
	codeOperations.push_back("\tjl " + returnAddressRegister + ",getstr");

	// restore jump register state
	codeOperations.push_back("\tlw " + returnAddressRegister + "," + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")");
	

	// save jump register state
	codeOperations.push_back("\tsw " + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")," + returnAddressRegister);

	// Convert string to integer
	codeOperations.push_back("\tjl " + returnAddressRegister + ",strint");

	// restore jump register state
	codeOperations.push_back("\tlw " + returnAddressRegister + "," + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")");

	VariableEntry* tempRecord = table->findVariableRecord(n->getChild(0)->getAssemData());
	codeOperations.push_back("\tsw " + std::to_string(tempRecord->getOffset()) + "(" + stackFramePointerRegister + "),r13");

	registers.push(charRegister);
	registers.push(bufferRegister);
}

void GenerateMoonAssemblyVisitor::visit(ReturnAST* n)
{
	visitChildren(n);
	SymTab* table = n->getNearestSymbolTable();

	// load the return variable from the stack into a register
	string returnValReg = loadVariable(n->getChild(0), table);

	// store the contents of the register on top of the stack, so that the calling function can retrieve it
	codeOperations.push_back("\tsw " + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")," + returnValReg);

	// TODO handle arrays / aggregate types
	// TODO add jump statement to actually exit function
	registers.push(returnValReg);
}

void GenerateMoonAssemblyVisitor::visit(StartAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(StatementAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(StatementListAST* n)
{
	visitChildren(n);
}

void GenerateMoonAssemblyVisitor::visit(VarDeclAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(VariableAST* n)
{
	visitChildren(n);

}

void GenerateMoonAssemblyVisitor::visit(WhileAST* n)
{
	codeOperations.push_back("% while loop");
	SymTab* table = n->getNearestSymbolTable();
	string goWhileLabel = lg.generateGoWhileLabel();
	string endWhileLabel = lg.generateEndWhileLabel();

	// Loop statement
	codeOperations.push_back(goWhileLabel + "\tnop");

	// Generate while expresion code
	n->getChild(0)->accept(this, false);

	// Load variable used in while expression
	string whileExprRegister = loadVariable(n->getChild(0), table);

	// Check while expression truth value
	codeOperations.push_back("\tbz " + whileExprRegister + "," + endWhileLabel);

	// Generate while statement code
	if (AST* statementListChild = n->getChild(1)) {
		statementListChild->accept(this, false);
	}

	// Jump back to beginning of while
	codeOperations.push_back("\tj " + goWhileLabel);

	// End of while loop
	codeOperations.push_back(endWhileLabel + "\tnop");

	registers.push(whileExprRegister);
}

void GenerateMoonAssemblyVisitor::visit(WriteAST* n)
{
	SymTab* table = n->getNearestSymbolTable();

	visitChildren(n);

	codeOperations.push_back("% write statement");

	string writeExprRegister = loadVariable(n->getChild(0), table);

	// save jump register state
	codeOperations.push_back("\tsw " + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")," + returnAddressRegister);

	// increment stack frame
	codeOperations.push_back("\taddi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(table->computeInternalOffset() - 4));

	// Put value on stack
	codeOperations.push_back("\tsw -8(" + stackFramePointerRegister + ")," + writeExprRegister);

	// Link buffer to stack
	codeOperations.push_back("\taddi " + writeExprRegister + "," + zeroRegister + ",buf");
	codeOperations.push_back("\tsw -12(" + stackFramePointerRegister + ")," + writeExprRegister);

	// Convert int to string for output
	codeOperations.push_back("\tjl " + returnAddressRegister + ",intstr");
	
	// ?? im overwriting some memory on the stack for some reason
	codeOperations.push_back("\tsw -8(" + stackFramePointerRegister + "),r13");

	// Output to console
	codeOperations.push_back("\tjl r15,putstr");

	// decrement stack frame
	codeOperations.push_back("\tsubi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(table->computeInternalOffset() - 4));

	// restore jump register state
	codeOperations.push_back("\tlw " + returnAddressRegister + "," + std::to_string(table->computeInternalOffset()) + "(" + stackFramePointerRegister + ")");

	registers.push(writeExprRegister);
}