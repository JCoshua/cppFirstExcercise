#pragma once
#include "Actor.h"

class Scene
{
public:
	Scene();
	~Scene();
	bool getStarted() { return m_started; }
	void setStarted(bool value) { m_started = value; }
	Actor** getActors() { return m_actors; }
	void addActor(Actor* actor);
	bool removeActor(Actor* actor);

	virtual void start();
	virtual void update();
	virtual void draw();
	virtual void end();

private:
	Actor** m_actors;
	bool m_started;
	int m_actorCount;
};
