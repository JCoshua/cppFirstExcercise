#include "Scene.h"

Scene::Scene()
{
	m_actors = {};
	m_actorCount = 0;
	m_started = false;
}

Scene::~Scene()
{
	for (int i = 0; i < m_actorCount; i++)
		delete m_actors[i];
	delete[] m_actors;
}

void Scene::addActor(Actor* actor)
{
	Actor** tempArray = new Actor * [m_actorCount + 1];

	for (int i = 0; i < m_actorCount; i++)
		tempArray[i] = m_actors[i];

	tempArray[m_actorCount] = actor;
	m_actorCount++;

	m_actors = tempArray;
}

bool Scene::removeActor(Actor* actor)
{
	Actor** tempArray = new Actor * [m_actorCount - 1];
	bool actorRemoved = false;

	int j = 0;
	for (int i = 0; i < m_actorCount; i++)
	{
		if (m_actors[i] != actor)
		{
			tempArray[i] = m_actors[i];
			j++;
		}
		else
			actorRemoved = false;
	}

	if (actorRemoved)
	{
		m_actorCount--;
		m_actors = tempArray;
	}

	return actorRemoved;
}

void Scene::start()
{
	m_started = true;
}

void Scene::update()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		if (!m_actors[i]->getStarted())
			m_actors[i]->start();

		m_actors[i]->update();
	}
}

void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->draw();
	}
}

void Scene::end()
{
	
}
