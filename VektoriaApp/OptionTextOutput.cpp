#include "OptionTextOutput.h"

OptionTextOutput::OptionTextOutput(std::string name, float dauer_sec, float cooldown_sec)
	: Option(name)
{
	m_dauer = dauer_sec;
	m_originaldauer = dauer_sec;
	m_cooldown = cooldown_sec;
	m_status = READY;
}

void OptionTextOutput::Starten()
{
	Option::Starten();
	printf("Option %s gestartet\n", m_name.c_str());
}

void OptionTextOutput::Update(float fTimeDelta)
{
	if (m_status == PROGRESSING)
	{
		// Reduziert die Dauer um die verstrichene Zeit
		m_dauer -= fTimeDelta;

		if (m_dauer <= 0.0f)
		{
			m_dauer = 0.0f;
			m_status = FINISHED;
			printf("Option ABGELAUFEN!\n");
		}
		else
		{
			//printf("Verbleibende Dauer: %.2f\n", m_dauer);
		}
	}
}

void OptionTextOutput::Stoppen()
{
	printf("Option gestoppt mit verbleibender Dauer: %.2f\n", m_dauer);
	Option::Stoppen();
}

void OptionTextOutput::Pausieren()
{
	printf("Option pausiert: %s\n", m_name.c_str());
	Option::Pausieren();

}


