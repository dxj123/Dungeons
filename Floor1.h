#pragma once

class Floor1 {
	public:
		Floor1();
		~Floor1();

		void draw();
		void update();
		void mouseDown(SDL_Event* evt);
		void mouseUp(SDL_Event* evt);
		void mouseMotion(SDL_Event* evt);
};