#pragma once
#include "SteeringDynamic.h"
#include "KnowledgeKinematicGroup.h"

class SteeringBevahiorDynamicSEPARATION :
    public SteeringDynamic
{
private:
    KnowledgeKinematicGroup* m_buddies;
	float m_activationDistance = 15.0f;

public:
    SteeringBevahiorDynamicSEPARATION() = default;
    ~SteeringBevahiorDynamicSEPARATION() override = default;

    SteeringForce getForce() override;

    void setBuddies(KnowledgeKinematicGroup* buddies);
	void setActicationDistance(float ad);
	void Update() override {};
};

