// input.cpp
// Created by sam on 21.03.22.
//
#include <iostream>  // for std
#include <termios.h> // for ICANON and termios
#include <unistd.h>  // for STDIN_FILENO
#include <bitset>

struct termios t;
int main()
{
    tcgetattr(STDIN_FILENO, &t); 
    t.c_lflag &= ~ICANON;                   // disable canonical mode (input is available immediately)
    t.c_lflag &= ~ECHO;                     // dont print back input chars to the stdout
    tcsetattr(STDIN_FILENO, TCSANOW, &t);   // make sure changes take effect immediately
   
    while (1) 
    {
        char user_input = getchar();
    }
    return 0;
}

