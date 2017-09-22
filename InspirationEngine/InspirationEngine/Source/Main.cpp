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
	SDL_Rect rect;
	SDL_Rect rectP;
	rect.h = 16;
	rect.w = 16;
	rect.x = 0;
	rect.y = 8;

	rectP.h = 16;
	rectP.w = 16;
	rectP.x = 0;
	rectP.y = 0;

	InspirationEngine* engine = new InspirationEngine();
	engine->sdl_event = new SDL_Event;
	engine->window = new Window("Inspiration", SCREEN_WIDTH, SCREEN_HEIGHT, 2);
	engine->input = new Input();

	engine->window->engine = engine;
	engine->input->engine = engine;

	engine->input->Start();

	Image tileSet; // Tileset Image
	Tile tile; // Tile
//	Input input;

//	input.Start(&sdl_event);
	tileSet.ReadBMP("../Release/file.bmp");
	tile.ImageToTile(tileSet, 16);
	
	engine->window->Render();
	SDL_SetTextureBlendMode(engine->window->GetTexture(1), SDL_BLENDMODE_BLEND);

	while (!engine->IsQuit())
	{
		SDL_PollEvent(engine->sdl_event);
		if (engine->sdl_event->type == SDL_QUIT)
			engine->SetQuit();

		SDL_UpdateTexture(engine->window->GetTexture(0), &rect, tile.GetData(1), 16 * sizeof(Uint32));

			
//			SDL_UpdateTexture(engine->window->GetTexture(0), NULL, engine->window->GetGraphicBuffer(), SCREEN_WIDTH * sizeof(Uint32));
		engine->window->Render();
	}
	delete engine;
	SDL_Quit();
	return 0;
}