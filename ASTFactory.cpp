#include "ASTFactory.h"
#include "IntegerAST.h"
#include "IdAST.h"
#include "FloatAST.h"
#include "StringAST.h"
#include "VisibilityAST.h"
#include "CompositeConceptAST.h"
#include "GeneralTokenAST.h"

vector<std::shared_ptr<AST>> ASTFactory::treesProduced;

AST* ASTFactory::makeNode()
{
	treesProduced.push_back(std::unique_ptr<AST>(new AST()));
	return treesProduced[treesProduced.size() - 1].get();
}

AST* ASTFactory::makeNode(Token t)
{
	// TODO add the rest of the class types here
	switch (t.getTokenType()) {
	case TokenType::ID:
		treesProduced.push_back(shared_ptr<AST>(new IdAST(t)));
		break;
	case TokenType::INTEGER:
		treesProduced.push_back(shared_ptr<AST>(new IntegerAST(t)));
		break;
	case TokenType::FLOAT:
		treesProduced.push_back(shared_ptr<AST>(new FloatAST(t)));
		break;
	case TokenType::STRING:
		treesProduced.push_back(shared_ptr<AST>(new StringAST(t)));
		break;
	case TokenType::PUBLIC:
	case TokenType::PRIVATE:
		treesProduced.push_back(shared_ptr<AST>(new VisibilityAST(t)));
		break;
	default:
		treesProduced.push_back(shared_ptr<AST>(new GeneralTokenAST(t)));
	}

	return treesProduced[treesProduced.size() - 1].get();
}

AST* ASTFactory::makeNode(CompositeConcept t)
{
	// TODO introduce individual class types here
	treesProduced.push_back(shared_ptr<AST>(new CompositeConceptAST(t)));
	return treesProduced[treesProduced.size() - 1].get();
}

AST* ASTFactory::makeFamily(CompositeConcept t, vector<AST*> children)
{
	AST* parent = makeNode(t);

	makeFamily(parent, children);

	return parent;
}

void ASTFactory::makeFamily(AST* parent, vector<AST*> children)
{
	AST* firstValidChild = nullptr;

	for (AST* child : children) {
		if (child) {
			if (!firstValidChild) {
				// the first non-null sibling is found
				firstValidChild = child;
				continue;
			}
			firstValidChild->makeSiblings(child);
		}
	}
	
	if (firstValidChild) {
		parent->adoptChildren(firstValidChild);
	}
}