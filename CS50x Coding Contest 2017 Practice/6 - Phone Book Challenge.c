#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

typedef struct trie {
    char number[1000];
    bool is_name;
    struct trie* children[26];
} trie;

trie* root;

void insert(char name[], char number[]) {
    trie* cursor = root;
    
    for(int i = 0; name[i] != '\0'; i++) {
        int char_num = name[i] - 'a';
        
        if(cursor->children[char_num] == NULL)
            cursor->children[char_num] = malloc(sizeof(trie));

        cursor = cursor->children[char_num];
    }
    
    cursor->is_name = true;
    
    int j;
    for(j = 0; number[j] != '\0'; j++)
        cursor->number[j] = number[j];
    cursor->number[j] = '\0';
}

void check(char query[]) {
    trie* cursor = root;
    
    for(int i = 0; query[i] != '\0'; i++) {
        int char_num = query[i] - 'a';
        
        if(cursor->children[char_num] == NULL) {
            puts("Not found");
            return;
        }

        cursor = cursor->children[char_num];
    }
    
    if(cursor->is_name)
        printf("%s=%s\n", query, cursor->number);
    else
        puts("Not found");
}

void freeTrie(trie* cursor) {
    if(cursor == NULL) return;

    for (int i = 0; i < 26; i++)
       freeTrie(cursor->children[i]);

    free(cursor);
}

int main(void)
{
    root = malloc(sizeof(trie));
    
    int n;
    scanf("%d", &n);
    
    char name[1000], number[1000];
    while(n--) {
        scanf("%s%s", name, number);
        insert(name, number);
    }
    
    char query[1000];
    while(scanf("%s", query) == 1)
        check(query);
}
