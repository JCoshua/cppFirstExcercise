#include "SimulationManager.h"
#include "Entity.h"
#include "Engine.h"
#include <iostream>

SimulationManager::SimulationManager()
{
	m_entities = (Entity**)(Engine::getCurrentScene()->getActors());
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}

SimulationManager::~SimulationManager()
{
	delete[] m_entities;
	delete m_currentFighter1;
	delete m_currentFighter2;
	delete this;
}

void SimulationManager::start()
{
	m_currentFighter1 = m_entities[0];
	m_currentFighter2 = m_entities[1];
	m_currentFighterIndex = 2;
}

void SimulationManager::update()
{
	if (m_currentFighter1->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter1 = m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	if (m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter2 = m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	if ((m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0) && m_currentFighterIndex >= m_entityCount)
	{
		Engine::setApplicationShouldClose(true);
		return;
	}

	m_currentFighter1->attack(m_currentFighter2);
	m_currentFighter2->attack(m_currentFighter1);

	system("pause");
}

void SimulationManager::draw()
{
	m_currentFighter1->printStats();
	m_currentFighter2->printStats();
}
