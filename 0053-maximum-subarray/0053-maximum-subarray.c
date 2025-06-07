/*
 * Kadane's Algorithm là cách tối ưu để tìm tổng lớn nhất của một dãy con liên tiếp bằng cách quét một lần từ trái sang phải, luôn so sánh giữa việc bắt đầu lại hoặc tiếp tục cộng dồn.
*/
#define max(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize) {
    int current_index = nums[0];
    int max_sum = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        current_index = max(nums[i], current_index + nums[i]);
        max_sum = max(max_sum, current_index);
    }
    
    return max_sum;
}