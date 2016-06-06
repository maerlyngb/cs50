/*
    Author: Maerlyn Broadbent
    Created: 5th June 2016

    Purpose: CS50 Introduction to Computer Science, Problem Set 1
*/

#include <stdio.h>
#include <cs50.h>

int get_bottles_per_shower(int shower_length){
    double gallons_per_minute = 1.5;
    int ounces_per_gallon = 128;
    int ounces_in_bottle = 16;
    
    int shower_flow_rate = gallons_per_minute * ounces_per_gallon;
    int bottles_per_min = shower_flow_rate / ounces_in_bottle;
    int bottles_per_shower = bottles_per_min * shower_length;
    
    return bottles_per_shower;
}

int main(void){
    int shower_length;
    
    do {
        printf("How many minutes do you shower for? ");
        shower_length = GetInt();
    } while (shower_length < 1);
    
    int bottles_per_shower = get_bottles_per_shower(shower_length);
    
    printf("Minutes: %i\n", shower_length);
    printf("Bottles: %i\n", bottles_per_shower);
    
}