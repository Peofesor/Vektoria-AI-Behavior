#pragma once
#include "Vektoria\Root.h"

class Option
{
public:
	enum Status { READY, PROGRESSING, PAUSED, FINISHED, COOLDOWN };

	Option(float dauer_sec = 0, float cooldown_sec = 0)
		: m_dauer(dauer_sec), m_cooldown(cooldown_sec), m_status(READY) {
	}

	virtual void Starten();
	virtual void Stoppen();
	virtual void Pausieren();

	float m_dauer;
	float m_originaldauer;
	float m_cooldown;
	Status m_status;

	float m_startTime;
};