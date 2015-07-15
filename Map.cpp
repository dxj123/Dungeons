#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Globals.h"

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

	for (int y = this->viewPort.y1; y < this->viewPort.y2; y++) {
		for (int x = this->viewPort.x1; x < this->viewPort.x2; x++) {
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

void Map::setViewPort(int x1, int y1, int x2, int y2) {
	viewPort.x1 = x1;
	viewPort.y1 = y1;
	viewPort.x2 = x2;
	viewPort.y2 = y2;

	this->convertViewPort();
}

void Map::convertViewPort() {
	// Handle the viewport
	float newX1 = floor(viewPort.x1 / TILE_WIDTH);
	float newY1 = floor(viewPort.y1 / TILE_HEIGHT);

	float newX2 = ceil(viewPort.x2 / TILE_WIDTH);
	float newY2 = ceil(viewPort.y2 / TILE_HEIGHT);

	viewPort.x1 = newX1;
	viewPort.y1 = newY1;
	viewPort.x2 = newX2;
	viewPort.y2 = newY2;
}