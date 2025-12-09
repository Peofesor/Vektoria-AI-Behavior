#include "SteeringBehaviorDynamicWANDER.h"
#include "Kinematics.h"
#include "Random.h"
#include <cmath> // Für sin/cos

SteeringBehaviorDynamicWANDER::SteeringBehaviorDynamicWANDER()
    : m_wanderRadius(5.0f)     // Standardwert: Breite der Kurven
    , m_wanderDistance(10.0f)  // Standardwert: Vorausschau
    , m_wanderJitter(0.2f)     // Standardwert: Zufälligkeit ("Zittern")
    , m_wanderAngle(0.0f)
{
}

SteeringForce SteeringBehaviorDynamicWANDER::getForce()
{
    SteeringForce aSteeringForce;

    if (!m_kinematics)
        return aSteeringForce;

    // 1. Zufällige Änderung des aktuellen Winkels berechnen
    // Wir addieren einen kleinen Zufallswert zum bestehenden Winkel (Jitter)
    float randomBinomial = Random::gleichVerteilungFloat(-1.0f, 1.0f);
    m_wanderAngle += randomBinomial * m_wanderJitter;

    // 2. Zielpunkt auf dem Wander-Kreis berechnen
    // (Relativ zum Mittelpunkt des Kreises)
    CHVector circleTarget;
    circleTarget.x = std::cos(m_wanderAngle) * m_wanderRadius;
    circleTarget.y = std::sin(m_wanderAngle) * m_wanderRadius;
    circleTarget.z = 0.0f; // Annahme: 2D Bewegung auf X/Y Ebene

    // 3. Mittelpunkt des Kreises vor dem Charakter bestimmen
    // Wir nehmen die aktuelle Geschwindigkeit (Heading) und projizieren sie nach vorne
    CHVector characterHeading = m_kinematics->m_movementVelocity;

    // Falls wir stehen, nehmen wir eine Standardrichtung, sonst normalisieren
    if (characterHeading.Length() < 0.01f) {
        characterHeading = CHVector(1.0f, 0.0f, 0.0f); // Default nach rechts
    }
    else {
        characterHeading.Norm();
    }

    CHVector circleCenter = characterHeading * m_wanderDistance;

    // 4. Die Zielrichtung ist: Zentrum des Kreises + Punkt auf dem Kreis
    CHVector displacement = circleCenter + circleTarget;

    // 5. Kraft in diese Richtung berechnen
    displacement.Norm();

    // Maximale Kraft anwenden
    aSteeringForce.m_movementForce = displacement * m_kinematics->m_maxMovementForce;

    return aSteeringForce;
}

void SteeringBehaviorDynamicWANDER::Update()
{
    // Diese Funktion muss existieren, um den Compiler zufrieden zu stellen.
    // Da deine Berechnungen (Jitter) momentan in getForce() passieren, 
    // kann sie hier leer bleiben.
}