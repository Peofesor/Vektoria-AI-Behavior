#pragma once
#include "SteeringBehavior.h"
#include "SteeringForce.h"

class SteeringDynamic : public SteeringBehavior
{
public:
	SteeringDynamic() {};
	virtual ~SteeringDynamic() {};

	virtual SteeringForce getForce() = 0;
	virtual void Update() = 0;
};

