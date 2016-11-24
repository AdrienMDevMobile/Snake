#include <stdlib.h>
#include <stdio.h>
#include "board.h"

board * initBoard(int doAddWall){
    /*Creates the board */
    board *toReturn=NULL;
    toReturn = malloc(sizeof(board));
    if (toReturn == NULL){exit(0);} /* Alocation failed */

    char** tab = (char**)malloc(constHeight*sizeof(char*));
    int i;
    for(i=0;i<constHeight;i++)
        tab[i]=(char*)malloc(constLength*sizeof(char));


    int y=0;
    while(y < constHeight){
        int x = 0;
        while(x<constLength){
             //toReturn->boardTable[y][x] = ' ';
             if(y == constHeight-1 || y == 0 || x == 0 || x == constLength-1) {
                tab[y][x] = '#';
             } else {
                tab[y][x] = ' ';
             }
             ++x;
        }
        ++y;
    }

    board* res = (board*)malloc(sizeof(board));
    res->boardTable = tab;

    if(doAddWall) toReturn =  addWall(toReturn, 1);
    return toReturn;
}


board * addWall(board * toReturn, int numberTable){
    FILE* file = NULL;
    char nameFile[80];

    char num[2];
    sprintf(num, "%d", numberTable);


    /*char *bob = {numberTable, '\0'};
    printf("a"); */
    strcat(nameFile, "./table/table");

    strcat(nameFile, num);
    strcat (nameFile,".txt");

    file = fopen(nameFile, "r");

    if (file != NULL)
    {
        char actualChar;

        int x = 0; int y = 0;
        do
        {
            actualChar = fgetc(file); // On lit le caractère
            if(actualChar=='\n'){
                y++;
                x=0;
                //printf("y: %d ", y);
            }
            else {
                if(actualChar != ' '){
                    toReturn->boardTable[y][x] = actualChar;
                }
                x++;
                //printf("x : %d ", x);
            }

        }
        while (actualChar != EOF);

        fclose(file); // On ferme le fichier qui a été ouvert
    }

    return toReturn;
}



char readSquare(board * currentBoard, int x, int y){
    if(x > constLength || y > constHeight) return charEmptyBloc;
    return currentBoard->boardTable[y][x];
}
