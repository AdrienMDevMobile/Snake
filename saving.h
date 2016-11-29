
#ifndef saving_H_INCLUDED
#define saving_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "game.h"

snakeList * readSaveSnake(FILE * file);
game * readSaveFile();
int readSaveLife(FILE * file);
#endif // snakeList_H_INCLUDED
