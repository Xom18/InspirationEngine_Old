#pragma once
#include <SDL/SDL.h>
#include "InspirationEngine_Math.h"

class Input
{
	struct Mouse{
		Uint32* type;
		Uint32* timestamp;
		Uint32* windowID;
		Uint32* which;
		Uint32* state;
		Sint32* x;
		Sint32* y;
		Sint32* deltaX;
		Sint32* deltaY;
	};
public:
	void Start(SDL_Event* sdl_event);
	void Update();
	const Uint8* keyInput;
	Mouse mouse;
	//SDL_MouseMotionEvent mouse;
	SDL_Event* s_event;
	int a;
private:
};