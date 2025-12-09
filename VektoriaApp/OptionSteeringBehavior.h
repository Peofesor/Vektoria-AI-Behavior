#pragma once
#include "Option.h"
#include "SteeringBehavior.h"
#include "Npc.h"

class OptionSteeringBehavior : public Option
{
public:
    OptionSteeringBehavior(std::string name, SteeringBehavior* behavior, Npc* npc);
    ~OptionSteeringBehavior();

    void Starten() override;
    void Stoppen() override;

private:
    SteeringBehavior* m_behavior;
    Npc* m_npc;
    SteeringBehavior* m_previousBehavior;
};