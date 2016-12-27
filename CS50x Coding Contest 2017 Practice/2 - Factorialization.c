#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

int main(void)
{
    long long n, r = 1;
    scanf("%lld", &n);
    
    for(int i = 1; i <= n; i++)
        r *= i;
    
    printf("%lld\n", r);
}
