#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *arruma(char *entrada);
bool isPalindrome(char* s);

// Não funcionou em alguns casos do LeetCode, mas testando os mesmos casos no VSCode com o codigo completo, funciona.


int main(){
    bool palindromo;
    char *entrada;
    entrada = (char *)malloc(sizeof(char) * 50);
    printf("Digite uma string:\n");
    scanf("%[^\n]",entrada);
    entrada = arruma(entrada);
    printf("String lida: %s\n", entrada);
    palindromo = isPalindrome(entrada);
    if(palindromo) printf("Eh palindromo\n");
    else printf("Nao eh palindromo\n");
    return 0;

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

bool isPalindrome(char* s) {
    for(int i = 0; i< strlen(s)/2; i++){
        if(s[i] != s[strlen(s)-1-i]) return false;
    }
    return true;
}
