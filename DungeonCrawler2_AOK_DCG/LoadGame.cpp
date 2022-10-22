#include "LoadGame.h"
Hero* LoadGame::LoadHero()
{
	std::ifstream* jsonReadFile = new std::ifstream("Character.json", std::ifstream::binary);

	if (!jsonReadFile->fail()) //Comprovamos si se a abierto correctamente
	{
		Json::Value jsonValue; //Inicializamos la veriable que almacena el JSON en forma de objeto
		*jsonReadFile >> jsonValue; //Cargamos el texto dentro del objeto
		jsonReadFile->close(); //Cerramos el archivo para que no se quede abierto ¡¡Importante!!

		//Character* newChar = Character::Parse(jsonValue); //Llamamos a la funcion estatica que nos sirve para crear un objeto a partir de un JsonValue
		Hero* hero = Hero::Parse(jsonValue["Character"]); //Llamamos a la funcion estatica que nos sirve para crear un objeto a partir de un JsonValue
		hero->HeroLoaded();

		if (hero != nullptr) //La funcion anterior devolvera un nullptr si ha fallado por algo
		{
			return hero;
		}
	}

	Hero* player = new Hero(5, 5, 1, 5, 2);
	return player;
}
