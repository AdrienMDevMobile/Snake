#include "testKerian.h"

/*void testCreationApple() {

    apple *apple = init_apple();
    print_apple(apple);

    while(1) {
        if(_kbhit()) {
            int key = _getch();

            if(key == 27) {
                break;

            } else {
                apple = init_apple();
                print_apple(apple);
            }
        }
    }

}*/

void testInput() {

    snakeList *snake = createSnakeList(1, 1, south, 4);
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

        //shouldMove(snake, snake->countdown);
        //moveList(snake);
        //gotoligcol(snake->x, snake->y);
    }
}
