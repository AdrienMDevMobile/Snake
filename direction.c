#include <stdio.h>
#include <stdlib.h>

#include "direction.h"

direction* setNewDirection(int dir){
      /*Creates the direction */
    direction *toReturn = NULL;
    toReturn = malloc(sizeof(direction));
    if (toReturn == NULL){exit(0);} /* Allocation failed */

    if(dir == north){
        toReturn->x = 0;
        toReturn->y = 1;
    }
    else if(dir == east){
        toReturn->x = 1;
        toReturn->y = 0;
    }
    else if(dir == south){
        toReturn->x = 0;
        toReturn->y = -1;
    }
    else if(dir == west){
        toReturn->x = -1;
        toReturn->y = 0;
    }
    else { return NULL; }

    return toReturn;
}

int getDirection(direction *snakeDirection) {
    int direction = 0;

    if(snakeDirection->x == 0 && snakeDirection->y == 1){
        direction = north;
    }
    else if(snakeDirection->x == 1 && snakeDirection->y == 0){
        direction = east;
    }
    else if(snakeDirection->x == 0 && snakeDirection->y == -1){
        direction = south;
    }
    else if(snakeDirection->x == -1 && snakeDirection->y == 0){
        direction = west;
    }

    return direction;
}
