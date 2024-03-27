int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if(k<=1) return 0;
    int lb =0, res = 0, prod = 1;
    for(int ub = 0; ub<numsSize; ub++) {
        prod *= nums[ub];
        while(prod >= k) {
            prod /= nums[lb];
            lb++;
        }
        res += ub - lb + 1;
    }
    return res;
}
