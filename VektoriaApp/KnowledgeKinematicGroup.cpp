#include "KnowledgeKinematicGroup.h"

size_t KnowledgeKinematicGroup::size() const {
	return m_boids.size();
}

Kinematics* KnowledgeKinematicGroup::getKinematic(size_t index)
{
	if (index < m_boids.size()) {
		return m_boids[index];
	}
	return nullptr;
}

void KnowledgeKinematicGroup::addBoid(Kinematics* kinematic)
{
	if (kinematic) {
		m_boids.push_back(kinematic);
	}
}

void KnowledgeKinematicGroup::removeBoid(Kinematics* kinematic)
{
	m_boids.erase(std::remove(m_boids.begin(), m_boids.end(), kinematic), m_boids.end());
}
