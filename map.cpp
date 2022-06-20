#include "map.h"
#include <iostream>
#include "snake.h"

using namespace std;

Map::Map(Snake *snake)
{
	this->snake = snake;
	clear_map(this->map_array);
	snake_food = pair<int, int>(4,4);
}

void Map::draw(void)
{
    	// redraw empty map
	clear_map(this->map_array); 
	// print empty lines to clear console
	for (int i = 0; i < MAP_END; i++)
	{
		cout << endl;
	}

	// draw food
	this->map_array[snake_food.first][snake_food.second] = FOOD_CHAR;
	if (snake->food_eaten == 1) {
		snake_food = pair<int, int>(rand()%MAP_WIDTH, rand()%MAP_HEIGHT);
		snake->food_eaten = 0;
	}

	// draw the snake's body in the map
	vector<pair<int, int>> snake_body = snake->body;
	for (int i =0; i < snake_body.size(); i++)
	{
		pair<int, int> tmp = snake_body[i];
		this->map_array[tmp.first][tmp.second] = SNAKE_CHAR;
	}
	// draw the map in the console
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
	    for (int j = 0; j < MAP_WIDTH; j++)
	    {
		cout << this->map_array[i][j] << " ";
	    }
	    cout << endl;
	}
}

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (j == 0 || i == 0 || j == MAP_WIDTH -1 || i == MAP_HEIGHT -1 ) { map_array[i][j] = MAP_CHAR; } else
			{
				map_array[i][j] = ' ';
			}
		}
	}
}

