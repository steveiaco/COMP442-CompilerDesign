#pragma once
#include <string>

using std::string;

class AST {
public:
	AST* leftMostSibling;
	AST* leftMostChild;
	AST* rightSibling;
	AST* parent;

	AST();
	~AST();

	// inserts a new sibling node y into the current instance's list of siblings
	AST* makeSiblings(AST* y);

	// adopts y as a child
	void adoptChildren(AST* y);

	virtual string toString();
	string toDotString();
};