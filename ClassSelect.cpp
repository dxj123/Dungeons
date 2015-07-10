#pragma once

#include "Globals.h"

ClassSelect::ClassSelect() {
	// Init callbacks
	game.drawScene = [this]() { this->draw(); };
	game.updateScene = [this]() { this->update(); };
	game.mouseDownScene = [this](SDL_Event* evt) { this->mouseDown(evt); };
	game.mouseUpScene = [this](SDL_Event* evt) { this->mouseUp(evt); };
	game.mouseMotionScene = [this](SDL_Event* evt) { this->mouseMotion(evt); };

	// Load button
	Button* selectButton = new Button();

	selectButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 220, 250, 75, "images/button_select.png");

	selectButton->onClick = [this]() { this->onClickSelect(); };
}

ClassSelect::~ClassSelect() {
	// Remove callbacks
	game.drawScene = []() {};
	game.updateScene = []() {};
	game.mouseDownScene = [](SDL_Event* evt) {};
	game.mouseUpScene = [](SDL_Event* evt) {};
	game.mouseMotionScene = [](SDL_Event* evt) {};

	// Remove buttons
	buttons.clear();

	std::cout << "Cleaned up class select" << std::endl;
}

void ClassSelect::onClickSelect() {
	std::cout << "Select button clicked" << std::endl;

	delete this;

	game.gameState = game.gameStates::SceneFloor;
	Floor1* floor = new Floor1();

	std::cout << "Switched game state to new floor" << std::endl;
}

void ClassSelect::draw() {
	for (int i = 0; i < buttons.size(); i++)
		buttons[i]->draw();
}

void ClassSelect::update() {

}

void ClassSelect::mouseDown(SDL_Event* evt) {
	for (int i = 0; i < buttons.size(); i++) {
		if (evt->button.x >= buttons[i]->x && evt->button.y >= buttons[i]->y && evt->button.x <= buttons[i]->x + buttons[i]->width && evt->button.y <= buttons[i]->y + buttons[i]->height) {
			buttons[i]->click();
		}
	}
}

void ClassSelect::mouseUp(SDL_Event* evt) {

}

void ClassSelect::mouseMotion(SDL_Event* evt) {
	for (int i = 0; i < buttons.size(); i++) {
		if (evt->motion.x >= buttons[i]->x && evt->motion.y >= buttons[i]->y && evt->motion.x <= buttons[i]->x + buttons[i]->width && evt->motion.y <= buttons[i]->y + buttons[i]->height) {
			buttons[i]->hover();
		}
	}
}