#include "SteeringBevahiorDynamicSEPARATION.h"

void SteeringBevahiorDynamicSEPARATION::setBuddies(KnowledgeKinematicGroup* buddies)
{
	m_buddies = buddies;
}

void SteeringBevahiorDynamicSEPARATION::setActicationDistance(float ad)
{
	m_activationDistance = ad;
}

SteeringForce SteeringBevahiorDynamicSEPARATION::getForce()
{
	SteeringForce aSteeringForce;

	// Prüfe ob buddies exitieren
	if (!m_buddies || !m_kinematics)
		return aSteeringForce;

	if (m_buddies->size() == 0)
		return aSteeringForce;

	// Durchlaufe alle buddies
	for (size_t i = 0; i < m_buddies->size(); i++)
	{
		Kinematics* target = m_buddies->getKinematic(i);

		// Eigene Kinematic soll nicht beachtet werden
		if (target == GetKinematics())
			continue;

		if (target)
		{
			// Richtungsvektoren der Boids zu eigenen Positon
			CHVector directionTargetToNpc = GetKinematics()->GetPosition() - target->GetPosition();
			float distance = directionTargetToNpc.Length();

			// nur Boids beacten, die innerhalb eines bestimmten Abstands sind
			if (distance < m_activationDistance && distance > 0.01f)
			{
				// Kraft ist stärker, je näher der andere Boid ist
				float force = GetKinematics()->m_maxMovementForce * (m_activationDistance - distance) / m_activationDistance;

				// Normalisiere die Richtung und skaliere mit der Kraft
				directionTargetToNpc.Norm();
				CHVector separationForce = directionTargetToNpc * force;

				aSteeringForce.m_movementForce += separationForce;
			}
		}
	}
	
	return aSteeringForce;
}
