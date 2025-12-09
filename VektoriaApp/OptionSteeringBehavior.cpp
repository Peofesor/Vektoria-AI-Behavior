#include "OptionSteeringBehavior.h"

OptionSteeringBehavior::OptionSteeringBehavior(std::string name, SteeringBehavior* behavior, Npc* npc)
    : Option(name), m_behavior(behavior), m_npc(npc), m_previousBehavior(nullptr)
{
}

OptionSteeringBehavior::~OptionSteeringBehavior()
{
    // Behavior wird nicht gelöscht, da es außerhalb verwaltet wird
}

void OptionSteeringBehavior::Starten()
{
    Option::Starten();

    if (m_npc && m_behavior)
    {
        // Setze neues Steering Behavior
        m_npc->SetSteeringBehavior(m_behavior);
        printf("Steering Behavior gestartet: %s\n", m_name.c_str());
    }
}

void OptionSteeringBehavior::Stoppen()
{
    printf("Steering Behavior gestoppt: %s\n", m_name.c_str());
    Option::Stoppen();
}