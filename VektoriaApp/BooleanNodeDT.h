#pragma once
#include "DecisionNodeDT.h"
#include "ConsiderationBoolean.h"

class BooleanNodeDT : public DecisionNodeDT
{
public:
    ConsiderationBoolean* m_consideration;

    BooleanNodeDT();    

    void setConsideration(ConsiderationBoolean* aConsideration) {
        m_consideration = aConsideration;
    }

    NodeDT* getNextNode() override;
};

