#pragma once

class DevMode {
public:
	DevMode();
	~DevMode();

	void draw();
	void update();
	void mouseDown(SDL_Event* evt);
	void mouseUp(SDL_Event* evt);
	void mouseMotion(SDL_Event* evt);
};