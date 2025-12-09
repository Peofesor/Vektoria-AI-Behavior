#pragma once
#include "NodeDT.h"

class DecisionNodeDT : public NodeDT
{
public:
    NodeDT* getNextNode();

    DecisionNodeDT() {
        isALeaf = false;
    }
};

