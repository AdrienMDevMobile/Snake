#include "menu.h"

menu* init_menu() {
    menu *toReturn = NULL;

    toReturn = malloc(sizeof(menu));
    if (toReturn == NULL) /*Allocation failed */
        {
            exit(0);
        }

    toReturn->walls_on = 0;
    toReturn->borders_on = 0;
    toReturn->start_speed = 3;
    toReturn->increasing_speed_on = 0;
    toReturn->main_choice = 1;
    toReturn->option_choice = 1;

    print_main_menu();

    return toReturn;
}

menu* reverse_walls_option(menu* menu) {
    menu->walls_on = reverse_boolean_value(menu->walls_on);

    print_main_menu();
    print_options_menu(menu);

    return menu;
}

menu* reverse_borders_option(menu* menu) {
    menu->borders_on = reverse_boolean_value(menu->borders_on);

    print_main_menu();
    print_options_menu(menu);

    return menu;
}

menu* set_start_speed(menu* menu) {
    print_choice_user("Veuillez entrer une valeur de 1 à 5 : ");

    char input = '.';
    int error = 0;
    int out = 0;
    do {
        //Afficher une erreur
        if(error) {
            print_choice_user("Erreur dans la donnee recuperee. Veuillez entrer une valeur de 1 à 5 : ");
            error = 0;
        }

        if(kbhit()) {

            input = getch();

            switch(input) {
                case '1': menu->start_speed = 1; out = 1; break;
                case '2': menu->start_speed = 2; out = 1; break;
                case '3': menu->start_speed = 3; out = 1; break;
                case '4': menu->start_speed = 4; out = 1; break;
                case '5': menu->start_speed = 5; out = 1; break;
                case KEY_ESC: out = 1; break;
                default: error = 1; break;
            }
        }

    } while(!out);

    print_main_menu();
    print_options_menu(menu);

    return menu;
}

menu* reverse_increasing_speed(menu* menu) {
    menu->increasing_speed_on = reverse_boolean_value(menu->increasing_speed_on);

    print_main_menu();
    print_options_menu(menu);

    return menu;
}

int reverse_boolean_value(int value) {
    switch(value) {
        case 0: value = 1; break;
        case 1: value = 0; break;
        default: value = 0; break;
    }

    return value;
}

int increase_main_choice(menu* menu) {
    menu->main_choice++;

    return menu->main_choice;
}

int decrease_main_choice(menu* menu) {
    menu->main_choice--;

    return menu->main_choice;
}

int increase_options_choice(menu* menu) {
    menu->option_choice++;

    return menu->option_choice;
}

int decrease_options_choice(menu* menu) {
    menu->option_choice--;

    return menu->option_choice;
}

int define_user_choice(menu* menu) {
    game* game = init_game(NULL, NULL, NULL, 3, 0, menu->walls_on, menu->borders_on);
    switch(menu->main_choice) {
        case 1: launch_game(menu->start_speed, menu->increasing_speed_on, game); break;
        case 2: start_option_menu(menu); break;
        case 3: exit(0); break;
    }
}

int define_user_option(menu* menu) {
    switch(menu->option_choice) {
        case 1: reverse_borders_option(menu); break;
        case 2: reverse_walls_option(menu); break;
        case 3: set_start_speed(menu); break;
        case 4: reverse_increasing_speed(menu); break;
    }
}

void moveCursorMainMenu(menu* menu, int pos_y) {
    int tmp_choice = menu->main_choice + pos_y;

    //Checks if the choice is valid. If so, clears the cursor and prints it elsewhere
    if(tmp_choice > 0 && tmp_choice < 4) {
        clear_cursor_main_menu(menu->main_choice);
        menu->main_choice += pos_y;
        print_cursor_main_menu(menu->main_choice);
    }
}

void moveCursorOptionMenu(menu* menu, int pos_y) {
    int tmp_choice = menu->option_choice + pos_y;

    //Checks if the choice is valid. If so, clears the cursor and prints it elsewhere
    if(tmp_choice > 0 && tmp_choice < 5) {
        clear_cursor_option_menu(menu->option_choice);
        menu->option_choice += pos_y;
        print_cursor_option_menu(menu->option_choice);
    }
}

void start_main_menu() {
    menu* menu = init_menu();
    int out = 0;
    int key;

    print_main_menu();
    print_cursor_main_menu(menu->main_choice);

    while(!out) {

        if(kbhit()) {
            key = getch();

            switch(key) {
                case KEY_ENTER: define_user_choice(menu); break;
                case KEY_UP: moveCursorMainMenu(menu, -1); break;//Changer par changeDirection du Snake
                case KEY_DOWN: moveCursorMainMenu(menu, 1); break;
            }
        }

    }
}

void start_option_menu(menu* menu) {
    int out = 0;
    int key;

    print_options_menu(menu);
    print_cursor_option_menu(menu->option_choice);

    while(!out) {

        if(kbhit()) {
            key = getch();

            switch(key) {
                case KEY_ESC: print_main_menu(); print_cursor_main_menu(menu->main_choice); out = 1; break;
                case KEY_ENTER: define_user_option(menu); break;
                case KEY_UP: moveCursorOptionMenu(menu, -1); break;//Changer par changeDirection du Snake
                case KEY_DOWN: moveCursorOptionMenu(menu, 1); break;
            }
        }

    }
}
