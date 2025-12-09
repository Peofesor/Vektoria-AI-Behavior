#include "BooleanNodeDT.h"

BooleanNodeDT::BooleanNodeDT() : DecisionNodeDT()
    , m_consideration(nullptr)
{
    m_trueNode = nullptr;
    m_falseNode = nullptr;
}

NodeDT* BooleanNodeDT::getNextNode()
{
    // Sicherheitscheck
    if (!m_consideration) return nullptr;

    if (m_consideration->compute())
    {
        return m_trueNode;
    }
    else
    {
        return m_falseNode;
    }
}