#include "SteeringBehaviorKinematicFLEE.h"

void SteeringBehaviorKinematicFLEE::Update()
{
	if (!m_target) return;

	CHVector toTarget = -(m_target->GetPosition() - this->GetKinematics()->GetCurrentPosition());

	toTarget.z = 0.0f; // Bewegung nur in X-Y Ebene
	toTarget.Normal();

	CHVector steeringVelocity = toTarget * this->GetKinematics()->m_maxMovementVelocity;
	this->GetKinematics()->m_movementVelocity = steeringVelocity;
}
