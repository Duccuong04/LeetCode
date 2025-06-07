/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Tạo mảng lưu giá trị output
 * Duyệt từ trái -> i, từ i -> phải, sau đó nhân lại 
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *answer = (int *)malloc(sizeof(int) * numsSize);

    // answer i bằng tích từ nums[0] đến num[i - 1] (prefix product)
    answer[0] = 1; // trước nums[0] ko có số j, answer[0] = 1 để khi nhân với right ko thay đổi giá trị
    for(int i = 1; i < numsSize; i++)
    {
        answer[i] = answer[i - 1] * nums[i - 1]; 
    }

    // tích các phần tử bên phải suffiz product
    int right = 1; // sau nums[numsSize - 1] ko có số j
    for(int i = numsSize - 1; i >= 0; i--)
    {
        answer[i] *= right;
        right *= nums[i];
    }

    return answer;
}