
#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

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
struct apple *init_apple();

//Define the setters and getters
int get_apple_pos_x(apple *currentApple);
int get_apple_pos_y(apple *currentApple);

int get_apple_type(apple *currentApple);

int get_countdown(apple *currentApple);

void set_apple_pos_x(apple *currentApple, int x_to_set);
void set_apple_pos_y(apple *currentApple, int y_to_set);

//Define procedures to use the apple
void decrease_countdown(apple *currentApple);

void print_apple(apple *currentApple);

#endif
