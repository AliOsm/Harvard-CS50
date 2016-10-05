/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
 
// struct to store bytes blocks
typedef struct {
    uint8_t block[512];
} BUFFER;

int main(void)
{
    // open card.raw which is input file
    FILE* card = fopen("card.raw", "r");
    // output file for all results
    FILE* image;
    // BUFFER object to read from input file
    BUFFER bf;
    // array of chars to use with `sprintf`
    char arr[8] = {0};
    // count images for name them
    char *image_counter = malloc(4 * sizeof(char));
    image_counter[0] = '0';
    image_counter[1] = '0';
    image_counter[2] = '0';
    // determine when find an image
    int finded_jpg = 0;
    // determine there is file opened or not to close it
    int close_the_file = 0;
    
    // iterate over all bytes block in input file
    while(fread(&bf, sizeof(BUFFER), 1, card)) {
        // check if the first 3 bytes of the block equal to 0xff 0xd8 0xff
        if(bf.block[0] == 0xff && bf.block[1] == 0xd8 && bf.block[2] == 0xff) {
            // check if the forth byte of the block in range from 0xe0 to 0xef
            if(bf.block[3] == 0xe0 || bf.block[3] == 0xe1 || bf.block[3] == 0xe2 || bf.block[3] == 0xe3 ||
               bf.block[3] == 0xe4 || bf.block[3] == 0xe5 || bf.block[3] == 0xe6 || bf.block[3] == 0xe7 ||
               bf.block[3] == 0xe8 || bf.block[3] == 0xe9 || bf.block[3] == 0xea || bf.block[3] == 0xeb ||
               bf.block[3] == 0xec || bf.block[3] == 0xed || bf.block[3] == 0xee || bf.block[3] == 0xef) {
                    // if there is image finded then there is file opened
                    if(finded_jpg) close_the_file = 1;
                   
                    // yay! I find an image
                    finded_jpg = 1;
                   
                    // if there is file opened thene close it
                    if(close_the_file) fclose(image);
                   
                    // create new jpg file for the new image
                    sprintf(arr, "%s.jpg", image_counter);

                    // detect next image number
                    if(image_counter[2] < '9') {
                		int tmp = image_counter[2];
                		image_counter[2] = (char)(tmp + 1);
                	} else if(image_counter[2] == '9') {
                		image_counter[2] = '0';
                		int tmp = image_counter[1];
                		image_counter[1] = (char)(tmp + 1);
                	}
                   
                    // open the new image file
                    image = fopen(arr, "a");
                   
                    // write the current block to the new image file
                    fwrite(&bf, sizeof(BUFFER), 1, image);
                }
        // if there is jpg found
        } else if(finded_jpg) {
            // write the current block to the new image file
            fwrite(&bf, sizeof(BUFFER), 1, image);
        }
    }
    
    // close last image
    fclose(image);
    // close input file
    fclose(card);
    
    return 0;
}
