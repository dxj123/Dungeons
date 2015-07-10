#pragma once

#include <string>

#include <SDL.h>

class Graphics {
	public:
		static void fillRect(SDL_Rect* rect, int r, int g, int b);
		static SDL_Texture* loadImageFromFile(std::string path);
};