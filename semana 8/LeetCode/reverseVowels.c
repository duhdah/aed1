/*
345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/

// Funcionou (6 ms)

bool ehVogal(char a);
void troca(char *a, char *b);

char* reverseVowels(char* s) {
    int inicio = 0, fim = strlen(s)-1;
    while(inicio<fim){
        if(ehVogal(s[inicio])){
            while(!ehVogal(s[fim]) && inicio<fim){
                fim--;
            }
            if(inicio<fim){
                troca(&s[fim],&s[inicio]);
                fim--;
            }
        }
        inicio++;
    }
    return s;
}

bool ehVogal(char a){
    return a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'a' || a == 'e' ||  a == 'i' || a == 'o' || a == 'u';        
}

void troca(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
