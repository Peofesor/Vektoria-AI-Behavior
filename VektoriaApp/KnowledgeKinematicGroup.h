#pragma once
#include "Knowledge.h"
#include <vector>
#include "Kinematics.h"

class KnowledgeKinematicGroup :
    public Knowledge
{
private:
    std::vector<Kinematics*> m_boids;

public:
    KnowledgeKinematicGroup(std::string name) : Knowledge(name) {};
    KnowledgeKinematicGroup() : Knowledge() {};

    size_t size() const;
    Kinematics* getKinematic(size_t index);
    void addBoid(Kinematics* kinematic);
    void removeBoid(Kinematics* kinematic);
};

