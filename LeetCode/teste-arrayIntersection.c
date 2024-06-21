/*

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Link: https://leetcode.com/problems/intersection-of-two-arrays/description/

*/

// Versão com código completo para teste:

#include <stdio.h>
#include <stdlib.h>

int isInArray (int *array, int n, int arraySize);
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int main(){

    int *array1, *array2, tamarray1, tamarray2, *intersec, size;

    printf("Digite o tamanho da array 1: ");
    scanf("%d",&tamarray1);
    array1 = (int *)malloc(sizeof(int)*tamarray1);

    printf("Digite os elementos da array 1: ");
    for(int i = 0; i < tamarray1; i++){
        scanf("%d",&array1[i]);
    }
    printf("Digite o tamanho da array 2: ");
    scanf("%d",&tamarray2);
    array2 = (int *)malloc(sizeof(int)*tamarray2);

    printf("Digite os elementos da array 2: ");
    for(int i = 0; i < tamarray2; i++){
        scanf("%d",&array2[i]);
    }

    intersec = intersection(array1, tamarray1, array2, tamarray2, &size);

    printf("Tamanho da array: %d\n",size);

    printf("Elementos da array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", intersec[i]);
    }
    printf("\n");

    free(intersec);
    free(array1);
    free(array2);
    return 0;
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0;
    int *array;
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]){
                if(!(*returnSize)){
                    array = (int *)malloc(sizeof(int));
                    array[0] = nums1[i];
                    *returnSize = 1;
                }else{
                    int checkIfInArray = isInArray(array, nums1[i], *returnSize);
                    if(!checkIfInArray){
                        int *newArray = array;
                        *returnSize = *returnSize + 1;
                        newArray = realloc(array, *returnSize);
                        array[*returnSize - 1] = nums1[i];
                    }
                }
            }
        }
    }
    return array;
}
 
 int isInArray (int *array, int n, int arraySize){
    printf("Checando se %d esta na array... ",n);
    int check = 0;
    for(int i = 0; i < arraySize; i++){
        if(array[i] == n){
            check = 1;
        }
    }
    if(check){
        printf("Sim\n");
    }else printf("Nao\n");
    return check;
 }
