#pragma once
#include <iostream>
#include <fstream>
#include <json/json.h> //https://github.com/open-source-parsers/jsoncpp
#include <vector>
#include "Hero.h"

class SaveGame
{
public:
	void SaveHero(Hero* hero);

	Json::Value HeroToJsonValue(Hero* hero);
};

