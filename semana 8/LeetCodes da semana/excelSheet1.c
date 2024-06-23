/*

168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 
Link: https://leetcode.com/problems/excel-sheet-column-title/description/
*/

//Funcionou (0 ms)
char* convertToTitle(int columnNumber) {
    char* titulo;
    titulo = (char *)malloc(sizeof(char) * 10);
    int indice = 0;
    while(columnNumber>0){
        columnNumber--;
        titulo[indice++] = columnNumber % 26 + 'A';
        columnNumber /= 26;
    }
    titulo[indice] = '\0';
    for(int i = 0; i < strlen(titulo)/2; i++){
        char temp = titulo[i];
        titulo[i] = titulo[strlen(titulo)-i-1];
        titulo[strlen(titulo)-i-1] = temp;
    }
    return titulo;
}
