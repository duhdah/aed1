/*
Given an integer x, return true if x is a palindrome, and false otherwise
*/

// Minha solucao: 

#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

bool isPalindrome(int x) {
    bool a = true;
    int length = snprintf( NULL, 0, "%d", x );
    char* str = malloc( length + 1 );
    snprintf( str, length + 1, "%d", x );
    for(int i = 0; i <= length/2; i++){
        a = (str[i] == str[length-i-1]);
        if(!a){
            free(str);
            return a;
        }
    }
    free(str);
    return a;
}

// Solucao otimizada: 

bool isPalindrome(int x) {
    int original = x;
     long long int reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;  
        x /= 10; 
    }
    return original == reversed;
    if ( original == reversed) {
        printf("%d true\n", x);
    } else {
        printf("%d false\n", x);
    }

    return 0;
}