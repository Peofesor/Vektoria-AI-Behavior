#pragma once
#include "SteeringKinematic.h"
#include "KnowledgePosition.h"
#include "Kinematics.h"

class SteeringBehaviorKinematicFLEE : public SteeringKinematic
{
public:
	//SteeringBehaviorKinematicFLEE();
	//~SteeringBehaviorKinematicFLEE();

	void setTarget(KnowledgePosition* target) { m_target = target; };
	void Update();

private:
	KnowledgePosition* m_target;
};

