/* Expecto Palindronum: For each input, print out an integer L denoting
    the length of the shortest palindrome you can generate from the input
    string */

//Problem        : Expecto Palindronum
//Problem        : Expecto Palindronum
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
bool debug = false;
char debugString[40] = "_";

void substring(char *s, char *sub, int p, int l) {
  if (strcmp(s, debugString) == 0) {
       printf("Taking characters from %d to %d\n", p, l);
  }
  int c = 0;

  while (c < l) {
      sub[c] = s[p + c - 1];
      c++;
  }
  sub[c] = '\0';
  if (strcmp(s, debugString) == 0) {
     printf("Returning %s\n", sub);
  }
}

void reverse_string(char *string) {
    int length, c;
    char *begin, *end, temp;
    length = strlen(string);

    begin = string;
    end = string;

    for (c = 0; c < (length - 1); c++) {
        end++;
    }
    for (c = 0; c < (length / 2); c++) {
        temp = *end;
        *end = *begin;
        *begin = temp;

        begin++;
        end--;
    }
}

bool is_palindrome(char *string) {
    int check, length;
    char *reverse;
    if (debug) {
       printf("is_palindrome checking %s\n", string);
    }
    length = strlen(string);
    reverse = (char*)malloc(length + 1);
    reverse[length + 1] = '\0';
    strcpy(reverse, string);
    reverse_string(reverse);
    if (debug) {
        printf("reverse string: %s\n", reverse);
    }
    check = strcmp(string, reverse);

    if(check == 0) {
        return true;
    }
    else {
        return false;
    }
}

int smallestPalindrome(char * string) {
   int length = strlen(string);
   if (strcmp(string, debugString) == 0) {
       printf("Starting malloc\n");
       debug = true;
   }
   char *addString = (char *)malloc(length);
   char *newString = (char *)malloc(length + length);
   int i;
   for (i = 0; i < length; i++) {
       newString[length + 1] = '\0';
       substring(string, addString, (length - i), length);
       if (strcmp(string, debugString) == 0) {
           printf("%s\n", addString);
       }
       reverse_string(addString);
       newString = strcat(addString, string);
       if (strcmp(string, debugString) == 0) {
           printf("%s\n", newString);
       }
       if (is_palindrome(newString)) {
           return strlen(newString);
       }
   }
   return 0;
}

int main() {
    char string[101];
    scanf("%s", string);
    int length  = strlen(string);
    // printf("%d \n", is_palindrome("iqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiq"));
    // printf("%d \n", is_palindrome("qiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiqiq"));
    if(is_palindrome(string)) {
        printf("%d", length);
        return 0;
    }
    else if(length == 2) {
        printf("%d", 3);
        return 0;
    }
    else {
        int L = smallestPalindrome(string);
        printf("%d", L);
        return 0;
    }
    return 0;
}
