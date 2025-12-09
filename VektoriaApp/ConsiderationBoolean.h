#pragma once
#include "Knowledge.h"

class ConsiderationBoolean
{
public:
	virtual bool compute();
	ConsiderationBoolean(Knowledge* knowledge);

	bool m_value;
};

