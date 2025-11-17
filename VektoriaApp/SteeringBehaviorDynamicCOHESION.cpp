#include "SteeringBehaviorDynamicCOHESION.h"

void SteeringBehaviorDynamicCOHESION::setBuddies(KnowledgeKinematicGroup* buddies)
{
	m_buddies = buddies;
}

void SteeringBehaviorDynamicCOHESION::setActicationDistance(float ad)
{
	m_activationDistance = ad;
}

SteeringForce SteeringBehaviorDynamicCOHESION::getForce()
{
	SteeringForce aSteeringForce;

	// Prüfe ob buddies exitieren
	if (!m_buddies || !m_kinematics)
		return aSteeringForce;

	if (m_buddies->size() == 0)
		return aSteeringForce;

	CHVector centerOfMass = CHVector();
	int neighborCount = 0;

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
			CHVector direction = target->GetPosition() - GetKinematics()->GetPosition();
			float distance = direction.Length();

			// nur Boids beacten, die innerhalb eines bestimmten Abstands sind
			if (distance < m_activationDistance)
			{
				centerOfMass += target->GetPosition();
				neighborCount++;
			}
		}
	}

	// Berechne den Mittelpunkt der Nachbarn
	if (neighborCount > 0)
	{
		centerOfMass /= (float)neighborCount;

		// SEEK zum Mittelpunkt
		CHVector desiredVelocity = centerOfMass - GetKinematics()->GetPosition();

		// Kraft skaliert mit Distanz zum Mittelpunkt
		float force = GetKinematics()->m_maxMovementForce * desiredVelocity.Length() / m_activationDistance;

		desiredVelocity.Norm();

		// Berechne die Steuerkraft
		aSteeringForce.m_movementForce = desiredVelocity * force;
	}

	return aSteeringForce;
}
