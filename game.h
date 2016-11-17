#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

//CONSTANTS DEFINITIONS//
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "snakePart.h"
#include "snakeList.h"
#include "input_functions.h"

typedef struct game
{
    int *current_direction;
    char game_map [62][52];
    int *lives;
    int *speed;
    struct snakeList *snake;

}game;

void launch_game(int walls_on, int borders_on, int start_speed, int increasing_speed_on);//TODO: Ajouter la vue en param�tre//
struct snakeList init_snake(char game_map[62][52]);

#endif
