#include "SaveGame.h"

void SaveGame::Save()
{
	
}

Json::Value HeroToJsonValue(Hero* hero)
{
    Json::Value jsonValue;

    jsonValue["x"] = hero->getX();
    jsonValue["y"] = hero->getY();

    jsonValue["health"] = hero->getHealth();
    jsonValue["money"] = hero->getMoney();
    jsonValue["potions"] = hero->getPotions();

    /*Json::Value weaponsArray = Json::Value(Json::arrayValue);

    for (Weapon* weapon : *this->weapons)
    {
        weaponsArray.append(weapon->ToJsonValue());
    }
    jsonValue["weapons"] = weaponsArray;*/

    return jsonValue;
}