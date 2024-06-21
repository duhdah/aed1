int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if((*(nums+i) + *(nums+j)) == target){
                int *p;
                ret = (int*)malloc(2*sizeof(int));
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
