#pragma once
#include "Actor.h"
#include "Entity.h"

class SimulationManager :
	public Actor
{
public:
	SimulationManager();
	~SimulationManager();

	void start() override;
	void update() override;
	void draw() override;

private:
	Entity** m_entities = new Entity*[m_entityCount];
	Entity* m_currentFighter1;
	Entity* m_currentFighter2;

	int m_currentFighterIndex;
	int m_entityCount;
};

