/*
Question Link: https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505

Concept: https://www.youtube.com/watch?v=frf7qxiN2qU&t=2230s

Process:
1. Start iterating in the array from the first element
2. Store the sum element by element in a variable called sum and simulataneously store the sum along with the index upto which the corresponding sum is generated in the hash Table
3. If this sum gets greater than k, then we will have to do reverse engineering --> Check in the hashTable whether
   (sum-k) exists or not; if it exists, that means there is a subarray which is present from the index (i-preSumMap[sum-k])
4. If it is not present, check for the presence of an entry of sum in the hashTable
    --> If it does not exist, make a new entry of the sum with its index
    --> else, don't do anything (This test case is specially for handling the zeroes in the array)
*/

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &nums, int k)
{
    // Write your code here

    int n = nums.size();

    long long sum = 0;
    int maxLen = 0;

    map<int, int> preSumMap;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
            preSumMap[sum] = i;
        }
        else
        {
            if (preSumMap.find(sum - k) != preSumMap.end())
            {
                maxLen = max(maxLen, i - preSumMap[sum - k]);
            }
            else
            {
                if (preSumMap.find(sum) == preSumMap.end())
                {
                    preSumMap[sum] = i;
                }
            }
        }
    }

    return maxLen;
}