#pragma once

#include <SDL.h>

#include "UI.h"

class Button : public UI {
	public:
		SDL_Surface* image;

		void init(float posX, float posY, float w, float h);
		void draw();
		void update();

	private:
		void click();
		void hover();
};