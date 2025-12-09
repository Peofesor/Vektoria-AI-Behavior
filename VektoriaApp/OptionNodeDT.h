#pragma once
#include "NodeDT.h"
#include "Option.h"

class OptionNodeDT :
    public NodeDT
{
public:
    NodeDT* getNextNode() { return nullptr; }
    Option* getOption();

    OptionNodeDT() {};
    OptionNodeDT(Option* aOption) {
        m_option = aOption;
        isALeaf = true;
    }
};

