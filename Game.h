#pragma once

#include <stdio.h>
#include <map>
#include <functional>

#include <SDL.h>

class Game {
	public:
		int frameSkip;
		int running;
		int gameState;

		Game();
		~Game();

		enum gameStates {
			SceneDev,
			SceneMainMenu,
			SceneClassSelect,
			SceneFloor,
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

		std::map<int, int> keys;
		SDL_Window* window;
		SDL_Renderer* renderer;

		// callbacks
		std::function<void()> drawScene;
		std::function<void()> updateScene;
		std::function<void(SDL_Event* evt)> mouseDownScene;
		std::function<void(SDL_Event* evt)> mouseUpScene;
		std::function<void(SDL_Event* evt)> mouseMotionScene;
};