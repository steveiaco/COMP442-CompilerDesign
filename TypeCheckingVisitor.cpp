#include "TypeCheckingVisitor.h"
#include "SymTabFactory.h"
TypeCheckingVisitor::TypeCheckingVisitor()
{
}
void TypeCheckingVisitor::visit(CompositeConceptAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(IdAST* n)
{
	// find variables of the same name in scope
	std::vector<VariableEntry*> variables = n->searchVariableScope(n->getData());

	if (variables.size() > 0) {
		n->setType(variables[0]->type);
	}
}

void TypeCheckingVisitor::visit(IntegerAST* n)
{
	n->setType("integer");
}

void TypeCheckingVisitor::visit(FloatAST* n)
{
	n->setType("float");
}

void TypeCheckingVisitor::visit(StringAST* n)
{
	n->setType("string");
}

void TypeCheckingVisitor::visit(IntegerIdAST* n)
{
}

void TypeCheckingVisitor::visit(FloatIdAST* n)
{
}

void TypeCheckingVisitor::visit(StringIdAST* n)
{
}

void TypeCheckingVisitor::visit(VoidAST* n)
{
}

void TypeCheckingVisitor::visit(PublicAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(PrivateAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(BreakAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ContinueAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(EqualToAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("comparison operation == left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType("boolean");
		}
	}
}

void TypeCheckingVisitor::visit(NotEqualToAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("comparison operation != left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType("boolean");
		}
	}
}

void TypeCheckingVisitor::visit(LessThanAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("comparison operation < left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType("boolean");
		}
	}
}

void TypeCheckingVisitor::visit(GreaterThanAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("comparison operation > left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType("boolean");
		}
	}
}

void TypeCheckingVisitor::visit(LessThanEqualToAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("comparison operation <= left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType("boolean");
		}
	}
}

void TypeCheckingVisitor::visit(GreaterThanEqualToAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("comparison operation >= left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType("boolean");
		}
	}
}

void TypeCheckingVisitor::visit(AdditionAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("addition operation left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType(children[0]->getType());
		}
	}
}

void TypeCheckingVisitor::visit(SubtractionAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("subtraction operation left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType(children[0]->getType());
		}
	}
}

void TypeCheckingVisitor::visit(MultiplicationAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("multiplication operation left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType(children[0]->getType());
		}
	}
}

void TypeCheckingVisitor::visit(DivisionAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("division operation left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
		else {
			n->setType(children[0]->getType());
		}
	}
}

void TypeCheckingVisitor::visit(AssignmentAST* n)
{
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		if (children[0]->getType() != children[1]->getType()) {
			reportError("assignment operation left operand type \"" + children[0]->getType() + "\" and right operand type \"" + children[1]->getType() + "\" are incompatible", n->getToken().getLineNumber());
		}
	}
}

void TypeCheckingVisitor::visit(OrAST* n)
{
}

void TypeCheckingVisitor::visit(AndAST* n)
{
}

void TypeCheckingVisitor::visit(NotAST* n)
{
}

void TypeCheckingVisitor::visit(TernaryAST* n)
{
}

void TypeCheckingVisitor::visit(PeriodAST* n)
{
	// id . function()
	// id . variable
	std::vector<AST*> children = n->getChildren();

	if (children.size() == 2) {
		// check if left side is a class type
		std::vector<VariableEntry*> results = n->searchVariableScope(children[0]->getData());

		if (results.size() > 0) {
			ClassEntry* classResult = n->searchClassScope(results[0]->type);

			//TODO fix this fucking hack
			if (!classResult && (results[0]->type == "float" || results[0]->type == "integer" || results[0]->type == "string")) {
				reportError("dot operator used on variable that is not a class type: " + results[0]->name, n->getToken().getLineNumber());
			}

		}
		else {
			
		}
	}
}

