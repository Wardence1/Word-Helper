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

void append(char *original, char *append) {

    int i;

    for(i = 0; original[i] != '\0'; i++)
        ;

    for(int j = 0; append[j] != '\0'; j++, i++) {
        original[i] = append[j];
    }
}

int getName(char s[], unsigned int max) {

    // clears the buffer
    // this gave me so many issues
    if(getchar() == '\n')
        ;

    char c;
    unsigned long i = 0;
    while((c = getchar()) != '\n') {
        if(i >= max) {
            s[i] = '\0';
            while((getchar()) != '\n')
                ;
            return 0;
        }

        s[i++] = c;
        if(i >= max) {

            printf("\nThe file name was over the limit.\n");
            break;
        }
    }

    s[i] = '\0';

    return 1; 
}
