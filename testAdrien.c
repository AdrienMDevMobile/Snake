#include "testAdrien.h"

void testCreationSnake()
{
    printf("testa");
    snakeList *test = createList(1, 1, north, 4);
    //    addSnakePartToList(test, createSnakePart(1, 2));
    printf("testb \n");

    printf("%d",test->length);

    int i = 1;
    while(i<17){
        moveList(test);
        i++;

        if(8 == i){
            changeDirection(test, east);
        }

        if(11 == i){
            changeDirection(test, south);
        }

        if(14 == i){
            changeDirection(test, west);
        }

    printf("testc \n");

    snakePart * tmp = test->snakeTail;
    while(tmp != NULL){
        printf(" %d %d ",tmp->x, tmp->y);
        tmp = tmp->nextSnakePart;
    }

    }


    deletesnakeList(test);
    printf("Test");

    return 0;
}
