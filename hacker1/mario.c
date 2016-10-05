#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;
    
    do {
        printf("height: ");
        height = GetInt();
    } while(height > 23 || height < 0);
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        
        for(int j = 0; j < height; j++) {
            if(i >= j)
                printf("#");
        }
        
        printf("  ");
        
        for(int j = 0; j < height; j++) {
            if(i >= j)
                printf("#");
        }
        
        printf("\n");
    }
    
    return 0;
}