#include "output.h"

//Move the cursor on one
void gotoligcol( int lig, int col ) {
       // ressources
       COORD mycoord;

       mycoord.X = col;
       mycoord.Y = lig;
       SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

//A TERME, CETTE FONCTION DOIT AVOIR UN TABLEAU DE CARACTERES EN PARAMETRE
void print_map(board* map) {

    //Get number of columns and rows
    int num_rows = ROWS;
    int num_cols = COLS;

    char** table = map->boardTable;

    //Iterators of the map for columns and rows
    int row_iterator_map;
    int col_iterator_map;

    for(col_iterator_map = 0; col_iterator_map<num_cols; col_iterator_map++) {
        for(row_iterator_map = 0; row_iterator_map<num_rows; row_iterator_map++) {
            printf("%c", table[col_iterator_map][row_iterator_map]);
        }
        printf("\n");
    }
}

//JUSTE UNE FONCTION DE TEST LE TEMPS D'AVOIR LE TABLEAU
void create_test_map() {

    //TEST DE TABLEAU POUR LA MAP
    char** map = (char**)malloc(ROWS*sizeof(char*));
    int i;
    for(i = 0; i<ROWS; i++)
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

    //print_map(map, sizeof(map));

}

void print_main_menu() {
    system("cls");
    gotoligcol(3,0);
    printf("Démarrer la partie");
    gotoligcol(5,0);
    printf("Options de la partie");
    gotoligcol(7,0);
    printf("Quitter le jeu");
}

void print_options_menu() {
    gotoligcol(3,0);
    printf("Mettre des bordures : ");
    gotoligcol(7,0);
    printf("Mettre des murs : ");
    gotoligcol(5,0);
    printf("Vitesse de départ du Snake : ");
    gotoligcol(7,0);
    printf("Vitesse croissante : ");
}

void print_game_interface() {
    gotoligcol(62,0);
    printf("Score: 0");
    gotoligcol(63,0);
    printf("Lives: 3");
}

void update_score(int score) {
    gotoligcol(62,7);
    printf("%d", score);
}

void update_lives(int lives) {
    gotoligcol(63,7);
    printf("%d", lives);
}
