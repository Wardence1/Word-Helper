#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "patternFind.h"

/*
 *  Print the amount of characters and other things correctly.
 *  Organize your variables, Geez.
*/

int main() {

    char c;

    long cc = 0; // character count
    long nc = 0; // new line count
    long tc = 0; // tab count
    long sc = 0; // space count
    long wc = 0; // word count
    short wl = 0;// temporary word length
    char *pcount = malloc(sizeof(char)*99999);// whole paragraph count.
    long pc = 0; // how long the paragraph is.
    long *nwcount = malloc(sizeof(long) * 10);// word length count
    
    // pattern find variables
    unsigned char patternFinding = 0;
    unsigned int patternP = 0;
    char pattern[100];
    unsigned int found = 0;
    int foundAt[1000];
    int foundLine = 1;
    char foundInTime = 0;
    unsigned part = 0;
    unsigned patternPart = 0;
    unsigned foundPoint = 0;

    #define INWORD 1
    #define OUTWORD 0
    unsigned char state = OUTWORD;

    unsigned char blankCheck = 0;

    printf("Welcome to Jackson's Word Helper! (1.4 / Linux Support Update)\n");

    // Check if the device is Windows or Linux
    #if defined(_WIN64) || defined(_WIN32)
        printf("(Enter Ctrl + Z into the terminal to end.)\n");
    #endif

    #ifdef __unix__
        printf("(Enter ^ into the terminal to end.)\n");
    #endif
    printf("-----------------------------------------\n\n");

    // Pattern Finding
    printf("Would you like to search lines for text? (Y/N): ");
    if((c = get1()) == 'y' || c == 'Y') {
        patternFinding = 1;
        printf("What would you like to search for?: ");
        for(patternP = 0; (c = getchar()) != '\n'; pattern[patternP++] = c)
            if(c==EOF)
                return 0;
        pattern[patternP] = '\0';
        printf("Currently searching for %s.\n\n", pattern);
    }
    else   
        printf("Searching for nothing.\n\n");
    
    // Word Helper
    #if defined(_WIN64) || defined(_WIN32)
    while((c = getchar()) != EOF) {
    #endif
    #ifdef __unix__
    while((c = getchar()) != '^') {
    #endif

        if(c == ' ') {
            
            if(blankCheck == 0) {

                blankCheck = 1;
                sc++;
                pcount[pc++] = c;
            }
                
        } else {
            blankCheck = 0;
            pcount[pc++] = c;
        }

        if(c == '\n') {
            nc++;
        }
        
        if(c == '\t') {
            tc++;
        }    
        
        if(c == '\n' || c == '\t' || c == ' ' || c == '.' || c == '?' || c == '!' || c == ',') { //Sees if there's a separation between different words.
            state = OUTWORD;
            nwcount[wl]++;
            wl = 0;
        } else if (state == OUTWORD) {
            wc++;
            cc++;
            wl++;
            state = INWORD;
        } else {
            cc++;
            if(c != '\'')
                wl++;
        }

        
        if(pcount[part] == pattern[patternPart]) {
            patternPart++;
        }
        else 
            patternPart = 0;
    
        if(patternPart == strlen(pattern)) {
            found++;
            patternPart = 0;
            foundAt[foundPoint++] = foundLine;
        }

        part++;

        if(c == '\n')
            foundLine++;
    }

    foundPoint--;
    
    #ifdef __unix__
    while(getchar() != '\n')
        ;
    #endif
    
    // Printing the results
        printf("\nWhat you wrote but space corrected:\n-----------------------------------------\n\n");
        printf("%s\n", pcount);
        printf("-----------------------------------------");

        printf("\n%5ld words.\n", wc);
        printf("%5ld characters.\n", cc);
        printf("%5ld tabs.\n", tc);
        printf("%5ld new lines.\n", nc);
        printf("%5ld spaces.\n", sc);

        if(patternFinding) {
            if(found > 2)
                printf("Found %d matching patterns at lines", found);
            else if(found == 0)
                printf("Couldn't find any matching patterns.");
            else if(found == 1)
                printf("Found 1 matching pattern in line %d.", foundAt[0]);
            else if(found == 2)
                printf("Found 2 matching patterns in lines %d and %d.", foundAt[0], foundAt[1]);

        if(found > 2)
            for(int i = 0; i <= foundPoint; i++) {

                if(i == foundPoint)
                    printf(" and %d.", foundAt[i]);
                else
                    printf(" %d,", foundAt[i]);
            }
        }


        printf("\nWord length hyptograph:");
        for(int i = 1; i < 10; i++) {

            if(i == 9) {
                printf(" %ld.\n", nwcount[i]);
            } else {
                printf(" %ld", nwcount[i]);
            }
        }

    
    // saving the text
    printf("\nWould you like to save the spell corrected text?: ");
    printf("\n(Y / N):");

    char response;
    scanf("%c", &response);

    if(response == 'y' || response == 'Y') {
        char name[17];
        printf("What would you like to name the file?: ");
        getName(name, 12);
        append(name, ".txt");

        FILE *text = fopen(name, "w");
        fprintf(text, "%s", pcount);

        #if defined(_WIN64) || defined(_WIN32)
        // exit check
        printf("\nPress Enter to Exit:");
        scanf("Exit Check");
        #endif
    }

    return 0;
}

