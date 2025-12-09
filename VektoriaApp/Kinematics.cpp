#include "Kinematics.h"

Kinematics::Kinematics()
{
	m_position = CHVector(0.0f, 0.0f, 0.0f);
	m_movementVelocity = CHVector(0.0f, 0.0f, 0.0f);
	
	m_orientation = 0.0f;
	m_rotationVelocity = 0.0f;

	m_maxMovementVelocity = 5.0f;
	m_maxMovementForce = 200.0f;
	m_maxRotationVelocity = 1.0f;
	m_maxRotationForce = 1.0f;
	
}

/// <summary>
/// Verändert Position des NPCs.
/// </summary>
void Kinematics::UpdateKinematik(float fTimeDelta)
{
	m_position.x += m_movementVelocity.x * fTimeDelta;
	m_position.y += m_movementVelocity.y * fTimeDelta;

	m_position.z = -90.0f; // Bewegung nur in X-Y Ebene

	m_orientation += m_rotationVelocity * fTimeDelta;
}