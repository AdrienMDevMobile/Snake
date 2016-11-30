#include <stdlib.h>
#include <stdio.h>
#include "board.h"

board * initBoard(int doAddWall, int addBorder){
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
            if((addBorder == 1) && (y == constHeight-1 || y == 0 || x == 0 || x == constLength-1)) {
                tab[y][x] = '#';
            } else {
                tab[y][x] = ' ';
            }
                ++x;
            }
                ++y;
        }


    toReturn->boardTable = tab;

    if(doAddWall == 1){
         toReturn = addWall(toReturn, 1);
    }

    return toReturn;
}

board * addWall(board * toReturn, int numberTable){
    FILE* file = NULL;
    //If file is null, it is called by the add wall function.
    //If it is not null, it is called by the load saved game function.


    char nameFile[80];

    char num[2];
    sprintf(num, "%d", numberTable);

    strcat(nameFile, "./Table/table");

    strcat(nameFile, num);
    strcat (nameFile,".txt");

    file = fopen(nameFile, "r");

    return loadBoard(toReturn, file);
}

board * loadBoard(board * toReturn, FILE * file){

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
            }
            else {
                if(actualChar != ' '){
                    toReturn->boardTable[y][x] = actualChar;
                }
                x++;
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

int setElementAtPosition(board *table, char element, int position_x, int position_y) {
    int check_state = 1;

    if(position_x < constLength && position_y < constHeight) {
        table->boardTable[position_y][position_x] = element;
    } else {
        check_state = 0;
    }
}
