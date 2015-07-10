#pragma once

#include "Globals.h"

MainMenu::MainMenu() {
	// Init callbacks
	game.drawScene = [this]() { this->draw(); };
	game.updateScene = [this]() { this->update(); };

	// Load background
	this->title = Graphics::loadImageFromFile("images/title.png");

	// Load buttons
	Button* startButton = new Button();
	Button* settingsButton = new Button();
	Button* exitButton = new Button();

	startButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 20, 250, 75, "images/button_play.png");
	settingsButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 120, 250, 75, "images/button_settings.png");
	exitButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 220, 250, 75, "images/button_quit.png");

	startButton->onClick = [this]() { this->onClickStart(); };
	settingsButton->onClick = [this]() { this->onClickSettings(); };
	exitButton->onClick = [this]() { this->onClickQuit(); };
}

MainMenu::~MainMenu() {
	// Remove callbacks
	game.drawScene = []() {};
	game.updateScene = []() {};

	// Remove buttons
	buttons.empty();

	std::cout << "Cleaned up main menu" << std::endl;
}

void MainMenu::onClickStart() {
	std::cout << "Start button clicked" << std::endl;

	delete this;

	game.gameState = game.gameStates::Running;
	std::cout << "Switched game state to running" << std::endl;
}

void MainMenu::onClickSettings() {
	std::cout << "Settings button clicked" << std::endl;
}

void MainMenu::onClickQuit() {
	std::cout << "Quit button clicked" << std::endl;
	game.stop();
}

void MainMenu::draw() {
	SDL_Rect rect;
	rect.x = WINDOW_WIDTH / 2 - 170;
	rect.y = WINDOW_HEIGHT / 2 - 100;
	rect.w = 340;
	rect.h = 45;

	SDL_RenderCopy(game.renderer, this->title, NULL, &rect);
}

void MainMenu::update() {

}