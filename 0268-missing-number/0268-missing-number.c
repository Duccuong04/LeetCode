/*
 * Dùng toán học để xử lý
 * Số bị missing = Tổng  của n + 1 số nguyên liên tiếp từ  0 đến n - tổng giá trị phần tử của mảng
*/


int missingNumber(int* nums, int numsSize) {
    int sum_array = 0, sum_n = 0;
    for(int i = 0; i < numsSize; i++)
    {
        sum_array += nums[i];
    }

    sum_n = numsSize*(numsSize + 1)/2;

    return sum_n - sum_array;
}