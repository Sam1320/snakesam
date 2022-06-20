#include <string>
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include "input.h"
#include "snake.h"
#include "map.h"

Snake snake;
Map map(&snake);
void start_game()
{
	while (snake.alive)
	{
		snake.update_movement(&map);
		map.draw();
		usleep(PAUSE_LENGTH);
	}
	std::cout << "GAME OVER!" << std::endl;	

	
};

int main()
{
    input_enter_off();
    start_game();
    return 0;
}
