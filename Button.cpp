#pragma once

#include "Globals.h"

void Button::init(float posX, float posY, float w, float h) {
	this->x = posX;
	this->y = posY;
	this->width = w;
	this->height = h;

	this->visible = true;

	buttons.push_back(this);
}

void Button::draw() {
	if (this->visible) {
		SDL_Rect rect;
		rect.x = this->x;
		rect.y = this->y;
		rect.w = this->width;
		rect.h = this->height;

		Graphics::fillRect(&rect, 0, 0, 0);
	}
}

void Button::update() {

}

void Button::click() {

}

void Button::hover() {

}