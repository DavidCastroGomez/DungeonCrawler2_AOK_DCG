#include "DrawClass.h"

std::mutex* DrawClass::controlDraw = new std::mutex;

void DrawClass::Draw(int x, int y, std::string s) {
	controlDraw->lock();
	ConsoleControl::SetPosition(x, y);
	std::cout << s;
	controlDraw->unlock();
}