int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

long long lower_bound(int *nums, int ns, int value) {
    int left = 0, right = ns - 1;
    long long result = 0;
    while(left < right) {
        if(nums[left] + nums[right] < value) {
            result += right - left;
            left++;
        } else {
            right--;
        }
    }
    return result;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), compare);
    return lower_bound(nums, numsSize, upper + 1) - lower_bound(nums, numsSize, lower);
}
