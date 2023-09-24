#include <stdio.h>

int main() {

    int c;

    long cc = 0; //character count
    long nc = 0; //new line count
    long tc = 0; //tab count
    long sc = 0; //space count
    long wc = 0; //word count
    short wl = 0;//temporary word length
    long nwcount[10];//word length count
    for (int i; i < 10; i++)
        nwcount[i] = 0; 

    #define INWORD 1
    #define OUTWORD 0
    short state  = OUTWORD;

    short blankCheck = 0;

    printf("Welcome to Jackson's Word Helper!\n");
    printf("Enter Ctrl + Z into the terminal to end.\n");
    printf("-----------------------------------------\n");
    printf("\n");

    while((c = getchar()) != EOF) {

    
        if(c == ' ') {
            
            if(blankCheck == 0) {

                blankCheck = 1;
                sc++;
                putchar(c);
            }
                
        } else {
            blankCheck = 0;
            putchar(c);
        }

        if(c == '\n') {
            nc++;
        }
        
        if(c == '\t') {
            tc++;
        }    
        
        if(c == '\n' || c == '\t' || c == ' ') {
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
            wl++;
        }
    }

    printf("\n%5d words.\n", wc);
    printf("%5d characters.\n", cc);
    printf("%5d tabs.\n", tc);
    printf("%5d new lines.\n", nc);
    printf("%5d spaces.\n", sc);

    printf("\nWord length hyptograph:");
    for(int i = 1; i < 10; i++) {

        if(i == 9) {
            printf(" %d.\n", nwcount[i]);
        } else {
            printf(" %d", nwcount[i]);
        }
    }
    

    printf("\nPress Enter to Exit:");
    scanf("Exit Check");

    return 0;
}