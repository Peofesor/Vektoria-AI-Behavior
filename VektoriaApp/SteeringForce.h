#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;

class SteeringForce
{
public:
	CHVector m_movementForce;
	float m_rotationForce;

	SteeringForce(CHVector a_movementForce, float a_rotationForce)
	{
		m_movementForce = a_movementForce;
		m_rotationForce = a_rotationForce;
	}
	SteeringForce() {};

	SteeringForce operator+=(const SteeringForce& other)
	{
		this->m_movementForce += other.m_movementForce;
		this->m_rotationForce += other.m_rotationForce;
		return *this;
	}
	SteeringForce operator*(float scalar)
	{
		SteeringForce result;
		result.m_movementForce = this->m_movementForce * scalar;
		result.m_rotationForce = this->m_rotationForce * scalar;
		return result;
	}
	SteeringForce operator+(SteeringForce& other)
	{
		SteeringForce result;
		result.m_movementForce = this->m_movementForce + other.m_movementForce;
		result.m_rotationForce = this->m_rotationForce + other.m_rotationForce;
		return result;
	}
};

