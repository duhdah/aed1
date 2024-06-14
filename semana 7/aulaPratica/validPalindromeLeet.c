
/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing 
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Link: https://leetcode.com/problems/valid-palindrome/description/

*/

// Não funcionou em alguns casos do LeetCode, mas testando os mesmos casos com o codigo completo (validPalindrome.c), funciona.

char *arruma(char *entrada);

bool isPalindrome(char* s) {
    int tam = strlen(s);
    s = arruma(s);
    for(int i = 0; i< tam/2; i++){
        if(s[i] != s[tam-1-i]) return false;
    }
    return true;
}

char *arruma(char *entrada){
    char *nova;
    int tamNova = 0;
    nova = (char *)malloc(sizeof(char) * strlen(entrada));
    for(int i = 0; i < strlen(entrada); i++){
        if(entrada[i] >= 'A' && entrada[i] <= 'Z') entrada[i] = entrada[i] + 32;
        if(entrada[i] >= 'a' && entrada[i] <= 'z'){
            nova[tamNova] = entrada[i];
            tamNova++;
        }
    }
    return nova;
}