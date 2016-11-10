#include <stdio.h>
#include <stdlib.h>


#include "linked_list.h"
#include "direction.h"

/*
Create the linked list
Contains five parts    */
linkedList * createList(int x, int y, int direction, int speed){

    /*Creates the list */
    linkedList *toReturn = NULL;
    toReturn = malloc(sizeof(linkedList));
    if (toReturn == NULL){exit(0);} /* Alocation failed */
    toReturn->length = 1;

    /*Creates the head block */
    snakePart *s = createSnakePart(x, y);
    toReturn->snakeHead = s;
    toReturn->snakeTail = s;

    /* Initialize the direction, the speed, the countdown, the growth of the snake */
    toReturn->speed = speed;
    toReturn->direction = newDirection(direction);
    toReturn->countdown = speed;
    toReturn->growth = 4;

    return toReturn;
}

/* Destroy the linked list */
//TODO : Eliminer les elements un à un.
void deleteLinkedList(linkedList *list){
    free(list);
}

void addPartToList(linkedList *list, int x, int y){
    snakePart *s = createSnakePartBefore(x, y, list->snakeTail);
    list->snakeTail = s;
    list->length++;
}


int getLength(linkedList *list){
    return list->length;
}

int shouldMove(linkedList *list, int * countdown){
    if(countdown == 0) {
        *countdown = list->speed;
        return 1;
    }
    else {
       *countdown--;
        return 0;
    }
}
linkedList * moveList(linkedList *list){

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

/*
direction * getDirection(linkedList *list){
    return list->direction;
}
*/
