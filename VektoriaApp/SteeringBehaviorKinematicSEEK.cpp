#include "SteeringBehaviorKinematicSEEK.h"

void SteeringBehaviorKinematicSEEK::UpdateVelocity()
{
	if (!m_target || !m_kinematics) 
		return;

	CHVector targetDirection = m_target->GetPosition() - this->GetKinematics()->GetPosition();

	targetDirection.z = 0.0f; // Bewegung nur in X-Y Ebene
	targetDirection.Normal();

	CHVector steeringVelocity = targetDirection * this->GetKinematics()->m_maxMovementVelocity;

	this->GetKinematics()->m_movementVelocity = steeringVelocity;
}