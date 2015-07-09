#pragma once

#include "Globals.h"

void Entity::init() {

}

void Entity::draw() {
	SDL_Rect test;
	test.x = x;
	test.y = y;
	test.w = 20;
	test.h = 20;

	Graphics::fillRect(&test, 0, 0, 0);
}

void Entity::update() {

}