
/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing 
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Link: https://leetcode.com/problems/valid-palindrome/description/

*/

// Como o codigo que fiz antes desse não funcionou no LeetCode, apesar de funcionar fora dele, busquei outra lógica pra poder submeter.
// Funcionou (2 ms)

int alphanumeric(char c);
int minuscula(char c);
int isPalindrome(char* s) {
    int left, right; // percorre a palavra dos dois lados ao mesmo tempo
    right = strlen(s) - 1;
    left = 0;
    while (left < right){ // se left == right, eh palindromo
        if(alphanumeric(s[left])){
            if(alphanumeric(s[right])){
                if (minuscula(s[left]) != minuscula(s[right])){
                    return 0;
                }
                left++;
                right--;
            }
            else 
                right--;
        }
        else 
            left++;
    }
    return (1);
}
 
int alphanumeric(char c){ // verifica se é numero ou letra
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'); 
}

int minuscula(char c){ // deixa as letras minusculas pra comparar elas 
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}
