#include "input.h"
#include <termios.h>	// for tcgettatr, ICNANON...
#include <iostream>	// for cout, endl
#include <unistd.h>     // for STDIN_FILENO


struct termios t;

void input_enter_off()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

enum Direction get_input()
{
    enum Direction result = East;
    char user_input = getchar();
    switch (user_input) 
    {
	case 'a':
	    result = West;
	    break; 
	case 'w':
	    result = North;
	    break; 
	case 'd':
	    result = East;
	    break; 
	case 's':
	    result = South;
	    break; 
	default:
	    result = Error;
	    std::cout << "Incorrect button pressed(:" << user_input << ")" << std::endl;
	    break;
    }
    return result;

}


