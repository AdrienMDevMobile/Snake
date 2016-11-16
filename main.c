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


int main()
{
    srand(time(NULL)); //Creates the randomness inside the program
    //testCreationSnake();

    //APPLE TEST
    /*
    apple *apple = init_apple();
    print_apple(apple);

    while(1) {
        if(_kbhit()) {
            int key = _getch();

            if(key == 27) {
                break;

            } else {
                apple = init_apple();
                print_apple(apple);
            }
        }
    }*/



    //-------------DON'T TOUCH : First shot at input-------------//

    /*
    snakeList *snake = createList(1, 1, south, 4);
    while(1) {

        if(_kbhit()) {

            int key = _getch();

            switch(key) {
                case KEY_SAVE: printf("Save :D\n"); break;
                case KEY_LOAD: printf("Load :O\n"); break;
                case KEY_QUIT: printf("Quit T_T\n"); break;
                case KEY_PAUSE: printf("Pause o.o\n"); break;
                case KEY_UP: printf("KEY UP!\n"); break;//Changer par changeDirection du Snake
                case KEY_DOWN: printf("KEY DOWN!\n"); break;
                case KEY_LEFT: printf("KEY LEFT!\n"); break;
                case KEY_RIGHT: printf("KEY RIGHT!\n"); break;
            }
        }

        //shouldMove(snake, snake->countdown);
        //moveList(snake);
        //gotoligcol(snake->x, snake->y);
    }*/
}

