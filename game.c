#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void launch_game(int walls_on, int borders_on, int start_speed, int increasing_speed_on) {
    create_test_map();

    //Creates the snake in data and outputs it
    snakeList* snake = createList(5,5,south,start_speed);
    gotoligcol(get_snake_x(snake), get_snake_y(snake));
    printf("#");

    while(1) {

        if(_kbhit()) {

            int key = _getch();

            switch(key) {
                case KEY_SAVE: printf("Save :D\n"); break;
                case KEY_LOAD: printf("Load :O\n"); break;
                case KEY_QUIT: printf("Quit T_T\n"); break;
                case KEY_PAUSE: printf("Pause o.o\n"); break;
                case KEY_UP: changeDirection(snake, north); break;//Changer par changeDirection du Snake
                case KEY_DOWN: changeDirection(snake, south); break;
                case KEY_LEFT: changeDirection(snake, west); break;
                case KEY_RIGHT: changeDirection(snake, east); break;
            }
        }

        int canMove = shouldMove(snake, snake->countdown);

        if(canMove) {
            //Gets back to where the snake was
            gotoligcol(get_snake_x(snake), get_snake_y(snake));
            printf(" ");

            //Makes the snake move
            snake = moveList(snake);
            gotoligcol(get_snake_x(snake), get_snake_y(snake));
            printf("#");
        }
    }
}
