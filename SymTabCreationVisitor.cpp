#include "SymTabCreationVisitor.h"
#include <vector>
#include "SymTabFactory.h"

using std::vector;

SymTabCreationVisitor::SymTabCreationVisitor()
{
}

void SymTabCreationVisitor::visit(CompositeConceptAST* n)
{
	//nothing
}

void SymTabCreationVisitor::visit(IdAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(IntegerAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(FloatAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(StringAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(IntegerIdAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(FloatIdAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(StringIdAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(VoidAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(PublicAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(PrivateAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(BreakAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(ContinueAST* n)
{
	// leaf node
	return;
}

void SymTabCreationVisitor::visit(EqualToAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(NotEqualToAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(LessThanAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(GreaterThanAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(LessThanEqualToAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(GreaterThanEqualToAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(AdditionAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(SubtractionAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(MultiplicationAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(DivisionAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(AssignmentAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(OrAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(AndAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(NotAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(TernaryAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(PeriodAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(AParamsListAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(ArrayDimensionAST* n)
{
}

void SymTabCreationVisitor::visit(ArraySizeReptListAST* n)
{
}

void SymTabCreationVisitor::visit(AssignStatAST* n)
{
	// operator
	return;
}

void SymTabCreationVisitor::visit(ClassDeclBodyListAST* n)
{
	// do nothing
	return;
}

void SymTabCreationVisitor::visit(ClassListAST* n)
{

	std::vector<AST*> children = n->getChildren();
	std::vector<string> duplicateClasses;
	// check for multiply declared classes
	for (int i = 0; i < children.size(); i++) {
		for (int j = 0; j < children.size(); j++) {
			if (i == j) {
				continue;
			}

			// if we have a duplicate, it's an error
			if (children[i]->getSymRec()->name == children[j]->getSymRec()->name) {
				if (std::find(duplicateClasses.begin(), duplicateClasses.end(), children[i]->getSymRec()->name) == duplicateClasses.end()) {
					int line = ((TokenAST*)children[j]->getChild(0))->getToken().getLineNumber();
					reportError("multiply declared class: " + children[i]->getSymRec()->name, line);
					duplicateClasses.push_back(children[i]->getSymRec()->name);
				}
				else {
					// else we have already detected this duplicate
				}
			}
		}
	}

	// populate inheritance links for each ClassEntry
	for (AST* classDecl : children) {
		std::vector<ClassEntry*> inheritanceList = classDecl->getSymTab()->getClassRecords();
		// iterate over the class entry's inheritence list
		for (ClassEntry* ancestor : inheritanceList) {

			// if the current class name is the same as the class it's inheriting, this is a self inheritance
			if (classDecl->getSymRec()->name == ancestor->name) {
				int line = ((TokenAST*)classDecl->getChild(0))->getToken().getLineNumber();
				reportError("circular inhertiance (class attempting to inherit itself): " + classDecl->getSymRec()->name, line);
			}

			bool matchFound = false;
			// find the actual class the inheritance entry is referring to 
			for (AST* classDeclCompare : children) {
				// found the class
				if (classDeclCompare->getSymRec()->name == ancestor->name) {
					ancestor->link = classDeclCompare->getSymTab();
					matchFound = true;
				}
			}

			if (!matchFound) {
				int line = ((TokenAST*)classDecl->getChild(0))->getToken().getLineNumber();
				reportError("inherit undeclared class: " + ancestor->name, line);
			}
		}

	}
}

void SymTabCreationVisitor::visit(FParamsListAST* n)
{
}

void SymTabCreationVisitor::visit(FuncCallStatAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(FuncListAST* n)
{
}

void SymTabCreationVisitor::visit(FuncOrVarListAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(IndiceRepListAST* n)
{
}

void SymTabCreationVisitor::visit(InheritListAST* n)
{
	std::vector<AST*> children = n->getChildren();

	for (AST* child : children) {
		ClassEntry* classEntry = SymTabFactory::makeSymClassRec();
		classEntry->name = child->getData();
		child->setSymRec(classEntry);
	}
}

void SymTabCreationVisitor::visit(VarCallStatAST* n)
{
	//may cause bugs!!
	// this is a quick fix, pass the variable name up to it's parent node so that future traversals don't have to traverse all the way to the leaf to get the var name
	n->setData(n->getChild(0)->getData());
}

void SymTabCreationVisitor::visit(VarDeclListAST* n)
{
	std::vector<AST*> varDeclNodes = n->getChildren();
	std::vector<string> duplicateDetected;
	for (AST* varDecl : varDeclNodes) {
		for (AST* varDeclCompare : varDeclNodes) {
			if (varDecl != varDeclCompare && varDecl->getSymRec()->name == varDeclCompare->getSymRec()->name) {
				if (std::find(duplicateDetected.begin(), duplicateDetected.end(), varDecl->getSymRec()->name) == duplicateDetected.end()) {
					int line = ((TokenAST*)varDeclCompare->getChild(1))->getToken().getLineNumber();
					reportError("multiply declared data member: " + varDecl->getSymRec()->name, line);
					duplicateDetected.push_back(varDecl->getSymRec()->name);
				}
			}
		}
	}
}

void SymTabCreationVisitor::visit(ArithExprAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(ClassDeclAST* n)
{
	std::vector<AST*> children = n->getChildren();

	// create symTab
	SymTab* table = SymTabFactory::makeSymTab();
	n->setSymTab(table);

	// create class entry
	ClassEntry* classEntry = SymTabFactory::makeSymClassRec();

	// link symtab to class entry
	classEntry->link = table;
	n->setSymRec(classEntry);

	if (children.size() == 3) {
		// POPULATE CLASSENTRY
		// set class name
		classEntry->name = children[0]->getData();

		// POPULATE SYMTAB
		// add inherited classes to symtab
		std::vector<AST*> inheritListChildren = children[1]->getChildren();
		for (AST* inheritId : inheritListChildren) {
			table->insertRecord(inheritId->getSymRec());
		}

		// add class declarations to symtab
		std::vector<AST*> classDeclBodyListChildren = children[2]->getChildren();
		for (AST* classDeclBody : classDeclBodyListChildren) {
			// visiblity may or may not be included here, so get the right most child
			table->insertRecord(classDeclBody->getChildren().back()->getSymRec());
		}
	}

}

void SymTabCreationVisitor::visit(ClassDeclBodyAST* n)
{
	std::vector<AST*> children = n->getChildren();

	VisibilityEntry* record = nullptr;
	// If visibility was not included
	if (children.size() == 1) {
		record = (VisibilityEntry*)(children[0]->getSymRec());
	}
	// If visibility was included
	else if (children.size() == 2) {
		// TRANSFER VISIBILITY
		record = (VisibilityEntry*)(children[1]->getSymRec());
		record->visibility = children[0]->getData();
	}

	n->setSymRec(record);
}

void SymTabCreationVisitor::visit(ClassMethodAST* n)
{
	if (AST* child = n->getChild(0)) {
		n->setData(child->getData());
	}
}

void SymTabCreationVisitor::visit(ExprAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(FParamsAST* n)
{
	std::vector<AST*> children = n->getChildren();
	ParameterEntry* parameter = SymTabFactory::makeSymParameterEntry();
	// child, id
	if (children.size() == 2) {
		parameter->type = children[0]->getData();
		parameter->name = children[1]->getData();
	}
	// child, id, arrayind
	else if (children.size() == 3) {
		parameter->type = children[0]->getData();
		parameter->name = children[1]->getData();
		std::vector<int> arraydims;
		std::vector<AST*> arrayDimensions = children[2]->getChildren();
		for (AST* arrayDim : arrayDimensions) {
			std::vector<AST*> arrayDimChild = arrayDim->getChildren();
			if (arrayDimChild.size() == 0) {
				arraydims.push_back(-1);
			}
			else if (arrayDimChild.size() == 1) {
				arraydims.push_back(std::stoi(arrayDimChild[0]->getData()));
			}
		}
		parameter->arrayIndices = arraydims;
	}
	n->setSymRec(parameter);
}

void SymTabCreationVisitor::visit(FuncBodyAST* n)
{
}

void SymTabCreationVisitor::visit(FuncDeclAST* n)
{
	std::vector<AST*> funcDeclChildren = n->getChildren();
	FunctionEntry* fe = SymTabFactory::makeSymFunctionEntry();
	n->setSymRec(fe);

	if (funcDeclChildren.size() == 3) {
		// set function name
		fe->name = funcDeclChildren[0]->getData();
		// set function return type
		fe->returnType = funcDeclChildren[2]->getData();

		// set function parameters
		for (AST* funcParam : funcDeclChildren[1]->getChildren()) {
			ParameterEntry* param = ((ParameterEntry*)funcParam->getSymRec());
			fe->parameterVarList.push_back(std::make_tuple(param->type, param->name, param->arrayIndices));
		}

	}
}

void SymTabCreationVisitor::visit(FuncDefAST* n)
{
	// in the case of the main function, the SymTab and FunctionEntry go unused
	std::vector<AST*> children = n->getChildren();
	FunctionEntry* fe = SymTabFactory::makeSymFunctionEntry();
	SymTab* symTable = SymTabFactory::makeSymTab();
	fe->link = symTable;
	n->setSymTab(symTable);
	n->setSymRec(fe);

	if (children.size() == 2) {
		std::vector<AST*> funcHeadChildren = children[0]->getChildren();

		// free function
		if (funcHeadChildren.size() == 3) {
			// set function name
			fe->name = funcHeadChildren[0]->getData();
			// set function return type
			fe->returnType = funcHeadChildren[2]->getData();

			// set function parameters
			for (AST* funcParam : funcHeadChildren[1]->getChildren()) {
				symTable->insertRecord(funcParam->getSymRec());
				ParameterEntry* param = ((ParameterEntry*)funcParam->getSymRec());
				fe->parameterVarList.push_back(std::make_tuple(param->type, param->name, param->arrayIndices));
			}
		}
		// class member function
		else if (funcHeadChildren.size() == 4) {
			// set function name
			fe->name = funcHeadChildren[1]->getChild(0)->getData();
			// set function return type
			fe->returnType = funcHeadChildren[3]->getData();
			// set function class method if it is a member function
			fe->classmethod = funcHeadChildren[0]->getData();
			// set function parameters
			for (AST* funcParam : funcHeadChildren[2]->getChildren()) {
				symTable->insertRecord(funcParam->getSymRec());
				ParameterEntry* param = ((ParameterEntry*)funcParam->getSymRec());
				fe->parameterVarList.push_back(std::make_tuple(param->type, param->name, param->arrayIndices));
			}
		}

		std::vector<AST*> funcBodyChildren = children[1]->getChildren();
		// if the VarDeclList is excluded, then there will only be 1 child (the StatementList)
		if (funcBodyChildren.size() == 2) {
			std::vector<AST*> varDeclListChildren = funcBodyChildren[0]->getChildren();

			for (AST* varDecl : varDeclListChildren) {
				symTable->insertRecord(varDecl->getSymRec());
			}
		}


	}
}

void SymTabCreationVisitor::visit(FuncHeadAST* n)
{
	//empty?
}

void SymTabCreationVisitor::visit(FuncStatAST* n)
{
	// non-declaration
}

void SymTabCreationVisitor::visit(FunctionAST* n)
{
	//doesn't exist in ast
}

void SymTabCreationVisitor::visit(IfAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(IndiceRepAST* n)
{
}

void SymTabCreationVisitor::visit(InheritAST* n)
{
}

void SymTabCreationVisitor::visit(ProgAST* n)
{
	std::vector<AST*> children = n->getChildren();

	// create global symbol table
	SymTab* globalTable = SymTabFactory::makeSymTab();
	n->setSymTab(globalTable);

	if (children.size() == 3) {
		// process class list
		std::vector<AST*> classListChildren = children[0]->getChildren();

		// process function list
		std::vector<AST*> funcListChildren = children[1]->getChildren();

		// process main function
		std::vector<AST*> mainFuncBodyChildren = children[2]->getChildren();


		// gather class SymRecords 
		for (AST* classDeclNode : classListChildren) {
			globalTable->insertRecord(classDeclNode->getSymRec());
		}

		// gather function SymRecords
		for (AST* funcDefNode : funcListChildren) {
			FunctionEntry* functionSymbol = (FunctionEntry*)(funcDefNode->getSymRec());

			// if we encounter a class member function
			if (functionSymbol->classmethod != "") {
				// we must find the corresponding function entry in the class symbol table and link it to this function's symbol table
				ClassEntry* classEntry = globalTable->findClassRecord(functionSymbol->classmethod);

				if (classEntry != nullptr) {
					SymTab* classTable = classEntry->link;
					std::vector<FunctionEntry*> classFunctionEntries = classTable->findFunctionRecord(functionSymbol->name);

					// check that the matched function has the same signature
					if (classFunctionEntries.size() > 0) {
						for (FunctionEntry* shadowFound : classFunctionEntries) {
							if (functionSymbol->compare(shadowFound)) {
								shadowFound->link = functionSymbol->link;
							}
						}
						functionSymbol->containerClass = classTable;
					}
					else {
						int line = ((TokenAST*)funcDefNode->getChild(0)->getChild(0))->getToken().getLineNumber();
						reportError("definition for undeclared class member function: " + functionSymbol->classmethod + "::" + functionSymbol->name, line);
					}
				}
				else {
					int line = ((TokenAST*)funcDefNode->getChild(0)->getChild(0))->getToken().getLineNumber();
					reportError("member function definition for undeclared class: " + functionSymbol->classmethod + "::" + functionSymbol->name, line);
				}

			}
			// if we encounter a global function
			else {
				std::vector<FunctionEntry*> results = globalTable->findFunctionRecord(functionSymbol->name);
				if (results.size() > 0) {
					for (FunctionEntry* result : results) {
						// check if it is overloading another function
						int line = ((TokenAST*)funcDefNode->getChild(0)->getChild(0))->getToken().getLineNumber();
						if (result->compare(functionSymbol)) {
							reportError("free function redefinition: " + functionSymbol->name, line);
						}
						else {
							reportError("free function overload: " + functionSymbol->name, line);
						}
					}
					

					// check if it is redefining another function

				}
				// add it's symrec to the global scope symbol table
				globalTable->insertRecord(functionSymbol);
			}
		}

		// gather main function symRecords (global variables)
		for (AST* mainVarDecl : mainFuncBodyChildren[0]->getChildren()) {
			globalTable->insertRecord(mainVarDecl->getSymRec());
		}

		//// check if all class member functions have a definition
		//// detect shadowing class variables
		for (AST* classDecl : classListChildren) {
			std::vector<FunctionEntry*> memberFunctions = classDecl->getSymTab()->getFunctionRecords();

			// check if all class member functions have a definition
			for (FunctionEntry* memberFunction : memberFunctions) {
				if (memberFunction->link == nullptr) {
					int line = ((TokenAST*)classDecl->getChild(0))->getToken().getLineNumber();
					string s = "class member function definition not found: " + classDecl->getSymRec()->name + "::" + memberFunction->name;
					reportError(s, line);
				}
			}

			SymTab* classSymTab = classDecl->getSymTab();

			std::vector<ClassEntry*> classRecords = classSymTab->getClassRecords();
			std::vector<VariableEntry*> variableRecords = classSymTab->getVariableRecords();
			std::vector<FunctionEntry*> functionRecords = classSymTab->getFunctionRecords();

			for (ClassEntry* classRec : classRecords) {
				// detect shadowing class variables
				for (VariableEntry* variable : variableRecords) {
					VariableEntry* shadowedRecord = classRec->link->findVariableRecord(variable->name);
					if (shadowedRecord) {
						int line = ((TokenAST*)classDecl->getChild(0))->getToken().getLineNumber();
						reportError("shadowed inherited member variable: " + classDecl->getSymRec()->name + "::" + variable->name + " shadows " + classRec->name + "::" + shadowedRecord->name, line);
					}
				}
				// detect shadowing member functions
				for (FunctionEntry* function : functionRecords) {
					std::vector<FunctionEntry*> shadowedRecord = classRec->link->findFunctionRecord(function->name);
					// we must compare the function signature, as we may have an overload
					for (FunctionEntry* shadowFound : shadowedRecord) {
						if (function->compare(shadowFound)) {
							int line = ((TokenAST*)classDecl->getChild(0))->getToken().getLineNumber();
							reportError("shadowed member function (overwritten function): " + classDecl->getSymRec()->name + "::" + function->name + " shadows " + classRec->name + "::" + shadowFound->name, line);
						}

					}
				}
			}
		}
	}
}

void SymTabCreationVisitor::visit(ReadAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(ReturnAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(StartAST* n)
{

}

void SymTabCreationVisitor::visit(StatementAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(StatementListAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(VarDeclAST* n)
{
	std::vector<AST*> children = n->getChildren();
	VariableEntry* variableRec = SymTabFactory::makeSymVariableRec();
	n->setSymRec(variableRec);

	// no array specifier 
	if (children.size() == 2) {
		variableRec->type = children[0]->getData();
		variableRec->name = children[1]->getData();
	}
	// array specifier
	else if (children.size() == 3) {
		variableRec->type = children[0]->getData();
		variableRec->name = children[1]->getData();

		std::vector<int> indices;
		std::vector<AST*> arrayDimensions = children[2]->getChildren();
		for (AST* dim : arrayDimensions) {
			std::vector<AST*> index = dim->getChildren();
			// index specifier included
			if (index.size() == 1) {
				indices.push_back(std::stoi(index[0]->getData()));
			}
			// index specifier not included
			else {
				indices.push_back(-1);
			}
		}
		variableRec->arrayIndices = indices;
	}
}

void SymTabCreationVisitor::visit(VariableAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(WhileAST* n)
{
	// non-declaration
	return;
}

void SymTabCreationVisitor::visit(WriteAST* n)
{
	// non-declaration
	return;
}
