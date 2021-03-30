#pragma once
#include <string>
#include "Visitor.h"

using std::string;

class AST {
public:
	AST* leftMostSibling;
	AST* leftMostChild;
	AST* rightSibling;
	AST* parent;

	AST();
	~AST();

	AST* getChild(int c);

	// inserts a new sibling node y into the current instance's list of siblings
	AST* makeSiblings(AST* y);

	// adopts y as a child
	void adoptChildren(AST* y);

	virtual void accept(Visitor* visitor) = 0;

	virtual string toString() = 0;
	string toDotString();
};