#include <stdio.h>
#include <stdlib.h>

#include "snakePart.h"
#include "linked_list.h"
#include "direction.h"

int main()
{
    printf("testa");
    linkedList *test = createList(1, 1, north, 4);
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


    //deleteLinkedList(test);
    printf("Test");

    return 0;
}

