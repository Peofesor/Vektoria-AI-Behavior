#pragma once
#include "SteeringKinematic.h"
#include "Random.h"

class SteeringBehaviorKinematicWANDER : public SteeringKinematic
{
public:
    SteeringBehaviorKinematicWANDER();

    void UpdateVelocity() override;

    void setWanderStrength(float strength) { m_wanderStrength = strength; }
    void setChangeInterval(float interval) { m_changeInterval = interval; }

private:
    float m_wanderStrength;
    float m_changeInterval;
    float m_timeSinceLastChange;
    CHVector m_currentDirection;
};