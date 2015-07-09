#pragma once

#include <stdio.h>
#include <string>

class Entity {
	public:
		float x;
		float y;

		std::string image;

		void init();
		void draw();
		void update();
};