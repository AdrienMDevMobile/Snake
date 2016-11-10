#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "snakePart.h"
#include "direction.h"

//TODO : Limit snake speed

typedef struct linkedList
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
} linkedList;


linkedList * createList(int x, int y, int direction, int speed);
//TODO
void addPartToList(linkedList *list, int x, int y);

/*
Returns to the game if the snake should move this frame, then decreases the countdown (or resets if cd = 0)
We also need to pass the pointer of the elements because we want to modify it.
*/
int shouldMove(linkedList *list, int *countdown);
//TODO
linkedList * moveList(linkedList *list);


//Later
void deleteLinkedList(linkedList *list);

//TODO int getDirection(linkedList *list);

#endif // LINKED_LIST_H_INCLUDED
