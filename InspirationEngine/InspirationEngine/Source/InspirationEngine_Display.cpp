#include <SDL/SDL.h>
#include <iostream>
#include "InspirationEngine_Display.h"

Display::Display(char *title, int width, int height, int layerCount)
{
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

Display::~Display()
{
	delete[] graphicBuffer;
	for(int i = 0; i < layerCount; ++i)
		SDL_DestroyTexture(m_texture[i]);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(m_window);
}

SDL_Texture* Display::GetTexture(int i)
{
	return m_texture[i];
}

void Display::Render()
{
	for (int i = 0; i < layerCount; ++i)
		SDL_RenderCopy(renderer, m_texture[i], NULL, NULL);
	
	SDL_RenderPresent(renderer);
}

bool Display::Closed()
{
	if (m_window == NULL)
		return true;
	else
		return false;
}

int Display::GetLayerCount()
{
	return layerCount;
}

Uint32* Display::GetGraphicBuffer()
{
	return graphicBuffer;
}

SDL_Renderer* Display::GetRenderer()
{
	return renderer;
}