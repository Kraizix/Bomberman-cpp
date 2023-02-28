#include "managers/GameManager.h"
#include <iostream>

int main()
{
	int a = 1 << 2;
	std::cout <<a;
	GameManager* gameManager = GameManager::GetInstance();
	bool success = gameManager->Run("Bomberman", Vec2i(960,832));

	return success ? EXIT_SUCCESS : EXIT_FAILURE;
}