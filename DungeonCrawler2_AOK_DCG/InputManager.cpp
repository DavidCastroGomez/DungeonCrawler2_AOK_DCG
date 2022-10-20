
#include "InputManager.h"

void InputManager::StartListener()
{
	bool exit = false;

	while (!exit)
	{

		keyCode = ConsoleControl::WaitToReadNextKey();

		switch (keyCode)
		{
		case KB_SPACE: 
		case KB_UP:
		case KB_DOWN:
		case KB_LEFT:
		case KB_RIGHT:
		{
			inputsReadMutex->lock();

			inputsRead->push_back(keyCode);

			inputsReadMutex->unlock();
			break;
		}
		default:
			break;
		}
	}
}

int InputManager::LastInput()
{
	if (!inputsRead->empty())
	{
		inputsReadMutex->lock();

		int last = 0;
		last = *(inputsRead->end() - 1);
		inputsRead->clear();

		inputsReadMutex->unlock();

		return last;
	}

	return 0;
}

bool InputManager::GetKey(int keyCode)
{
	bool isDetected = false;

	inputsReadMutex->lock();

	if (!inputsRead->empty()) {
		for (int i = 0;
			i < inputsRead->size();
			i++)
		{
			if ((*inputsRead)[i] == keyCode)
			{
				isDetected = true;
				inputsRead->erase(inputsRead->begin() + i);
				i--;
			}
		}
	}
	inputsReadMutex->unlock();

	return isDetected;
}

InputManager::~InputManager()
{
	delete inputsRead;
	delete inputsReadMutex;
}
