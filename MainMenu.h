#pragma once

class MainMenu {
	public:
		MainMenu();
		~MainMenu();

		void onClickStart();
		void onClickSettings();
		void onClickQuit();
		void onClickDev();

		void draw();
		void update();
		void mouseDown(SDL_Event* evt);
		void mouseUp(SDL_Event* evt);
		void mouseMotion(SDL_Event* evt);

	private:
		SDL_Texture* title;
};