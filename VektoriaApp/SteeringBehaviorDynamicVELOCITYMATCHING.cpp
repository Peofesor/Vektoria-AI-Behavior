#include "SteeringBehaviorDynamicVELOCITYMATCHING.h"

void SteeringBehaviorDynamicVELOCITYMATCHING::setBuddies(KnowledgeKinematicGroup* buddies)
{
    m_buddies = buddies;
}

void SteeringBehaviorDynamicVELOCITYMATCHING::setActicationDistance(float ad)
{
    m_activationDistance = ad;
}

SteeringForce SteeringBehaviorDynamicVELOCITYMATCHING::getForce()
{
    SteeringForce aSteeringForce;

    // Prüfe ob buddies exitieren
    if (!m_buddies || !m_kinematics)
        return aSteeringForce;

    if (m_buddies->size() == 0)
        return aSteeringForce;

    CHVector averageVelocity = CHVector();

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
                averageVelocity += target->m_movementVelocity;
            }
        }
    }

	// Durchschnittsgeschwindigkeit wird zur Steuerkraft
    aSteeringForce.m_movementForce = averageVelocity;

    return aSteeringForce;
}

