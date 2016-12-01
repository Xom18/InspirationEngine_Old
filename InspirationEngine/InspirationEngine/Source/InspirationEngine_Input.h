#pragma once
#include <SDL/SDL.h>
#include "InspirationEngine_Math.h"

enum MOUSE_STATE
{
	LEFT = 1,
	MIDDLE = 2,
	RIGHT = 3
};

class Input
{
	struct Mouse
	{
		bool button[3];
		Vector2_Int position;
		Vector2_Int deltaPosition;
	};
public:
	void Start(SDL_Event* _sdl_event);
	void MouseUpdate();
	void MouseDeltaReset();
	const Uint8* keyInput;
	Mouse mouse;
	SDL_Event* sdl_event;
private:
	void MouseMoveUpdate();
	void MouseButtonUpdate();
};