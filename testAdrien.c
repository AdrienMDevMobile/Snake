#include "testAdrien.h"

void testCreationSnake()
{
    printf("testa");
    snakeList *test = createList(1, 1, south, 4);
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


    deletesnakeList(test);
    printf("Test");

    return 0;
}
