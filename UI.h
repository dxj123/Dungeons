#pragma once

#include <stdio.h>
#include <functional>

class UI {
	public:
		float x;
		float y;
		float width;
		float height;

		bool visible;
		
		std::function<void()> onClick;
		std::function<void()> onHover;
};