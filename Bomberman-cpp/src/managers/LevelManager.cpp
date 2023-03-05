#include <iostream>
#include "managers/LevelManager.h"

LevelManager* LevelManager::m_instance = nullptr;

LevelManager* LevelManager::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new LevelManager();
	}

	return m_instance;
}

Level* LevelManager::GetLevel()
{
	return m_level;
}

LevelManager::LevelManager()
{
	m_level = nullptr;
}

LevelManager::~LevelManager()
{
	if (m_level != nullptr)
	{
		delete m_level;
	}

	if (m_instance != nullptr)
	{
		delete m_instance;
	}
}

Level* LevelManager::LoadLevel(const std::string& _fileName)
{
	if (m_level != nullptr)
	{
		delete m_level;
	}

	m_level = new Level();
	m_level->LoadLevel(_fileName);

	return m_level;
}
