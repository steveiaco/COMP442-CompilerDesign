#include "AST.h"
#include "ASTFactory.h"
#include "Token.h"
#include <iostream>
#include "SymTabFactory.h"
#include "VariableEntry.h"
#include "FunctionEntry.h"
#include "ClassEntry.h"
#include "ParameterEntry.h"


AST::AST()
{
	leftMostSibling = this;
	leftMostChild = nullptr;
	rightSibling = nullptr;
	parent = nullptr;

	symRec = nullptr;
	symTable = nullptr;
}

AST::~AST()
{
	std::cout << "deleting";
}

std::vector<AST*> AST::getChildren()
{
	vector<AST*> children;
	AST* child = leftMostChild;

	while (child != nullptr) {
		children.push_back(child);
		child = child->rightSibling;
	}
	return children;
}

AST* AST::getChild(int c)
{
	AST* child = leftMostChild;
	int childCount = 0;
	while (child != nullptr && childCount != c) {
		child = child->rightSibling;
		childCount++;
	}
	return child;
}

string AST::toDotString()
{
	stringstream astDot;
	AST* child = leftMostChild;

	string currentIdentifier = this->toString();

	while (child != nullptr) {
		astDot << "\"" + currentIdentifier + "\"->\"" + child->toString() + "\"\n";
		astDot << child->toDotString();
		child = child->rightSibling;
	}

	return astDot.str();
}

void AST::setSymTab(SymTab* symTable)
{
	this->symTable = symTable;
	this->symTable->setName(toString());
	this->symTable->setNode(this);
}

std::vector<VariableEntry*> AST::searchVariableScope(string name)
{
	std::vector<VariableEntry*> results;

	//if (FunctionEntry* symRecFunction = dynamic_cast<FunctionEntry*>(symRec)) {
	//	if (symRecFunction && symRecFunction->containerClass) {
	//		symRecFunction->containerClass->findVariableRecord(name);
	//	}
	//}

	if (symTable) {
		if (VariableEntry* r = symTable->findVariableRecord(name)) {
			results.emplace_back(r);
		}
	}

	if (parent) {
		std::vector<VariableEntry*> parentResults = parent->searchVariableScope(name);
		results.insert(results.end(), parentResults.begin(), parentResults.end());
	}

	return results;
}

std::vector<ParameterEntry*> AST::searchParameterScope(string name)
{
	std::vector<ParameterEntry*> results;

	if (symTable) {
		if (ParameterEntry* r = symTable->findParameterRecord(name)) {
			results.emplace_back(r);
		}
	}

	if (parent) {
		std::vector<ParameterEntry*> parentResults = parent->searchParameterScope(name);
		results.insert(results.end(), parentResults.begin(), parentResults.end());
	}

	return results;
}

std::vector<FunctionEntry*> AST::searchFunctionScope(string name)
{
	std::vector<FunctionEntry*> results;

	if (symTable) {
		std::vector<FunctionEntry*> functionEntries = symTable->findFunctionRecord(name);
		if (functionEntries.size() > 0) {
			results.insert(results.end(), functionEntries.begin(), functionEntries.end());
		}
	}

	if (parent) {
		std::vector<FunctionEntry*> parentResults = parent->searchFunctionScope(name);
		results.insert(results.end(), parentResults.begin(), parentResults.end());
	}

	return results;
}

ClassEntry* AST::searchClassScope(string name)
{

	if (symTable) {
		ClassEntry* result = symTable->findClassRecord(name);
		if (result) {
			return result;
		}
	}

	if (parent) {
		return parent->searchClassScope(name);
	}

	return nullptr;
}

void AST::insertIntoNearestTable(SymTabEntry* data)
{
	SymTab* table = getNearestSymbolTable();
	table->insertRecord(data);
}

SymTab* AST::getNearestSymbolTable()
{
	if (symTable) {
		return symTable;
	}
	else if(parent) {
		return parent->getNearestSymbolTable();
	}
	else {
		return nullptr;
	}
}

AST* AST::makeSiblings(AST* y)
{
	if (!y) {
		return nullptr;
	}

	// find the rightmode node in this sibling list
	AST* xsibs = this;
	while (xsibs->rightSibling != nullptr) {
		xsibs = xsibs->rightSibling;
	}

	// join the lists
	AST* ysibs = y->leftMostSibling;
	xsibs->rightSibling = ysibs;

	// set points for the new siblings
	ysibs->leftMostSibling = xsibs->leftMostSibling;
	ysibs->parent = xsibs->parent;

	while (ysibs->rightSibling != nullptr) {
		ysibs = ysibs->rightSibling;
		ysibs->leftMostSibling = xsibs->leftMostSibling;
		ysibs->parent = xsibs->parent;
	}

	return ysibs;
}

void AST::adoptChildren(AST* y)
{
	if (this->leftMostChild != nullptr) {
		this->leftMostChild->makeSiblings(y);
	}
	else {
		AST* ysibs = y->leftMostSibling;
		this->leftMostChild = ysibs;

		while (ysibs != nullptr) {
			ysibs->parent = this;
			ysibs = ysibs->rightSibling;
		}
	}
}
