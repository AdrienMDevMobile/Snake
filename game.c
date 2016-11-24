#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "board.h"
#include "output.h"

void launch_game(int walls_on, int borders_on, int start_speed, int increasing_speed_on) {
    board *map = initBoard(1);
    print_map(map);
    //create_test_map(map);

    //Creates the snake in data and outputs it
    snakeList* snake = createSnakeList(1,5,west,start_speed);
    gotoligcol(get_snake_y(snake), get_snake_x(snake));
    printf("#");

    int old_position_x, old_position_y;

    while(1) {

        old_position_x = get_snake_x(snake);
        old_position_y = get_snake_y(snake);

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

        int allowed_to_move = canMove(snake, map);

        if(allowed_to_move) {
            //Gets back to where the snake was
            gotoligcol(old_position_y, old_position_x);
            printf(" ");
            setElementAtPosition(map, ' ', old_position_x, old_position_y);

            //Makes the snake move
            snake = moveList(snake);
            if(setElementAtPosition(map, '#', get_snake_x(snake), get_snake_y(snake))) {
                gotoligcol(get_snake_y(snake), get_snake_x(snake));
                printf("#");

                if(setElementAtPosition(map, ' ', snake->snakeTail->x, snake->snakeTail->y)) {
                    gotoligcol(snake->snakeTail->y, snake->snakeTail->x);
                    printf(" ");
                } else {
                    printf("Oho...");
                }

            } else {
                printf("Oho...");
            }
        }
    }
}

int canMove(snakeList *snake, board *map) {
    int canMove = 0;
    int position_x = get_snake_x(snake);
    int position_y = get_snake_y(snake);
    direction *dir = snake->direction;
    char nextSquare = readSquare(map, position_x+(dir->x), position_y+(dir->y));

    if(nextSquare != 35 && shouldMove(snake, &(snake->countdown)) ) {
        canMove = 1;
    }

    return canMove;
    return canMove;
}
