#pragma once
//-----------------------------------------------------------------------
// CGame
// 
// Erklärung : Eine Klasse, 
//             sinnfällig in eine Windows-Applikation eingebettet,
//             welche eine Hello-Welt-Kugel als Beispiel und zum Testen erzeugt. 
// Autor     : Prof. Dr. Tobias Breiner
// Ort       : Pfungstadt
// Zeit      : seit Aug. 2011 (mit seitdem ständigen Verbesserungs-Updates)
// Copyright : Tobias Breiner  
// Disclaimer: Nutzung auf eigene Gefahr, keine Gewähr, no warranty!
//------------------------------------------------------------------------



#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#endif
#endif

#include "Vektoria\Root.h"
#include "Npc.h"
#include "Random.h"
#include "OptionTextOutput.h"
#include "KnowledgePosition.h"
#include "KnowledgeKinematicGroup.h"

#include "SteeringBehaviorKinematicFLEE.h"
#include "SteeringBehaviorKinematicSEEK.h"

#include "SteeringBehaviorDynamicVELOCITYMATCHING.h"
#include "SteeringBehaviorDynamicCOHESION.h"
#include "SteeringBevahiorDynamicSEPARATION.h"

using namespace Vektoria;

class CGame
{
public:
	// Wird vor Begin einmal aufgerufen (Konstruktor):
	CGame(void);

	// Wird nach Ende einmal aufgerufen (Destruktor):
	~CGame(void);


	// Wird zu Begin einmal aufgerufen:
	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash* psplash);

	// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen:
	void Tick(float fTime, float fTimeDelta);

	// Wird am Ende einmal aufgerufen:
	void Fini();

	// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat:
	void WindowReSize(int iNewWidth, int iNewHeight);

	// Holt das minimale Zeitdelta zur eventuellen Frame-Rate-Beschränkung:
	float GetTimeDeltaMin();

	// Holt die Versionsnummer:
	float GetVersion();


private:
	CRoot m_zr;
	CFrame m_zf;
	CViewport m_zv;
	CLightParallel m_zl;
	CScene m_zs;

	CPlacement m_zpCamera;
	CCamera m_zc;

	CPlacement m_pPlane;
	CGeoQuad m_gPlane;

	Npc m_NpcRed[10];
	Npc m_NpcBlue[10];

	CPlacement pNpc;
	CGeoSphere gNpc;
	CMaterial mNpc;

	// Player / Target
	CPlacement m_pTarget;
	CGeoSphere m_gTarget;
	CMaterial m_mTarget;

	OptionTextOutput option;

	CDeviceKeyboard m_dk;
	CDeviceCursor m_dc;

	bool m_kinematicsActive = false;

	KnowledgePosition m_knowledgePosition;

	KnowledgeKinematicGroup m_buddiesRed;
	KnowledgeKinematicGroup m_buddiesBlue;
};