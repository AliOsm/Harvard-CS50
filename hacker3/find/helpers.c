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
bool search(int value, int array[], int n)
{
    if(n < 1) return false;
    
    // Linear search
    /*
    while(n--)
        if(array[n] == value)
            return true;
    */
    
    // Binary search
    return binarySearch(value, array, 0, --n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Selection Sort
    int i = 0, mini_v, mini_i;
    while(i < n) {
        mini_v = values[i];
        mini_i = i;
        
        // find smallest element
        for(int j = i; j < n; j++) if(values[j] < mini_v) {
            mini_v = values[j];
            mini_i = j;
        }
        
        // swap smallest element with first one in unsorted portion
        int tmp = values[i];
        values[i] = values[mini_i];
        values[mini_i] = tmp;
        
        // plus one to sorted portion
        i++;
    }
}