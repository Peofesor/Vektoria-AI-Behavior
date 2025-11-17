#pragma once
#include "SteeringDynamic.h"
#include "KnowledgeKinematicGroup.h"

class SteeringBehaviorDynamicCOHESION :
    public SteeringDynamic
{
private:
    KnowledgeKinematicGroup* m_buddies;
	float m_activationDistance = 15.0f;

public:
    SteeringBehaviorDynamicCOHESION() = default;
    ~SteeringBehaviorDynamicCOHESION() override = default;
    SteeringForce getForce() override;
    void setBuddies(KnowledgeKinematicGroup* buddies);
    void setActicationDistance(float ad);
	void Update() override {};
};

