/*
Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array

Test Case:
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
*/

int maxProduct(int* nums, int numsSize) {
    int largest = 1, largest2 = 0;
    for(int i = 0; i< numsSize; i++) {
        if(nums[i] > largest) {
            largest2 = largest;
            largest = nums[i];
        } else if(largest2 < nums[i]  && largest2 < largest) {
            largest2 = nums[i];
        }
    }
    return (largest - 1) * (largest2 - 1);
}
