//Problem        : Knights of Terror
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

int c0, c1, c2; // x, y, z
int n, m, r;
bool cont;

int min_three(int x, int y, int z) {
    if (x < y && x < z) return x;
    else if (y < x && y < z) return y;
    else if (z < x && z < y) return z;
    return 0;
}

int min_two(int x, int y) {
    if (x < y) return x;
    else return y;
    return 0;
}

int main() {
    int i;
    scanf("%d", &c0);
    scanf(" %d", &c1);
    scanf(" %d", &c2);
    scanf(" %d", &n);
    cont = true;
    while(cont) {
        m = 0;
        if(min_three(c0, c1, c2) == c0) m = 0;
        else if(min_three(c0, c1, c2) == c1) m = 1;
        else m = 2;
        if(m == 0) {
            if(((c1 - n) <= 0) || ((c2 - n) <= 0)) {
                r += min_two(c1, c2);
                cont = false;
            }
            c1 -= n;
            c2 -= n;
        }
        if(m == 1) {
            if(((c0 - n) <= 0) || ((c2 - n) <= 0)) {
                r += min_two(c0, c2);
                cont = false;
            }
            c0 -= n;
            c2 -= n;
        }
        if(m == 2) {
            if(((c0 - n) <= 0) || ((c1 - n) <= 0)) {
                r += min_two(c0, c1);
                cont = false;
            }
            c0 -= n;
            c1 -= n;
        }
        if(cont) {
            r += n;
        }
    }
    printf("%d", r);
    return 0;
}
