#include "UI.h"
Hero* UI::hero;

void UI::setHero(Hero* h)
{
	hero = h;
}

void UI::printUI()
{
	ConsoleControl::SetPosition(UI_X, UI_Y);
	std::cout << "Health: " << hero->getHealth();
	ConsoleControl::SetPosition(UI_X, UI_Y + 1);
	std::cout << "Money: " << hero->getMoney();
	ConsoleControl::SetPosition(UI_X, UI_Y + 2);
	std::cout << "Potions: " << hero->getPotions();
}
