#include "GenerateMoonAssemblyVisitor.h"
#include "SymTabFactory.h"
#include <iostream>

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

	// If the right child is an expression (operator)
	else if (CompositeConceptTokenAST* operatorType = dynamic_cast<CompositeConceptTokenAST*>(valueNode))
	{
		SymTabEntry* tempVar = table->findTemporaryRecord(operatorType->getAssemData());

		codeOperations.push_back("\tlw " + reg + "," + std::to_string(tempVar->getOffset()) + "(" + zeroRegister + ")");
	}

	// If right child is immediate type (integer, float, string)
	else if (TokenAST* immType = dynamic_cast<TokenAST*>(valueNode))
	{
		codeOperations.push_back("\taddi " + reg + "," + zeroRegister + "," + immType->getAssemData());
	}

	return reg;
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
	registers.push("r13");
}

std::vector<string> GenerateMoonAssemblyVisitor::getCode()
{
	std::vector<string> construct;

	//for (std::string::iterator stackContent = codeOperations.top().begin(); stackContent != codeOperations.top().end(); stackContent++) {
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
}

void GenerateMoonAssemblyVisitor::visit(IdAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(IntegerAST* n)
{
	// assem data is already setup
}

void GenerateMoonAssemblyVisitor::visit(FloatAST* n)
{
	// assem data is already setup
}

void GenerateMoonAssemblyVisitor::visit(StringAST* n)
{
	// assem data is already setup
}

void GenerateMoonAssemblyVisitor::visit(IntegerIdAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FloatIdAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(StringIdAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(VoidAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(PublicAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(PrivateAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(BreakAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ContinueAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(EqualToAST* n)
{
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
	codeOperations.push_back("% assignment operation");

	AST* leftChild = n->getChild(0);
	AST* rightChild = n->getChild(1);

	SymTab* table = n->getNearestSymbolTable();

	// Search variable and parameter in symtab
	SymTabEntry* varAssignmentLHS = table->findVariableRecord(leftChild->getData());
	if (varAssignmentLHS == nullptr) 
	{
		varAssignmentLHS = table->findParameterRecord(leftChild->getData());
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
}

void GenerateMoonAssemblyVisitor::visit(PeriodAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(AParamsListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ArrayDimensionAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ArraySizeReptListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(AssignStatAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ClassDeclBodyListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ClassListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FParamsListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FuncCallStatAST* n)
{
	// if the parent node is of type PeriodAST then we must skip this funccall as the parent will take care of the operation
	if (PeriodAST* period = dynamic_cast<PeriodAST*>(n->parent)) {
		return;
	}

	// TODO handle the case where we are within a class scope

	// Handle free function call
	AST* functionNameNode = n->getChild(0);
	SymTab* table = n->getNearestSymbolTable();

	if (functionNameNode != nullptr && table != nullptr) {

		FunctionEntry* functionEntry = nullptr;

		// grab function name 
		std::vector<FunctionEntry*> entries = table->findFunctionRecord(functionNameNode->getData());
		if (entries.size() != 0) {
			functionEntry = entries[0];
		}
		// comment
		codeOperations.push_back("\t% function call to " + functionNameNode->getData());

		// TODO handle parameter copying

		// increment stack frame
		codeOperations.push_back("\taddi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(table->computeInternalOffset()));
		
		// save jump register state
		
		// jump instruction
		codeOperations.push_back("\tjl " + returnAddressRegister + "," + functionEntry->name);
		
		// restore jump register state
		
		// decrement stack frame
		codeOperations.push_back("\tsubi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(table->computeInternalOffset()));
	}
}

void GenerateMoonAssemblyVisitor::visit(FuncListAST* n)
{
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
}

void GenerateMoonAssemblyVisitor::visit(IndiceRepListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(InheritListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(VarCallStatAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(VarDeclListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ArithExprAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ClassDeclAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ClassDeclBodyAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ClassMethodAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ExprAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FParamsAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FuncBodyAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FuncDeclAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FuncDefAST* n)
{
	if (FunctionEntry* fEntry = dynamic_cast<FunctionEntry*>(n->getSymRec())) {
		codeOperations.push_front(fEntry->name);
		functions.push_back(codeOperations);
		codeOperations = std::deque<string>();
	}
}

void GenerateMoonAssemblyVisitor::visit(FuncHeadAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FuncStatAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(FunctionAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(IfAST* n)
{
	SymTab* table = n->getSymTab();
	string boolExpr = loadVariable(n->getChild(0), table);


}

void GenerateMoonAssemblyVisitor::visit(IndiceRepAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(InheritAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ProgAST* n)
{
	if (SymTab* table = n->getSymTab()) {
		// Setup program entry
		codeOperations.push_front("MAIN");
		codeOperations.push_front("\taddi " + stackFramePointerRegister + "," + zeroRegister + ",topaddr");
		codeOperations.push_front("\tentry");
		// Add the hlt instruction to the end of main
		codeOperations.push_back("\thlt");

		functions.push_back(codeOperations);
	}
}

void GenerateMoonAssemblyVisitor::visit(ReadAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(ReturnAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(StartAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(StatementAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(StatementListAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(VarDeclAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(VariableAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(WhileAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(WriteAST* n)
{
}
