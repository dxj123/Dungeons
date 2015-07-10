#pragma once

#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "UI.h"

class Button : public UI {
	public:
		SDL_Texture* image;
		float red, green, blue;

		void init(float posX, float posY, float w, float h, std::string img = "", bool isVisible = true);
		void draw();
		void update();
		void click();
		void hover();
};