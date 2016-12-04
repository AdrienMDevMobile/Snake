#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "input_functions.h"

typedef struct menu {
    int walls_on;
    int borders_on;
    int start_speed;
    int increasing_speed_on;
    int main_choice;
    int option_choice;
} menu;

menu* init_menu();

//Functions to change the options of the game
menu* reverse_walls_option(menu* menu);

menu* reverse_borders_option(menu* menu);

menu* set_start_speed(menu* menu);

menu* reverse_increasing_speed(menu* menu);

//Function that reverses a boolean value. 0 to 1 and 1 to 0.
int reverse_boolean_value(int value);

//Increment/decrement for main_choice and option_choice
int increase_main_choice(menu* menu);
int decrease_main_choice(menu* menu);
int increase_options_choice(menu* menu);
int decrease_options_choice(menu* menu);

//Allows the program to determine what the user wants to do when enter key is hit
int define_user_choice(menu* menu);

//Allows the program to move the cursor
void moveCursorMainMenu(menu* menu, int pos_y);
void moveCursorOptionMenu(menu* menu, int pos_y);

//Starts the menus
void start_main_menu();
void start_option_menu(menu* menu);


#endif // MENU_H_INCLUDED
