/*

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Link: https://leetcode.com/problems/intersection-of-two-arrays/description/

*/

// Anotação para mim: Os argumentos do realloc são a array e o tamanho novo da array em bytes (sizeof)!

// Funcionou: 9ms
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int size = 0;
    int *array;
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]){
                if(!size){
                    array = (int *)malloc(sizeof(int));
                    array[0] = nums1[i];
                    size = 1;
                }else{
                    int checkIfInArray = isInArray(array, nums1[i], size);
                    if(!checkIfInArray){
                        size++;
                        array = realloc(array, size*sizeof(int));
                        array[size - 1] = nums1[i];
                    }
                }
            }
        }
    }
    *returnSize = size;
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