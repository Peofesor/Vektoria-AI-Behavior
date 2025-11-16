#pragma once
#include "Option.h"
#include "Vektoria\Root.h"

class OptionTextOutput : public Option
{
public:
	OptionTextOutput(float dauer_sec = 0, float cooldown_sec = 0);

	void Starten();
	void Stoppen();
	void Pausieren();
	void Update(float dt);
};

