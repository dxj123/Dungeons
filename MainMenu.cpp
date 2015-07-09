#pragma once

#include "Globals.h"

MainMenu::MainMenu() {
	// Load background

	// Load buttons
	Button* startButton = new Button();
	Button* settingsButton = new Button();
	Button* exitButton = new Button();

	startButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 20, 250, 75);
	settingsButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 120, 250, 75);
	exitButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 220, 250, 75);
}

MainMenu::~MainMenu() {

}