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
#include "game.h"
#include "testAdrien.h"


int main()
{
    srand(time(NULL)); //Creates the randomness inside the program

    //testCreationTable();

    //testCreationSnake();

    //APPLE TEST
    //testCreationApple();

    //INPUT TEST
    //testInput();

    //OUTPUT TEST
    //create_test_map();

    //GAME TEST
    launch_game(0,0,3,0);

    return 1;
}

