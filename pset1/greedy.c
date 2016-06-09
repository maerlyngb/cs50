/*
    Author: Maerlyn Broadbent
    Created: 5th June 2016

    Purpose: CS50 Introduction to Computer Science, Problem Set 1
*/

#include <stdio.h>
#include <math.h>
#include <cs50.h>


int get_change_owed();
int get_coins_for_change(int change);
int greedy(int pool, int slices[], int counter, int coins);


int main(void){
    int change = get_change_owed();
    int coins = get_coins_for_change(change);
    printf("%i\n", coins);
}


int get_change_owed(){
    float change_owed;
        
    do {
        printf("How much change is owed? ");
        change_owed = GetFloat();
        
    // don't accept a value smaller than 1c.
    } while (change_owed < (float) 0.01);

    // convert to cents to prevent floating point rounding errors
    return round(change_owed * 100);
}


int get_coins_for_change(int change){
    // array must be sorted smallest to largest
    int coin_vals[4] = {1, 5, 10, 25};
    int coin_val_count = sizeof(coin_vals)/sizeof(coin_vals[0]);

    return greedy(change, coin_vals, coin_val_count, 0);
}


int greedy(int pool, int slices[], int slice_id, int total_slices){
    
    // iterate backwards through the array so we can accept arrays of any length
    slice_id--;
    
    if (slice_id >= 0 ){
        
        // select next slice in the array
        int slice = slices[slice_id];
        
        // how many slices can we take out of the pool?
        int current_slices = floor(pool / slice);
        
        // take away slices and update the pool
        pool = pool - (slice * current_slices);
        
        // add number of taken away slices to running total
        total_slices += current_slices;
        
        if (pool > 0){
            // if we sill have something in the pool, take away smaller slices
            total_slices = greedy(pool, slices, slice_id, total_slices); 
        }
    }

    // return how many slices we were able to take away
    return total_slices;
}
