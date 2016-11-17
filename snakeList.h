#ifndef snakeList_H_INCLUDED
#define snakeList_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "snakePart.h"
#include "direction.h"

//TODO : Limit snake speed

typedef struct snakeList
{
    int length;

    /*First block of the tail of the snake */
    struct snakePart *snakeTail;

    /* Last snakePart is the head of the snake */
    struct snakePart *snakeHead;

    /*
    Speed : the speed in which the snake moves (4=slowest, 0=fastest)
    Countdown : decreases each frames, when it hits 0, the snake moves and the value resets
    Growth : by how many parts, must the snake move.
    */
    int speed, countdown, growth;

    /*   Direction : the direction (struct with x and y) */
    struct direction *direction;
} snakeList;


snakeList * createSnakeList(int x, int y, int direction, int speed);
//TODO
void addPartToList(snakeList *list, int x, int y);

/*
Returns to the game if the snake should move this frame, then decreases the countdown (or resets if cd = 0)
We also need to pass the pointer of the elements because we want to modify it.
*/
int shouldMove(snakeList *list, int *countdown);
//TODO
snakeList * moveList(snakeList *list);


//Later
void deletesnakeList(snakeList *list);

/* Change the direction the snake is going. It will apply to the next time, the Snake moves
Will use the static int north, south, east, west from direction.h */
snakeList * changeDirection(snakeList *list, int newDirection);

//TODO int getDirection(snakeList *list);

#endif // snakeList_H_INCLUDED
