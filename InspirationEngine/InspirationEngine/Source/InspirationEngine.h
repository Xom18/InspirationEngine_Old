#pragma once

class Input;
class Window;
class InspirationEngine
{
public:
	InspirationEngine();
	~InspirationEngine();
	SDL_Event* sdl_event;
	Input* input;
	Window* window;
	void SetQuit();
	bool IsQuit();

private:
	bool quit;
};