void TypeCheckingVisitor::visit(AParamsListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ArrayDimensionAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ArraySizeReptListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(AssignStatAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ClassDeclBodyListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ClassListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FParamsListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncCallStatAST* n)
{
	
	// if the node's parent is a PeriodAST, then skip checking as we are accessing a method
	if (!dynamic_cast<PeriodAST*>(n->parent)) {
		// if it is not a period, then we are accessing a free function (or a class member function from within the scope of a class!)

		//child 0 : function id
		string functionName = n->getChild(0)->getData();
		//child 1 : aparamslist
		AST* aParamsList = n->getChild(1);
		std::vector<AST*> aParams;
		if (aParamsList) {
			aParams = aParamsList->getChildren();
		}

		std::vector<FunctionEntry*> functionsFoundInScope = n->searchFunctionScope(functionName);

		if (functionsFoundInScope.size() == 0) {
			reportError("function not found: " + functionName, ((TokenAST*)n->getChild(0))->getToken().getLineNumber());
			return;
		}

		bool functionWithMatchingParameterListFound = false;
		bool functionWithSameNumberOfParametersFound = false;
		for (FunctionEntry* functionOfInterest : functionsFoundInScope) {

			if (aParams.size() == functionOfInterest->parameterVarList.size()) {
				functionWithSameNumberOfParametersFound = true;
				bool allParamsMatch = true;

				for (int i = 0; i < functionOfInterest->parameterVarList.size(); i++) {
					AST* aParamsNode = aParams[i];

					if (aParams[i]->getType() != std::get<0>(functionOfInterest->parameterVarList[i])) {
						//n->searchVariableScope()
						//std::vector<int> functionSignatureParamArraySpecifier = std::get<2>(functionOfInterest->parameterVarList[i]);

						allParamsMatch = false;
					}
				}
				if (allParamsMatch) {
					n->setType(functionOfInterest->returnType);
					functionWithMatchingParameterListFound = true;
				}
			}
			
		}

		if (!functionWithSameNumberOfParametersFound) {
			reportError("function call with wrong number of parameters: " + functionName, ((TokenAST*)n->getChild(0))->getToken().getLineNumber());
			return;
		}

		if (!functionWithMatchingParameterListFound) {
			reportError("function call with wrong parameter types: " + functionName, ((TokenAST*)n->getChild(0))->getToken().getLineNumber());
		}

	}
}

void TypeCheckingVisitor::visit(FuncListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncOrVarListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(IndiceRepListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(InheritListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(VarCallStatAST* n)
{
	vector<AST*> children = n->getChildren();
	// check if the variable exists in the current scope
	if (TokenAST* id = (TokenAST*)children[0]) {
		std::vector<VariableEntry*> varResults = n->searchVariableScope(id->getData());
		std::vector<ParameterEntry*> paramResults = n->searchParameterScope(id->getData());

		if (varResults.size() > 0) {
			VariableEntry* record = varResults[0];
			n->setType(record->type);

			if (children.size() == 2) {
				std::vector<AST*> indices = children[1]->getChildren();

				if (indices.size() == record->arrayIndices.size()) {
					for (int i = 0; i < indices.size(); i++) {
						AST* index = indices[i];

						if (index->getType() != "integer") {
							reportError("array dimension " + std::to_string(i) + " index does not resolve to integer type: " + id->getData(), id->getToken().getLineNumber());
						}
					}
				}
				else {
					reportError("wrong number of dimensions used to access array: " + id->getData(), id->getToken().getLineNumber());
				}
			}
		}
		else if (paramResults.size()) {
			// parameter was found
		}
		else {
			reportError("use of undeclared variable: " + id->getData(), id->getToken().getLineNumber());
			return;
		}
	}
}

void TypeCheckingVisitor::visit(VarDeclListAST* n)
{

}

void TypeCheckingVisitor::visit(ArithExprAST* n)
{

}

void TypeCheckingVisitor::visit(ClassDeclAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ClassDeclBodyAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ClassMethodAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ExprAST* n)
{
}

void TypeCheckingVisitor::visit(FParamsAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncBodyAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncDeclAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncDefAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncHeadAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FuncStatAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(FunctionAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(IfAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(IndiceRepAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(InheritAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ProgAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ReadAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(ReturnAST* n)
{
	if (FunctionEntry* function = (FunctionEntry*)n->getNearestSymbolTable()->getNode()->getSymRec()) {
		if (n->getChild(0)->getType() != function->returnType) {
			reportError("return statement does not match return type declared by function: " + function->name, -1);
		}
	}
}

void TypeCheckingVisitor::visit(StartAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(StatementAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(StatementListAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(VarDeclAST* n)
{
	if (VariableEntry* record = (VariableEntry*)n->getSymRec()) {
		if (record->type != "string" && record->type != "integer" && record->type != "float") {
			if (!n->searchClassScope(record->type)) {
				reportError("use of undeclared class: " + record->type, ((TokenAST*)n->getChild(1))->getToken().getLineNumber());
			}
		}
	}

	// TODO this is a huge hack
	VariableEntry* variableRec = (VariableEntry*)n->getSymRec();
	if (ClassEntry* record = n->getNearestSymbolTable()->findClassRecord(variableRec->type)) {
		variableRec->link = record->link;
	}
}

void TypeCheckingVisitor::visit(VariableAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(WhileAST* n)
{
	// no implementation
}

void TypeCheckingVisitor::visit(WriteAST* n)
{
	// no implementation
}
