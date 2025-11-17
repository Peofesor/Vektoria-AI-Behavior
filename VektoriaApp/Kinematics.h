#pragma once
#include "Vektoria\Root.h"
#include "SteeringBehavior.h"
using namespace Vektoria;

class Kinematics
{
public:
	Kinematics();

	float m_orientation;
	float m_rotationVelocity;

	CHVector m_movementVelocity;

	float m_maxMovementForce;
	float m_maxRotationForce;
	float m_maxMovementVelocity;
	float m_maxRotationVelocity;

	void UpdateKinematik(float fTimeDelta);

	void SetTargetPosition(CHVector& targetPos);

	void SetPosition(CHVector pos) { m_position = pos; }
	CHVector GetPosition() { return m_position; }

private:
	CHVector m_position;
};