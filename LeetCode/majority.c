
/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Link: https://leetcode.com/problems/majority-element/description/

*/

#include <stdio.h>
#include <stdlib.h>

// Funcionou, mas deu time limit exceeded
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
    printf("Elemento com mais frequencia na array: %d", m);
}    


int majorityElement(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        int count = 0;
        float times = ceil((float)numsSize/2);
        for(int j = 0; j < numsSize; j++){
            if (nums[i] == nums[j]) count++;
        }
        if(count >= times){
            return nums[i];
        }
    }
    return 0;
}