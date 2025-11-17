#include "Game.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash* psplash)
{
	//---------------------------------
	// Initialisiere die Knotenobjekte:
	//---------------------------------

	// Zuallererst muss die Root mit dem Splash-Screen initialisiert werden, 
	// damit die Engine freigeschaltet wird:
	m_zr.Init(psplash, false, true, true);

	// Initialisiere die Kamera mit einem horizontalen Öffnungswinkel von 60°:
	m_zc.Init(THIRDPI);

	// Initialisiere den Frame (Fensterrenderbereich)! 
	// Übergebe dabei das Handle auf das Window, und ein Funktionspointer auf die Betriebssystem-Callback-Routine:
	m_zf.Init(hwnd, procOS);

	// Setze den Viewport (Renderbereich für eine Kamera) auf die volle Größe des Frames:
	m_zv.InitFull(&m_zc);

	// Initialisiere ein weißes Parallellicht:
	m_zl.Init(CHVector(1.0f, 1.0f, -1.0f), CColor(1.0f, 1.0f, 1.0f));

	m_zs.SetSkyOn(&m_zpCamera);

	// Plane Größe
	const float planeSize = 25.0f;
	m_pPlane.AddGeo(&m_gPlane);
	m_gPlane.Init(planeSize * 2, planeSize, nullptr);
	m_pPlane.TranslateZ(-90.0f);

	// Target
	m_pTarget.AddGeo(&m_gTarget);
	m_gTarget.Init(1.5f, &m_mTarget);
	m_mTarget.Translate(CColor(0.0f, 1.0f, 0.0f));
	m_zs.AddPlacement(&m_pTarget);

	//----------------------------
	// Vernetze die Knotenobjekte:
	//----------------------------

	// Hänge den Frame an die Root:
	m_zr.AddFrame(&m_zf);

	// Hänge den Viewport an den Frame:
	m_zf.AddViewport(&m_zv);

	// Keyboard & Mouse
	m_zf.AddDeviceKeyboard(&m_dk);
	m_zf.AddDeviceCursor(&m_dc);

	m_zpCamera.SetTranslationSensitivity(20.0f);
	m_zpCamera.SetRotationSensitivity(0.8);

	// Hänge die Szene an den Frame:
	m_zr.AddScene(&m_zs);

	// Hänge das Kameraplacement an die Szene:
	m_zs.AddPlacement(&m_zpCamera);

	// Hänge das Parallellicht an die Szene:
	m_zs.AddLightParallel(&m_zl);

	// Hänge die Kamera an das Kameraplacement:
	m_zpCamera.AddCamera(&m_zc);

	// Plane
	m_zs.AddPlacement(&m_pPlane);

	float gridSizeX = 35.0f;
	float gridSizeY = 15.0f;

	// NPCs
	for (auto& npc : m_NpcRed)
	{
		CHVector pos = CHVector(Random::gleichVerteilungFloat(-gridSizeX, gridSizeX), Random::gleichVerteilungFloat(-gridSizeY, gridSizeY), -90.0f);
		npc.Init(pos);

		m_zs.AddPlacement(&npc);
		npc.SetColor(CColor(1.0f, 0.0f, 0.0f));

		m_buddiesRed.addBoid(npc.GetKinematics());
	}

	for (auto& npc : m_NpcBlue)
	{
		CHVector pos = CHVector(Random::gleichVerteilungFloat(-gridSizeX, gridSizeX), Random::gleichVerteilungFloat(-gridSizeY, gridSizeY), -90.0f);
		npc.Init(pos);

		m_zs.AddPlacement(&npc);

		npc.SetColor(CColor(0.0f, 0.0f, 1.0f));

		m_buddiesBlue.addBoid(npc.GetKinematics());
	}

	//--------------------------------
	// 1.2 Option Text Output Test
	//--------------------------------
	option.Starten();


	////--------------------------------
	//// 1.3 Zufallszahlen
	////--------------------------------
	//
	//// Gleichverteilung
	//float values[100];
	//for (int i = 0; i < 100; i++)
	//{
	//	values[i] = Random::gleichVerteilung(-gridSize, gridSize);
	//}
	//
	//std::ofstream gleichFile("C:\\Users\\y_sch\\Desktop\\gleichValues.csv");
	//for (float val : values)
	//{
	//	gleichFile << val << ",";
	//}
	//gleichFile.close();
	//
	//// Normalverteilung
	//for (int i = 0; i < 100; i++)
	//{
	//	values[i] = Random::normalVerteilung(0.0f, 5.0f); // meisten Werte liegen in [-15,15]
	//}
	//
	//std::ofstream normalFile("C:\\Users\\y_sch\\Desktop\\normalValues.csv");
	//for (float val : values)
	//{
	//	normalFile << val << ",";
	//}
	//normalFile.close();
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	option.Update(fTimeDelta);

	// Knowledge Updaten
	CHVector targetPos = m_pTarget.GetPos();
	m_knowledgePosition.SetPosition(targetPos);

	// NPCs updaten
	if (m_kinematicsActive)
	{
		for (auto& npc : m_NpcRed)
		{
			//npc.SetTarget(targetPos);
			npc.Tick(fTimeDelta);
		}
		for (auto& npc : m_NpcBlue)
		{
			//npc.SetTarget(targetPos);
			npc.Tick(fTimeDelta);
		}
	}

	// Traversiere den Szenengraf und rendere:
	m_zr.Tick(fTimeDelta);

	// MOUSE AND KEYBOARD
	m_dk.PlaceWASD(m_zpCamera, fTimeDelta);

	CHVector vIntersection;
	float fDistanceSquare;

	if (m_dc.ButtonPressedLeft())
	{
		CGeo* pGeo = m_dc.PickGeo(vIntersection, fDistanceSquare);
		m_pTarget.Translate(vIntersection);
	}

	if (m_dk.KeyDown(DIK_E)) // FLEE
	{
		m_kinematicsActive = true;

		for (auto& npc : m_NpcRed)
		{
			auto* flee = new SteeringBehaviorKinematicFLEE();
			flee->setTarget(&m_knowledgePosition);
			npc.SetSteeringBehavior(flee);
		}
		for (auto& npc : m_NpcBlue)
		{
			auto* flee = new SteeringBehaviorKinematicFLEE();
			flee->setTarget(&m_knowledgePosition);
			npc.SetSteeringBehavior(flee);
		}
	}
	if (m_dk.KeyDown(DIK_Q)) // SEEK
	{
		m_kinematicsActive = true;

		for (auto& npc : m_NpcRed)
		{
			auto* seek = new SteeringBehaviorKinematicSEEK();
			seek->setTarget(&m_knowledgePosition);
			npc.SetSteeringBehavior(seek);
		}
		for (auto& npc : m_NpcBlue)
		{
			auto* seek = new SteeringBehaviorKinematicSEEK();
			seek->setTarget(&m_knowledgePosition);
			npc.SetSteeringBehavior(seek);
		}
	}
	if (m_dk.KeyDown(DIK_SPACE)) // IDLE
	{
		for (auto& npc : m_NpcRed)
		{
			auto* seek = new SteeringBehaviorIDLE();
			npc.SetSteeringBehavior(seek);
		}
		for (auto& npc : m_NpcBlue)
		{
			auto* seek = new SteeringBehaviorIDLE();
			npc.SetSteeringBehavior(seek);
		}
	}

	if (m_dk.KeyDown(DIK_T)) // VELOCITY MATCHING
	{
		for (auto& npc : m_NpcRed)
		{
			auto* velocityMatching = new SteeringBehaviorDynamicVELOCITYMATCHING();
			velocityMatching->setBuddies(&m_buddiesRed);
			//velocityMatching->setActicationDistance(6.0f);

			npc.SetSteeringBehavior(velocityMatching);

			// Zufällige Richtung
			CHVector dir = CHVector(
				Random::gleichVerteilungFloat(-1.0f, 1.0f),
				Random::gleichVerteilungFloat(-1.0f, 1.0f),
				0.0f
			);
			dir.Norm();

			// Zufällige Geschwindigkeit
			float speed = Random::gleichVerteilungFloat(5.0f, 15.0f);

			// Kinematics direkt setzen
			npc.GetKinematics()->m_movementVelocity = dir * speed;
		}
		for (auto& npc : m_NpcBlue)
		{
			auto* velocityMatching = new SteeringBehaviorDynamicVELOCITYMATCHING();
			velocityMatching->setBuddies(&m_buddiesBlue);
			//velocityMatching->setActicationDistance(6.0f);

			npc.SetSteeringBehavior(velocityMatching);

			// Zufällige Richtung
			CHVector dir = CHVector(
				Random::gleichVerteilungFloat(-1.0f, 1.0f),
				Random::gleichVerteilungFloat(-1.0f, 1.0f),
				0.0f
			);
			dir.Norm();

			// Zufällige Geschwindigkeit
			float speed = Random::gleichVerteilungFloat(1.0f, 10.0f);

			// Kinematics direkt setzen
			npc.GetKinematics()->m_movementVelocity = dir * speed;
		}
	}

	if (m_dk.KeyDown(DIK_Z)) // SEPARATION RED
	{
		for (auto& npc : m_NpcRed)
		{
			auto* separation = new SteeringBevahiorDynamicSEPARATION();
			separation->setBuddies(&m_buddiesRed);
			separation->setActicationDistance(5.0f);
			npc.SetSteeringBehavior(separation);
		}
	}
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	m_zf.ReSize(iNewWidth, iNewHeight);
}

float CGame::GetTimeDeltaMin()
{
	return m_zr.GetTimeDeltaMin();
}

float CGame::GetVersion()
{
	return m_zr.GetVersion();
}


