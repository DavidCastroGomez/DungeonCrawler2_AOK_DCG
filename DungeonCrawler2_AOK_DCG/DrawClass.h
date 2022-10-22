#pragma once
#include <string>
#include <mutex>
#include "ConsoleControl.h"
#include <iostream>

static class DrawClass
{
private: 
	static std::mutex* controlDraw;
public:
	static void Draw(int x, int y, std::string s);
};

