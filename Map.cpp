#pragma once

#include "Globals.h"

const int Map::TILE_NORMAL_GROUND_1[2] = { 0, 19 };
const int Map::TILE_NORMAL_GROUND_2[2] = { 3, 22 };

Map::Map() {

}

Map::~Map() {

}

void Map::drawTile(const int src[2], SDL_Rect location) {
	SDL_Rect newSrc;
	newSrc.x = src[0] * TILE_WIDTH;
	newSrc.y = src[1] * TILE_HEIGHT;
	newSrc.w = TILE_WIDTH;
	newSrc.h = TILE_HEIGHT;

	SDL_RenderCopy(game.renderer, this->tileSheet, &newSrc, &location);
}