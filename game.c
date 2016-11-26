#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void launch_game(int walls_on, int borders_on, int start_speed, int increasing_speed_on) {
    board *map = initBoard(1);
    print_map(map);
    //create_test_map(map);

    //Creates the snake in data and outputs it
    snakeList* snake = createSnakeList(1,5,west,start_speed);
    gotoligcol(get_snake_y(snake), get_snake_x(snake));
    printf("#");
    setElementAtPosition(map, '#', get_snake_x(snake), get_snake_y(snake));

    //Creates an apple in data and outputs it
    apple current_apple = create_new_apple(map);

    int old_position_x, old_position_y;
    direction *dir = snake->direction;

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

        dir = snake->direction;
        int allowed_to_move = canMove(snake, map);

        if(allowed_to_move) {

            //Checks if the next square is an apple. If so, adds a part to the snake.
            if(is_square_apple(map, old_position_x+(dir->x), old_position_y+(dir->y))) {
                //Erases the apple and adds a part to the snake
                setElementAtPosition(map, ' ', old_position_x+(dir->x), old_position_y+(dir->y));
                addPartToList(snake, snake->snakeTail->x, snake->snakeTail->y);

                //Creates a new apple and outputs it
                current_apple = create_new_apple(map);

                //Outputs the new part of the snake
                gotoligcol(get_snake_y(snake), get_snake_x(snake));
                printf("#");
            } else {
                //Makes the snake move
                snake = moveList(snake);
            }

            //Puts the character in the data table, and checks if it really did
            if(setElementAtPosition(map, '#', get_snake_x(snake), get_snake_y(snake))) {

                //Sets the cursor where the snake will be and output a character
                gotoligcol(get_snake_y(snake), get_snake_x(snake));
                printf("#");

                //Same logic to erase the tail
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
}

int is_square_apple(board *table, int pos_x, int pos_y) {
    int is_it_apple = 0;

    char square = readSquare(table, pos_x, pos_y);

    if(square == NORMAL_APPLE || square == SPECIAL_APPLE) {
        is_it_apple = 1;
    }

    return is_it_apple;
}

apple create_new_apple(board *table) {
    apple *current_apple = init_apple(table);
    setElementAtPosition(table, get_apple_type(current_apple), get_apple_pos_x(current_apple), get_apple_pos_y(current_apple));
    gotoligcol(get_apple_pos_y(current_apple), get_apple_pos_x(current_apple));
    printf("O");

    return *current_apple;
}
