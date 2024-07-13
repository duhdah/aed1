
char *removeSubstring(char *s, int indice);
int encontraSubstring(char *s, const char* substr);
int maximumGain(char* s, int x, int y);

// Esse é o código feito em aula, mas melhorado com o Chat GPT para obter melhor desempenho.
// Passou em 55 testes. Nos outros 21, deu Time Limit Exceeded. Portanto, procurei soluções melhores.

int maximumGain(char* s, int x, int y) {
    int pontos = 0;
    int len = strlen(s);    
    int indice;

    if (x > y) {
        while ((indice = encontraSubstring(s, "ab")) != -1) {
            char *nova = removeSubstring(s, indice);
            strcpy(s, nova);
            free(nova);
            pontos += x;
        }
        while ((indice = encontraSubstring(s, "ba")) != -1) {
            char *nova = removeSubstring(s, indice);
            strcpy(s, nova);
            free(nova);
            pontos += y;
        }
    } else {
        while ((indice = encontraSubstring(s, "ba")) != -1) {
            char *nova = removeSubstring(s, indice);
            strcpy(s, nova);
            free(nova);
            pontos += y;
        }
        while ((indice = encontraSubstring(s, "ab")) != -1) {
            char *nova = removeSubstring(s, indice);
            strcpy(s, nova);
            free(nova);
            pontos += x;
        }
    }
    return pontos;
}

char *removeSubstring(char *s, int indice){
    int tam = 0;
    int len = strlen(s);
    char *nova = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        if (i != indice && i != indice + 1) {
            nova[tam++] = s[i];
        }
    }
    nova[tam] = '\0';
    return nova;
}

int encontraSubstring(char *s, const char* substr) {
    char *pos = strstr(s, substr);
    if (pos) {
        return pos - s;
    }
    return -1;
}
