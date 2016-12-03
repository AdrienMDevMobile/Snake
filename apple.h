
#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define NORMAL_APPLE 'O'
#define SPECIAL_APPLE '*'

typedef struct apple
{
    int pos_x;
    int pos_y;
    int apple_type;
    int countdown;
    char apple_char;

}apple;

//Define the init of apple
struct apple *init_apple(board *table, int appleType);

//Define the setters and getters
int get_apple_pos_x(apple *currentApple);
int get_apple_pos_y(apple *currentApple);

int get_apple_type(apple *currentApple);
char get_apple_char(apple *currentApple);

int get_countdown(apple *currentApple);

void set_apple_pos_x(apple *currentApple, int x_to_set);
void set_apple_pos_y(apple *currentApple, int y_to_set);

//Define procedures to use the apple
int decrease_countdown(apple *currentApple);

#endif
