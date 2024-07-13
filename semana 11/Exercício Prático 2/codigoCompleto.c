#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeSubstring(char *s, int indice);
int encontraSubstring(char *s);
int maximumGain(char* s, int x, int y);

// Esse é o código feito em aula, mas com o main() para poder testar!

int main(){
    int pontos = 0;
    char *s = malloc(strlen("aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha") + 1);
    strcpy(s, "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha");
    printf("String lida: %s\n", s);
    pontos = maximumGain(s, 1926, 4320);
    printf("String modificada: %s\n", s);
    printf("Pontos obtidos: %d\n", pontos);
    free(s);
    return 0;
}


int maximumGain(char* s, int x, int y) {
    int pontos = 0;

    // ideia do codigo: tirar primeiro 'ab' se eles valerem mais e depois os 'ba's, vice versa
    // fica em um while para ver se encontra novas substrings formadas depois de passar pelos fors
    // problema: se forma 'ab' em um dos fors de 'ba' quando 'ab' deveria ser prioridade, nao obtem o maximo

    if(x>y){
        while(encontraSubstring(s)){
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'a'){
                    if(s[i+1] == 'b'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=x;
                    }
                }
            }
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'a'){
                    if(s[i+1] == 'b'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=x;
                    }
                }
                if(s[i] == 'b'){
                    if(s[i+1] == 'a'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=y;
                    }
                }
            }
        }
    }else{
        while(encontraSubstring(s)){
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'b'){
                    if(s[i+1] == 'a'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=y;
                    }
                }
            }
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'b'){
                    if(s[i+1] == 'a'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=y;
                    }
                }if(s[i] == 'a'){
                    if(s[i+1] == 'b'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=x;
                    }
                }
            }
        }
    }
    return pontos;
}

// remove uma substring dado o indice
char *removeSubstring(char *s, int indice){
    int tam = 0;
    char *nova = (char *)malloc(sizeof(char)*(strlen(s)+1));
    for(int i = 0; i < strlen(s); i++){
        if((i != indice) && (i != indice+1)){
            nova[tam] = s[i];
            tam++;
        }
    }
    nova[tam] = '\0';
    return nova;
}

int encontraSubstring(char *s){
    for(int i = 0; s[i+1]; i++){
        if(s[i]=='b'){
            if(s[i+1] =='a'){
               return 1;
            }
        }
        if(s[i]=='a'){
            if(s[i+1] =='b'){
               return i;
            }
        }
    }
    return 0;
}