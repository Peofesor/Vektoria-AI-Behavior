#pragma once
#include "SteeringBehavior.h"

class SteeringBehaviorIDLE : public SteeringBehavior
{
public:
    void Update() override
    {
        // macht absichtlich nichts
    }
};

