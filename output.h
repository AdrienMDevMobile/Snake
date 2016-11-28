#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "board.h"

//A REMPLACER LORSQUE LA MAP SERA FAITE
#define ROWS 50
#define COLS 60

void gotoligcol( int lig, int col );

void print_map(board* map);
void create_test_map();

void print_interface();

void update_score(int score);
void update_lives(int lives);

#endif
