
/*
171. Excel Sheet Column Number

 Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 
Link: https://leetcode.com/problems/excel-sheet-column-number/description/
*/
int titleToNumber(char* columnTitle) {
    int coluna = 0;
    for(int i = 0; i < strlen(columnTitle); i++){
        coluna *= 26; // a partir da segunda letra, começa a multiplicar por 26
        coluna += columnTitle[i] - 'A' + 1; // resto da divisão
        // o +1 é pq os restos vão de 0 a 25, mas precisamos contabilizar de 1 (A) a 26 (Z) no somatorio
    }
    return coluna;
}
