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
#include "ClassSelect.h"
#include "Map.h"
#include "DevMode.h"

// Scenes / Floors
#include "Floor1.h"

extern enum {
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 720,
	GAME_FPS = 1000/60
};

extern std::vector<Entity*> entities;
extern std::vector<Button*> buttons;

extern Game game;
extern Map map;
