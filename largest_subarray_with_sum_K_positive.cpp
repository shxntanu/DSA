#include <bits/stdc++.h>
using namespace std;

/*
Question Link: https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399

# Brute Force Solution:

Concept:
1. Calculate the sum of all the subarrays and based on comparison, update the length to be the maximum

Code:

int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here

    int n = arr.size();

    long long sum = 0;
    int maxLen = 0;

    for(int i=0;i<n;i++) {
      sum = 0;
      for(int j=i;j<n;j++) {
        sum += arr[j];

        if(sum == k) {
          maxLen = max(maxLen, j-i+1);
        }
      }
    }

    return maxLen;
}

# Better Solution: (Very Very Important Concept)
https://www.youtube.com/watch?v=frf7qxiN2qU&t=2230s


# Most Optimal Solution for this problem (Only if it contains positive elements)

Concept:
1. We will take use of 2 pointers, i and j.
2. These 2 pointers will define a subarray from i to j
3. We are calculating the sum of the subarray from i to j, and we are checking if the sum is equal to K or not.
4. If the sum is equal to k,
    --> Compare the length of this subarray with the previously stored length and whichever is greater, update length with that
5. If the sum is less than k,
    --> keep on incrementing j pointer
6. If the sum is greater than k,
    --> Subtract all the elements from the start until the sum is either less than k or equal to k
    --> If the sum now is equal to k, update the lenght with the maximum
    --> else, if the sum is less than k, increment j and continue the process
*/

int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    // Write your code here
    int n = arr.size();

    int i = 0;
    int j = 0;
    long long sum = 0;
    int maxLen = 0;

    while (j < n)
    {
        sum += arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else
        {
            while (i <= j && sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }

    return maxLen;
}

int main()
{
    return 0;
}