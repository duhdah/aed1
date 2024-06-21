/*
1464. Maximum Product of Two Elements in an Array

Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).

Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
*/

// Funcionou (13 ms)
int maxProduct(int* nums, int numsSize) {
    int index1=0, index2=0, maior=0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if((nums[i]*nums[j])>maior){
                maior = nums[i] * nums[j];
                index1 = i;
                index2 = j;
            }
        }
    }
    return((nums[index1]-1)*(nums[index2]-1));
}