#pragma once
#include "SteeringBehavior.h"

class SteeringKinematic : public SteeringBehavior
{
public:
	//SteeringKinematic();
	virtual ~SteeringKinematic() {};

	virtual void UpdateVelocity() = 0;
};

