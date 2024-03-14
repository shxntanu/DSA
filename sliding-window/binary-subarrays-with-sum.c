int numSubarraysWithSum(int* nums, int numsSize, int goal){
    // atmostSubarray(..., goal) will give you number of subarrays with sum <= goal i.e. goal, goal-1 , goal-2 , goal-3 ... 0
    // atmostSubarray(..., goal - 1) will give you number of subarrays with sum <= goal - 1 i.e. goal-1, goal-2 , goal-3, goal-4, ... 0
    return atmostSubarray(nums, numsSize, goal) - atmostSubarray(nums, numsSize, goal - 1);
}

int atmostSubarray(int *nums, int numsSize, int goal) {
    //checking if the goal is negative
    //then return 0 as sum can't be negative
    //0's and 1's are there in the array.
    if(goal < 0) return 0;
    int sum = 0, i=0, j=0, res = 0; // sum is for current sum, res for returning result

    //we're iterating over the nums array and 
    //then adding the current element into the sum
    while(j < numsSize) {
        sum += nums[j];

        // if our current sum is greater than our goal
        // that means we don't need the extra element
        // so we will shrink our window by subtracting 
        // the ith elements from sum till sum > goal
        while(sum > goal) {
            sum -= nums[i];
            i++;
        }

        // add length of each such subarray to result
        res += j-i+1;
        j++;
    }
    return res;
}
