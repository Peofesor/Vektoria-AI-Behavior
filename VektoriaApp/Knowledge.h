#pragma once
#include <string>

class Knowledge
{	
protected:
	std::string m_name;
public:
	Knowledge(std::string name) { m_name = name; };
	Knowledge() {};

	virtual ~Knowledge() {};
};

