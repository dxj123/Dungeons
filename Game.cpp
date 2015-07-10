#pragma once

#include "Globals.h"

Game::Game() : frameSkip(0), running(0), window(NULL), renderer(NULL) {
	// Init the application
	gameState = gameStates::SceneMainMenu;
}

Game::~Game() {
	// Stop the application
	this->stop();
}

void Game::start() {
	// Init SDL
	int flags = SDL_WINDOW_SHOWN;

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		return;
	}

	if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, flags, &window, &renderer)) {
		return;
	}

	MainMenu* mainMenu = new MainMenu();

	this->running = 1;
	run();
}

void Game::draw() {
	// Draw / render the game
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	// Render
	/*switch (gameState) {
		case gameStates::SceneMainMenu:
			for (int i = 0; i < buttons.size(); i++)
				buttons[i]->draw();
			break;
		case gameStates::Running:
			for (int i = 0; i < entities.size(); i++)
				entities[i]->draw();
			break;
		case gameStates::Menu:
			break;
		case gameStates::Paused:
			break;
	}*/

	if (this->drawScene)
		this->drawScene();

	SDL_RenderPresent(renderer);
}

void Game::stop() {
	// Stop SDL
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}

	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
	}

	SDL_Quit();
}

void Game::fpsChanged(int fps) {
	// FPS Change
	char szFps[128];
	sprintf_s(szFps, "%s: %d FPS", "Dungeons", fps);
	SDL_SetWindowTitle(window, szFps);
}

void Game::onQuit() {
	// Stop the run loop
	running = 0;
}

void Game::run() {
	// Start the loop & handle the fps & init the callbacks
	SDL_Event event;

	int past = SDL_GetTicks();
	int now = past, pastFps = past;
	int fps = 0, framesSkipped = 0;
	
	while (running) {
		int timeElapsed = 0;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: 
					onQuit();
					break;
				case SDL_KEYDOWN: 
					onKeyDown(&event);
					break;
				case SDL_KEYUP: 
					onKeyUp(&event);
					break;
				case SDL_MOUSEBUTTONDOWN:
					onMouseDown(&event);
					break;
				case SDL_MOUSEBUTTONUP:
					onMouseUp(&event);
					break;
				case SDL_MOUSEMOTION:
					onMouseMotion(&event);
					break;
			}
		}
		
		timeElapsed = (now = SDL_GetTicks()) - past;

		if (timeElapsed >= GAME_FPS) {
			past = now;
			update();
			if (framesSkipped++ >= frameSkip) {
				draw();
				++fps;
				framesSkipped = 0;
			}
		}

		if (now - pastFps >= 1000) {
			pastFps = now;
			fpsChanged(fps);
			fps = 0;
		}

		SDL_Delay(1);
	}
}

void Game::update() {
	if (this->updateScene)
		this->updateScene();
}

void Game::onKeyDown(SDL_Event* evt) {
	keys[evt->key.keysym.sym] = 1;
}

void Game::onKeyUp(SDL_Event* evt) {
	keys[evt->key.keysym.sym] = 0;
}

void Game::onMouseDown(SDL_Event* evt) {
	for (int i = 0; i < buttons.size(); i++) {
		if (evt->button.x >= buttons[i]->x && evt->button.y >= buttons[i]->y && evt->button.x <= buttons[i]->x + buttons[i]->width && evt->button.y <= buttons[i]->y + buttons[i]->height) {
			buttons[i]->click();
		}
	}
}

void Game::onMouseUp(SDL_Event* evt) {

}

void Game::onMouseMotion(SDL_Event* evt) {
	for (int i = 0; i < buttons.size(); i++) {
		if (evt->motion.x >= buttons[i]->x && evt->motion.y >= buttons[i]->y && evt->motion.x <= buttons[i]->x + buttons[i]->width && evt->motion.y <= buttons[i]->y + buttons[i]->height) {
			buttons[i]->hover();
		}
	}
}