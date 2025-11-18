#pragma once
#include "SteeringDynamic.h"
#include "KnowledgeKinematicGroup.h"
#include "SteeringBevahiorDynamicSEPARATION.h"
#include "SteeringBehaviorDynamicVELOCITYMATCHING.h"
#include "SteeringBehaviorDynamicCOHESION.h"

class SteeringBehaviorDynamicFLOCKING :
    public SteeringDynamic
{
private:
	KnowledgeKinematicGroup* m_buddies;

    SteeringBehaviorDynamicSEPARATION* m_separation;
    SteeringBehaviorDynamicVELOCITYMATCHING* m_velocityMatching;
    SteeringBehaviorDynamicCOHESION* m_cohesion;

    // Gewichtung
    float m_separationWeight = 1.5f;
    float m_velocityMatchingWeight = 1.0f;
	float m_cohesionWeight = 1.0f;
public:
    SteeringBehaviorDynamicFLOCKING();
    ~SteeringBehaviorDynamicFLOCKING() override;
    
    SteeringForce getForce() override;

    void setBuddies(KnowledgeKinematicGroup* buddies);
    void setWeight(float sep, float coh, float vel);
	void Update() override {};
};

