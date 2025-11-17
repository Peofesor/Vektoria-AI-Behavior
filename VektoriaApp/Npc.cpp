#include "Npc.h"
#include "SteeringDynamic.h"
#include "SteeringKinematic.h"

Npc::Npc()
{
	SteeringBehaviorIDLE* idle = new SteeringBehaviorIDLE();
	m_steeringBehavior = idle;
}

Npc::~Npc()
{
	delete m_steeringBehavior;
}

void Npc::Init(CHVector pos) 
{
	// Position setzen
	Translate(pos);

	m_steeringBehavior->GetKinematics()->SetPosition(pos);

	// Init Geo
	m_zgSphere.Init(1.5f, &m_zmSphere);
	m_zgSphereNose.Init(0.5f, &m_zmSphereNose);

	// Nase verschieben
	m_zpSphereNose.TranslateXDelta(1.5f);

	// Placements zuweisen
	AddPlacement(&m_zpSphereNose);

	// Geos zuweisen
	AddGeo(&m_zgSphere);
	m_zpSphereNose.AddGeo(&m_zgSphereNose);

	m_zmSphereNose.Translate(CColor(1.0f, 1.0f, 0.0f));
}

void Npc::Tick(float fTimeDelta)
{
	if (!m_steeringBehavior)
		return;

	// Unterscheide zwischen Kinematic und Dynamic
	SteeringDynamic* dynamicBehavior = dynamic_cast<SteeringDynamic*>(m_steeringBehavior);
	SteeringKinematic* kinematicBehavior = dynamic_cast<SteeringKinematic*>(m_steeringBehavior);

	// Aktualisiere Geschwindigkeit
	// DYNAMIC
	if (dynamicBehavior)
	{
		// Hole Kraft
		SteeringForce force = dynamicBehavior->getForce();

		// Beschleunigung berechnen
		CHVector acceleration = CHVector(
			force.m_movementForce.x,
			force.m_movementForce.y, 
			0);

		CHVector currentVelocity = GetKinematics()->m_movementVelocity;
		CHVector newVelocity = currentVelocity + acceleration * fTimeDelta;

		// Limitieren der Geschwindigkeit
		float speed = newVelocity.Length();
		if (speed > GetKinematics()->m_maxMovementVelocity)
		{
			newVelocity.Norm();
			newVelocity *= GetKinematics()->m_maxMovementVelocity;
		}

		GetKinematics()->m_movementVelocity = newVelocity;
	}

	// KINEMATIC
	else if (kinematicBehavior)
	{
		kinematicBehavior->UpdateVelocity();
	}

	// Position updaten
	GetKinematics()->UpdateKinematik(fTimeDelta);

	// Neue Position setzen
	Translate(GetKinematics()->GetPosition());

	//// Ausrichtung
	//RotateZDelta(GetKinematics()->m_orientation);

	//// Velocity setzten
	//if (m_steeringBehavior)
	//{
	//	m_steeringBehavior->Update();
	//}

	//// Kinematik updaten
	//m_steeringBehavior->GetKinematics()->UpdateKinematik(fTimeDelta);

	//// Neue Position setzen
	//Translate(m_steeringBehavior->GetKinematics()->GetPosition());
}

void Npc::SetColor(CColor color)
{
	// Materialien zuweisen
	m_zmSphere.Translate(color);
}

void Npc::SetSteeringBehavior(SteeringBehavior* sb)
{
	// Alte pos kopieren
	auto pos = GetKinematics()->GetPosition();
	
	delete m_steeringBehavior;
	m_steeringBehavior = sb;

	//// Pos wieder setzten
	GetKinematics()->SetPosition(pos);
	// Kinematics zuweisen
	m_steeringBehavior->setKinematics(GetKinematics());
}

Kinematics* Npc::GetKinematics()
{
	return m_steeringBehavior->GetKinematics();
}
