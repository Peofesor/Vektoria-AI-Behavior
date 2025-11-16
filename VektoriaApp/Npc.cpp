#include "Npc.h"

Npc::Npc()
{
	SteeringBehaviorIDLE* idle = new SteeringBehaviorIDLE();
	m_steeringBehavior = idle;
}

void Npc::Init(CHVector pos) {
	// Position setzen zu s
	Translate(pos);

	m_steeringBehavior->GetKinematics()->SetCurrentPosition(pos);

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
	// Velocity setzten
	if (m_steeringBehavior)
	{
		m_steeringBehavior->Update();
	}

	// Kinematik updaten
	m_steeringBehavior->GetKinematics()->UpdateKinematik(fTimeDelta);

	// Neue Position setzen
	Translate(m_steeringBehavior->GetKinematics()->GetCurrentPosition());
}

void Npc::SetColor(CColor color)
{
	// Materialien zuweisen
	m_zmSphere.Translate(color);
}

void Npc::SetSteeringBehavior(SteeringBehavior* sb)
{
	// Alte pos kopieren
	auto pos = m_steeringBehavior->GetKinematics()->GetCurrentPosition();
	
	delete m_steeringBehavior;
	m_steeringBehavior = sb;

	// Pos wieder setzten
	m_steeringBehavior->GetKinematics()->SetCurrentPosition(pos);
}
