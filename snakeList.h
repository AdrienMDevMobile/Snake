#ifndef snakeList_H_INCLUDED
#define snakeList_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "snakePart.h"
#include "direction.h"

//Multiplier = multiplier of the speed to get the number of frames that the snake must wait before moving.
static int const multiplier=500;

typedef struct snakeList
{
    int length;

    /*First block of the tail of the snake */
    struct snakePart *snakeTail;

    /* Last snakePart is the head of the snake */
    struct snakePart *snakeHead;

    /*
    Speed : the speed in which the snake moves (5=slowest, 1=fastest)
    */
    int speed;

    /*
    Countdown : decreases each frames, when it hits 0, the snake moves and the value resets
    Growth : by how many parts, must the snake move.
    */
    int countdown, growth;

    /*    Direction : the direction (struct with x and y) */
    struct direction *direction;
} snakeList;


snakeList * createSnakeList(int x, int y, int direction, int speed);
/* Add a snakePart to the snakeList. That function is only used by createSnakeList and moveList */
void addPartToList(snakeList *list, int x, int y);

/*
Returns to the game if the snake should move this frame, then decreases the countdown (or resets if cd = 0)
We also need to pass the pointer of the elements because we want to modify it.
*/
int shouldMove(snakeList *list, int *countdown);
/* Move the list */
snakeList * moveList(snakeList *list);


/* Delete every sub element of the list and delete the list itself */
void deletesnakeList(snakeList *list);

/* Change the direction the snake is going. It will apply to the next time, the Snake moves
Will use the static int north, south, east, west from direction.h */
snakeList * changeDirection(snakeList *list, int newDirection);
snakeList * changeSpeed(snakeList *list, int newSpeed);

/* Getters of the head coordinates */
int get_snake_x(snakeList *snake);
int get_snake_y(snakeList *snake);

char * toString(snakeList *snake);

int getGrowth(snakeList *snake);
snakeList * setGrowth(snakeList *snake, int growth);
#endif // snakeList_H_INCLUDED
