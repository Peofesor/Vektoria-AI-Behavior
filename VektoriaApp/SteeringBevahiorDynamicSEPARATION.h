#pragma once
#include "SteeringDynamic.h"
#include "KnowledgeKinematicGroup.h"

class SteeringBehaviorDynamicSEPARATION :
    public SteeringDynamic
{
private:
    KnowledgeKinematicGroup* m_buddies;
	float m_activationDistance = 10.0f;

public:
    SteeringBehaviorDynamicSEPARATION() = default;
    ~SteeringBehaviorDynamicSEPARATION() override = default;

    SteeringForce getForce() override;

    void setBuddies(KnowledgeKinematicGroup* buddies);
	void setActicationDistance(float ad);
	void Update() override {};
};

