/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

// Binary search
bool binarySearch(int value, int values[], int min, int max) {
    if(min > max) return false;
    
    int mid = (min + max) / 2;

    if(value > values[mid])
        return binarySearch(value, values, mid + 1, max);
    else if(value < values[mid])
        return binarySearch(value, values, min, mid - 1);
        
    return value == values[mid];
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Linear search
    /*
    while(n--)
        if(values[n] == value)
            return true;
    */
    
    // Binary search
    return binarySearch(value, values, 0, --n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Bubble sort
    while(--n)
        for(int i = 0; i < n; i++)
            if(values[i] > values[i+1]) {
                values[i] = values[i] - values[i+1];
                values[i+1] = values[i] + values[i+1];
                values[i] = values[i+1] - values[i];
            }

    return;
}
