#include <SDL/SDL.h>
#include <iostream>
#include <thread>
#include "InspirationEngine.h"
#include "InspirationEngine_Modul.h"
#include "InspirationEngine_Window.h"
#include "InspirationEngine_Math.h"
#include "InspirationEngine_Input.h"

Input::~Input()
{
	trd->join();
}

void Input::Start()
{
	keyboard = SDL_GetKeyboardState(NULL);
	for(int i = 0; i < 3; ++i)
		mouse.button[i] = 0;
	mouse.position = mouse.deltaPosition = 0;
	
	trd = new std::thread([&](){InputThread();});
}

void Input::InputThread()
{
	while(!engine->IsQuit())
	{
		if(engine->sdl_event->type & SDL_MOUSEMOTION)
			MouseUpdate(engine->sdl_event->type - SDL_MOUSEMOTION);
	}
	printf("InputThread Quit\n");
}

void Input::MouseUpdate(int mEvent)
{
	if(mEvent == 0)
	{
		mouse.position.x = engine->sdl_event->motion.x;
		mouse.position.y = engine->window->GetScreenHeight() - engine->sdl_event->motion.y;
		mouse.deltaPosition.x = engine->sdl_event->motion.xrel;
		mouse.deltaPosition.y = -engine->sdl_event->motion.yrel;
	}
	else
	{
		mouse.position.x = engine->sdl_event->button.x;
		mouse.position.y = engine->window->GetScreenHeight() - engine->sdl_event->button.y;

		if (engine->sdl_event->button.state)
			mouse.button[engine->sdl_event->button.button - 1] = true;
		else
			mouse.button[engine->sdl_event->button.button - 1] = false;
	}
}