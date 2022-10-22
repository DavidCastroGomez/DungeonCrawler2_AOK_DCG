#pragma once
#include <iostream>
#include <fstream>
#include <json/json.h> //https://github.com/open-source-parsers/jsoncpp
#include <vector>
#include "Hero.h"

class SaveGame
{
private:
	Hero* hero;

	std::thread* saveGameThread;
	std::mutex* saveGamemutex;

public:
	SaveGame(Hero* h);

	void SaveLoop();

	void SaveHero(Hero* hero);

	void EraseHero();

	Json::Value HeroToJsonValue(Hero* hero);
};

