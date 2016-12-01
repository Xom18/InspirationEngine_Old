#include "InspirationEngine_Input.h"

void Input::Start(SDL_Event* sdl_event)
{
	keyInput = SDL_GetKeyboardState(NULL);
	
	mouse.type = &(sdl_event->motion.type);
	mouse.timestamp = &(sdl_event->motion.timestamp);
	mouse.windowID = &(sdl_event->motion.windowID);
	mouse.which = &(sdl_event->motion.which);
	mouse.state = &(sdl_event->motion.state);
	mouse.x = &(sdl_event->motion.x);
	mouse.y = &(sdl_event->motion.y);
	mouse.deltaX = &(sdl_event->motion.xrel);
	mouse.deltaY = &(sdl_event->motion.yrel);
}

void Input::Update()
{
//	a = s_event->motion.x;
}