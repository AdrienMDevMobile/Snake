#include "output.h"

//Move the cursor on one
void gotoligcol( int lig, int col ) {
    // ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void print_map(board* map) {
    gotoligcol(0,0);

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

void print_main_menu() {
    system("cls");

    gotoligcol(3,3);
    printf("Demarrer la partie");

    gotoligcol(5,3);
    printf("Options de la partie");

    gotoligcol(7,3);
    printf("Quitter le jeu");
}

void print_options_menu(menu* menu) {
    gotoligcol(5,26);
    printf("Mettre des bordures : %d", menu->borders_on);

    gotoligcol(7,26);
    printf("Mettre des murs : %d", menu->walls_on);

    gotoligcol(9,26);
    printf("Vitesse de depart du Snake : %d", menu->start_speed);

    gotoligcol(11,26);
    printf("Vitesse croissante : %d", menu->increasing_speed_on);
}

void print_game_interface(game * game) {
    gotoligcol(62,0);
    printf("Score: %i", game->score);

    gotoligcol(63,0);
    printf("Lives: %i", game->lives);
}

void print_cursor_main_menu(int choice) {
    switch(choice) {
        case 1: gotoligcol(3,2); printf("%c", CURSOR); break;
        case 2: gotoligcol(5,2); printf("%c", CURSOR); break;
        case 3: gotoligcol(7,2); printf("%c", CURSOR); break;
        default: break;
    }
}

void clear_cursor_main_menu(int choice) {
    switch(choice) {
        case 1: gotoligcol(3,2); printf(" "); break;
        case 2: gotoligcol(5,2); printf(" "); break;
        case 3: gotoligcol(7,2); printf(" "); break;
        default: break;
    }
}

void print_cursor_option_menu(int choice) {
    switch(choice) {
        case 1: gotoligcol(5,25); printf("%c", CURSOR); break;
        case 2: gotoligcol(7,25); printf("%c", CURSOR); break;
        case 3: gotoligcol(9,25); printf("%c", CURSOR); break;
        case 4: gotoligcol(11,25); printf("%c", CURSOR); break;
        default: break;
    }
}

void clear_cursor_option_menu(int choice) {
    switch(choice) {
        case 1: gotoligcol(5,25); printf(" "); break;
        case 2: gotoligcol(7,25); printf(" "); break;
        case 3: gotoligcol(9,25); printf(" "); break;
        case 4: gotoligcol(11,25); printf(" "); break;
        default: break;
    }
}

void print_choice_user(char* msg) {
    //Afficher une ligne à l'utilisateur
    system("cls");
    gotoligcol(3,3);
    printf("%s", msg);
    gotoligcol(4,3);
}

void update_score(int score) {
    gotoligcol(62,7);
    printf("%d", score);
}

void update_lives(int lives) {
    gotoligcol(63,7);
    printf("%d", lives);
}
