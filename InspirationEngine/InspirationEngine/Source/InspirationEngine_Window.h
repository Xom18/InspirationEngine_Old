#pragma once

class InspirationEngine_Modul;
class Window : public InspirationEngine_Modul
{
public:
	Window(char* title, int _width, int _height, int layerCount);
	~Window();

	SDL_Texture* GetTexture(int i);
	bool Closed();
	int GetLayerCount();
	Uint32* GetGraphicBuffer();
	SDL_Renderer* GetRenderer();
	void Render();
	int GetScreenWidth();
	int GetScreenHeight();
protected:

private:
	Uint32* graphicBuffer;
	SDL_Renderer* renderer;
	SDL_Window* m_window;
	SDL_Texture* m_texture[16];
	int width;
	int height;
	int layerCount;
};