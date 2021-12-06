#include "StartScene.h"
#include "Engine.h"
#include <iostream>

void StartScene::draw()
{
	std::cout << "Welcome to Fight Simulator++" << std::endl;
	std::cout << "1. Start" << std::endl;
	std::cout << "2. Quit" << std::endl;
}

void StartScene::update()
{
	int input;
	std::cin >> input;

	if (input == 1)
		Engine::setCurrentSceneIndex(1);
	else if (input == 2)
		Engine::setApplicationShouldClose(true);
	else
	{
		std::cout << "Invalid Input" << std::endl;
		system("pause");
	}

	system("cls");
}
