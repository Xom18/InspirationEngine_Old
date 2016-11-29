#pragma once
#include <SDL\SDL.h>
#include <thread>
#include "InspirationEngine_Display.h"
#include "InspirationEngine_Image.h"
#include "InspirationEngine_ReadFile.h"
#include "InspirationEngine_Input.h"

class InspirationEngine
{
public:
	Input input;
	Display display;

};