#include "managers/GameManager.h"

int main()
{
	GameManager* gameManager = GameManager::GetInstance();
	bool success = gameManager->Run("Bomberman", Vec2i(1260,800));

	return success ? EXIT_SUCCESS : EXIT_FAILURE;
}