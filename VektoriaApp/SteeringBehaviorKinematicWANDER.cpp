#include "SteeringBehaviorKinematicWANDER.h"
#include "Kinematics.h"
#include "Random.h" 

SteeringBehaviorKinematicWANDER::SteeringBehaviorKinematicWANDER()
    : m_wanderStrength(1.0f)
    , m_changeInterval(1.0f)
    , m_timeSinceLastChange(0.0f)
{
    // Initiale zufällige Richtung
    m_currentDirection = CHVector(
        Random::gleichVerteilungFloat(-1.0f, 1.0f),
        Random::gleichVerteilungFloat(-1.0f, 1.0f),
        0.0f
    );
    m_currentDirection.Norm();
}
    
void SteeringBehaviorKinematicWANDER::UpdateVelocity()
{
    if (!m_kinematics)
        return;

    m_timeSinceLastChange += 0.016f; // Approximate delta time

    // Ändere Richtung in Intervallen
    if (m_timeSinceLastChange >= m_changeInterval)
    {
        m_timeSinceLastChange = 0.0f;

        // Neue zufällige Richtung
        m_currentDirection = CHVector(
            Random::gleichVerteilungFloat(-1.0f, 1.0f),
            Random::gleichVerteilungFloat(-1.0f, 1.0f),
            0.0f
        );
        m_currentDirection.Norm();
    }

    CHVector steeringVelocity = m_currentDirection * m_kinematics->m_maxMovementVelocity * m_wanderStrength;
    m_kinematics->m_movementVelocity = steeringVelocity;
}