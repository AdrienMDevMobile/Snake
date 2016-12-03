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

menu* set_walls_option(menu* menu) {
    print_choice_user("Veuillez entrer O pour oui ou N pour non : ");

    char input = '.';
    int error = 0;
    int out = 0;
    do {
        //Afficher une erreur
        if(error) {
            print_choice_user("Erreur dans la donnee recuperee. Veuillez entrer O pour oui ou N pour non : ");
            error = 0;
        }

        if(kbhit()) {

            input = getch();

            switch(input) {
                case 'O':
                case 'o': menu->walls_on = 1; out = 1; break;
                case 'N':
                case 'n': menu->walls_on = 0; out = 1; break;
                case KEY_ESC: out = 1; break;
                default: error = 1; break;
            }
        }

    } while(!out);

    print_main_menu();
    print_options_menu();
    printf("%d", menu->walls_on);

    return menu;
}

menu* set_borders_option(menu* menu) {

}

menu* set_start_speed(menu* menu) {

}

menu* set_increasing_speed(menu* menu) {

}
