#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "snakePart.h"
#include "linked_list.h"
#include "direction.h"
#include "input_functions.h"

int main()
{
    srand(time(NULL)); //Creates the randomness inside the program

    //TEST ADRIEN
    printf("testa");
    linkedList *test = createList(1, 1, south, 4);
    //    addSnakePartToList(test, createSnakePart(1, 2));
    printf("testb \n");

    printf("%d",test->length);

    int i = 1;
    while(i<7){
        moveList(test);
        i++;
    }
    printf("testc \n");

    snakePart * tmp = test->snakeTail;
    while(tmp != NULL){
        printf(" %d %d ",tmp->x, tmp->y);
        tmp = tmp->nextSnakePart;
    }


    deleteLinkedList(test);
    printf("Test");

    return 0;

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
    linkedList *snake = createList(1, 1, south, 4);
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

        shouldMove(snake, snake->countdown);
        moveList(snake);
    }*/
}

