/*
1844. Replace All Digits with Characters

You are given a 0-indexed string s that has lowercase English letters in its even indices and digits in its odd indices.

There is a function shift(c, x), where c is a character and x is a digit, that returns the xth character after c.

For example, shift('a', 5) = 'f' and shift('x', 0) = 'x'.
For every odd index i, you want to replace the digit s[i] with shift(s[i-1], s[i]).

Return s after replacing all digits. It is guaranteed that shift(s[i-1], s[i]) will never exceed 'z'.

Link: https://leetcode.com/problems/replace-all-digits-with-characters/description/
*/

// Funcionou (3 ms)
char shift(char c, int x);

char* replaceDigits(char* s) {
    int tam = strlen(s);
    for(int i = 1; i < tam; i+=2){
        if(i % 2 != 0){
            s[i] = shift(s[i-1], s[i] - '0'); // subtrai '0' para transformar o char s[i] em int s[i]
        }
    }
    return s;
}

char shift(char c, int x){
    return c + x;
}