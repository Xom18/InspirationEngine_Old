#include <SDL/SDL.h>
#include <iostream>
#include <thread>
#include "InspirationEngine_Modul.h"
#include "InspirationEngine_Window.h"

Window::Window(char *title, int _width, int _height, int layerCount)
{
	width = _width;
	height = _height;
	//SDL setting
	SDL_Init(SDL_INIT_VIDEO);
	//Create Window, Renderer, texture, buffer, memoryset
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(m_window, -1, 0);
	this->layerCount = layerCount;
	for(int i = 0; i < layerCount; ++i)
		m_texture[i] = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height);
	
	graphicBuffer = new Uint32[width * height];
	memset(graphicBuffer, 255, width * height * sizeof(Uint32));
}

Window::~Window()
{
	if(graphicBuffer) delete[] graphicBuffer; graphicBuffer = 0;
	for(int i = 0; i < layerCount; ++i) { if(m_texture[i]) SDL_DestroyTexture(m_texture[i]); m_texture[i] = 0;}
//	if(renderer) delete renderer; renderer = 0;
//	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(m_window);
}

SDL_Texture* Window::GetTexture(int i)
{
	return m_texture[i];
}

void Window::Render()
{
	for (int i = 0; i < layerCount; ++i)
		SDL_RenderCopy(renderer, m_texture[i], NULL, NULL);
	
	SDL_RenderPresent(renderer);
}

bool Window::Closed()
{
	if (m_window == NULL)
		return true;
	else
		return false;
}

int Window::GetLayerCount() { return layerCount; }

Uint32* Window::GetGraphicBuffer() { return graphicBuffer; }

SDL_Renderer* Window::GetRenderer() { return renderer; }

int Window::GetScreenWidth() { return width; }
int Window::GetScreenHeight() { return height; }