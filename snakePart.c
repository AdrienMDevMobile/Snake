#include <stdio.h>
#include <stdlib.h>

#include "snakePart.h"
/*
Returns the address of the snakePart after the snakePart given in parameter
*/
snakePart* nextSnakePart(snakePart *currentSnakePart){
    return currentSnakePart->nextSnakePart;
}

int getX(snakePart *currentSnakePart){return currentSnakePart->x;}
int getY(snakePart *currentSnakePart){return currentSnakePart->y;}

snakePart* createSnakePart(int x, int y){
    snakePart *toReturn = NULL;

    toReturn = malloc(sizeof(snakePart));
    if (toReturn == NULL) /*Allocation failed */
        {
            exit(0);
        }

    toReturn->x = x;
    toReturn->y = y;
    toReturn->nextSnakePart = NULL;

    return toReturn;
}

snakePart* createSnakePartBefore(int x, int y, snakePart *nextPart){
    snakePart *toReturn = createSnakePart(x, y);

    toReturn->nextSnakePart = nextPart;

    return toReturn;
}

snakePart* createSnakePartAfter(int x, int y, snakePart **pointerPrevPart){
       snakePart *toReturn = createSnakePart(x, y);

       *pointerPrevPart = toReturn;

       return toReturn;

}

void deleteSnakePart(snakePart *bl){
    if(bl->nextSnakePart != NULL) {
        deleteSnakePart(nextSnakePart(bl->nextSnakePart));
    }
    free(bl);
}

void addNextSnakePart(snakePart *pointer, snakePart *pointed){
    pointer->nextSnakePart = pointed;
}
