/*
# Question Link: https://leetcode.com/problems/find-all-duplicates-in-an-array
# Problem Statement: To find all the duplicate elements in the array; in O(n) time complexity and O(1) space complexity
# How to think:
* If there are duplicate elements in the array, for example: 3; we know that if we encounter 3, it will point to the same location, that is, index 2 in the array
* So, if we can find a way to check whether that index 2 has already been visited or not, we can either assign it to its negative value,
    * or, we can assign it to 0 --> The main point here is, we need a condition to check whether that index is already visited or not

# Time Complexity: O(n)
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int absValue;
    int index;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        absValue = abs(nums[i]);
        index = absValue - 1;

        if (nums[index] < 0)
        {
            // Negative Value
            ans.push_back(absValue);
        }
        else
        {
            // Positive Value
            nums[index] -= 2 * nums[index];
        }
    }
    return ans;
}