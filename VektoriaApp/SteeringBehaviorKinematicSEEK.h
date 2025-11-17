#pragma once
#include "SteeringKinematic.h"
#include "KnowledgePosition.h"
#include "Kinematics.h"

class SteeringBehaviorKinematicSEEK : public SteeringKinematic
{
public:
	//SteeringBehaviorKinematicFLEE();
	//~SteeringBehaviorKinematicFLEE();

	void setTarget(KnowledgePosition* target) { m_target = target; };
	void UpdateVelocity();

private:
	KnowledgePosition* m_target;
};