int firstMissingPositive(int* nums, int numsSize) {
    int tmp, tmp2;
    for(int i=0; i<numsSize;i++) {
        tmp = nums[i];
        while(tmp > 0 && tmp <= numsSize && nums[tmp - 1] != tmp) {
            tmp2 = nums[tmp - 1];
            nums[tmp - 1] = tmp;
            tmp = tmp2;
        }
    }
    for(int i=0; i<numsSize;i++)
        if(nums[i] != i+1)
            return i + 1;
    return numsSize + 1;
}
