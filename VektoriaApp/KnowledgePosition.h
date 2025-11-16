#pragma once
#include "Vektoria\Root.h"
#include "Knowledge.h"
using namespace Vektoria;

class KnowledgePosition : public Knowledge
{
public:
	//KnowledgePosition();
	//~KnowledgePosition();

	void SetPosition(CHVector pos) { m_playerPosition = pos; }
	CHVector GetPosition() { return m_playerPosition; }

private:
	CHVector m_playerPosition;
};