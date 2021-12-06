#pragma once
#include "Entity.h"
#include "Scene.h"

class Engine
{
//Functions
public:
	Engine();
	~Engine();
	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }
	static int getCurrentSceneIndex() { return m_currentSceneIndex; }
	static void setCurrentSceneIndex(int value) { m_currentSceneIndex = value; }

	static void addScene(Scene* scene);
	static Scene* getCurrentScene() { return m_scenes[m_currentSceneIndex]; }

private:
	void start();
	void update();
	void draw();
	void end();

//Variables
private:
	static bool m_applicationShouldClose;

	static Scene** m_scenes;
	static int m_sceneCount;
	static int m_currentSceneIndex;
};
