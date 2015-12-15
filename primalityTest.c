/* If the input is a prime numer, return prime else return composite */

//Problem        : Primality Test
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isPrime(int number) {
    int i;
    for (i=2; i<number; i++) {
        if (number % i == 0 && i != number) return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    if (isPrime(N)) {
        printf("prime");
    }
    else {
        printf("composite");
    }
    return 0;
}
