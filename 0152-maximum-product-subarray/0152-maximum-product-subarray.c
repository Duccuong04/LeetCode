/*
#define max(a,b) ((a) > (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    int max_pro = nums[0];

    for (int i = 0; i < numsSize; i++) {
        int pro = 1;
        for (int j = i; j < numsSize; j++) {
            pro *= nums[j];
            max_pro = max(max_pro, pro);
        }
    }

    return max_pro;
}
*/
#define max(a,b) ((a) > (b) ? (a) : (b))
int maxProduct(int* nums, int numsSize) {
    int max_subarray = -9999999999;
    int prefix = 1, suffix = 1;
    for(int i = 0; i < numsSize; i++)
    {
        if(prefix == 0)
        {
            prefix = 1;
        }

        if(suffix == 0)
        {
            suffix = 1;
        }
        prefix *= nums[i];
        suffix *= nums[numsSize - i - 1];

        max_subarray = max(max_subarray, max(prefix, suffix));
    }

    return max_subarray;
}