
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "snakeList.h"

//List of possible values return by the function readSquares
static char const charEmptyBloc=' ';
static char const charSnakePart='*';
static char const charWall='#';
static char const charApple='A';

//The dimension of the table at the creation has been written manually.
static int const constLength=50;
static int const constHeight=60;

typedef struct board {
    char** boardTable;
} board;

//Creates a new board
//addWall = boolean
board * initBoard(int addWall);

//Read a square in the board and returns what value is inside (following the norm defined above).
char readSquare(board * currentBoard, int x, int y);

//Add walls from a file to the board
board * addWall(board * toReturn, int numberTable);

#endif // BOARD_H_INCLUDED
