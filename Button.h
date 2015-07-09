#pragma once

#include <SDL.h>

#include "UI.h"

class Button : public UI {
	public:
		SDL_Surface* image;
		float red, green, blue;

		void init(float posX, float posY, float w, float h, bool isVisible = true);
		void draw();
		void update();
		void click();
		void hover();
};