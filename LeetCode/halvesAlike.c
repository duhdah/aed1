/*
    1704. Determine if String Halves Are Alike

    You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
    Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
    Return true if a and b are alike. Otherwise, return false.

    Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-05-01

*/

// Funcionou (0 ms, 6.08 MB) (Melhor)
bool halvesAreAlike(char* s) {
    char  *a, *b;
    int metade, v1=0, v2=0;
    metade = (strlen(s))/2;
    a = (char *)malloc(sizeof(char) * metade);
    b = (char *)malloc(sizeof(char) * metade);
    for(int i = 0; i < 2*metade; i++){
        if(i < metade){
            a[i] = s[i];
        }else{
            b[i-metade] = s[i];
        }
    }
    for(int i = 0; i < metade; i++){
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ){
            v1++;
        }if(b[i] == 'A' || b[i] == 'E' || b[i] == 'I' || b[i] == 'O' || b[i] == 'U' || b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' ){
            v2++;
        }
    }
    return v1 == v2;
}

// Funcionou (2 ms, 5.54 MB) (Sem armazenar a variavel 'metade')
bool halvesAreAlike(char* s) {
    char  *a, *b;
    int v1=0, v2=0;
    a = (char *)malloc(sizeof(char) * strlen(s)/2);
    b = (char *)malloc(sizeof(char) * strlen(s)/2);
    for(int i = 0; i < strlen(s); i++){
        if(i < strlen(s)/2){
            a[i] = s[i];
        }else{
            b[i-strlen(s)/2] = s[i];
        }
    }
    for(int i = 0; i < strlen(s)/2; i++){
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ){
            v1++;
        }if(b[i] == 'A' || b[i] == 'E' || b[i] == 'I' || b[i] == 'O' || b[i] == 'U' || b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' ){
            v2++;
        }
    }
    return v1 == v2;
}

// Funcionou (4 ms, 5.56 MB) (Usando uma unica variavel para 'vogais')
bool halvesAreAlike(char* s) {
    char  *a, *b;
    int vogais = 0;
    a = (char *)malloc(sizeof(char) * strlen(s)/2);
    b = (char *)malloc(sizeof(char) * strlen(s)/2);
    for(int i = 0; i < strlen(s); i++){
        if(i < strlen(s)/2){
            a[i] = s[i];
        }else{
            b[i-strlen(s)/2] = s[i];
        }
    }
    for(int i = 0; i < strlen(s)/2; i++){
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ){
            vogais++;
        }if(b[i] == 'A' || b[i] == 'E' || b[i] == 'I' || b[i] == 'O' || b[i] == 'U' || b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' ){
            vogais--;
        }
    }
    return vogais == 0;
}

// Funcionou (3 ms, 6.08 MB) (Usando a variavel `metade` e uma unica variavel `vogais`)
bool halvesAreAlike(char* s) {
    char  *a, *b;
    int metade, vogais = 0;
    metade = (strlen(s))/2;
    a = (char *)malloc(sizeof(char) * metade);
    b = (char *)malloc(sizeof(char) * metade);
    for(int i = 0; i < metade*2; i++){
        if(i < metade){
            a[i] = s[i];
        }else{
            b[i-metade] = s[i];
        }
    }
    for(int i = 0; i < metade; i++){
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ){
            vogais++;
        }if(b[i] == 'A' || b[i] == 'E' || b[i] == 'I' || b[i] == 'O' || b[i] == 'U' || b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' ){
            vogais--;
        }
    }
    return vogais == 0;
}