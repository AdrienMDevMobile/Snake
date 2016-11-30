#ifndef  TEST_ADRIEN_H_INCLUDED
#define  TEST_ADRIEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "output.h"

#include "apple.h"
#include "snakePart.h"
#include "snakeList.h"
#include "direction.h"
#include "input_functions.h"
#include "board.h"

void testCreationSnake();
void testCreationTable();
void testCreationSave(board *test);
void testCreationSaveSnake(snakeList *test);

#endif // TEST_ADRIEN_H ENDS
