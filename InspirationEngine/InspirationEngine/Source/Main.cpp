#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MAP_SIZE 30
#define TILE_SIZE 4

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif

#include "InspirationEngineHeaders.h"

int main(int argc, char* argv[])
{
//	SDL_Event sdl_event;
	InspirationEngine* engine = new InspirationEngine();
	engine->sdl_event = new SDL_Event;
	engine->display = new Display("Inspiration", SCREEN_WIDTH, SCREEN_HEIGHT, 2);
	engine->input = new Input();
	engine->display->parent = engine;
	engine->input->parent = engine;

	Image tileSet; // Tileset Image
	Tile tile; // Tile
//	Input input;

//	input.Start(&sdl_event);
	tileSet.ReadBMP("../Release/file.bmp");
	tile.ImageToTile(tileSet, 16);
	
	engine->display->Render();
	SDL_SetTextureBlendMode(engine->display->GetTexture(1), SDL_BLENDMODE_BLEND);

	while (!engine->display->Closed())
	{
		engine->input->MouseDeltaReset();
		while(SDL_PollEvent(engine->sdl_event))
		{
			if(engine->sdl_event->type == SDL_QUIT)
				SDL_Quit();
			engine->input->MouseUpdate();
			engine->display->Render();
			
			SDL_UpdateTexture(engine->display->GetTexture(0), NULL, engine->display->GetGraphicBuffer(), SCREEN_WIDTH * sizeof(Uint32));
		}

		engine->display->Render();
	}
	SDL_Quit();
	return 0;
}