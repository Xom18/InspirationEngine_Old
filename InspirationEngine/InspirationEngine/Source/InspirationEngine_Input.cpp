#include "InspirationEngine_Input.h"

void Input::Start(SDL_Event* _sdl_event)
{
	keyInput = SDL_GetKeyboardState(NULL);
	for(int i = 0; i < 3; ++i)
		mouse.button[i] = 0;
	sdl_event = _sdl_event;
}

void Input::MouseUpdate()
{
	switch (sdl_event->type)
	{
		case SDL_MOUSEMOTION:
			MouseMoveUpdate();
		break;

		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEBUTTONDOWN:
			MouseButtonUpdate();
		break;
	}
}

void Input::MouseDeltaReset()
{
	mouse.deltaPosition.x = 0;
	mouse.deltaPosition.y = 0;
}

void Input::MouseMoveUpdate()
{
	mouse.position.x = sdl_event->motion.x;
	mouse.position.y = sdl_event->motion.y;
	mouse.deltaPosition.x = sdl_event->motion.xrel;
	mouse.deltaPosition.y = sdl_event->motion.yrel;
}

void Input::MouseButtonUpdate()
{
	mouse.position.x = sdl_event->button.x;
	mouse.position.y = sdl_event->button.y;
	mouse.deltaPosition.x = sdl_event->motion.xrel;
	mouse.deltaPosition.y = sdl_event->motion.yrel;
	if(sdl_event->button.state)
		mouse.button[sdl_event->button.button - 1] = true;
	else
		mouse.button[sdl_event->button.button - 1] = false;
}