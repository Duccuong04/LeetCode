/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int num1 = 0; num1 < numsSize; num1++) {
        for(int num2 = num1 + 1; num2 < numsSize; num2++) {
            if(target - nums[num1] == nums[num2]) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = num1;
                result[1] = num2;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}