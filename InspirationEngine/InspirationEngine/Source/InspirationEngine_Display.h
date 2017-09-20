#pragma once

class InspirationEngine;
class Display
{
public:
	InspirationEngine* parent;
	Display(char* title, int width, int height, int layerCount);
	~Display();

	SDL_Texture* GetTexture(int i);
	bool Closed();
	int GetLayerCount();
	Uint32* GetGraphicBuffer();
	SDL_Renderer* GetRenderer();
	void Render();
protected:

private:
	Uint32* graphicBuffer;
	SDL_Renderer* renderer;
	SDL_Window* m_window;
	SDL_Texture *m_texture[16];
	int layerCount;
};