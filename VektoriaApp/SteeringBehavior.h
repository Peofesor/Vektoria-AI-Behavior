#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class Kinematics;

class SteeringBehavior
{
public:
	SteeringBehavior();
	~SteeringBehavior();

	Kinematics* GetKinematics() const { return m_kinematics; }
	virtual void Update() = 0;

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

private:
	bool m_lookIntoMoveDirection;
	CHVector m_standardForce;

	//KnowledgeCollisionVector* m_KnowledgeCollisionWithFloor;
	//MoveOrRotate m_moveOrRoatate;
};

