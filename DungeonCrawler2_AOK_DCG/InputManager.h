#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <mutex>

#include "ConsoleControl.h"

class InputManager
{
	std::string text;
	int keyCode;

public:
	std::vector<int>* inputsRead = new std::vector<int>();
	std::mutex* inputsReadMutex = new std::mutex;

	void StartListener();
	int LastInput();
	bool GetKey(int keyCode);

	~InputManager();
};
