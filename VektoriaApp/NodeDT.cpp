#include "NodeDT.h"

NodeDT::NodeDT()
    : isALeaf(false), m_falseNode(nullptr), m_trueNode(nullptr), m_option(nullptr)
{
}

void NodeDT::addFalseNode(NodeDT* node)
{
    m_falseNode = node;
}

void NodeDT::addTrueNode(NodeDT* node)
{
    m_trueNode = node;
}

NodeDT* NodeDT::getNextNode()
{
    // Standard-Implementierung: Gibt keinen Nachfolger zurück, 
    // falls nicht überschrieben (oder wenn es ein Blatt ist).
    return nullptr;
}

NodeDT* NodeDT::makeDecision()
{
    if (!isALeaf)
    {
        this->getNextNode()->makeDecision();
    }
    else
    {
        return this;
    }
}