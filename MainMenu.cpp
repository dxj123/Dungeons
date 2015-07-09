#pragma once

#include "Globals.h"

MainMenu::MainMenu() {
	// Load background

	// Load buttons
	Button* startButton = new Button();
	Button* settingsButton = new Button();
	Button* exitButton = new Button();

	startButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 20, 250, 75, true);
	settingsButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 120, 250, 75, true);
	exitButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 220, 250, 75, true);

	startButton->onClick = [this]() { this->onClickStart(); };
}

MainMenu::~MainMenu() {
	buttons.empty();
	std::cout << "Cleaned up main menu" << std::endl;
}

void MainMenu::onClickStart() {
	std::cout << "Start clicked" << std::endl;

	game.gameState = game.gameStates::Running;
	std::cout << "Switched game state to running" << std::endl;

	delete this;
}

void MainMenu::onClickSettings() {

}

void MainMenu::onClickQuit() {

}