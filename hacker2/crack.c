/**
 * crack.c
 *
 * Computer Science 50
 * Problem Set 2 (Hacker Edition)
 *
 * Password cracker assuming DES based encryption, in this case, the crypt() function of C. 
 * WARNING: Run time is hours/days.
 * 
 */

#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>
#include <unistd.h>

// Compile with || clang -o crack crack.c -lcrypt
// Run with || ./crack [hash]

// Tested on
/*
1        || 50Xu9TV42tQOg || 0.002s      || 3,420 possible passwords
al       || 507IH4BV0kgzc || 0.789s      || 324,900 possible passwords
RoR      || 50b5ILzBEDplw || 45.780s     || 30,865,500 possible passwords
Ruby     || 50VfakyL0ptK. || 4170.874s   || 2,932,222,500 possible passwords
Linux    || 50u8HReKZleek || 355826.965s || 278,561,137,500 possible passwords
*/

// You can try with
/*
AliOsm   || 50F7Vs3yYSpak || Do it! || 26,463,308,062,500 possible passwords
abcdefg  || 50ozejrWnaK1U || Do it! || 2,514,014,265,937,500 possible passwords
12345678 || 50gyRGMzn6mi6 || Do it! || 238,831,355,264,062,500 possible passwords
*/

int main(int argc, char* argv[]) {
    // make sure there exist one command argument only
    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    // uncomment this two lines to generate new hashes
    /*
    printf("%s\n", crypt("abcdefg", "50"));
    return 0;
    */

    // generated password to crack encrypted one
    char generated_password[9] = {};
    
    // test array to store passwords of all lengths
    char test[9] = {};

    // extract salt from encrypted password
    char salt[3];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];

    // store all ASCII characters in an array
    char arr[95];
    for(int i = 0; i < 95; i++) arr[i] = (char) (i + 32);
    
    printf("Trying to hack entered hash, please wait an hour, a day or months,\nyou will stay here a long long (long)^(inf) time :D\n");
    
    // try all possible passwords of length 8 or less
    for(int i = 0; i < 95; i++)
        for(int j = 0; j < 95; j++)
            for(int k = 0; k < 95; k++)
                for(int l = 0; l < 95; l++)
                    for(int m = 0; m < 95; m++)
                        for(int n = 0; n < 95; n++)
                            for(int o = 0; o < 95; o++)
                                for(int p = 0; p < 95; p++) {
                                    // generate first password
                                    generated_password[0] = arr[i];
                                    generated_password[1] = arr[j];
                                    generated_password[2] = arr[k];
                                    generated_password[3] = arr[l];
                                    generated_password[4] = arr[m];
                                    generated_password[5] = arr[n];
                                    generated_password[6] = arr[o];
                                    generated_password[7] = arr[p];

                                    // try all subpasswords of all lengths from generated password
                                    for(int q = 0, r = 8; q <= 7; q++, r--)
                                        for(int s = 0; s < q + 1; s++) {
                                            // take r characters
                                            strncpy(test, generated_password+s, r);
                                            test[r] = '\0';
                                            
                                            // try password of length r
                                            if(strcmp(crypt(test, salt), argv[1]) == 0) {
                                                printf("Password found!\n%s\n", test);
                                                return 0;   
                                            }
                                        }
                                }
    
    // if nothing found print nothing found xD
    printf("Nothing found :(\n");
    
    return 0;
}
