#include "board.h"

board * initBoard(int doAddWall){
    /*Creates the board */
    board *toReturn=NULL;
    toReturn = malloc(sizeof(board));
    if (toReturn == NULL){exit(0);} /* Alocation failed */

   /* toReturn->boardTable = toReturn = malloc(sizeof(char[constLength][constHeight]));
    if (toReturn->boardTable == NULL){exit(0);} /* Alocation failed */

    int y=0;
    while(y < constHeight){
            int x = 0;
        while(x<constLength){
             toReturn->boardTable[y][x] = ' ';
             ++x;
        }
        ++y;
    }

    if(doAddWall) return addWall(toReturn);
    else return toReturn;
}


board * addWall(board * toReturn){
    /*TODO : Recuperer un tableau dans un fichier pour le charger */
    toReturn->boardTable[5][5] = '#';
    toReturn->boardTable[12][15] = '#';
    toReturn->boardTable[26][13] = '#';
    toReturn->boardTable[30][20] = '#';

    toReturn->boardTable[6][5] = '#';
    toReturn->boardTable[40][50] = '#';
    toReturn->boardTable[39][39] = '#';
    toReturn->boardTable[20][20] = '#';

    return toReturn;
}



char readSquare(board * currentBoard, int x, int y){
    if(x > constLength || y > constHeight) return charEmptyBloc;
    return currentBoard->boardTable[y][x];
}
