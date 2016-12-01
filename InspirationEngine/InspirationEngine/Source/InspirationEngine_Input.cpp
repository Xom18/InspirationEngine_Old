#include "InspirationEngine_Input.h"

void Input::Start(SDL_Event* sdl_event)
{
	keyInput = SDL_GetKeyboardState(NULL);
	
	//mouse.x = sdl_event->motion.x;
	mouse.x = sdl_event->motion.x;
	//mouse.x = &(sdl_event->motion.x);
}

void Input::Update()
{
//	a = s_event->motion.x;
}