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
