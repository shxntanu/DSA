#define lli long long int
int waysToSplitArray(int* nums, int numsSize) {
    lli sum = 0;
    lli *prefixSum = (lli*)malloc((numsSize+1) * sizeof(lli));
    prefixSum[0] = 0;
    for(int i=0; i<numsSize; i++) {
        sum += nums[i];
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }
    int ans = 0;
    for(int i=0; i<numsSize-1; i++) {
        if(2* prefixSum[i+1] >= sum) ans++;
    }
    free(prefixSum);
    return ans;
}
