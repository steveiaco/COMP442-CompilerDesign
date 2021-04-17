#include "GenerateMoonAssemblyVisitor.h"
#include "SymTabFactory.h"
#include <iostream>

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
	while (codeOperations.size() != 0) {
		construct.push_back(codeOperations.top());
		codeOperations.pop();
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
}

void GenerateMoonAssemblyVisitor::visit(NotEqualToAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(LessThanAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(GreaterThanAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(LessThanEqualToAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(GreaterThanEqualToAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(AdditionAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(SubtractionAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(MultiplicationAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(DivisionAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(AssignmentAST* n)
{
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

		// FOLLOWING INSTRUCTIONS ARE OUTPUT IN OPPOSITE ORDER

		// Write the register contents to the variables stack offset
		codeOperations.push("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);

		// Load the variable's contents into a register
		codeOperations.push("\tlw " + reg + "," + std::to_string(varAssignmentRHS->getOffset()) + "(" + stackFramePointerRegister + ")");

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

		// FOLLOWING INSTRUCTIONS ARE OUTPUT IN OPPOSITE ORDER

		// Write the register contents to the variables stack offset
		codeOperations.push("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);

		// Load the variable's contents into a register
		codeOperations.push("\tlw " + reg + "," + std::to_string(varAssignmentRHS->getOffset()) + "(" + stackFramePointerRegister + ")");

		// Put the register back as we're done with it
		registers.push(reg);
	}

	// If right child is immediate type (integer, float, string)
	else if (TokenAST* immType = dynamic_cast<TokenAST*>(rightChild)) 
	{
		// Get a register
		string reg = registers.top(); registers.pop();

		// FOLLOWING INSTRUCTIONS ARE OUTPUT IN OPPOSITE ORDER

		// Write the register contents to the variable's stack offset
		codeOperations.push("\tsw " + std::to_string(varAssignmentLHS->getOffset()) + "(" + stackFramePointerRegister + ")" + "," + reg);

		// Add the immediate value to the register
		codeOperations.push("\taddi " + reg + "," + reg + "," + immType->getData());

		// Clear the contents of the register
		codeOperations.push("\tsub " + reg + "," + reg + "," + reg);

		// Put the register back as we're done with it
		registers.push(reg);
	}
	// TODO support array assignment
}

void GenerateMoonAssemblyVisitor::visit(OrAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(AndAST* n)
{
}

void GenerateMoonAssemblyVisitor::visit(NotAST* n)
{
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

		// decrement stack frame
		codeOperations.push("\tsubi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(table->computeInternalOffset()));

		// restore jump register state

		// jump instruction
		codeOperations.push("\tjl " + returnAddressRegister + "," + functionEntry->name);

		// save jump register state

		// increment stack frame
		codeOperations.push("\taddi " + stackFramePointerRegister + "," + stackFramePointerRegister + "," + std::to_string(table->computeInternalOffset()));

		// TODO handle parameter copying

		// comment
		codeOperations.push("\t% function call to " + functionNameNode->getData());
	}
}

void GenerateMoonAssemblyVisitor::visit(FuncListAST* n)
{
	// This node is visited right before we start visiting the main subtree
	// Add the hlt instruction to the end of main
	if (ProgAST* progParent = dynamic_cast<ProgAST*>(n->parent)) {
		codeOperations.push("\thlt");
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
		// TODO check if the table contains the correct function name, otherwise grab it from the function node itself
		codeOperations.push(fEntry->name);
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
		codeOperations.push("MAIN");
		codeOperations.push("\taddi " + stackFramePointerRegister + "," + zeroRegister + ",topaddr");
		codeOperations.push("\tentry");
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
