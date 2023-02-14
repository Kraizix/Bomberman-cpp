#pragma once

#include <string>
#include "models/Level.h"

class LevelManager
{
public:
	virtual ~LevelManager();
	LevelManager(LevelManager& _other) = delete;
	void operator=(const LevelManager& _other) = delete;
	static LevelManager* GetInstance();

	Level* LoadLevel(const std::string& _fileName);

private:
	LevelManager();
	static LevelManager* m_instance;
	Level* m_level;
};
