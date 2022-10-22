#pragma once
#include <iostream>
#include <fstream>
#include <json/json.h> //https://github.com/open-source-parsers/jsoncpp
#include <vector>
#include "Hero.h"

class SaveGame
{
public:
	void Save();

	Json::Value HeroToJsonValue(Hero* hero);
};

