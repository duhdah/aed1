
/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Link: https://leetcode.com/problems/longest-common-prefix/

*/

// Primeira lógica testada (não funcionou):

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL) return 0;
    
    // Guarda o maior tamanho possivel do prefixo:
    int tamPrefix = strlen(strs[0]);
    for(int i = 1; i < strsSize; i++){
        if(strlen(strs[i]) < tamPrefix){
            tamPrefix = strlen(strs[i]);
        }
    }
    // Subtrai o tamanho do prefixo conforme letras diferentes forem encontradas:
    for(int i = 0; i < strsSize - 1; i++){
        // Provavlemente dava errado aqui:
        while(strs[i][tamPrefix]!=strs[i+1][tamPrefix] && tamPrefix > 0){
            tamPrefix--;
            if(!tamPrefix) return "";
        }
    }

    // Copia as 'tamPrefix' primeiras letras para a string 'prefix'.
    char *prefix;
    prefix = (char *)malloc(sizeof(char) * (tamPrefix + 1));
    for(int i = 0; i < tamPrefix; i++){
        prefix[i] = strs[0][i];
    }
    prefix[tamPrefix] = '\0';
    return prefix;
}

// Segunda tentativa:

// Funcionou (0 ms)
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    // Guarda a primeira palavra e o tamanho dela:
    char* primeira = strs[0];
    int tam = strlen(primeira);

    // Passa pelas palavras comparando elas com a primeira:
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < tam && strs[i][j] == primeira[j]) {
            j++;
        }
        tam = j;
        if (tam == 0) {
            return "";
        }
    }

    // Copia as primeiras 'tam' letras da primeira palavra pra string 'prefixo':
    char* prefixo = (char*)malloc((tam + 1) * sizeof(char));
    strncpy(prefixo, primeira, tam);
    prefixo[tam] = '\0';
    
    return prefixo;
}

