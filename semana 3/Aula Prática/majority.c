#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize);

int main(){
    int *nums, numsSize, m;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&numsSize);
    nums = (int *)malloc(sizeof(int)*numsSize);
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < numsSize; i++){
        scanf("%d",&nums[i]);
    }
    m = majorityElement(nums, numsSize);
    printf("Elemento com mais frequencia: %d", m);
}    

int majorityElement(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        int count = 0;
        for(int j = i; j < numsSize; i++){
            if (*(nums+i) == *(nums+j)) count++;
        }
        if(count >= (numsSize/2)){
            return nums[i];
        }
    }
    return 0;
}