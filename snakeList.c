#include <stdio.h>
#include <stdlib.h>


#include "snakeList.h"
#include "direction.h"

/*
Create the linked list
Contains five parts    */
snakeList * createSnakeList(int x, int y, int direction, int speed){

    /*Creates the list */
    snakeList *toReturn = NULL;
    toReturn = malloc(sizeof(snakeList));
    if (toReturn == NULL){exit(0);} /* Alocation failed */
    toReturn->length = 1;

    /*Creates the head block */
    snakePart *s = createSnakePart(x, y);
    toReturn->snakeHead = s;
    toReturn->snakeTail = s;

    /* Initialize the direction, the speed, the countdown, the growth of the snake */
    toReturn->speed = speed;
    toReturn->direction = setNewDirection(direction);
    toReturn->countdown = speed;
    toReturn->growth = 4;

    return toReturn;
}

/* Destroy the linked list */
//TODO : Eliminer les elements un à un.
void deletesnakeList(snakeList *list){
    deleteSnakePart(list->snakeTail);
    free(list);
}

void addPartToList(snakeList *list, int x, int y){
    snakePart *s = createSnakePartBefore(x, y, list->snakeTail);
    list->snakeTail = s;
    list->length++;
}


int getLength(snakeList *list){
    return list->length;
}

int shouldMove(snakeList *list, int * countdown){
    if(countdown == 0) {
        *countdown = list->speed;
        return 1;
    }
    else {
       *countdown--;
        return 0;
    }
}

snakeList * moveList(snakeList *list){

    if(list->growth > 0){
        snakePart* newPart = createSnakePartAfter(list->snakeHead->x + list->direction->x,
                             list->snakeHead->y + list->direction->y,
                             &list->snakeHead->nextSnakePart);
        list->snakeHead = newPart;

        list->growth--;
    }
    else {
        /*We change the x and y of the last element that will then be placed at the head of the snake */
        list->snakeTail->x = list->snakeHead->x + list->direction->x;
        list->snakeTail->y = list->snakeHead->y + list->direction->y;

        /*Placing the previously last block (head) at the second to last position */
        list->snakeHead->nextSnakePart = list->snakeTail;
        /* Placing the previously first bloc (tail) at the end */
        list->snakeHead = list->snakeTail;
        /*Placing the previously second block at the first place (tail) */
        list->snakeTail = list->snakeTail->nextSnakePart;

        list->snakeHead->nextSnakePart = NULL;
    }

    return list;
}


snakeList * changeDirection(snakeList *list, int newDirection) {
    list->direction = setNewDirection(newDirection);
    return list;
}
/*
direction * getDirection(snakeList *list){
    return list->direction;
}
*/
