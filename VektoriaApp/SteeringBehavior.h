#pragma once
#include "Vektoria\Root.h"
#include "Option.h"

using namespace Vektoria;

class Kinematics;

class SteeringBehavior : public Option
{
public:
	SteeringBehavior();
	~SteeringBehavior();

	Kinematics* GetKinematics() const { return m_kinematics; }
	void setKinematics(Kinematics* kinematics) { m_kinematics = kinematics; }

	virtual void Update() {};

	//chvector angletodirectionvector();
	//void directionvectortoangle();
	//bool infov();
	//chvector limit();
	//float limitorientation();
	//
	//void setfloorknowledge();
	//void setlookintomovedirection();
	//void setstandardforce();


protected:
	Kinematics* m_kinematics;
	bool m_lookIntoMoveDirection;
	CHVector m_standardForce;

	//KnowledgeCollisionVector* m_KnowledgeCollisionWithFloor;
	//MoveOrRotate m_moveOrRoatate;
};

