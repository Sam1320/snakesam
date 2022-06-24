#ifndef snake_map_h
#define snake_map_h

#include "macros.h"
#include "snake.h"
#include <chrono>


class Map
{
public:
	Map(Snake *snake);
	void draw();
	pair<int, int> snake_food;
private:
	char map_array[MAP_HEIGHT][MAP_WIDTH];
	Snake *snake;
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
#endif
