#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    printf("O hai! How much change is owed? ");
    double change = GetFloat();
    
    while(change < 0) {
        printf("How much change is owed? ");
        change = GetFloat();
    }

    int tmp = round((change - (int)change) * 100);
    
    int coins = 0;

    while(tmp >= 25) {
        tmp -= 25;
        coins++;
    }

    while(tmp >= 10) {
        tmp -= 10;
        coins++;
    }

    while(tmp >= 5) {
        tmp -= 5;
        coins++;
    }
    
    while(tmp >= 1) {
        tmp -= 1;
        coins++;
    }

    printf("%i\n", coins + ((int)change * 4));
}