#pragma once

#include "Globals.h"

void Button::init(float posX, float posY, float w, float h, std::string img, bool isVisible) {
	this->x = posX;
	this->y = posY;
	this->width = w;
	this->height = h;

	this->red = 0;
	this->green = 0;
	this->blue = 0;

	this->visible = isVisible;

	if (img != "") 
		this->image = Graphics::loadImageFromFile(img);

	buttons.push_back(this);
}

void Button::draw() {
	if (this->visible) {
		SDL_Rect rect;
		rect.x = this->x;
		rect.y = this->y;
		rect.w = this->width;
		rect.h = this->height;

		if (this->image) {
			SDL_RenderCopy(game.renderer, this->image, NULL, &rect);
		} else {
			Graphics::fillRect(&rect, this->red, this->green, this->blue);
		}
	}
}

void Button::update() {
	if (this->visible) {
		
	}
}

void Button::click() {
	if (this->visible) {
		if (this->onClick) {
			this->onClick();
		} else {
			std::cout << "Click registered on unbound button" << std::endl;
		}
	}
}

void Button::hover() {
	if (this->visible) {
		if (this->onHover) {

		} else {
			//std::cout << "Hover registered on unbound button" << std::endl;
		}
	}
}