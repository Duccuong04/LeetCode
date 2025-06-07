int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
            return mid;

        // Nửa trái [left..mid] có thứ tự
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1; // target nằm trong nửa trái
            else
                left = mid + 1;  // target nằm bên phải
        }
        // Nửa phải [mid..right] có thứ tự
        else {
            // kiểm tra phần tử cần tìm có nằm trong đó không
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;  // target nằm trong nửa phải
            else
                right = mid - 1; // target nằm bên trái
        }
    }
    return -1; 
}
