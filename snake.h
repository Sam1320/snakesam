#ifndef _snake_h
#define _snake_h

#include "input.h"
#include "macros.h"
//#include "map.h"
#include <utility> // for pair<> datatype

#include <vector>
#include <semaphore.h> // for sem_t
class Map;
using namespace std;

class Snake
{
    public:
        Snake();
        bool food_eaten;
        bool alive;
        int length;
	vector<pair<int, int>> body;
	pair<int, int> head;
	void update_movement(Map *map);
	void update_direction(enum Direction);
    private:
    	pthread_t input_thread;
	sem_t snake_sema;
        enum Direction direction;
        enum Direction next_direction;
	void initialize_snake(void);
	int occupation_array[MAP_WIDTH][MAP_HEIGHT];
};

#endif
