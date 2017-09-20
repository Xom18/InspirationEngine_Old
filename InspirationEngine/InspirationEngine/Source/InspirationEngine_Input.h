#pragma once

enum MOUSE_STATE
{
	LEFT = 1,
	MIDDLE = 2,
	RIGHT = 3
};
class InspirationEngine;
class Input
{
	struct Mouse
	{
		bool button[3];
		Vector2_Int position;
		Vector2_Int deltaPosition;
	};
public:
	InspirationEngine* parent;
	void Start(SDL_Event* _sdl_event);
	void MouseUpdate();
	void MouseDeltaReset();
	const Uint8* keyInput;
	Mouse mouse;
private:
	void MouseMoveUpdate();
	void MouseButtonUpdate();
};