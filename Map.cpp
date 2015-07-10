#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Globals.h"

const int Map::TILE_NORMAL_GROUND_1[2] = { 0, 19 };
const int Map::TILE_NORMAL_GROUND_2[2] = { 3, 22 };

Map::Map() {

}

Map::~Map() {

}

void Map::load(std::string mapName) {
	// Check sheet compatibility
	SDL_QueryTexture(this->tileSheet, NULL, NULL, &sheetWidth, &sheetHeight);

	if (sheetWidth % TILE_WIDTH != 0 || sheetHeight % TILE_HEIGHT != 0) {
		std::cout << "Map error: Sprite sheet dimensions do not match" << std::endl;
		return;
	}

	// Load map
	std::ifstream mapStream(mapName);
	std::string line;

	// Check if has stream
	if (!mapStream) {
		std::cout << "Map error: Could not load map" << std::endl;
		return;
	}

	int mapPosX = 0;
	int mapPosY = 0;

	while (std::getline(mapStream, line)) {
		std::stringstream lineStream(line);
		int tileType;

		mapPosX = 0;
		while (lineStream >> tileType) {
			// Check for read error
			if (mapStream.fail()) {
				mapStream.close();
				std::cout << "Map error: Could not read map" << std::endl;
				return;
			}

			tiles[mapPosX][mapPosY] = tileType;

			mapPosX++;
		}

		mapPosY++;
	}

	this->mapWidth = mapPosX;
	this->mapHeight = mapPosY;

	mapStream.close();
	std::cout << "Map success: Map " << mapName << " loaded successfully" << std::endl;

	this->initTileSheet();
}

void Map::initTileSheet() {
	int columns = sheetWidth / TILE_WIDTH;
	int rows = sheetHeight / TILE_HEIGHT;
	int total = 0;
	sLocation sLoc;

	for (int h = 0; h < rows; h++) {
		for (int w = 0; w < columns; w++) {
			sLoc.x = w;
			sLoc.y = h;
			tileSprites[total] = sLoc;

			total++;
		}
	}
}

void Map::drawMap() {
	SDL_Rect loc;
	int tileType;
	sLocation src;

	for (int y = 0; y < this->mapHeight; y++) {
		for (int x = 0; x < this->mapWidth; x++) {
			loc.x = x * TILE_WIDTH;
			loc.y = y * TILE_HEIGHT;
			loc.w = TILE_WIDTH;
			loc.h = TILE_HEIGHT;

			tileType = tiles[x][y];
			src = tileSprites[tileType];

			this->drawTile(src.x, src.y, loc);
		}
	}
}

void Map::drawTile(int srcX, int srcY, SDL_Rect location) {
	SDL_Rect newSrc;
	newSrc.x = srcX * TILE_WIDTH;
	newSrc.y = srcY * TILE_HEIGHT;
	newSrc.w = TILE_WIDTH;
	newSrc.h = TILE_HEIGHT;

	SDL_RenderCopy(game.renderer, this->tileSheet, &newSrc, &location);
}