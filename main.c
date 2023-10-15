#include <stdio.h>

void printAmount(unsigned long wc, unsigned long cc, unsigned long tc, unsigned long nc, unsigned long sc, long nwcount[], char pcount[]) {

printf("\nWhat you wrote but spell corrected:\n-----------------------------------------\n\n");
printf("%s\n", pcount);
printf("-----------------------------------------");

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
}

int main() {

    char c;

    unsigned long cc = 0; //character count
    unsigned long nc = 0; //new line count
    unsigned long tc = 0; //tab count
    unsigned long sc = 0; //space count
    unsigned long wc = 0; //word count
    unsigned short wl = 0;//temporary word length
    char pcount[99999];//whole paragraph count.
    unsigned long pc = 0; //how long the paragraph is.
    long nwcount[10];//word length count

    #define INWORD 1
    #define OUTWORD 0
    short state  = OUTWORD;

    short blankCheck = 0;

    printf("Welcome to Jackson's Word Helper! (Beta 1.1.2)\n");
    printf("Enter Ctrl + Z into the terminal to end.\n");
    printf("-----------------------------------------\n\n");

    while((c = getchar()) != EOF) {

    
        if(c == ' ') {
            
            if(blankCheck == 0) {

                blankCheck = 1;
                sc++;
                pcount[pc] = c;
                pc++;
            }
                
        } else {
            blankCheck = 0;
            pcount[pc] = c;
            pc++;
        }

        if(c == '\n') {
            nc++;
        }
        
        if(c == '\t') {
            tc++;
        }    
        
        if(c == '\n' || c == '\t' || c == ' ' || c == '.' || c == '?' || c == '!' || c == ',') { //Sees if there's a seperation between differen't words.
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
    }

    
    printAmount(wc, cc, tc, nc, sc, nwcount, pcount);

    printf("\nPress Enter to Exit:");
    scanf("Exit Check");

    return 0;
}

