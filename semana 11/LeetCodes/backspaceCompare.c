/*
844. Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Link: https://leetcode.com/problems/backspace-string-compare/description/
*/

// Funcionou (0 ms)

void arrumandoString(char* string, char* stringArrumada){
    int indice = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if(string[i] == '#'){
            if(indice > 0) indice--;
        }else{
            stringArrumada[indice++] = string[i];
        }
    }
    stringArrumada[indice] = '\0';
}

bool backspaceCompare(char* s, char* t){
    char* sArrumada= (char*)malloc(strlen(s) + 1);
    char* tArrumada = (char*)malloc(strlen(t) + 1);
    arrumandoString(s, sArrumada);
    arrumandoString(t, tArrumada);
    bool compara = strcmp(sArrumada, tArrumada) == 0;
    free(sArrumada);
    free(tArrumada);
    return compara;
}


// Versao usando pilha (0ms):

void arrumandoString(char* string, char* stringArrumada){
    int topo = -1, tam = strlen(string);
    for (int i = 0; i<tam; i++) {
        if(string[i] == '#'){
            if (topo>-1) topo--;
        }else{
            stringArrumada[++topo] = string[i];
        }
    }
    stringArrumada[topo+1] = '\0';
}

bool backspaceCompare(char* s, char* t){
    char* sArrumada= (char*)malloc(strlen(s) + 1);
    char* tArrumada = (char*)malloc(strlen(t) + 1);
    arrumandoString(s, sArrumada);
    arrumandoString(t, tArrumada);
    bool compara = strcmp(sArrumada, tArrumada) == 0;
    free(sArrumada);
    free(tArrumada);
    return compara;
}

