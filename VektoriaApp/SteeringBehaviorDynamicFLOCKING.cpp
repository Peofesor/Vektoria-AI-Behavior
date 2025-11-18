#include "SteeringBehaviorDynamicFLOCKING.h"

SteeringBehaviorDynamicFLOCKING::SteeringBehaviorDynamicFLOCKING()
	: m_buddies(nullptr),
	m_separationWeight(1.0f),
	m_velocityMatchingWeight(1.0f),
	m_cohesionWeight(1.0f)
{
	m_separation = new SteeringBehaviorDynamicSEPARATION();
	m_velocityMatching = new SteeringBehaviorDynamicVELOCITYMATCHING();
	m_cohesion = new SteeringBehaviorDynamicCOHESION();
}

SteeringBehaviorDynamicFLOCKING::~SteeringBehaviorDynamicFLOCKING()
{
	delete m_separation;
	delete m_velocityMatching;
	delete m_cohesion;
}

void SteeringBehaviorDynamicFLOCKING::setBuddies(KnowledgeKinematicGroup* buddies)
{
	m_buddies = buddies;

	m_separation->setBuddies(buddies);
	m_velocityMatching->setBuddies(buddies);
	m_cohesion->setBuddies(buddies);

	m_separation->setActicationDistance(5.0f);
	m_velocityMatching->setActicationDistance(6.0f);
	m_cohesion->setActicationDistance(7.0f);
}

void SteeringBehaviorDynamicFLOCKING::setWeight(float sep, float coh, float vel)
{
	m_separationWeight = sep;
	m_cohesionWeight = coh;
	m_velocityMatchingWeight = vel;
}

SteeringForce SteeringBehaviorDynamicFLOCKING::getForce()
{
	SteeringForce aSteeringForce;

	// Prüfe ob buddies exitieren
	if (!m_buddies || !m_kinematics)
		return aSteeringForce;

	// Übergebe Kinematics an die einzelnen Verhaltensweisen
	m_separation->setKinematics(m_kinematics);
	m_velocityMatching->setKinematics(m_kinematics);
	m_cohesion->setKinematics(m_kinematics);

	// Blending
	SteeringForce sepForce = m_separation->getForce();
	SteeringForce cohForce = m_cohesion->getForce();
	SteeringForce velForce = m_velocityMatching->getForce();

	aSteeringForce.m_movementForce += sepForce.m_movementForce * m_separationWeight;
	aSteeringForce.m_movementForce += cohForce.m_movementForce * m_cohesionWeight;
	aSteeringForce.m_movementForce += velForce.m_movementForce * m_velocityMatchingWeight;

	return aSteeringForce;
}