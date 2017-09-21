#include <SDL\SDL.h>
#include <thread>
#include "InspirationEngineHeaders.h"

InspirationEngine::InspirationEngine()
{
	quit = false;
}

InspirationEngine::~InspirationEngine()
{
	if(window) delete window; window = 0;
	if(input) delete input; input = 0;
}

void InspirationEngine::SetQuit()
{
	quit = true;
}

bool InspirationEngine::IsQuit()
{
	return quit;
}