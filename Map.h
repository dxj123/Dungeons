#pragma once

#include <string>

class Map {
	public:
		SDL_Texture* tileSheet;

		Map();
		~Map();

		void load(std::string mapName);
		void drawTile(const int src[2], SDL_Rect location);

		const int TILE_WIDTH = 32;
		const int TILE_HEIGHT = 32;

		static const int TILE_NORMAL_GROUND_1[2];
		static const int TILE_NORMAL_GROUND_2[2];

	private:
		int mapWidth, mapHeight;
};