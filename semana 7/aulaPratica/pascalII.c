#include <stdio.h>
#include <stdlib.h>

/*

119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

Link: https://leetcode.com/problems/pascals-triangle-ii/description/

*/

// Funcionou (0 ms)
// OBS: Esse é o código completo que fiz pra testar no VSCode.

int* getRow(int rowIndex, int* returnSize);

int main(){
    int row;
    printf("Digite a linha do triangulo de Pascal: ");
    scanf("%d",&row);
    int *result;
    result = getRow(row,result);
    for(int i = 0; i <= row; i++){
        printf("%d ", result[i]);
    }
    return 0;
}


int* getRow(int rowIndex, int* returnSize) {
    int **rows;
    // OBS: No LeetCode, precisa ter a seguinte linha de codigo para funcionar:
    // *return size = rowIndex + 1;
    // Nesse codigo, não cheguei a usar returnSize, mas o LeetCode usa para saber qual o tamanho da linha do output.
    rows = (int **)malloc(sizeof(int**)*(rowIndex+1));
    for(int i = 0; i <= rowIndex; i++){
        rows[i] = (int*)malloc((rowIndex+1)*sizeof(int *));
        if(i == 0) rows[0][0] = 1;
        else if(i == 1){
            rows[1][0] = 1;
            rows[1][1] = 1;
        }else{
            int a = 0;
            rows[i][0] = 1;
            rows[i][i] = 1;
            for(int j = 1; j < i; j++){
                rows[i][j] = rows[i-1][a] + rows[i-1][a+1];
                a++;
            }
        }
    }
    return rows[rowIndex];
}
