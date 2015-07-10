#pragma once

#include "Globals.h"

MainMenu::MainMenu() {
	// Init callbacks
	game.drawScene = [this]() { this->draw(); };
	game.updateScene = [this]() { this->update(); };
	game.mouseDownScene = [this](SDL_Event* evt) { this->mouseDown(evt); };
	game.mouseUpScene = [this](SDL_Event* evt) { this->mouseUp(evt); };
	game.mouseMotionScene = [this](SDL_Event* evt) { this->mouseMotion(evt); };

	// Load background
	this->title = Graphics::loadImageFromFile("images/title.png");

	// Load buttons
	Button* startButton = new Button();
	Button* settingsButton = new Button();
	Button* exitButton = new Button();
	Button* devButton = new Button();

	startButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 20, 250, 75, "images/button_play.png");
	settingsButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 120, 250, 75, "images/button_settings.png");
	exitButton->init(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 + 220, 250, 75, "images/button_quit.png");
	devButton->init(WINDOW_WIDTH - 25 - 75, WINDOW_HEIGHT - 25 - 75, 75, 75, "images/button_square.png");

	startButton->onClick = [this]() { this->onClickStart(); };
	settingsButton->onClick = [this]() { this->onClickSettings(); };
	exitButton->onClick = [this]() { this->onClickQuit(); };
	devButton->onClick = [this]() { this->onClickDev(); };
}

MainMenu::~MainMenu() {
	// Remove callbacks
	game.drawScene = []() {};
	game.updateScene = []() {};
	game.mouseDownScene = [](SDL_Event* evt) {};
	game.mouseUpScene = [](SDL_Event* evt) {};
	game.mouseMotionScene = [](SDL_Event* evt) {};

	// Remove buttons
	buttons.clear();

	std::cout << "Cleaned up main menu" << std::endl;
}

void MainMenu::onClickStart() {
	std::cout << "Start button clicked" << std::endl;

	delete this;

	game.gameState = game.gameStates::SceneClassSelect;
	ClassSelect* classSelect = new ClassSelect();

	std::cout << "Switched game state to class select" << std::endl;
}

void MainMenu::onClickSettings() {
	std::cout << "Settings button clicked" << std::endl;
}

void MainMenu::onClickQuit() {
	std::cout << "Quit button clicked" << std::endl;
	game.stop();
}

void MainMenu::onClickDev() {
	delete this;
	game.gameState = game.gameStates::SceneDev;
	DevMode* editor = new DevMode();
	std::cout << "Switched game state to dev mode" << std::endl;
}

void MainMenu::draw() {
	for (int i = 0; i < buttons.size(); i++)
		buttons[i]->draw();

	SDL_Rect rect;
	rect.x = WINDOW_WIDTH / 2 - 170;
	rect.y = WINDOW_HEIGHT / 2 - 100;
	rect.w = 340;
	rect.h = 45;

	SDL_RenderCopy(game.renderer, this->title, NULL, &rect);
}

void MainMenu::update() {

}

void MainMenu::mouseDown(SDL_Event* evt) {
	for (int i = 0; i < buttons.size(); i++) {
		if (evt->button.x >= buttons[i]->x && evt->button.y >= buttons[i]->y && evt->button.x <= buttons[i]->x + buttons[i]->width && evt->button.y <= buttons[i]->y + buttons[i]->height) {
			buttons[i]->click();
		}
	}
}

void MainMenu::mouseUp(SDL_Event* evt) {

}

void MainMenu::mouseMotion(SDL_Event* evt) {
	for (int i = 0; i < buttons.size(); i++) {
		if (evt->motion.x >= buttons[i]->x && evt->motion.y >= buttons[i]->y && evt->motion.x <= buttons[i]->x + buttons[i]->width && evt->motion.y <= buttons[i]->y + buttons[i]->height) {
			buttons[i]->hover();
		}
	}
}