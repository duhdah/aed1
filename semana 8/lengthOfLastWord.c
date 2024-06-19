/*
58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Link: https://leetcode.com/problems/length-of-last-word/description/
*/

// Funcionou (6 ms)

int lengthOfLastWord(char* s) {
    int tamanho = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i]!=' '){
            tamanho++;
        }else{
            if(s[i+1]!=' ' && s[i+1]) tamanho = 0;
        }
    }
    return tamanho;
}
