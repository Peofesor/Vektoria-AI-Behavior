#pragma once
#include "Vektoria\Root.h"
#include "SteeringBehavior.h"
using namespace Vektoria;

class Kinematics
{
public:
	Kinematics();
	float m_orientation;

	CHVector m_movementVelocity;
	float m_rotationVelocity;

	float m_maxMovementForce;
	float m_maxMovementVelocity;

	float m_maxRotationForce;
	float m_maxRotationVelocity;

	void UpdateKinematik(float fTimeDelta);

	void SetTargetPosition(CHVector& targetPos);
	void SetCurrentPosition(CHVector pos) { m_position = pos; }
	CHVector GetCurrentPosition() { return m_position; }

private:
	CHVector m_position;
};