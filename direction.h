#ifndef DIRECTION_H_INCLUDED
#define DIRECTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

static int const north = 1;
static int const east = 2;
static int const south = 3;
static int const west = 4;
static int const none_dir = 0;

typedef struct direction {
    int x;
    int y;
} direction;

direction * setNewDirection(int dir);
int getDirection(direction *snakeDirection);

#endif // DIRECTION_H_INCLUDED
