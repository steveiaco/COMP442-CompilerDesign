#pragma once
#include <string>
#include "SymTabEntry.h"
#include "SymTab.h"
#include <vector>
class Visitor;

using std::string;

class AST {
private:
	string data;

	string assemData;

	// Symbolic entry and table generation, error checking visitors
	string type;
	SymTab* symTable;
	SymTabEntry* symRec;

public:
	AST* leftMostSibling;
	AST* leftMostChild;
	AST* rightSibling;
	AST* parent;

	AST();
	~AST();

	std::vector<AST*> getChildren();

	AST* getChild(int c);

	// inserts a new sibling node y into the current instance's list of siblings
	AST* makeSiblings(AST* y);

	// adopts y as a child
	void adoptChildren(AST* y);

	// visitor functions
	virtual void accept(Visitor* visitor) = 0;


	virtual string toString() = 0;
	string toDotString();

	// todo remove?
	virtual string getData() { return data; }
	virtual void setData(string data) { this->data = data; }

	virtual string getAssemData() { return assemData; }
	virtual void setAssemData(string data) { this->assemData = data; }

	SymTabEntry* getSymRec() { return symRec; }
	void setSymRec(SymTabEntry* data) { this->symRec = data; }

	SymTab* getSymTab() { return symTable; }
	void setSymTab(SymTab* symTable);

	string getType() { return type; }
	void setType(string type) { this->type = type; }

	std::vector<VariableEntry*> searchVariableScope(string name);
	std::vector<FunctionEntry*> searchFunctionScope(string name);
	std::vector<ParameterEntry*> searchParameterScope(string name);
	ClassEntry* searchClassScope(string name);

	void insertIntoNearestTable(SymTabEntry* data);
	SymTab* getNearestSymbolTable();
};