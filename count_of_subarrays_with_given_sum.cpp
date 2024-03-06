#include <bits/stdc++.h>
using namespace std;

/*
Question Link: https://www.codingninjas.com/studio/problems/subarray-sums-i_1467103

Explanation:

# Concept: 2 pointers
* Take 2 pointers i and j, keep adding arr[j] to sum
* After each addition, check whether the sum is equal to k or not
    If it is equal, increment the count by 1
    If it is less than k, increment j by 1 and continue the process
    If it is greater than k, decrement the value of sum by arr[i] until it become less than or equal to k
        After doing this, check if the value of sum is equal to k or not
            If equal, increment count and increment j
            else increment j and continue the process

# Time Complexity: O(n) --> As we are traversing each element of the array only once
*/

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // Write Your Code Here

    int n = arr.size();

    int i = 0;
    int j = 0;
    int sum = 0;
    int count = 0;

    while (j < n)
    {
        sum += arr[j];
        if (sum == k)
        {
            count++;
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
            {
                count++;
                j++;
            }
            else
            {
                j++;
            }
        }
        else
        {
            j++;
        }
    }

    return count;
}

int main()
{
    return 0;
}