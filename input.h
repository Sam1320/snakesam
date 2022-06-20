#ifndef _input_h
#define _input_h

enum Direction {
	North = 0,
	East  = 1,
	South = 2,
	West  = 3,
	Error = -1
};
void input_enter_off(void);
enum Direction get_input(void);
#endif
