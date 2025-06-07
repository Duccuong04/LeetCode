int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int mid;
    int min_array;
    while(left < right)
    {
        mid = (left + right)/2;

        if(nums[mid] > nums[right]) // phần tử min nằm bên phải
        {
            left = mid + 1;
        }
        else                        // phần tử min nằm bên trái
        {
           right = mid; 
        }
    }
    return nums[left];              // nums[left] = nums[right] = min;
}