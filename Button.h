#pragma once

#include <SDL.h>

#include "UI.h"

class Button : UI {
	public:
		SDL_Surface* image;

		void init();
		void draw();
		void update();

	private:
		void click();
		void hover();
};