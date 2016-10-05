#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main() {
    string s = GetString();
    
    if(s[0] != ' ')
        printf("%c", toupper(s[0]));
    
    for(int i = 1, len = strlen(s); i < len; i++)
        if(s[i-1] == ' ' && s[i] != ' ')
            printf("%c", toupper(s[i]));
            
    printf("\n");
    
    return 0;
}