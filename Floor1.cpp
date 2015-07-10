#pragma once

#include "Globals.h"

Floor1::Floor1() {
	// Load spritesheet
	map.tileSheet = Graphics::loadImageFromFile("images/tiles.png");

	// Init callbacks
	game.drawScene = [this]() { this->draw(); };
	game.updateScene = [this]() { this->update(); };
}

Floor1::~Floor1() {
	// Remove callbacks
	game.drawScene = []() {};
	game.updateScene = []() {};
}

void Floor1::draw() {
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 32;
	rect.h = 32;

	map.drawTile(map.TILE_NORMAL_GROUND_1, rect);
}

void Floor1::update() {

}