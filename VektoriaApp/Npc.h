#pragma once
#include "Vektoria\Root.h"
#include "Kinematics.h"
#include "SteeringBehavior.h"
#include "SteeringBehaviorIDLE.h"

using namespace Vektoria;

class Npc : public CPlacement
{
public:
	Npc() ;

	void Init(CHVector pos);
	void Tick(float fTimeDelta);
	void Fini();
	void SetColor(CColor color);
	//void SetTarget(CHVector& targetPos);

	void SetSteeringBehavior(SteeringBehavior* sb);

private:
	CGeoSphere m_zgSphere;

	CPlacement m_zpSphereNose;
	CGeoSphere m_zgSphereNose;

	CMaterial m_zmSphere;
	CMaterial m_zmSphereNose;

	//Kinematics m_kinematics;
	SteeringBehavior* m_steeringBehavior = nullptr;

};