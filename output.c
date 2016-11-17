#include "output.h"

//Move the cursor on one
void gotoligcol( int lig, int col ) {
       // ressources
       /*COORD mycoord;

       mycoord.X = col;
       mycoord.Y = lig;
       SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );*/
}

//A TERME, CETTE FONCTION DOIT AVOIR UN TABLEAU DE CARACTERES EN PARAMETRE
void print_map(char **map, int map_size) {

    //Get number of columns and rows
    int num_rows = ROWS;
    int num_cols = COLS;

    //Iterators of the map for columns and rows
    int row_iterator_map;
    int col_iterator_map;

    for(col_iterator_map = 0; col_iterator_map<num_cols; col_iterator_map++) {
        for(row_iterator_map = 0; row_iterator_map<num_rows; row_iterator_map++) {
            printf("%c ", map[row_iterator_map][col_iterator_map]);
        }
        printf("\n");
    }
}

//JUSTE UNE FONCTION DE TEST LE TEMPS D'AVOIR LE TABLEAU
char** create_test_map() {

    //TEST DE TABLEAU POUR LA MAP
    char** map = (char**)malloc(ROWS*sizeof(char*));
    for(int i = 0; i<ROWS; i++)
        map[i] = (char*)malloc(COLS*sizeof(char));

    int num_cols = COLS;
    int num_rows = ROWS;

    //Iterators of the map for columns and rows
    int row_iterator_map;
    int col_iterator_map;

    for(col_iterator_map = 0; col_iterator_map<num_cols; col_iterator_map++) {
        for(row_iterator_map = 0; row_iterator_map<num_rows; row_iterator_map++) {
            if(col_iterator_map == 0 || col_iterator_map == num_cols-1 || row_iterator_map == 0 || row_iterator_map == num_rows-1) {
                map[row_iterator_map][col_iterator_map] = '#';

            } else {
                map[row_iterator_map][col_iterator_map] = ' ';
            }
        }
    }

    /*printf("%d\n",sizeof(map));
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<5; j++) {
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }*/


    return map;
}
