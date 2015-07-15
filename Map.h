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

		struct ViewPort {
			float x1;
			float y1;
			float x2;
			float y2;
		};

		std::map<int, sLocation> tileSprites;
		int tiles[64][64];
		SDL_Texture* tileSheet;
		ViewPort viewPort;

		Map();
		~Map();

		void load(std::string mapName);
		void initTileSheet();
		void drawMap();
		void drawTile(int srcX, int srcY, SDL_Rect location);
		void setViewPort(int x1, int y1, int x2, int y2);
		void convertViewPort();

		const int TILE_WIDTH = 32;
		const int TILE_HEIGHT = 32;

	private:
		int mapWidth, mapHeight, sheetWidth, sheetHeight;
};