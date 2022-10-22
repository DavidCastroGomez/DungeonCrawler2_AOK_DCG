#include "SaveGame.h"

void SaveGame::SaveHero(Hero* hero)
{

    Json::Value newJsonValue; //Declaramos un nuevo objetoJsonValue
    newJsonValue["Character"] = HeroToJsonValue(hero); //Llamamos una funcion que transforma el objeto en un JSON Value

    std::ofstream* jsonWriteFile = new std::ofstream("Character.json", std::ifstream::binary); //Abrimos un archivo en modo escritura

    if (!jsonWriteFile->fail()) //Comprovamos si se a abierto correctamente
    {
        *jsonWriteFile << newJsonValue; //Escrivimos en el archivo
        jsonWriteFile->close(); //Cerramos el archivo para que no se quede abierto ¡¡Importante!!
    }
}

Json::Value SaveGame::HeroToJsonValue(Hero* hero)
{
    Json::Value jsonValue;

    jsonValue["x"] = hero->getX();
    jsonValue["y"] = hero->getY();

    jsonValue["health"] = hero->getHealth();
    jsonValue["money"] = hero->getMoney();
    jsonValue["potions"] = hero->getPotions();

    return jsonValue;
}