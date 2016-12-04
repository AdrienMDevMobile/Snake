#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "output.h"

#define KEY_ESC 21

typedef struct menu {
    int walls_on;
    int borders_on;
    int start_speed;
    int increasing_speed_on;
} menu;

menu* init_menu();

//Functions to change the options of the game
menu* reverse_walls_option(menu* menu);

menu* reverse_borders_option(menu* menu);

menu* set_start_speed(menu* menu);

menu* reverse_increasing_speed(menu* menu);

//Function that reverses a boolean value. 0 to 1 and 1 to 0.
int reverse_boolean_value(int value);


#endif // MENU_H_INCLUDED
