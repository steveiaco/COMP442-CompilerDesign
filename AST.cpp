#include "AST.h"
#include "ASTFactory.h"
#include "Token.h"

AST::AST()
{
	leftMostSibling = this;
	leftMostChild = nullptr;
	rightSibling = nullptr;
	parent = nullptr;
}

AST::~AST()
{
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