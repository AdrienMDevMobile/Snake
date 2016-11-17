#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//A REMPLACER LORSQUE LA MAP SERA FAITE
#define ROWS 50
#define COLS 60

void gotoligcol( int lig, int col );

void print_map(char **map, int map_size);
void create_test_map();

#endif
