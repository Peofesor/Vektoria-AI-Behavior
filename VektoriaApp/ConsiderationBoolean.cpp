#include "ConsiderationBoolean.h"

ConsiderationBoolean::ConsiderationBoolean(Knowledge* knowledge)
{
    // Leer lassen oder Knowledge speichern, falls nötig
    // m_knowledge = knowledge; 
}

bool ConsiderationBoolean::compute()
{
    // Standard-Verhalten der Basisklasse: Gibt einfach false oder den gespeicherten Wert zurück.
    return m_value;
}