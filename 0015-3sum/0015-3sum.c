/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int capacity = 100; // ban đầu cấp 100
    int** res = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 2; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = numsSize - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                // Nếu gần đầy thì tăng gấp đôi dung lượng
                if(*returnSize >= capacity) {
                    capacity *= 2;
                    res = (int**)realloc(res, sizeof(int*) * capacity);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                }

                res[*returnSize] = (int*)malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if(sum < 0) left++;
            else right--;
        }
    }

    return res;
}
