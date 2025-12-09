#pragma once
#include "OptionTextOutput.h"
#include "ConsiderationBoolean.h"
#include "Vektoria\Root.h" // Für CHVector
#include <string>
#include <iostream>

using namespace Vektoria;

// =========================================================
// 1. ZOMBIE OPTION
// =========================================================
class ZombieOption : public OptionTextOutput
{
public:
    std::string m_actionName;

    // Konstruktor nimmt Namen + Dauer entgegen
    ZombieOption(std::string name, float dauer)
        : OptionTextOutput(name, dauer, 0.0f), m_actionName(name)
    {
    }

    void Starten() override
    {
        // Erst Text ausgeben
        std::cout << ">>> ZOMBIE STATUS: " << m_actionName << " <<<" << std::endl;

        // Dann die Basis-Logik (Timer starten, "Option gestartet" printen) aufrufen
        OptionTextOutput::Starten();
    }
};

// =========================================================
// 2. CONSIDERATION: IST ES TAG?
// =========================================================
class ConsiderationIsDay : public ConsiderationBoolean
{
public:
    bool* m_pIsDayRef;

    // Konstruktor erwartet Pointer auf die bool Variable im Game
    ConsiderationIsDay(bool* dayRef) : ConsiderationBoolean(nullptr), m_pIsDayRef(dayRef) {}

    bool compute() override
    {
        if (m_pIsDayRef) return *m_pIsDayRef;
        return false;
    }
};

// =========================================================
// 3. CONSIDERATION: IST SPIELER NAH?
// =========================================================
class ConsiderationPlayerNear : public ConsiderationBoolean
{
public:
    CPlacement* m_pZombiePlacement;
    CPlacement* m_pTargetPlacement;
    float m_distSqLimit;

    ConsiderationPlayerNear(CPlacement* zPlacement, CPlacement* tPlacement, float dist)
        : ConsiderationBoolean(nullptr), m_pZombiePlacement(zPlacement), m_pTargetPlacement(tPlacement)
    {
        m_distSqLimit = dist * dist;
    }

    bool compute() override
    {
        if (!m_pZombiePlacement || !m_pTargetPlacement) return false;

        // aktuellen Positionen frisch aus den Objekten
        CHVector zPos = m_pZombiePlacement->GetPos();
        CHVector tPos = m_pTargetPlacement->GetPos();

        // Vektor vom Zombie zum Ziel berechnen
        CHVector diff = zPos - tPos;

        // Quadratische Länge prüfen
        // Wenn Abstand² kleiner als Limit² ist, dann ist er nah dran.
        if (diff.LengthSquare() < m_distSqLimit)
        {
            return true;
        }

        return false;
    }
};