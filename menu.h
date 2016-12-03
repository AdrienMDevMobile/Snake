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

menu* set_walls_option(menu* menu);

menu* set_borders_option(menu* menu);

menu* set_start_speed(menu* menu);

menu* set_increasing_speed(menu* menu);


#endif // MENU_H_INCLUDED
