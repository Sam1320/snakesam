#ifndef snake_map_h
#define snake_map_h

#include "macros.h"
#include "snake.h"

class Map
{
public:
	Map(Snake *snake);
	void draw();
	pair<int, int> snake_food;
private:
	char map_array[MAP_HEIGHT][MAP_WIDTH];
	Snake *snake;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
#endif
