#include <stdio.h>

char get1() {

    char c[50], temp;
    unsigned char check = 0;
    
    while((temp = getchar()) != '\n') {

        if(!check)
            c[check++] = temp; 
    }

    return c[0];
}