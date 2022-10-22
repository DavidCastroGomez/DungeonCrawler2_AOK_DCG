#pragma once
#include "Hero.h"

static class UI
{
private:
	static Hero* hero;

public:
	static void setHero(Hero* hero);

	static void printUI();
};

