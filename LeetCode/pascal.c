/*

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Link: https://leetcode.com/problems/pascals-triangle/

 */


//Funcionou, deu 0ms!
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **matriz, size = 0;
    matriz = (int **)malloc(sizeof(int*)*numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int*)*numRows);
    for(int i = 0; i < numRows; i++){
        matriz[i] = (int *)malloc(sizeof(int*)*(i+1));
        matriz[i][0] = 1;
        matriz[i][i] = 1;
        (*returnColumnSizes)[i] = i + 1;
    }

    for(int i = 2; i < numRows; i++){
        for(int j = 0; j < i+1; j++){
            if(j == 0){
                matriz[i][j] = 1;
            }else if (j == i){
                matriz[i][j] = 1;
            }else{
                matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j];
            }
            
        }
    }
    *returnSize = numRows;
    return matriz;
}
