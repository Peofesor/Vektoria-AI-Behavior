#pragma once
#include "Vektoria\Root.h"
#include "string.h"

class Option
{
public:
	enum Status { READY, PROGRESSING, PAUSED, FINISHED, COOLDOWN };

	virtual ~Option() {}

	Option(std::string name) { m_name = name; };
	Option(float dauer_sec = 0, float cooldown_sec = 0)
		: m_dauer(dauer_sec), m_cooldown(cooldown_sec), m_status(READY) {
	}

	virtual void Starten();
	virtual void Stoppen();
	virtual void Pausieren();
	virtual void Update(float dt) {}

	float m_dauer;
	float m_originaldauer;
	float m_cooldown;
	Status m_status;

	float m_startTime;
	std::string m_name;
};