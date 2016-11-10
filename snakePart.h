#ifndef SNAKEPART_H_INCLUDED
#define SNAKEPART_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct snakePart
{
    int x;
    int y;
    struct snakePart *nextSnakePart;
}snakePart;

int getX(snakePart *currentSnakePart);
int getY(snakePart *currentSnakePart);

snakePart* nextSnakePart(snakePart *currentSnakePart);

/*Create snake part, is used by the two following functions */
snakePart* createSnakePart(int x, int y);
/* Create a new part in front of the one given. The new one will point to the old one */
snakePart* createSnakePartBefore(int x, int y, snakePart *nextPart);
/* Create a new part behind the one given. The old one will point to the new one */
snakePart* createSnakePartAfter(int x, int y, snakePart **pointerPrevPart);
void deleteSnakePart(snakePart *bl);

void addNextSnakePart(snakePart *pointer, snakePart *pointed);

#endif // SNAKEPART_H_INCLUDED
