#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "board.h"
#include "game.h"
#include "menu.h"

//A REMPLACER LORSQUE LA MAP SERA FAITE
#define ROWS 50
#define COLS 60

void gotoligcol( int lig, int col );

void print_map(board* map);
void create_test_map();

//Prints interface in the console
void print_game_interface();
void print_main_menu();
void print_options_menu(struct menu* menu);

//Updates data during the game
void update_score(int score);
void update_lives(int lives);

//Asks the user for a choice.
void print_choice_user(char* msg);

#endif
