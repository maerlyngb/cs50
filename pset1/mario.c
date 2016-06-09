/*
    Author: Maerlyn Broadbent
    Created: 5th June 2016

    Purpose: CS50 Introduction to Computer Science, Problem Set 1
*/

#include <stdio.h>
#include <cs50.h>


void print_pyramid(int height, char block, char pad);
int get_height();


int main(void){

    int min_height = 0;
    int max_height = 23;

    int height = get_height(min_height, max_height);

    char block = '#';
    char pad = ' ';

    print_pyramid(height, block, pad);
}


int get_height(int min_height, int max_height){

    int height;

    do {
        printf("Height? ");
        height = GetInt();
    } while ((height < min_height) || (height > max_height));

    return height;
}


void print_pyramid(int height, char block, char pad){

    for(int i = 0; i < height; i++){

        int blocks = i + 1;
        int padding = height - blocks;

        for(int j = 0; j < padding; j++){
            printf("%c", pad);
        }

        for(int k = 0; k < blocks; k++){
            printf("%c", block);
        }

        // print an extra block before new line
        printf("%c\n", block);
    }
}
