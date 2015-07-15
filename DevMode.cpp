#pragma once

#include "Globals.h"

DevMode::DevMode() {
	game.drawScene = [this]() { this->draw(); };
	game.updateScene = [this]() { this->update(); };
	game.mouseDownScene = [this](SDL_Event* evt) { this->mouseDown(evt); };
	game.mouseUpScene = [this](SDL_Event* evt) { this->mouseUp(evt); };
	game.mouseMotionScene = [this](SDL_Event* evt) { this->mouseMotion(evt); };

	map.setViewPort(40, 40, 500, 300);
	map.tileSheet = Graphics::loadImageFromFile("images/tiles.png");
	map.load("maps/floor1.map");
}

DevMode::~DevMode() {
	// Remove callbacks
	game.drawScene = []() {};
	game.updateScene = []() {};
	game.mouseDownScene = [](SDL_Event* evt) {};
	game.mouseUpScene = [](SDL_Event* evt) {};
	game.mouseMotionScene = [](SDL_Event* evt) {};
}

void DevMode::draw() {
	map.drawMap();
}

void DevMode::update() {
	if (game.keys[SDLK_F5]) {
		map.load("maps/floor1.map");
		std::cout << "Reloaded map" << std::endl;
	}
}

void DevMode::mouseDown(SDL_Event* evt) {
	
}

void DevMode::mouseUp(SDL_Event* evt) {

}

void DevMode::mouseMotion(SDL_Event* evt) {
	
}