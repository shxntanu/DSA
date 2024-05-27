/*
# Question Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
# Problem Statement: To find 'x', having exactly x elements in the array which are greater than or equal to x

# How to think:
* If we want to find 'x', satisfying a particular criteria, then we can think of starting from some minimum element and proceed further

# Time Complexity: O(x*n)
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, int value, int n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= value)
            {
                cnt++;
            }
        }
        return cnt;
    }

    int specialArray(vector<int> &nums)
    {
        int n = nums.size();

        int val = 1;
        int count;

        while (val <= n)
        {
            count = helper(nums, val, n);

            if (count == val)
            {
                return val;
            }
            else
            {
                val++;
            }
        }

        return -1;
    }
};