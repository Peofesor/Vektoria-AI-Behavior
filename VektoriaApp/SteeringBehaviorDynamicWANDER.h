#pragma once
#include "SteeringDynamic.h"
#include "SteeringForce.h"

class SteeringBehaviorDynamicWANDER : public SteeringDynamic
{
public:
    SteeringBehaviorDynamicWANDER();
    virtual ~SteeringBehaviorDynamicWANDER() {}

    virtual SteeringForce getForce() override;

    virtual void Update() override;

    // Setter für das Feintuning
    void setWanderRadius(float radius) { m_wanderRadius = radius; }
    void setWanderDistance(float distance) { m_wanderDistance = distance; }
    void setWanderJitter(float jitter) { m_wanderJitter = jitter; }

private:
    float m_wanderRadius;   // Radius des Wander-Kreises
    float m_wanderDistance; // Abstand des Kreises zum Agenten
    float m_wanderJitter;   // Wie stark sich die Richtung pro Frame ändern darf
    float m_wanderAngle;    // Aktueller Winkel auf dem Kreis
};


