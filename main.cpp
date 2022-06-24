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
		map.draw();
		snake.update_movement(&map);
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
