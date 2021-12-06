#include "StartScene.h"
#include "FightScene.h"
#include "Engine.h"

bool Engine::m_applicationShouldClose = false;
Scene** Engine::m_scenes;
int Engine::m_sceneCount;
int Engine::m_currentSceneIndex;

Engine::Engine()
{
	m_applicationShouldClose = false;
}

Engine::~Engine()
{
	delete[] m_scenes;
}

void Engine::run()
{
	start();

	while (!getApplicationShouldClose())
	{
		draw();
		update();
	}

	end();
}

void Engine::addScene(Scene* scene)
{
	Scene** tempArray = new Scene* [m_sceneCount + 1];

	for (int i = 0; i < m_sceneCount; i++)
		tempArray[i] = m_scenes[i];

	tempArray[m_sceneCount] = scene;
	m_sceneCount++;

	m_scenes = tempArray;
}

void Engine::start()
{
	StartScene* startScene = new StartScene();
	addScene(startScene);
	FightScene* fightScene = new FightScene();
	addScene(fightScene);
}

void Engine::update()
{
	if (!m_scenes[m_currentSceneIndex]->getStarted())
		m_scenes[m_currentSceneIndex]->start();

	m_scenes[m_currentSceneIndex]->update();
}

void Engine::draw()
{
	m_scenes[m_currentSceneIndex]->draw();

}

void Engine::end()
{

}