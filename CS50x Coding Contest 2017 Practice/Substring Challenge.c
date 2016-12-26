#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

int main(void)
{
    string s, t;
    s = GetString();
    t = GetString();
    
    int slen = strlen(s) - strlen(t) + 1, tlen = strlen(t);
    bool exist;
    
    for(int i = 0; i < slen; i++) {
        exist = true;
        
        for(int j = 0; j < tlen; j++) {
            if(t[j] == '*')
                continue;
            
            if(s[i+j] != t[j]) {
                exist = false;
                break;
            }
        }
        
        if(exist) {
            printf("%d", i);
            return 0;
        }
    }
    
    puts("-1");
}
