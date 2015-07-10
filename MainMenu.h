#pragma once

class MainMenu {
	public:
		MainMenu();
		~MainMenu();

		void onClickStart();
		void onClickSettings();
		void onClickQuit();

		void draw();
		void update();

	private:
		SDL_Texture* title;
};