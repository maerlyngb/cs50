/*
    Author: Maerlyn Broadbent
    Created: 5th June 2016

    Purpose: CS50 Introduction to Computer Science, Problem Set 1
*/

#include <stdio.h>
#include <cs50.h>

void print_pyramid(int height){
    
    char block = '#';
    char pad = ' ';
    
    for(int i = 0; i < height; i++){

        int blocks = i + 1;
        int pad_len = height - blocks;
        
        for(int j = 0; j < pad_len; j++){
            printf("%c", pad);
        }
        
        for(int k = 0; k < blocks; k++){
            printf("%c", block);
        }
        
        printf("#\n");
    }
}

int main(void){
    int height;
    
    do {
        printf("How tall do you want your pyramid? (>0 && <24) ");
        height = GetInt();
    } while ((height < 0) || (height > 23));

    if(height > 0){
        print_pyramid(height);
    }
    
    return 0;
}