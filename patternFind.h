/*
This program returns back a line if it contains whatever is in the pattern array.
It will also tell you the rightmost occurrence of the pattern in the line.
*/

int testLine(char s[], char t[]) {

    int i, j, k;
    int position = 0;
    int tempPosition = 0;

    for(i = 0; s[i] != '\0'; i++) {
        position++;
        for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; k++, j++)
            ;
        if(k > 0 && t[k] == '\0')
            tempPosition = position;
    }
    if(tempPosition > 0)
        return tempPosition - 1;
    else
        return -1;
}

int getLine(char s[], int lim) {
    
    int location = 0;
    char c;

    while(--lim != 0 && (c = getchar()) != EOF && c != '\n')
        s[location++] = c;

    if(c == '\n')
        s[location++] = c;
    
    s[location] = '\0';

    return location;
}
