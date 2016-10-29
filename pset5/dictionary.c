/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct trie {
    bool is_word;
    struct trie* children[27];
} trie;

trie* root;
unsigned int words = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    trie* cursor = root;
    
    for(int i = 0; word[i] != '\0'; i++) {
        int char_num;
            
        if(word[i] == '\'')
            char_num = 26;
        else
            char_num = tolower(word[i]) - 'a';
            
        if(cursor->children[char_num] == NULL)
            return false;
        
        cursor = cursor->children[char_num];
    }
    
    if(cursor->is_word)
        return true;
        
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = malloc(sizeof(trie));
    
    FILE* fp = fopen(dictionary, "r");
    
    if (fp == NULL) {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    
    char word[LENGTH + 1];
    while(fscanf(fp, "%s", word) != EOF) {
        trie* cursor = root;
        
        for(int i = 0; word[i] != '\0'; i++) {
            int char_num;
            
            if(word[i] == '\'')
                char_num = 26;
            else
                char_num = word[i] - 'a';
            
            if(cursor->children[char_num] == NULL)
                cursor->children[char_num] = malloc(sizeof(trie));
            
            cursor = cursor->children[char_num];
        }
        
        cursor->is_word = true;
        
        words++;
    }
    
    fclose(fp);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

void freeTrie(trie* cursor) {
    if(cursor == NULL) return;

    for (int i = 0; i < 27; i++)
       freeTrie(cursor->children[i]);

    free(cursor);
}
 
bool unload(void)
{
    freeTrie(root);
    return true;
}
