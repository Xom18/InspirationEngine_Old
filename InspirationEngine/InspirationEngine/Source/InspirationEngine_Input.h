#pragma once
#include <SDL/SDL.h>

class Input
{
public:
	void Start();
	const Uint8* GetKeyInput();
private:
	const Uint8* keyInput;
};