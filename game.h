#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "snakePart.h"
#include "snakeList.h"
#include "input_functions.h"
#include "apple.h"
#include "board.h"

//CONSTANTS DEFINITIONS//
#define SNAKE_CHAR '#'

typedef struct game
{
    board* game_map;
    int lives;
    struct snakeList *snake;
    int score;
    apple* apple;

}game;

//Initialize the game. Takes all of what will compose the game, as well as two options needed to create a board if needed
game* init_game(snakeList * snake, board * map, apple * newApple, int lives,int score,  int walls_on, int borders_on);

//Function that launches and organizes the game until it ends
void launch_game(int start_speed, int increasing_speed_on, game* game);

//Functions to check data during the game
int canMove(snakeList *snake, board *map);
int is_square_apple(board *table, int pos_x, int pos_y);
apple* create_new_apple(board *table);

//Function that outputs the snake as well as setting it right in the data board
void update_snake_data_output(game* game);

#endif
