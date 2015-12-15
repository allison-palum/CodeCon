/* Based on the input, print out the color of the tie.
    The color of the tie can on;y be one of the 5 colors namely
    White, Black, Blue, Red or Yellow. You can safely assume that
    there aways exists only one unique color that the tie can have */

//Problem        : Tie Color
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //fetch N from command line and convert to integer
    char num[6];
    int N;
    fgets(num, 6, stdin);
    N = atoi(num);

    //initialize integer variables to 0
    int white = 0;
    int black  = 0;
    int blue = 0;
    int red = 0;
    int yellow = 0;

    //fetch strings from command line
    char color[100000];
    int i;
    while ((!feof(stdin))) {
        fgets(color, 6, stdin);
        i = strlen(color) - 1;
        if (color[i] == '\n') {
            color[i] = '\0';
        }
        if (strcmp(color, "White") == 0) white++;
        else if (strcmp(color, "Black") == 0) black++;
        else if (strcmp(color, "Blue") == 0) blue++;
        else if (strcmp(color, "Red") == 0) red++;
        else if (strcmp(color, "Yellow") == 0) yellow++;
    }

    //find color with 0 mentions
    int MAXLENGTH = 6;
    char* ans[MAXLENGTH];
    if (white == 0) {
        fprintf(stdout, strcpy(ans, "White"));
    }
    else if (black == 0) {
        fprintf(stdout, strcpy(ans, "Black"));
    }
    else if (blue == 0) {
        fprintf(stdout, strcpy(ans, "Blue"));
    }
    else if (red == 0) {
        fprintf(stdout, strcpy(ans, "Red"));
    }
    else if (yellow == 0) {
        fprintf(stdout, strcpy(ans, "Yellow"));
    }
    return 0;
}
