#include "Kinematics.h"

Kinematics::Kinematics()
{
	m_maxMovementVelocity = 10.0f;
}

/// <summary>
/// Verändert Position des NPCs.
/// </summary>
void Kinematics::UpdateKinematik(float fTimeDelta)
{
	m_position.x += m_movementVelocity.x * fTimeDelta;
	m_position.y += m_movementVelocity.y * fTimeDelta;

	m_position.z = -90.0f; // Bewegung nur in X-Y Ebene

	m_orientation = atan2f(m_movementVelocity.y, m_movementVelocity.x);
}