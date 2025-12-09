#include "Npc.h"
#include "SteeringDynamic.h"
#include "SteeringKinematic.h"

Npc::Npc()
{
	SteeringBehaviorIDLE* idle = new SteeringBehaviorIDLE();
	idle->setKinematics(&m_kinematics);
	m_steeringBehavior = idle;
}

Npc::~Npc()
{
	delete m_steeringBehavior;
}

void Npc::Init(CHVector pos) 
{
	// Position setzen
	m_kinematics.SetPosition(pos);
	Translate(pos);

	// Init Geo
	m_zgSphere.Init(0.5f, &m_zmSphere);
	m_zgSphereNose.Init(0.2f, &m_zmSphereNose);

	// Nase verschieben
	m_zpSphereNose.TranslateXDelta(0.5f);

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

		CHVector currentVelocity = m_kinematics.m_movementVelocity;
		CHVector newVelocity = currentVelocity + acceleration * fTimeDelta;

		// Limitieren der Geschwindigkeit
		float speed = newVelocity.Length();
		if (speed > m_kinematics.m_maxMovementVelocity)
		{
			newVelocity.Norm();
			newVelocity *= m_kinematics.m_maxMovementVelocity;
		}

		m_kinematics.m_movementVelocity = newVelocity;
	}

	// KINEMATIC
	else if (kinematicBehavior)
	{
		kinematicBehavior->UpdateVelocity();
	}

	// Position updaten
	m_kinematics.UpdateKinematik(fTimeDelta);

	// Neue Position setzen
	Translate(m_kinematics.GetPosition());

	//// Ausrichtung
	//RotateZDelta(m_kinematics.m_orientation);
}

void Npc::SetColor(CColor color)
{
	// Materialien zuweisen
	m_zmSphere.Translate(color);
}

void Npc::SetSteeringBehavior(SteeringBehavior* sb)
{
	if (!sb)
		return;

	//// Alte pos kopieren
	//auto pos = GetKinematics()->GetPosition();
	
	delete m_steeringBehavior;
	m_steeringBehavior = sb;

	//// Pos wieder setzten
	//GetKinematics()->SetPosition(pos);

	// Kinematics zuweisen
	m_steeringBehavior->setKinematics(&m_kinematics);
}
