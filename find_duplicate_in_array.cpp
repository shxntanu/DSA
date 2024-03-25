/*
# Question Link: https://leetcode.com/problems/find-the-duplicate-number
# Problem Statement: To find a duplicate element in the array

# How to think:

// Brute Force:
* If we want to find the duplicate element, the most basic thing that comes in our mind is;
    * Iterate the array and store the frequency of every element in a map
    * Then retrieve the count of the elements from the map; the element with frequency greater than 1 will be returned
* Time Complexity: O(N) --> Traversal in the array
* Space Complexity: O(N) --> Map

// Another approach:
* If we want to find the duplicate element, without using extra space, then we will think of doing it in-place
* Now, if we have to do it in-place, then first thing we can think of is using a counter variable and incrementing it
* But, to use counter, we need to know that for which element we want to increment the counter
* Now, as we don't know that, we will try to use 2 pointers, so that, even if we don't know the element for which the counter is to be incremented, we will directly try to compare the elements of the array
* Now, to compare the elements, the elements should be consecutive, or else we will have to store the occurence of every element, which will be the same as that of 1st method
* So, if we sort the array, the similar elements will be consecutive, and then we can easily compare these consecutive elements!!

# Time Complexity: O(nlogn) --> Sorting (As it uses quick sort internally)
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Method 1:
int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int a;
    if (nums.size() == 0 || nums.size() == 1)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int j = 1;

        while (j < nums.size())
        {
            if (nums[i] == nums[j])
            {
                return nums[i];
            }
            else
            {
                i = j;
                j++;
            }
        }
    }
    return a;
}

// Method 2:
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int hash[n];
    int i;
    int a;

    for (i = 0; i < n; i++)
    {
        hash[i] = 0;
    }
    if (nums.size() == 0 || nums.size() == 1)
    {
        return -1;
    }
    for (i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }

    for (i = 0; i < n; i++)
    {
        if (hash[i] > 1)
        {
            return i;
        }
    }
    return a;
}
