#include "SteeringBehavior.h"
#include "Kinematics.h"

SteeringBehavior::SteeringBehavior()
    : m_kinematics(new Kinematics())
{
}

SteeringBehavior::~SteeringBehavior()
{
    delete m_kinematics;
}
