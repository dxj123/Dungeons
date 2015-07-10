#pragma once

#include "Globals.h"

void Graphics::fillRect(SDL_Rect* rect, int r, int g, int b) {
	SDL_SetRenderDrawColor(game.renderer, r, g, b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(game.renderer, rect);
}

SDL_Texture* Graphics::loadImageFromFile(std::string path) {
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	
	if (loadedSurface) {
		newTexture = SDL_CreateTextureFromSurface(game.renderer, loadedSurface);

		if (newTexture == NULL) 
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

		SDL_FreeSurface(loadedSurface);
	} else {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}

	return newTexture;
}