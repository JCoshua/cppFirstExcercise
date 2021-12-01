#include "Engine.h"

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}
void Engine::run()
{
	start();

	while (!m_applicationShouldClose)
	{
		update();
		draw();
	}

	end();
}

void Engine::start()
{
	Entity wompus = Entity('W', 120, 14, 17, 10);
	Entity thwompus = Entity('T', 130, 17, 10, 7);
	Entity unclePhil = Entity('U', 150, 15, 20, 5);
	Entity negaWompus = Entity('M', 100, 17, 14, 12);

	m_entities[0] = { wompus };
	m_entities[1] = { thwompus };
	m_entities[2] = { unclePhil };
	m_entities[3] = { negaWompus };
	m_entityCount = 4;

	m_currentFighter1 = &m_entities[0];
	m_currentFighter2 = &m_entities[1];
	m_currentFighterIndex = 2;
}

void Engine::update()
{
	if (m_currentFighter1->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter1 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	if (m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter2 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	if (m_currentFighterIndex >= m_entityCount && (m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0))
	{
		m_applicationShouldClose = true;
		return;
	}
	m_currentFighter1->attack(m_currentFighter2);
	m_currentFighter2->attack(m_currentFighter1);


}

void Engine::draw()
{

}

void Engine::end()
{

}
