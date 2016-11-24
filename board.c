#include "board.h"

board * initBoard(int doAddWall){
    /*Creates the board */
    board *toReturn=NULL;
    toReturn = malloc(sizeof(board));
    if (toReturn == NULL){exit(0);} /* Alocation failed */

    char** tab = (char**)malloc(constHeight*sizeof(char*));
    for(int i=0;i<constHeight;i++)
        tab[i]=(char*)malloc(constLength*sizeof(char));
   /* toReturn->boardTable = toReturn = malloc(sizeof(char[constLength][constHeight]));
    if (toReturn->boardTable == NULL){exit(0);} /* Alocation failed */

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
   // if(doAddWall) return addWall(toReturn);
    return toReturn;
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

int setElementAtPosition(board *table, char element, int position_x, int position_y) {
    int check_state = 1;

    if(position_x < constLength && position_y < constHeight) {
        table->boardTable[position_y][position_x] = element;
    } else {
        check_state = 0;
    }
}
