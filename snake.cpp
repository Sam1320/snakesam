#include "snake.h"
#include <pthread.h>
#include <iostream>
#include "map.h"



void * input_thread_work(void *arg)
{
	Snake *snake = (Snake *) arg;
	while (true)
	{
		enum Direction direction = get_input();
		snake->update_direction(direction);
	}
}

Snake::Snake(void)
{
    food_eaten = false;
    alive = true;
    length = INITIAL_SNAKE_LENGTH;
    initialize_snake();
    pthread_create(&input_thread, NULL, input_thread_work, this);
}

void Snake::initialize_snake(void)
{
	for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++)
	{
		pair<int, int> body_part = pair<int, int>(MAP_HEIGHT/2, MAP_WIDTH/2 - (INITIAL_SNAKE_LENGTH) +i);
		body.push_back(body_part);
		occupation_array[body_part.first][body_part.second]++;
	}
	head = body[body.size() -1];
}


void Snake::update_movement(Map *map)
{
	pair<int, int> new_head;
	switch (direction)
	{
		case East:
			new_head = pair<int, int>(head.first, (head.second +1));
			break;
		case North:
			new_head = pair<int, int>(head.first-1, head.second);
			break;
		case West:
			new_head = pair<int, int>(head.first, head.second -1);
			break;
		case South:
			new_head = pair<int, int>(head.first +1, head.second);
			break;
			
	}
	// create new part in front of head to replace previous head and delete tail
	head = new_head;
	body.push_back(new_head);
	occupation_array[new_head.first][new_head.second]++;
	//pair<int, int> tail = body.front();
	if (map->snake_food == head)
		food_eaten = 1;
	else {
		pair<int, int> tail = body.front();
		occupation_array[tail.first][tail.second]--;
		body.erase(body.begin());
	}
	if ((occupation_array[new_head.first][new_head.second] > 1) || new_head.first == 0 || new_head.first == (MAP_HEIGHT-1) || new_head.second == 0 || new_head.second == (MAP_WIDTH-1))
		alive = false;


}

void Snake::update_direction(enum Direction direction)
{
	switch (direction)
	{
	case West:
		if (this->direction != East) 
		{
		    this->direction = direction;
		}
		break;
	case North:
		if (this->direction != South)
		{
		    this->direction = direction;
		}
		break;
	case East:
		if (this->direction != West)
		{
		    this->direction = direction;
		}
		break;
	case South:
		if (this->direction != North)
		{
		    this->direction = direction;
		}
		break;
	}
}
