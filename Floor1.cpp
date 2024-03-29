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

}

void Floor1::update() {

}