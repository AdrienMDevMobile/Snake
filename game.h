#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

//CONSTANTS DEFINITIONS//
#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "snakePart.h"
#include "snakeList.h"
#include "input_functions.h"
#include "apple.h"
#include "board.h"

#define SNAKE_CHAR '#'

typedef struct game
{
    board* game_map;
    int lives;
    struct snakeList *snake;

}game;

game *init_game(snakeList  * snake, board * map, int lives);
void launch_game(int walls_on, int borders_on, int start_speed, int increasing_speed_on, game* game);//TODO: Ajouter la vue en paramètre//
struct snakeList init_snake(char game_map[62][52]);
int canMove(snakeList *snake, board *map);
int is_square_apple(board *table, int pos_x, int pos_y);
apple* create_new_apple(board *table);
void update_snake_data_output(game* game);

#endif
