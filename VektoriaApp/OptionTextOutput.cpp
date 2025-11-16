#include "OptionTextOutput.h"
OptionTextOutput::OptionTextOutput(float dauer_sec, float cooldown_sec)
	: Option(dauer_sec, cooldown_sec)
{
}

void OptionTextOutput::Starten()
{
	Option::Starten();
	printf("Option gestartet mit Dauer: %.2f\n", m_dauer);
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
			printf("Verbleibende Dauer: %.2f\n", m_dauer);
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
	printf("Option pausiert bei Dauer: %.2f\n", m_dauer);
	Option::Pausieren();

}


