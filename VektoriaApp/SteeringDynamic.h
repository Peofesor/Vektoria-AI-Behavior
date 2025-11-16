#pragma once
#include "SteeringBehavior.h"
#include "SteeringForce.h"

class SteeringDynamic : public SteeringBehavior
{
public:
	~SteeringDynamic();
	SteeringDynamic();

	SteeringForce getForce();
	void update();
};

