#include <SDL/SDL.h>
#include "InspirationEngine.h"
#include "InspirationEngine_Math.h"
#include "InspirationEngine_Input.h"
#include <iostream>

void Input::Start(SDL_Event* _sdl_event)
{
	keyInput = SDL_GetKeyboardState(NULL);
	for(int i = 0; i < 3; ++i)
		mouse.button[i] = 0;
	parent->sdl_event = _sdl_event;
}

void Input::MouseUpdate()
{
	switch (parent->sdl_event->type)
	{
		case SDL_MOUSEMOTION:
			MouseMoveUpdate();
		break;

		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEBUTTONDOWN:
			MouseButtonUpdate();
		break;
	}
	printf("%d / %d / %d / %d\n", mouse.position.x, mouse.position.y, mouse.button[0], mouse.button[1]);
}

void Input::MouseDeltaReset()
{
	mouse.deltaPosition.x = 0;
	mouse.deltaPosition.y = 0;
}

void Input::MouseMoveUpdate()
{
	mouse.position.x = parent->sdl_event->motion.x;
	mouse.position.y = parent->sdl_event->motion.y;
	mouse.deltaPosition.x = parent->sdl_event->motion.xrel;
	mouse.deltaPosition.y = parent->sdl_event->motion.yrel;
}

void Input::MouseButtonUpdate()
{
	mouse.position.x = parent->sdl_event->button.x;
	mouse.position.y = parent->sdl_event->button.y;
	mouse.deltaPosition.x = parent->sdl_event->motion.xrel;
	mouse.deltaPosition.y = parent->sdl_event->motion.yrel;
	if(parent->sdl_event->button.state)
		mouse.button[parent->sdl_event->button.button - 1] = true;
	else
		mouse.button[parent->sdl_event->button.button - 1] = false;
}