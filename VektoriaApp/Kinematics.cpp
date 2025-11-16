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
	//m_movementVelocity = NewMovementSpeed();
	
	m_position.x += m_movementVelocity.x * fTimeDelta;
	m_position.y += m_movementVelocity.y * fTimeDelta;

	m_position.z = -90.0f; // Bewegung nur in X-Y Ebene
}

//if (m_steeringBehavior == SEEK)
//{
//	CHVector toTarget = m_targetPosition - m_position;

//	toTarget.z = 0.0f; // Bewegung nur in X-Y Ebene
//	toTarget.Normal();

//	CHVector steeringVelocity = toTarget * m_maxMovementVelocity;

//	return steeringVelocity;
//}

//CHVector steeringVelocity = CHVector(0.0f,0.0f,0.0f);
