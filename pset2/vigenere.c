#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./vigenere key");
        return 1;
    }
    
    for(int i = 0, len = strlen(argv[1]); i < len; i++) {
        argv[1][i] = tolower(argv[1][i]);
        
        if(!isalpha(argv[1][i])) {
            printf("Usage: ./vigenere key");
            return 1;
        }
    }

    string s = GetString(), k = argv[1];
    int plain_len = strlen(s), key_len = strlen(argv[1]);
    
    for(int i = 0, j = 0; i < plain_len; i++)
        if(isalpha(s[i])) {
            if(j == key_len)
                j = 0;
            
            int tmp = (int) s[i] + ((int) k[j] % 97);
            
            if(isupper(s[i])) {
                if(tmp > 65 + 25)
                    tmp -= 26;
            } else {
                if(tmp > 97 + 25)
                    tmp -= 26;
            }
            
            printf("%c", (char) tmp);
            j++;
        } else
            printf("%c", s[i]);
        
    printf("\n");
    
    return 0;
}