#include "UI.h"
Hero* UI::hero;

void UI::setHero(Hero* h)
{
	hero = h;
}

void UI::printUI()
{
	DrawClass::Draw(UI_X, UI_Y, "Health: " + std::to_string(hero->getHealth()));
	DrawClass::Draw(UI_X, UI_Y + 1, "Money: " + std::to_string(hero->getMoney()));
	DrawClass::Draw(UI_X, UI_Y + 2, "Potions: " + std::to_string(hero->getPotions()));
}
