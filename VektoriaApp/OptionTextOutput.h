#pragma once
#include "Option.h"
#include "Vektoria\Root.h"
#include <string>

class OptionTextOutput : public Option
{
public:
	OptionTextOutput(std::string name = "Default", float dauer_sec = 0.0f, float cooldown_sec = 0.0f);

	void Starten();
	void Stoppen();
	void Pausieren();
	void Update(float dt);

	std::string m_name;
};

