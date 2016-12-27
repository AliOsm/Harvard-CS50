#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

int main(void)
{
    char r[1000];
    r[0] = '\0';
    
    int n, i;
    scanf("%d", &n);
    
    for(i = 0; n > 0.5; i++, n /= 2) {
        if(n % 2 == 0)
            r[i] = '0';
        else
            r[i] = '1';
        
        r[i+1] = '\0';
    }
    
    while(i--) printf("%c", r[i]);
    putchar('\n');
}
