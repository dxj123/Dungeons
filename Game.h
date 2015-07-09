#pragma once

#include <stdio.h>
#include <map>

#include <SDL.h>

class Game {
	public:
		Game();
		~Game();

		enum gameStates {
			MainMenu,
			Running,
			Menu,
			Paused
		};

		void start();
		void stop();
		void draw();
		void fpsChanged(int fps);
		void onQuit();
		void onKeyDown(SDL_Event* event);
		void onKeyUp(SDL_Event* event);
		void onMouseDown(SDL_Event* event);
		void onMouseUp(SDL_Event* event);
		void onMouseMotion(SDL_Event* event);
		void run();
		void update();

	//private:
		std::map<int, int> keys;
		int frameSkip;
		int running;
		int gameState;
		SDL_Window* window;
		SDL_Renderer* renderer;
};