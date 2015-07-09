#pragma once

#include "Globals.h"

void Graphics::fillRect(SDL_Rect* rect, int r, int g, int b) {
	SDL_SetRenderDrawColor(game.renderer, r, g, b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(game.renderer, rect);
}