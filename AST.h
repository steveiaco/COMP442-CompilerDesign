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

	// symbol table functions
	void insert(SymTabEntry s);
	void search(SymTabEntry s);
	void printSymTab();
	void deleteSymTab();

	virtual string toString() = 0;
	string toDotString();

	// todo remove?
	virtual string getData() { return data; }
	virtual void setData(string data) { this->data = data; }

	SymTabEntry* getSymRec() { return symRec; }
	void setSymRec(SymTabEntry* data) { this->symRec = data; }

	SymTab* getSymTab() { return symTable; }
	void setSymTab(SymTab* symTable);
};