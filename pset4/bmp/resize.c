/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    // remember factor
    int factor = atoi(argv[1]);

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if (factor < 1 || factor > 100)
    {
        printf("Factor must be in range 1..100!\n");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, nbf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // store new image file information
    nbf = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, nbi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // store new image information
    nbi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine new image width and height
    nbi.biWidth = bi.biWidth * factor;
    nbi.biHeight = bi.biHeight * factor;
    
    // determine old and new image padding padding for scanlines
    int opadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int npadding = (4 - (nbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine new image size
    nbi.biSizeImage = (nbi.biWidth * sizeof(RGBTRIPLE) + npadding) * abs(nbi.biHeight);

    // determine new image file size
    nbf.bfSize = nbi.biSizeImage + 0x36;

    // write outfile's BITMAPFILEHEADER
    fwrite(&nbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&nbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // temporary storage
        RGBTRIPLE triple[bi.biWidth];

        // read RGB triple from infile
        for (int j = 0; j < bi.biWidth; j++)
            fread(&triple[j], sizeof(RGBTRIPLE), 1, inptr);
        
        // iterate over pixels in scanline factor times
        for (int j = 0; j < factor; j++) {
            for (int k = 0; k < bi.biWidth; k++)
                // write RGB triple to outfile factor times
                for(int l = 0; l < factor; l++)
                    fwrite(&triple[k], sizeof(RGBTRIPLE), 1, outptr);
                
            // add a new padding
            for (int k = 0; k < npadding; k++)
                fputc(0x00, outptr);
        }

        // skip over padding, if any
        fseek(inptr, opadding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
