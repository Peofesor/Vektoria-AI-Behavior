#pragma once
#include "SteeringBehavior.h"

class SteeringBehaviorIDLE : public SteeringBehavior
{
public:
    void UpdateVelocity()
    {
        // macht absichtlich nichts
    }
};

