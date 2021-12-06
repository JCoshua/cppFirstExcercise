#include "FightScene.h"
#include "Scene.h"
#include "Entity.h"
#include "SimulationManager.h"

void FightScene::start()
{
	Entity* wompus = new Entity('W', 120, 14, 17, 10);
	Entity* thwompus = new Entity('T', 130, 17, 10, 7);
	Entity* unclePhil = new Entity('U', 150, 15, 20, 5);
	Entity* negaWompus = new Entity('M', 100, 17, 14, 12);
	addActor(wompus);
	addActor(thwompus);
	addActor(unclePhil);
	addActor(negaWompus);

	SimulationManager* simManager = new SimulationManager();
	addActor(simManager);
}