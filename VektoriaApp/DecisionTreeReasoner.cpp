#include "DecisionTreeReasoner.h"
#include "OptionNodeDT.h" 


std::vector<Option*>* DecisionTreeReasoner::update(float time, float fTimeDelta)
{
    std::vector<Option*>* results = new std::vector<Option*>();

    if (m_root)
    {
        // Den Baum traversieren bis zu einem Blatt
        NodeDT* finalNode = m_root->makeDecision();

        // Prüfen, ob wir bei einem gültigen Blatt mit einer Option angekommen sind
        if (finalNode && finalNode->isALeaf && finalNode->m_option)
        {
            results->push_back(finalNode->m_option);
        }
    }

    return results;
}