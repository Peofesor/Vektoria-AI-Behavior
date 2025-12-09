#pragma once
#include "Option.h"
#include "NodeDT.h"
#include "DecisionNodeDT.h"

class DecisionTreeReasoner
{
public:
	DecisionTreeReasoner(DecisionNodeDT* aRoot) { m_root = aRoot; }
	std::vector<Option*>* update(float time, float fTimeDelta);

	void setRoot(DecisionNodeDT* aRoot) { m_root = aRoot; }


private:
	DecisionNodeDT* m_root;
};

