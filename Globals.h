#pragma once

// Core
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>

// Libs
#include <SDL.h>
#include <SDL_image.h>

// Base
#include "Game.h"
#include "Entity.h"
#include "Graphics.h"
#include "UI.h"

// UI
#include "Button.h"

// Scenes
#include "MainMenu.h"

extern enum {
	WINDOW_WIDTH = 640,
	WINDOW_HEIGHT = 480,
	GAME_FPS = 1000/60
};

extern Game game;

extern std::vector<Entity*> entities;
extern std::vector<Button*> buttons;