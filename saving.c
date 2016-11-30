#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "snakeList.h"


snakeList * readSaveSnake(FILE * file){

    snakeList * toReturn;

    char actualChar;
    int i; //counter


    //readNumber is a table that will contain characters of each numbers before will turn it into a Int variable.
    //Will be clensed each time.
    char * readNumber = NULL;

    //Gets the direction-----------------------------------------------------
    actualChar = fgetc(file); // Read the first character of the countdown '{'
    readNumber = (char*)malloc(sizeof(char)*10);
    i=0;
    do{
        actualChar = fgetc(file);
        readNumber[i] = actualChar;
        i++;
    }
    while(actualChar!='}');
    int direction = atoi(readNumber);
    //prinf(" %d ", direction);
    free(readNumber);

    //Gets the speed-----------------------------------------------------
    actualChar = fgetc(file); // Read the first character of the countdown '{'
    readNumber = (char*)malloc(sizeof(char)*10);
    i=0;
    do{
    actualChar = fgetc(file);
    readNumber[i] = actualChar;
    i++;
    }
    while(actualChar!='}');
    int speed = atoi(readNumber);
    ////prinf(" %d ", speed);
    free(readNumber);


    //Gets the countdown--------------------------------------------------
    actualChar = fgetc(file); // Read the first character of the countdown '{'
    readNumber = (char*)malloc(sizeof(char)*10);
    i=0;
    do{
    actualChar = fgetc(file);
    readNumber[i] = actualChar;
    i++;
    }
    while(actualChar!='}');
    int countdown = atoi(readNumber);
    //prinf(" %d ", countdown);
    free(readNumber);

    //Gets the growth-----------------------------------------------------
    actualChar = fgetc(file); // Read the first character of the countdown '{'
    readNumber = (char*)malloc(sizeof(char)*10);
    i=0;
    do{
    actualChar = fgetc(file);
    readNumber[i] = actualChar;
    i++;
    }
    while(actualChar!='}');
    int growth = atoi(readNumber);
    //prinf(" %d ", growth);
    free(readNumber);

    //TODO : The length of the snake must be updated each new block.
    //Gets each parts of the snake.----------------------------------------------------------
    //{x, y}
    int numberBlock = 0;
    actualChar = fgetc(file); // Read the first character of the snake '{'
    actualChar = fgetc(file); // Read the first character of the snake_part '{'
    do{

    //Gets x
    readNumber = (char*)malloc(sizeof(char)*10);
    //char readNumber = char[10];
    i = 0;
    do{
        actualChar = fgetc(file);
        readNumber[i] = actualChar;
        i++;
    }
    while(actualChar != ',');
    int x = atoi(readNumber);
    free(readNumber);


    //Gets y
    i = 0;
    readNumber = (char*)malloc(sizeof(char)*10);
    do{
        actualChar = fgetc(file);
        readNumber[i] = actualChar;
        i++;
    }
    while( actualChar != '}' );
    int y = atoi(readNumber);
    free(readNumber);

    if(numberBlock == 0){
            toReturn = createSnakeList(x, y, direction, speed);
            toReturn = setGrowth(toReturn, growth);
    }
    else {
        addPartToList(toReturn, x, y);
    }
    numberBlock++;

    //printf(" %d %d ", x, y);

    actualChar = fgetc(file);
    /*
    Read the character at the end of the snake Part.
    If it is '}' that means the end of the snake_List
    If that is '{' that means there is another snakePart after
    */
    }
    while(actualChar !='}');


    return toReturn;
}

int readSaveLife(FILE * file){
    //Gets the direction-----------------------------------------------------
    char actualChar = fgetc(file); // Read the first character of the countdown '('
    char * readNumber = (char*)malloc(sizeof(char)*10);
    int i=0;
    do{
        actualChar = fgetc(file);
        readNumber[i] = actualChar;
        i++;
    }
    while(actualChar!=')');
    int life = atoi(readNumber);
    //prinf(" %d ", direction);
    free(readNumber);

    return life;
}


game * readSaveFile(){

    FILE* file = NULL;

    file = fopen("./Save/save.txt", "r");

    if (file != NULL)
    {
        snakeList * newSnake = readSaveSnake(file);

        int life = readSaveLife(file);

        char actualChar = fgetc(file); //Reads the \n in front of the board.
        board * newBoard = initBoard(0, 0);
        newBoard = loadBoard(newBoard, file);

        game * toReturn = init_game(newSnake, newBoard, life);


      //  readSaveSnake(file);
        fclose(file); // On ferme le fichier qui a été ouvert
        return toReturn;
    }
    else {
        //prinf("Error reading file");
        return NULL;
    }
}
