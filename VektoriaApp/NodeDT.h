#pragma once
#include "Option.h"

class NodeDT
{
public:
	NodeDT();
	bool isALeaf;

	NodeDT* m_falseNode;
	NodeDT* m_trueNode;

	Option* m_option;

	void addFalseNode(NodeDT* node);
	void addTrueNode(NodeDT* node);

	virtual NodeDT* getNextNode();

	NodeDT* makeDecision();
};

