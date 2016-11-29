#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MAP_SIZE 30
#define TILE_SIZE 4

#include "InspirationEngine.h"

int main(int argc, char* argv[])
{
	SDL_Event sdl_event;
	std::thread* inputThread;
	Display display("Inspiration", SCREEN_WIDTH, SCREEN_HEIGHT, 2);
	
	Image tileSet; // Tileset Image
	Tile tile; // Tile

	Input input;
	input.Start();

	tileSet.ReadBMP("../Release/file.bmp");
	tile.ImageToTile(tileSet, 16);
	
	display.Render();
	SDL_SetTextureBlendMode(display.GetTexture(1), SDL_BLENDMODE_BLEND);

	while (!display.Closed())
	{
		SDL_UpdateTexture(display.GetTexture(0), NULL, display.GetGraphicBuffer(), SCREEN_WIDTH * sizeof(Uint32));
		SDL_WaitEventTimeout(&sdl_event, 30);
		
		display.Render();
	}
	SDL_Quit();
	return 0;
}