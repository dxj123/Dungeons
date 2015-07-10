#pragma once

#include <vector>
#include <string>
#include <map>

class Map {
	public:
		struct sLocation {
			int x;
			int y;
		};

		std::map<int, sLocation> tileSprites;
		int tiles[64][64];
		SDL_Texture* tileSheet;

		Map();
		~Map();

		void load(std::string mapName);
		void initTileSheet();
		void drawMap();
		void drawTile(int srcX, int srcY, SDL_Rect location);

		const int TILE_WIDTH = 32;
		const int TILE_HEIGHT = 32;

		static const int TILE_NORMAL_GROUND_1[2];
		static const int TILE_NORMAL_GROUND_2[2];

	private:
		int mapWidth, mapHeight, sheetWidth, sheetHeight;
};