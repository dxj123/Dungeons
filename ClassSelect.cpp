#pragma once

#include "Globals.h"

ClassSelect::ClassSelect() {
	// Init callbacks
	game.drawScene = [this]() { this->draw(); };
	game.updateScene = [this]() { this->update(); };

	// Load button
	Button* selectButton = new Button();

	selectButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 220, 250, 75, "images/button_select.png");

	selectButton->onClick = [this]() { this->onClickSelect(); };
}

ClassSelect::~ClassSelect() {
	// Remove callbacks
	game.drawScene = []() {};
	game.updateScene = []() {};

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