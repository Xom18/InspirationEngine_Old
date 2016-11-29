#include "InspirationEngine_Input.h"

void Input::Start()
{
	keyInput = SDL_GetKeyboardState(NULL);
}

const Uint8* Input::GetKeyInput()
{
	return keyInput;
}