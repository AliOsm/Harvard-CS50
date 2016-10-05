#include <stdio.h>
#include <cs50.h>

int main(void) {
    int minutes;
    do {
        printf("minutes: ");
        minutes = GetInt();
    } while (minutes < 1);
    
    printf("bottles: %i", minutes * 12);
}