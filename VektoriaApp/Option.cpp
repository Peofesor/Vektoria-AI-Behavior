#include "Option.h"

void Option::Starten()
{
	if (m_status == READY || m_status == PAUSED)
	{
		m_status = PROGRESSING;
		m_startTime = 0.0f; // Simuliert den Startzeitpunkt
	}
}

void Option::Stoppen()
{
	if (m_status == PROGRESSING || m_status == PAUSED)
	{
		m_dauer = m_originaldauer;
		m_status = READY;
	}
}

void Option::Pausieren()
{
	if (m_status == PROGRESSING)
	{
		m_status = PAUSED;
	}
}