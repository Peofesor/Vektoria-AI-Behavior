#pragma once
#include "Vektoria\Root.h"
#include "Kinematics.h"
#include "SteeringBehavior.h"
#include "SteeringBehaviorIDLE.h"
#include "SteeringForce.h"

using namespace Vektoria;

class Npc : public CPlacement
{
public:
	Npc();
	~Npc();

	void Init(CHVector pos);
	void Tick(float fTimeDelta);
	void Fini();
	void SetColor(CColor color);
	//void SetTarget(CHVector& targetPos);

	void SetSteeringBehavior(SteeringBehavior* sb);
	Kinematics* GetKinematics() { return &m_kinematics; };

private:
	CGeoSphere m_zgSphere;

	CPlacement m_zpSphereNose;
	CGeoSphere m_zgSphereNose;

	CMaterial m_zmSphere;
	CMaterial m_zmSphereNose;

	SteeringBehavior* m_steeringBehavior = nullptr;
	Kinematics m_kinematics;

};