#include "managers/GameManager.h"

int main()
{
	GameManager* gameManager = GameManager::GetInstance();
	bool success = gameManager->Run("Bomberman", Vec2i(960,832));

	return success ? EXIT_SUCCESS : EXIT_FAILURE;
}